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

#include "runner/Driver.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
// static int32_t   bt_cmd = 0;
// static FILE     *bt = NULL;

Driver* driver;

//*****************************************************************************
// 関数名 : mainTask
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : メインタスク
//*****************************************************************************
void mainTask(intptr_t unused)
{
    char buf[64];
    driver = new Driver();

    // bt = ev3_serial_open_file(EV3_SERIAL_BT);
    // assert(bt != NULL);

    act_tsk(BT_TASK);

    driver->start();

    ER er = ev3_sta_cyc(CYC_HANDLER);   //周期ハンドラを起動
    sprintf(buf, "main_task: error_code=%d", MERCD(er) );   // APIのエラーコードの表示
    //ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT*1);     // の仕方です。

    slp_tsk();

    // ter_tsk(BT_TASK);
    // fclose(bt);

    ext_tsk();
}

//*****************************************************************************
// 関数名 : controllerTask
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : コントローラータスク
//*****************************************************************************
void controllerTask(intptr_t unused)
{
    driver->exec();
}

//*****************************************************************************
// 関数名 : cyc_handler
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : 周期ハンドラ(4ms)
//*****************************************************************************
void cycHandler(intptr_t unused)
{
    act_tsk(CONTROLLER_TASK);
}

//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//       ASCIIコードで1を送信すると、リモートスタートする。
//*****************************************************************************
void btTask(intptr_t unused)
{
    while(1) {
        driver->btTask();
    }
}
