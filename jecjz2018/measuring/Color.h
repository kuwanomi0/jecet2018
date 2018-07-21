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

#include "ev3api.h"
#include "ColorSensor.h"

using namespace ev3api;

class Color
{
private:
    rgb_raw_t mRgbLevel;
    int mRgbTotal = 365;
    int mRgbBefore;
    float KLPF = 0.6F;
    ColorSensor* colorSensor;

public:
    Color();
    int getRed();
    int getGreen();
    int getBrue();
    int getTotalRGB();
    void update();
    // ev3api::rgb_raw_t 値を取得する();
    // ev3api::rgb_raw_t LPF値を取得する();
    // boolean 灰色ですか();

};
#endif  // MEASURING_COLOR_H
