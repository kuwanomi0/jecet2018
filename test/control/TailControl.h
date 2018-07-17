/**
 ******************************************************************************
 ** ファイル名 : TailControl.h
 ** クラス名   : TailControl
 **
 ** 概要 : 尻尾制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_TAIL_CONTROL_H
#define CONTROL_TAIL_CONTROL_H

#include "Motor.h"
#include "PID.h"

using namespace ev3api;

class TailControl
{
private:
    const int PWM_ABS_MAX = 60;
    // int 目標角;
    Motor* tailMotor;
    PID* tailPid;

public:
    TailControl();
    void init();
    void setControl(int angle);
    // void 設定する(int 目標角);
    // void 制御する();

};
#endif  // CONTROL_TAIL_CONTROL_H
