/**
 ******************************************************************************
 ** ファイル名 : TailControl.cpp
 ** クラス名   : TailControl
 **
 ** 概要 : 尻尾制御を行うクラス
 ******************************************************************************
 **/
#include "TailControl.h"
#include "Clock.h"

/**
 * コンストラクタ
 */
TailControl::TailControl() {
    tailMotor = new Motor(PORT_A);
    tailPid = new PID(2.7F, 0.02F, 14.0F);
}

/**
 * 初期化
 */
void TailControl::init() {
    Clock clock;
    for (int i = 0; i < 500; i++) {
        tailMotor->setPWM(-3);
        clock.wait(1);
    }
    tailMotor->reset();
}

/**
 * 制御
 * @param angle 尻尾角度
 */
void TailControl::setControl(int angle) {
    int pwm = (int)tailPid->calcControl(angle - tailMotor->getCount() - 0.5);
    /* PWM出力飽和処理 */
    if (pwm > PWM_ABS_MAX) {
        pwm = PWM_ABS_MAX;
    }
    else if (pwm < -PWM_ABS_MAX) {
        pwm = -PWM_ABS_MAX;
    }

    tailMotor->setPWM(pwm);
}

/**
 * 尻尾モーター停止
 */
void TailControl::stop() {
    tailMotor->reset();
}
