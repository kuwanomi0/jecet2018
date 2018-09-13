/**
 ******************************************************************************
 ** ファイル名 : ImpactSensor.cpp
 ** クラス名   : ImpactSensor
 **
 ** 概要 : 衝撃検知の計算を行うクラス
 ******************************************************************************
 **/
#include "ImpactSensor.h"

ImpactSensor::ImpactSensor() {
    gyroSensor = new GyroSensor(PORT_4);
}

/**
 * 衝撃検知量状態取得
 * @return 衝撃検知状態
 */
int ImpactSensor::alert() {
    int32_t alert = 0;
    int32_t impact;

    impact = gyroSensor->getAnglerVelocity();
    if (impact < 0) {
        impact = impact * (-1);
    }
    if (impact >= 130) {
        alert = 1;
    }
    else {
        alert = 0;
    }

    return alert;
}

/**
 * 衝撃検知量取得
 * @return 衝撃検知量
 */
int ImpactSensor::getGyroImpact() {
    return 0;
}
