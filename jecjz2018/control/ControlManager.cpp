/**
 ******************************************************************************
 ** ファイル名 : ControlManager.cpp
 ** クラス名   : ControlManager
 **
 ** 概要 : 制御を管理するクラス
 ******************************************************************************
 **/
#include "ControlManager.h"

ControlManager::ControlManager() {
    balancer = new Balancer();
    mc = new MotorControl();
    tc = new TailControl();
    motorPid    = new PID(0.0F, 0.0F, 0.0F);
}

void ControlManager::tailInit() {
    tc->init();
}

void ControlManager::wheelInit() {
    mc->init();
}

void ControlManager::balancerInit() {
    balancer->init(2);
}

void ControlManager::running(int forward, int turn, int tailAngle) {
    tc->setControl(tailAngle);
}

void ControlManager::running(int forward, int turn, int tailAngle, int32_t gyro, int volt, int totalRGB) {
    turn = motorPid->calcControl(totalRGB - 365) + turn;
    // turn = 30;
    int32_t motor_ang_l = mc->getLMotorAngle();
    int32_t motor_ang_r = mc->getRMotorAngle();
    balancer->setCommand(forward, turn);
    balancer->update(gyro, motor_ang_r, motor_ang_l, volt);
    mc->setPWM(balancer->getPwmLeft(), balancer->getPwmRight());
    tc->setControl(tailAngle);
}

void ControlManager::stop() {
    mc->stop();
    tc->stop();
}

void ControlManager::setPID(float kp, float ki, float kd) {
    motorPid->setPID(kp, ki, kd);
}
