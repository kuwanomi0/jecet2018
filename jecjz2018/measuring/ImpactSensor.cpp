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
