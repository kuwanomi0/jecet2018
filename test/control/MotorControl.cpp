/**
 ******************************************************************************
 ** ファイル名 : MotorControl.cpp
 ** クラス名   : MotorControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#include "MotorControl.h"

MotorControl::MotorControl() {
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
    motorPid    = new PID(0.05F, 0.0F, 1.2F);
}
