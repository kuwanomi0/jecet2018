/**
 ******************************************************************************
 ** ファイル名 : Runner.cpp
 ** クラス名   : Runner
 **
 ** 概要 : 走行を管理するクラス
 ******************************************************************************
 **/
#include "Runner.h"

/**
 * 関数名 : Runner
 * 引数   : なし
 * 概要   : コンストラクタ
 */
Runner::Runner() {
    cm = new ControlManager();
    inspanel = new InstrumentPanel();
}

/**
 * 関数名 : start
 * 引数   : int forward, int turn, int tailAngle
 * 返り値 : なし
 * 概要   : スタート待機の処理をする
 */
void Runner::start(int forward, int turn, int tailAngle) {
    cm->tailInit();
    while (1) {
        int tailTMP = inspanel->pushTailButton();

        if (inspanel->getSonarAlert() == 1) {
            ev3_led_set_color(LED_RED);
        }
        else {
            ev3_led_set_color(LED_GREEN);
        }

        if (tailTMP != 0) {
            tailAngle += tailTMP;
            syslog(LOG_NOTICE, "TAIL: %3d\r", tailAngle);
        }

        cm->running(forward, turn, tailAngle);

        if (inspanel->pushButton()) {
            break;
        }

        cm->setTargetRgb(inspanel->pushColorButton());
    }
    cm->gyroInit();
    cm->wheelInit();
    cm->balancerInit();
}

/**
 * 関数名 : run
 * 引数   : int forward, int turn, int tailAngle
 * 返り値 : なし
 * 概要   : 走行の処理をする
 */
void Runner::run(int forward, int turn, int tailAngle) {
    inspanel->update();

    lookupRun(&forward, &turn, &tailAngle);

    int totalRGB = inspanel->getTotalRGB();
    if (style == 1) {
        cm->running(forward, turn, tailAngle, totalRGB);
    }
    else {
        cm->noBalanceRun(forward, turn, tailAngle, totalRGB);
    }
    if (totalRGB <= 7 || inspanel->getBtCmd() == 6) {
        ev3_led_set_color(LED_RED);
        wup_tsk(MAIN_TASK);
        ev3_stp_cyc(CYC_HANDLER);
        cm->stop();
        inspanel->stop();
    }
}

/**
 * 関数名 : btUpdate
 * 引数   : なし
 * 返り値 : なし
 * 概要   : Bluetoothからの情報を更新する
 */
void Runner::btUpdate() {
    inspanel->btUpdate();
}

/**
 * 関数名 : getDistance
 * 引数   : なし
 * 返り値 : int 走行距離
 * 概要   : 現在の走行距離を取得する
 */
int Runner::getDistance() {
    return inspanel->getRunDistance();
}

/**
 * 関数名 : getBtCmd
 * 引数   : なし
 * 返り値 : int BTコマンド
 * 概要   : 現在のBTコマンド値を取得する
 */
int Runner::getBtCmd() {
    return inspanel->getBtCmd();
}

/**
 * 関数名 : setPID
 * 引数   : float kp, float ki, float kd
 * 返り値 : なし
 * 概要   : ライントレースに必要なPID係数を設定する
 */
void Runner::setPID(float kp, float ki, float kd) {
    cm->setPID(kp, ki, kd);
}

/**
 * 関数名 : setStyle
 * 引数   : int getStyle
 * 返り値 : なし
 * 概要   : 走行方法を設定する
 */
void Runner::setStyle(int style) {
    this->style = style;
}

/**
 * 関数名 : lookupRun
 * 引数   : int* forward, int* turn, int* tailAngle
 * 返り値 : なし
 * 概要   : ルックアップに必要な走行情報にアドレスに直に書き換える
 * TODO   : このメソッドは配列などにできると思うのでもう少し改良を行う
 */
void Runner::lookupRun(int* forward, int* turn, int* tailAngle) {
    if (lookupLine == 0) {
        distanceTmp = getDistance();
    }

    if ((inspanel->getSonarAlert() && lookupLine == 0) || lookupLine == 1) {
        lookupLine = 1;
        style = 0;
        *tailAngle = 65;
        if (lookupLineC < 100/4) {
            *forward = 30;
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else if (lookupLineC < 700/4) {
            *forward = 0;
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else {
            *forward = 20;
            setPID(0.0F,0.0F,0.0F);
            // setPID(0.0100F, 0.0002F, 0.1000F);
        }
        if (getDistance() - distanceTmp > 400) {
            lookupLine = 2;
        }
    }

    if (lookupLine == 2) {
        lookupLine = 2;
        lookupLineC++;
        style = 0;
        *forward = 0;
        *tailAngle = 65;
        setPID(0.0F,0.0F,0.0F);
        if (lookupLineC > 1500/4) {
            lookupLine = 3;
        }
    }

    if (lookupLine == 3) {
        lookupLine = 3;
        style = 0;
        *forward = -30;
        *turn = 0;
        *tailAngle = 65;
        if (lookupLineC < 1800/4) {
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else {
            setPID(0.0000F, 0.0000F, 0.0000F);
        }
        if (getDistance() - distanceTmp < -50) {
            lookupLine = 44;
        }
    }

    if (lookupLine == 44) {
        lookupLine = 44;
        lookupLineC++;
        style = 0;
        *forward = 0;
        *tailAngle = 65;
        setPID(0.0F,0.0F,0.0F);
        if (lookupLineC > 3000/4) {
            lookupLine = 4;
        }
    }

    if (lookupLine == 4) {
        lookupLine = 4;
        style = 0;
        *forward = 15;
        *tailAngle = 65;
        setPID(0.0500F, 0.0002F, 0.3000F);
        if (getDistance() - distanceTmp > 440) {
            lookupLine = 55;
        }
    }

      if (lookupLine == 55) {
          lookupLine = 55;
          style = 0;
          *forward = 15;
          *tailAngle = 65;
          setPID(0.0000F, 0.0000F, 0.0000F);
          if (getDistance() - distanceTmp > 720) {
              lookupLine = 6;
          }
      }

    if (lookupLine == 5) {
        lookupLine = 5;
        style = 0;
        *forward = 15;
        *tailAngle = 65;
        setPID(0.0500F, 0.0002F, 0.3000F);
        if (getDistance() - distanceTmp > 920) {
            lookupLine = 6;
        }
    }

    if (lookupLine == 6) {
        lookupLine = 6;
        lookupLineC++;
        style = 0;
        *forward = 0;
        *tailAngle = 75;
        setPID(0.0000F, 0.0000F, 0.0000F);
    }

    if (lookupLine == 6) {
        lookupLine = 6;
        style = 0;
        *forward = -10;
        *tailAngle = 82;
        setPID(0.0000F, 0.0000F, 0.0000F);
        if (lookupLineC > 3200/4) {
            inspanel->setBtCmd(6);
        }
    }
}
