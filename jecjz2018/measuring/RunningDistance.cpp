/**
 ******************************************************************************
 ** ファイル名 : RunningDistance.cpp
 ** クラス名   : RunningDistance
 **
 ** 概要 : 走行距離の計算を行うクラス
 ******************************************************************************
 **/
#include "RunningDistance.h"

/**
 * コンストラクタ
 */
RunningDistance::RunningDistance() {
    leftMotor   = new Motor(PORT_C);
    rightMotor  = new Motor(PORT_B);
}

/**
 * 走行距離計算
 * @return 走行距離
 * @comment モーターの回転数から走行距離を計算し値を返す
 */
int RunningDistance::getRunDistance() {
    float leftDistance = 100.8 * PAI * leftMotor->getCount() / 360;
    float rightDistance = 100.8 * PAI * rightMotor->getCount() / 360;
    return (leftDistance + rightDistance) / 2;
}
