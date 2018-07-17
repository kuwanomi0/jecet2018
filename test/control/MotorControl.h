/**
 ******************************************************************************
 ** ファイル名 : MotorControl.h
 ** クラス名   : MotorControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_MOTOR_CONTROL_H
#define CONTROL_MOTOR_CONTROL_H

#include "Motor.h"
#include "PID.h"
using namespace ev3api;

class MotorControl
{
private:
    Motor* leftMotor;
    Motor* rightMotor;
    PID* motorPid;

public:
    MotorControl();
    void init();
    // void 走行する();

};
#endif  // CONTROL_MOTOR_CONTROL_H
