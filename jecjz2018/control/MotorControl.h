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

using namespace ev3api;

class MotorControl
{
private:
    Motor* leftMotor;
    Motor* rightMotor;

public:
    MotorControl();
    void init();
    int32_t getLMotorAngle();
    int32_t getRMotorAngle();
    void setPWM(int8_t pwmL, int8_t pwmR);
    void stop();
    void setNoBalanceRunParameter(int forward, int turn);
    // void 走行する();

};
#endif  // CONTROL_MOTOR_CONTROL_H
