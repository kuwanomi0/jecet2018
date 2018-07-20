/**
 ******************************************************************************
 ** ファイル名 : RunningDistance.cpp
 ** クラス名   : RunningDistance
 **
 ** 概要 : 走行距離の計算を行うクラス
 ******************************************************************************
 **/
#include "RunningDistance.h"

RunningDistance::RunningDistance() {
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
}
//
// int RunningDistance::running_Distance() {
//     int result;
//     RunningDistance distance;
//     distance.CalcRunDistance;
//     result = distance.GetRunDistance;
//     return result;
// }
//

// int RunningDistance::getRunDistance() {
//     return all_run_distance;
// }

int RunningDistance::getRunDistance() {
    float leftDistance = 100.8 * PAI * leftMotor->getCount() / 360;
    float rightDistance = 100.8 * PAI * rightMotor->getCount() / 360;
    return (leftDistance + rightDistance) / 2;
}

//
// void RunningDistance::calcRunDistance(int left, int right)
// {
//     float leftdistance = 101.2 * PAI * left / 360;
//     float rightdistance = 101.2 * PAI * right / 360;
//     all_run_distance = (leftdistance + rightdistance) / 2;
// }
//
// void RunningDistance::startRunDuring(int left, int right)
// {
//     float leftdistance = 101.2 * PAI * left / 360;
//     float rightdistance = 101.2 * PAI * right / 360;
//     during_f = (leftdistance + rightdistance) / 2;
// }
// void RunningDistance::calcDuringDistance() {
//
// }
// int RunningDistance::getRunDuring()
// {
//     return during_f;
// }
