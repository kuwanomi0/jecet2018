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

#include "ev3api/GyroSensor.h"

class ImpactSensor
{
private:
    ev3api::GyroSensor gyroSensor;

public:
    int 衝撃を検知する();
    void LPF値を取得する();

};
#endif  // MEASURING_IMPACT_SENSOR_H
