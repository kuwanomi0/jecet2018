/**
 ******************************************************************************
 ** ファイル名 : RunningDistance.h
 ** クラス名   : RunningDistance
 **
 ** 概要 : 走行距離の計算を行うクラス
 ******************************************************************************
 **/
#ifndef MEASURING_RUNNING_DISTANCE_H
#define MEASURING_RUNNING_DISTANCE_H

#include "Motor.h"

using namespace ev3api;

class RunningDistance
{
private:
    const float PAI = 3.141592653589793F;
    Motor* leftMotor;
    Motor* rightMotor;

public:
    RunningDistance();
    int getRunDistance();

};
#endif  // MEASURING_RUNNING_DISTANCE_H
