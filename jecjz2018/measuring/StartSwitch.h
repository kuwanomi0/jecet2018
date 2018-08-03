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
#include "ev3api.h"

using namespace ev3api;

class StartSwitch
{
private:
    TouchSensor* touchSensor;
    FILE *bt = NULL;
    int mBtCmd = 0;

public:
    StartSwitch();
    int pushColorButton();
    int pushButton();
    void btTask();
    void btStop();
    int getBtCmd();
    void setBtCmd(int mBtCmd);

    // bool 値を取得();

};
#endif  // MEASURING_START_SWITCH_H
