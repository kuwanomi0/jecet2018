/**
 ******************************************************************************
 ** ファイル名 : ImpactSensor.h
 ** クラス名   : ImpactSensor
 **
 ** 概要 : 衝撃検知の計算を行うクラス
 ******************************************************************************
 **/
#ifndef MEASURING_IMPACT_SENSOR_H
#define MEASURING_IMPACT_SENSOR_H

#include "GyroSensor.h"

using namespace ev3api;

class ImpactSensor
{
private:
    GyroSensor* gyroSensor;

public:
    ImpactSensor();
    int alert();
    int getGyroImpact();

};
#endif  // MEASURING_IMPACT_SENSOR_H
