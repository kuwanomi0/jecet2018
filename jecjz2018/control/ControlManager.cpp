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
    gyroSensor = new GyroSensor(PORT_4);
    balancer = new Balancer();
    mc = new MotorControl();
    tc = new TailControl();
    motorPid = new PID(0.0500F, 0.0000F, 1.2000F);
}

void ControlManager::gyroInit() {
    gyroSensor->reset();
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

void ControlManager::running(int forward, int turn, int tailAngle, int totalRgb) {
    turn = motorPid->calcControl(totalRgb - targetRgb) + turn;
    balancer->setCommand(forward, turn);
    balancer->update(gyroSensor->getAnglerVelocity(), mc->getRMotorAngle(), mc->getLMotorAngle(), (int)ev3_battery_voltage_mV());
    mc->setPWM(balancer->getPwmLeft(), balancer->getPwmRight());
    tc->setControl(tailAngle);
}

void ControlManager::noBalanceRun(int forward, int turn, int tailAngle, int totalRgb) {
    float KRGB = getKRGB(tailAngle);
    turn = motorPid->calcControl(totalRgb - (targetRgb * KRGB)) + turn;
    balancer->setCommand(forward, turn);
    balancer->update(gyroSensor->getAnglerVelocity(), mc->getRMotorAngle(), mc->getLMotorAngle(), (int)ev3_battery_voltage_mV());
    if (forward >= 0) {
        mc->setNoBalanceRun(forward, turn);
    }
    else {
        mc->setNoBalanceRun(forward, -turn);
    }
    tc->setControl(tailAngle);
}

void ControlManager::stop() {
    mc->stop();
    tc->stop();
}

void ControlManager::setPID(float kp, float ki, float kd) {
    motorPid->setPID(kp, ki, kd);
}

void ControlManager::setTargetRgb(int targetRgb) {
    this->targetRgb = targetRgb;
}

float ControlManager::getKRGB(int tailAngle) {
    float diff = 95.0F - (float)tailAngle;
    if (diff < 0.0F) {
        diff = 0.0F;
    }
    return (102.0F + ((-3.8F) * diff) + (0.038F * diff * diff)) / 100.0F;
}
