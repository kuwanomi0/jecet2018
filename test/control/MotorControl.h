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

#include "ev3api/Motor.h"
#include "control/PID.h"

class MotorControl
{
private:
    ev3api::Motor motor;
    PID pid;
    ev3api::Motor motor;
    ev3api::Motor motor;

public:
    void 走行する();

};
#endif  // CONTROL_MOTOR_CONTROL_H
