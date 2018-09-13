/**
 ******************************************************************************
 ** ファイル名 : ControlManager.cpp
 ** クラス名   : ControlManager
 **
 ** 概要 : 制御を管理するクラス
 ******************************************************************************
 **/
#include "ControlManager.h"

/**
 * コンストラクタ
 */
ControlManager::ControlManager() {
    gyroSensor = new GyroSensor(PORT_4);
    balancer = new Balancer();
    mc = new MotorControl();
    tc = new TailControl();
    motorPid = new PID(0.0500F, 0.0000F, 1.2000F);
}

/**
 * ジャイロセンサー初期化
 */
void ControlManager::gyroInit() {
    gyroSensor->reset();
}

/**
 * 尻尾モーター初期化
 */
void ControlManager::tailInit() {
    tc->init();
}

/**
 * タイヤモーター初期化初期化
 */
void ControlManager::wheelInit() {
    mc->init();
}

/**
 * バランサー初期化
 */
void ControlManager::balancerInit() {
    balancer->init(0);
}

/**
 * スタート待機
 * @param forward   前進
 * @param turn      旋回
 * @param tailAngle 尻尾角度
 */
void ControlManager::running(int forward, int turn, int tailAngle) {
    tc->setControl(tailAngle);
}

/**
 * バランス走行
 * @param forward   前進
 * @param turn      旋回
 * @param tailAngle 尻尾角度
 * @param totalRgb  目標RGB値
 */
void ControlManager::running(int forward, int turn, int tailAngle, int totalRgb) {
    turn = motorPid->calcControl(totalRgb - targetRgb) + turn;
    balancer->setCommand(forward, turn);
    balancer->update(gyroSensor->getAnglerVelocity(), mc->getRMotorAngle(), mc->getLMotorAngle(), (int)ev3_battery_voltage_mV());
    mc->setPWM(balancer->getPwmLeft(), balancer->getPwmRight());
    tc->setControl(tailAngle);
}

/**
 * 尻尾走行
 * @param forward   前進
 * @param turn      旋回
 * @param tailAngle 尻尾角度
 * @param totalRgb  RGB値
 */
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

/**
 * 停止処理
 */
void ControlManager::stop() {
    mc->stop();
    tc->stop();
}

/**
 * PID定数設定
 * @param kp 係数P
 * @param ki 係数I
 * @param kd 係数D
 */
void ControlManager::setPID(float kp, float ki, float kd) {
    motorPid->setPID(kp, ki, kd);
}

/**
 * 目標RGB値設定
 * @param targetRgb 目標RGB値
 */
void ControlManager::setTargetRgb(int targetRgb) {
    this->targetRgb = targetRgb;
}

/**
 * ジャイロオフセット設定
 * @param gyroOffset ジャイロオフセット
 */
void ControlManager::setGyroOffset(int gyroOffset) {
    balancer->setGyroOffset(gyroOffset);
}

/**
 * 走行体傾き時のRGB値比率
 * @param tailAngle 尻尾角度
 * @return 目標RGB値比率
 * @comment 走行体の傾きは尻尾の角度を元にしている
 */
float ControlManager::getKRGB(int tailAngle) {
    float diff = 95.0F - (float)tailAngle;
    if (diff < 0.0F) {
        diff = 0.0F;
    }
    return (102.0F + ((-3.8F) * diff) + (0.038F * diff * diff)) / 100.0F;
}
