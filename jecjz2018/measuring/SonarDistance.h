/**
 ******************************************************************************
 ** ファイル名 : SonarDistance.h
 ** クラス名   : SonarDistance
 **
 ** 概要 : 障害物との距離を図るクラス
 ******************************************************************************
 **/
#ifndef MEASURING_SONAR_DISTANCE_H
#define MEASURING_SONAR_DISTANCE_H

#include "SonarSensor.h"

using namespace ev3api;

class SonarDistance
{
private:
    SonarSensor* sonarSensor;

public:
    SonarDistance();
    int32_t alert();

};
#endif  // MEASURING_SONAR_DISTANCE_H
