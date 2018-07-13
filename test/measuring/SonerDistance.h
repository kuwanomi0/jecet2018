/**
 ******************************************************************************
 ** ファイル名 : SonerDistance.h
 ** クラス名   : SonerDistance
 **
 ** 概要 : PID制御の計算を行うクラス
 ******************************************************************************
 **/
#ifndef MEASURING_SONER_DISTANCE_H
#define MEASURING_SONER_DISTANCE_H

#include "ev3api/SonarSensor.h"
#include "ev3api/int8_t.h"

class SonerDistance
{
private:
    ev3api::SonarSensor sonarSensor;

public:
    ev3api::int8_t 距離を測る();

};
#endif  // MEASURING_SONER_DISTANCE_H
