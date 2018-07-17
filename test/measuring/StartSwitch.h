/**
 ******************************************************************************
 ** ファイル名 : StartSwitch.h
 ** クラス名   : StartSwitch
 **
 ** 概要 : タッチセンサーの確認をするクラス
 ******************************************************************************
 **/
#ifndef MEASURING_START_SWITCH_H
#define MEASURING_START_SWITCH_H

#include "TouchSensor.h"
// #include "ev3api/BluetoothTask.h"

using namespace ev3api;

class StartSwitch
{
private:
    TouchSensor* touchSensor;
    // ev3api::BluetoothTask bluetoothTask;

public:
    StartSwitch();
    // bool 値を取得();

};
#endif  // MEASURING_START_SWITCH_H
