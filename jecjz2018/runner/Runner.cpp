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
 * コンストラクタ
 */
Runner::Runner() {
    cm = new ControlManager();
    inspanel = new InstrumentPanel();
}

/**
 * スタート待機処理
 * @param forward    前進
 * @param turn       旋回
 * @param tailAngle  尻尾角度
 * @comment TODO whileで処理を行っているためタスク化を考える
 */
void Runner::start(int forward, int turn, int tailAngle) {
    cm->tailInit();
    while (1) {
        int tailTMP = inspanel->pushTailButton();

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
 * 走行処理
 * @param forward    前進
 * @param turn       旋回
 * @param tailAngle  尻尾角度
 */
void Runner::run(int forward, int turn, int tailAngle, float krgb) {
    inspanel->update();
    // if (seesawLine == 0) {
        lookupRun(&forward, &turn, &tailAngle);
    // }
    // if (lookupLine == 0) {
        // seesawRun(&forward, &turn, &tailAngle);
    // }

    int totalRGB = inspanel->getTotalRGB() / krgb;
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
 * BT更新
 */
void Runner::btUpdate() {
    inspanel->btUpdate();
}

/**
 * 総走行距離取得
 * @return 総走行距離
 */
int Runner::getDistance() {
    return inspanel->getRunDistance();
}

/**
 * BtCmd取得
 * @return BtCmd
 */
int Runner::getBtCmd() {
    return inspanel->getBtCmd();
}

/**
 * PID係数設定
 * @param kp 係数P
 * @param ki 係数I
 * @param kd 係数D
 */
void Runner::setPID(float kp, float ki, float kd) {
    cm->setPID(kp, ki, kd);
}

/**
 * 走行方法設定
 * @return style
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
// void Runner::seesawRun(int* forward, int* turn, int* tailAngle) {
//     if (seesawLine == 0) {
//         distanceTmp = getDistance();
//     }
//
//     if ((inspanel->getImpactAlert() && seesawLine == 0) || seesawLine == 1) {
//         seesawLine = 1;
//         // style = 1;
//         // *forward = -10;
//         *tailAngle = 75;
//         // setPID(0.0F,0.0F,0.0F);
//     }
// }

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
            *forward = 10;
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
        *forward = -10;
        *turn = 0;
        *tailAngle = 62;
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
        *forward = 10;
        *tailAngle = 65;
        setPID(0.0500F, 0.0002F, 0.3000F);
        if (getDistance() - distanceTmp > 440) {
            lookupLine = 55;
        }
    }

      if (lookupLine == 55) {
          lookupLine = 55;
          style = 0;
          *forward = 10;
          *tailAngle = 65;
          setPID(0.0000F, 0.0000F, 0.0000F);
          if (getDistance() - distanceTmp > 720) {
              lookupLine = 5;
          }
      }

    if (lookupLine == 5) {
        lookupLine = 5;
        style = 0;
        *forward = 10;
        *tailAngle = 70;
        setPID(0.0000F, 0.0000F, 0.0000F);
        if (getDistance() - distanceTmp > 900) {
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
        *tailAngle = 80;
        setPID(0.0000F, 0.0000F, 0.0000F);
        if (lookupLineC > 3200/4) {
            inspanel->setBtCmd(6);
        }
    }
}
