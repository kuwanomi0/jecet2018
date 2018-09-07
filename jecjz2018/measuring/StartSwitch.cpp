/**
 ******************************************************************************
 ** ファイル名 : StartSwitch.cpp
 ** クラス名   : StartSwitch
 **
 ** 概要 : タッチセンサーの確認をするクラス
 ******************************************************************************
 **/
#include "Clock.h"
#include "StartSwitch.h"

using namespace ev3api;

/**
 * コンストラクタ
 */
StartSwitch::StartSwitch() {
    touchSensor = new TouchSensor(PORT_1);
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);
}

/**
 * RGB設定用スイッチ
 * @return BtCmd
 */
int StartSwitch::pushColorButton() {
    int8_t result = 0;
    Clock clock;
    if (mBtCmd == 'w') {
        result = 1;
    }
    else if (mBtCmd == 'b') {
        result = 2;
    }

    clock.sleep(1);
    return result;
}

/**
 * 尻尾角度設定用スイッチ
 * @return BtCmd
 */
int StartSwitch::pushTailButton() {
    int8_t result = 0;
    Clock clock;
    if (mBtCmd == '[') {
        result = 1;
    }
    else if (mBtCmd == ']') {
        result = 2;
    }

    clock.sleep(1);
    return result;
}

/**
 * スタート用スイッチ
 * @return BtCmd
 */
int StartSwitch::pushButton() {
    int8_t result = 0;
    Clock clock;
    if (touchSensor->isPressed() || mBtCmd == 1 || mBtCmd == 2 || mBtCmd == 3) {
        result = 1;
    }

    clock.sleep(10);
    return result;
}

/**
 * BtCmd受信
 */
void StartSwitch::btUpdate() {
        uint8_t c = fgetc(bt);
        switch(c)
        {
        case '0':
            mBtCmd = 0;
            break;
        case '1':
            mBtCmd = 1;
            break;
        case '2':
            mBtCmd = 2;
            break;
        case '3':
            mBtCmd = 3;
            break;
        case '6':
            mBtCmd = 6;
            break;
        case 'w':
            mBtCmd = 'w';
            break;
        case 'b':
            mBtCmd = 'b';
            break;
        case '[':
            mBtCmd = '[';
            break;
        case ']':
            mBtCmd = ']';
            break;
        case '\r':
        case '9':
            mBtCmd = '\r';
            break;
        default:
            break;
        }
        fputc(c, bt); /* エコーバック */
}

/**
 * BTタスク停止
 */
void StartSwitch::btStop() {
    ter_tsk(BT_TASK);
    fclose(bt);
}

/**
 * BtCmd設定
 * @return mBtCmd
 */
int StartSwitch::getBtCmd() {
    return mBtCmd;
}

/**
 * BtCmd設定
 * @param BtCmd
 */
void StartSwitch::setBtCmd(int mBtCmd) {
    this->mBtCmd = mBtCmd;
}
