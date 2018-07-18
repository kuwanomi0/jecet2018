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
}

void MotorControl::init() {
    leftMotor->reset();
    rightMotor->reset();
}

int32_t MotorControl::getLMotorAngle() {
    return leftMotor->getCount();
}

int32_t MotorControl::getRMotorAngle() {
    return rightMotor->getCount();
}

void MotorControl::setPWM(int8_t pwmL, int8_t pwmR) {
    if (pwmL == 0) {
         leftMotor->stop();
    }
    else {
        leftMotor->setPWM(pwmL);
    }

    if (pwmR == 0) {
         rightMotor->stop();
    }
    else {
        rightMotor->setPWM(pwmR);
    }
}

void MotorControl::stop() {
    leftMotor->reset();
    rightMotor->reset();
}
