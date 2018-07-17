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

#include "ev3api/Motor.h"
#include "ev3api/int8_t.h"

class RunningDistance
{
private:
    int 計測開始距離;
    ev3api::Motor motor;

public:
    void 走行距離を計算する();
    ev3api::int8_t 走行距離を取得する();
    void 計測開始();
    int 計測距離を取得する();

};
#endif  // MEASURING_RUNNING_DISTANCE_H
