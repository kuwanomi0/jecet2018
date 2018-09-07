/**
 ******************************************************************************
 ** ファイル名 : MotorControl.cpp
 ** クラス名   : MotorControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#include "MotorControl.h"

/**
 * コンストラクタ
 */
MotorControl::MotorControl() {
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
}

/**
 * 初期化
 */
void MotorControl::init() {
    leftMotor->reset();
    rightMotor->reset();
}

/**
 * 左モーター回転角度所得
 * @return 左モーター回転角度
 */
int32_t MotorControl::getLMotorAngle() {
    return leftMotor->getCount();
}

/**
 * 右モーター回転角度所得
 * @return 右モーター回転角度
 */
int32_t MotorControl::getRMotorAngle() {
    return rightMotor->getCount();
}

/**
 * 走行
 * @param 左モーターPWM値
 * @param 右モーターPWM値
 */
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

/**
 * モーター完全停止
 */
void MotorControl::stop() {
    leftMotor->reset();
    rightMotor->reset();
}

/**
 * 尻尾走行
 * @param forward 前進
 * @param turn    旋回
 */
void MotorControl::setNoBalanceRun(int forward, int turn) {
    int pwmL = forward + turn;
    int pwmR = forward - turn;

    if (pwmL > 100) {
        pwmL = 100;
    }
    if (pwmR > 100) {
        pwmR = 100;
    }

    setPWM(pwmL, pwmR);
}
