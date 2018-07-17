/**
 ******************************************************************************
 ** ファイル名 : Color.h
 ** クラス名   : Color
 **
 ** 概要 : 色を測定するクラス
 ******************************************************************************
 **/
#ifndef MEASURING_COLOR_H
#define MEASURING_COLOR_H

#include "ColorSensor.h"

using namespace ev3api;

class Color
{
private:
    ColorSensor* colorSensor;
    // ev3api::rgb_raw_t 前のRGB値;
    // double kLPF;

public:
    Color();
    // ev3api::rgb_raw_t 値を取得する();
    // ev3api::rgb_raw_t LPF値を取得する();
    // boolean 灰色ですか();

};
#endif  // MEASURING_COLOR_H
