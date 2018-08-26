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
    static uint32_t gyroCounter = 0;
    int32_t alert = 0;
    int32_t impact;

    if (++gyroCounter == 4/4) {
        impact = gyroSensor->getAngle();
        if ((-30 >= impact) || (impact >= 30)) {
            alert = 1;
        }
        else {
            alert = 0;
        }
        gyroCounter = 0;
    }

    return alert;
}
