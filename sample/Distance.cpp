/**
 ******************************************************************************
 ** ファイル名 : Distance.cpp
 ** クラス名   : Distance
 **
 ** 概要 : 移動距離を測るクラス
 ******************************************************************************
 **/
#include "Distance.h"

int Distance::distanceAll(int left, int right) {
    float leftdistance = 101.2 * PAI * left / 360;
    float rightdistance = 101.2 * PAI * right / 360;
    int result = (leftdistance + rightdistance) / 2;

    return result;
}
