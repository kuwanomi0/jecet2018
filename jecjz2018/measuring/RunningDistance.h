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
    Motor* leftMotor;
    Motor* rightMotor;
    const float PAI = 3.141592653589793F;
    int during_f;     //前回読んでからの距離
    int all_run_distance;
    int during_run_distance;

public:
    RunningDistance();
    int getRunDistance();                        // 走行距離を取得する
    // void calcRunDistance(int left, int right);              // 走行距離を計算する
    // int running_Distance();
    // void startRunDuring(int left, int right);               // 計測開始
    // void calcDuringDistance();                              // 計測距離を計算する
    // int getRunDuring();                                     // 計測距離を取得する

};
#endif  // MEASURING_RUNNING_DISTANCE_H
