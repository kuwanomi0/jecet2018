/**
 ******************************************************************************
 ** ファイル名 : StartSwitch.cpp
 ** クラス名   : StartSwitch
 **
 ** 概要 : タッチセンサーの確認をするクラス
 ******************************************************************************
 **/
#include "StartSwitch.h"
#include "Clock.h"

StartSwitch::StartSwitch() {
    touchSensor = new TouchSensor(PORT_1);
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);
}

int StartSwitch::pushButton() {
    int8_t result = 0;
    Clock clock;
    if (touchSensor->isPressed() || mBtCmd == 1) {
        result = 1;
    }

    clock.sleep(10);
	return result;
}

void StartSwitch::btTask() {
        uint8_t c = fgetc(bt);
        switch(c)
        {
        case '0':
            mBtCmd = 0;
            break;
        case '1':
            mBtCmd = 1;
            break;
        case '6':
            mBtCmd = 6;
            break;
        case '\r':
            mBtCmd = '\r';
            break;
        default:
            break;
        }
        fputc(c, bt); /* エコーバック */
}

void StartSwitch::btStop() {
    ter_tsk(BT_TASK);
    fclose(bt);
}
