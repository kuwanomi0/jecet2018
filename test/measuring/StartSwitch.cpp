/**
 ******************************************************************************
 ** ファイル名 : StartSwitch.cpp
 ** クラス名   : StartSwitch
 **
 ** 概要 : タッチセンサーの確認をするクラス
 ******************************************************************************
 **/
#include "StartSwitch.h"

StartSwitch::StartSwitch() {
    touchSensor = new TouchSensor(PORT_1);
}

int StartSwitch::pushButton() {
    int8_t result = 0;
    if (touchSensor->isPressed()){
        result = 1;
    }
	return result;
}
