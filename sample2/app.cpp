/**
 ******************************************************************************
 ** ファイル名 : app.cpp
 **
 ** 概要 : 2輪倒立振子ライントレースロボットのTOPPERS/HRP2用C++サンプルプログラム
 **
 ** 注記 : sample_cpp (ライントレース/尻尾モータ/超音波センサ/リモートスタート)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"
#include "balancer.h"
#include "BalancerCpp.h"
#include "TouchSensor.h"
#include "SonarSensor.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "Motor.h"
#include "Clock.h"
#include "PID.h"
#include "Distance.h"
#include "Course.h"

using namespace ev3api;

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
static int32_t   bt_cmd = 0;      /* Bluetoothコマンド 1:リモートスタート */
static FILE     *bt = NULL;      /* Bluetoothファイルハンドル */

/* 下記のマクロは個体/環境に合わせて変更する必要があります */
/* 走行に関するマクロ */
#define GYRO_OFFSET           2  /* ジャイロセンサオフセット値(角速度0[deg/sec]時) */
#define RGB_TARGET          365  /*中央の境界線のRGBセンサ合計値 */
#define RGB_NULL              7  /* 何もないときのセンサの合計 */
#define KLP                 0.6  /* LPF用係数*/

/* 超音波センサーに関するマクロ */
#define SONAR_ALERT_DISTANCE 20  /* 超音波センサによる障害物検知距離[cm] */

/* 尻尾に関するマクロ */
#define TAIL_ANGLE_STAND_UP   93 /* 完全停止時の角度[度] */
#define TAIL_ANGLE_ROKET      93 /* ロケットダッシュ時の角度[度] */
#define TAIL_ANGLE_DRIVE       3 /* バランス走行時の角度[度] */
#define TAIL_ANGLE_STOP       87 /* 停止処理時の角度[度] */
#define TAIL_ANGLE_FIX      -0.5 /* 尻尾のずれ修正用 */
#define KP_TAIL             2.7F /* 尻尾用定数P */
#define KI_TAIL            0.02F /* 尻尾用定数I */
#define KD_TAIL            14.0F /* 尻尾用定数D */
#define PWM_ABS_MAX           60 /* 完全停止用モータ制御PWM絶対最大値 */


/* LCDフォントサイズ */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/* magic number*/)
#define CALIB_FONT_HEIGHT (8/* magic number*/)

/* 関数プロトタイプ宣言 */
static int32_t sonar_alert(void);
static void tail_control(int32_t angle);
static void run_result(void);
static void backlash_cancel(signed char lpwm, signed char rpwm, int32_t *lenc, int32_t *renc);

/* オブジェクトへのポインタ定義 */
TouchSensor*    touchSensor;
SonarSensor*    sonarSensor;
ColorSensor*    colorSensor;
GyroSensor*     gyroSensor;
Motor*          leftMotor;
Motor*          rightMotor;
Motor*          tailMotor;
Clock*          clock;
Clock*          clock_gate;

/* インスタンスの生成 */
Balancer balancer;
PID pid_walk(      0,       0,       0); /* 走行用のPIDインスタンス */
PID pid_tail(KP_TAIL, KI_TAIL, KD_TAIL); /* 尻尾用のPIDインスタンス */
Distance distance_way;

/* デフォルト */
static Course gCourse[] {
    { 0,     0, 80, 0.0500F, 0.0000F, 1.2000F }, //スタート
    { 1, 99999,  1, 0.0000F, 0.0000F, 0.0000F } //終わりのダミー
};

/* タイム格納用 */
static int times[2][100];
static int lapTime_count = 0;

/* 走行距離 */
static int32_t distance_now; /*現在の走行距離を格納する変数 */

static int8_t    forward;      /* 前後進命令 */
static int8_t    turn;         /* 旋回命令 */
static int8_t    pwm_L = 0, pwm_R = 0;
static rgb_raw_t rgb_level;    /* カラーセンサーから取得した値を格納する構造体 */
static int       course_number = 0; //TODO :2 コース関連 だいぶ改善されました
static int       count = 0;  //TODO :2 コース関連 だいぶ改善されました
static int       roket = 0;  //TODO :3 ロケットスタート用変数 タイマーの役割をしています
static int       forward_course = 50; //TODO :2 コース関連 だいぶ改善されました
static uint16_t  rgb_total = RGB_TARGET;
static uint16_t  rgb_before;
static Course*   mCourse = NULL;

static SYSUTM start_time;	//時間計測用:開始時間
static SYSUTM time;			//時間計測用:結果

/* メインタスク */
void main_task(intptr_t unused)
{

    /* 各オブジェクトを生成・初期化する */
    touchSensor = new TouchSensor(PORT_1);
    sonarSensor = new SonarSensor(PORT_2);
    colorSensor = new ColorSensor(PORT_3);
    gyroSensor  = new GyroSensor(PORT_4);
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
    tailMotor   = new Motor(PORT_A);
    clock       = new Clock();
    clock_gate  = new Clock();

    /* LCD画面表示 */
    char buf[64];
    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string("EV3way-ET 16JZ", 0, CALIB_FONT_HEIGHT*1);

    /* 尻尾モーターのリセット */
    for(int i = 0; i < 500; i++){
        tailMotor->setPWM(-3);
        clock->wait(1);
    }
    tailMotor->reset();

    /* Open Bluetooth file */
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);

    /* Bluetooth通信タスクの起動 */
    act_tsk(BT_TASK);

    ev3_led_set_color(LED_ORANGE); /* 初期化完了通知 */

    /* スタート待機 */
    double angle = (double)TAIL_ANGLE_STAND_UP;

    while(1)
    {
        tail_control(angle); /* 完全停止用角度に制御、調整も可 */

        /* デフォルコース */
        if (touchSensor->isPressed() || bt_cmd == 1)
        {
            mCourse = gCourse;
            break; /* タッチセンサが押された */
        }

        clock->sleep(10); /* 10msecウェイト */
    }

    /* 走行モーターエンコーダーリセット */
    leftMotor->reset();
    rightMotor->reset();

    /* ジャイロセンサーリセット */
    gyroSensor->reset();
    balancer.init(GYRO_OFFSET); /* 倒立振子API初期化 */

    ev3_led_set_color(LED_GREEN); /* スタート通知 */

    ER er = ev3_sta_cyc(CYC_HANDLER);   //周期ハンドラを起動
    sprintf(buf, "main_task: error_code=%d", MERCD(er) );   // APIのエラーコードの表示
    //ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT*1);     // の仕方です。

    /* 自タスク(メインタスク）を待ち状態にする */
    slp_tsk();

    leftMotor->reset();
    rightMotor->reset();
    tailMotor->reset();


    ter_tsk(BT_TASK);
    fclose(bt);

    ext_tsk();
}

//*****************************************************************************
// 関数名 : controller_task
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : コントローラータスク
//*****************************************************************************
void controller_task(intptr_t unused)
{
    /* 時間計測開始 */
	// get_utm(&start_time);

    int32_t motor_ang_l, motor_ang_r;
    int32_t gyro, volt;

    /* 参照しているコース配列が切り替わったことをLEDで知らせます */
    if((course_number % 2) == 1) {  /* 奇数配列参照時、赤 */
        ev3_led_set_color(LED_RED);
    }
    else {                          /* 偶数配列参照時、緑 */
        ev3_led_set_color(LED_GREEN);
    }

    if (course_number == 99) {
        bt_cmd = 6;
    }

    /* 尻尾の制御 */
    if (bt_cmd == 6) {  // TODO :4 停止用コマンド
    }
    else if(roket++ < 25) {  //TODO :3 ロケットスタートと呼ぶにはまだ怪しい、改良必須
        tail_control(TAIL_ANGLE_ROKET); /* ロケット走行用角度に制御 */
    }
    else {
        tail_control(TAIL_ANGLE_DRIVE); /* バランス走行用角度に制御 */
    }

    rgb_before = rgb_total; //LPF用前処理
    colorSensor->getRawColor(rgb_level); /* RGB取得 */
    rgb_total = (rgb_level.r + rgb_level.g + rgb_level.b)  * KLP + rgb_before * (1 - KLP); //LPF

    /* バックボタン, 転倒時停止処理 */
    if (ev3_button_is_pressed(BACK_BUTTON) || rgb_total <= RGB_NULL || bt_cmd == 6) {
        run_result();
        ev3_led_set_color(LED_RED);
        wup_tsk(MAIN_TASK);        //メインタスクを起床する
        ev3_stp_cyc(CYC_HANDLER);  //周期ハンドラを停止する
    }

    /* 現在の走行距離を取得 */
    distance_now = distance_way.distanceAll(leftMotor->getCount(), rightMotor->getCount());

    /* 区間変更を監視、行うプログラム */
    if (distance_now >= mCourse[count].getDis()) { //TODO :2 コース関連 だいぶ改善されました ここがまだ改良できる
        course_number  = mCourse[count].getCourse_num();
        forward_course = mCourse[count].getForward();
        pid_walk.setPID(mCourse[count].getP(), mCourse[count].getI(), mCourse[count].getD());
        count++;
    }

    if (sonar_alert() == 1) {/* 障害物検知 */
        forward = turn = 0; /* 障害物を検知したら停止 */
    }
    else {
        forward = forward_course; /* 前進命令 */
        /* PID制御 */
        turn = pid_walk.calcControl(RGB_TARGET - rgb_total);
    }

    /* 倒立振子制御API に渡すパラメータを取得する */
    motor_ang_l = leftMotor->getCount();
    motor_ang_r = rightMotor->getCount();
    gyro = gyroSensor->getAnglerVelocity();
    volt = ev3_battery_voltage_mV();

    /* バックラッシュキャンセル */
    backlash_cancel(pwm_L, pwm_R, &motor_ang_l, &motor_ang_r);

    balancer.setCommand(forward, turn);
    balancer.update(gyro, motor_ang_r, motor_ang_l, volt);
    pwm_L = balancer.getPwmRight();
    pwm_R = balancer.getPwmLeft();

    /* EV3ではモーター停止時のブレーキ設定が事前にできないため */
    /* 出力0時に、その都度設定する */
    if (pwm_L == 0)
    {
         leftMotor->stop();
    }
    else
    {
        leftMotor->setPWM(pwm_L);
    }

    if (pwm_R == 0)
    {
         rightMotor->stop();
    }
    else
    {
        rightMotor->setPWM(pwm_R);
    }

    /* ログを送信する処理 */
    // syslog(LOG_NOTICE, "G:%3d\r", gyro);

    // clock->sleep(4);

    /* 時間計測終了 */
    get_utm(&time);
    time = time - start_time;
    // act_tsk(PRINT_TIME_TASK);	//計測時間表示タスクを起動

    syslog(LOG_NOTICE, "TIME %ld us\r", time);

    ext_tsk();
}

//*****************************************************************************
// 関数名 : cyc_handler
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : 周期ハンドラ(4ms)
//*****************************************************************************
void cyc_handler(intptr_t unused)
{
    // コントローラタスクを起動する
    act_tsk(CONTROLLER_TASK);
}

//*****************************************************************************
// 関数名 : sonar_alert
// 引数 : 無し
// 返り値 : 1(障害物あり)/0(障害物無し)
// 概要 : 超音波センサによる障害物検知
//*****************************************************************************
static int32_t sonar_alert(void)
{
    static uint32_t counter = 0;
    int32_t alert = 0;

    int32_t distance;

    if (++counter == 4/4) /* 約40msec周期毎に障害物検知  */
    {
        /*
         * 超音波センサによる距離測定周期は、超音波の減衰特性に依存します。
         * NXTの場合は、40msec周期程度が経験上の最短測定周期です。
         * EV3の場合は、要確認
         */
        distance = sonarSensor->getDistance();
        if ((distance <= SONAR_ALERT_DISTANCE) && (distance >= 0))
        {
            alert = 1; /* 障害物を検知 */
        }
        else
        {
            alert = 0; /* 障害物無し */
        }
        counter = 0;
    }

    return alert;
}


//*****************************************************************************
// 関数名 : tail_control
// 引数 : angle (モータ目標角度[度])
// 返り値 : 無し
// 概要 : 走行体完全停止用モータの角度制御
//*****************************************************************************
static void tail_control(int32_t angle)
{
    int pwm = (int)pid_tail.calcControl(angle - tailMotor->getCount() - TAIL_ANGLE_FIX); /* PID制御 */
    /* PWM出力飽和処理 */
    if (pwm > PWM_ABS_MAX)
    {
        pwm = PWM_ABS_MAX;
    }
    else if (pwm < -PWM_ABS_MAX)
    {
        pwm = -PWM_ABS_MAX;
    }

    tailMotor->setPWM(pwm);
}

//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//       ASCIIコードで1を送信すると、リモートスタートする。
//*****************************************************************************
void bt_task(intptr_t unused)
{
    while(1)
    {
        uint8_t c = fgetc(bt); /* 受信 */
        switch(c)
        {
        case '0':
            bt_cmd = 0;
            break;
        case '1':
            bt_cmd = 1;
            break;
        case '6':
            bt_cmd = 6;
            break;
        case '\r':
            bt_cmd = '\r';
            break;
        default:
            break;
        }
        if (bt_cmd == 1 || bt_cmd == 2) {
            clock->reset();
        }
        else if (bt_cmd == '\r' && lapTime_count < 100) {
            syslog(LOG_NOTICE, "DEBUG, TIME : //////////////////////////////\r");
            syslog(LOG_NOTICE, "DEBUG, TIME : %d.%03d s , 距離 : %d.%d m\r", clock->now() / 1000, clock->now() % 1000, distance_now / 1000, distance_now % 1000);
            syslog(LOG_NOTICE, "DEBUG, TIME : //////////////////////////////\r");
            times[0][lapTime_count] = clock->now();
            times[1][lapTime_count] = distance_now;
            lapTime_count++;
        }
    }
}

//*****************************************************************************
// 関数名 : run_result
// 引数 : unused
// 返り値 : なし
// 概要 : 走行結果を表示する
//*****************************************************************************
static void run_result() {
    if (lapTime_count > 0) {
        syslog(LOG_NOTICE, "DEBUG, TIME --------------------\r");
        for (int i = 0; i < lapTime_count; i++) {
            syslog(LOG_NOTICE, "TIME(%3d) : %d.%03d s , 距離 : %d.%03d m",i + 1 , times[0][i] / 1000, times[0][i] % 1000, times[1][i] / 1000, times[1][i] % 1000);
            syslog(LOG_NOTICE, "(%3d m/s)\r",  (times[1][i] / 1000) / (times[1][i] / 1000));
        }
        syslog(LOG_NOTICE, "DEBUG, TIME --------------------\r");
    }
}

//*****************************************************************************
// 関数名 : backlash_cancel
// 引数 : lpwm (左モーターPWM値 ※前回の出力値)
//        rpwm (右モーターPWM値 ※前回の出力値)
//        lenc (左モーターエンコーダー値)
//        renc (右モーターエンコーダー値)
// 返り値 : なし
// 概要 : 直近のPWM値に応じてエンコーダー値にバックラッシュ分の値を追加します。
//*****************************************************************************
void backlash_cancel(signed char lpwm, signed char rpwm, int32_t *lenc, int32_t *renc)
{
    const int BACKLASHHALF = 0;   // バックラッシュの半分[deg]

    if(lpwm < 0) *lenc += BACKLASHHALF;
    else if(lpwm > 0) *lenc -= BACKLASHHALF;

    if(rpwm < 0) *renc += BACKLASHHALF;
    else if(rpwm > 0) *renc -= BACKLASHHALF;
}
