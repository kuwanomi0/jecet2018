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

void MotorControl::setPWM(int8_t pwm_L, int8_t pwm_R) {
    if (pwm_L == 0) {
         leftMotor->stop();
    }
    else {
        leftMotor->setPWM(pwm_L);
    }

    if (pwm_R == 0) {
         rightMotor->stop();
    }
    else {
        rightMotor->setPWM(pwm_R);
    }
}

void MotorControl::stop() {
    leftMotor->reset();
    rightMotor->reset();
}
