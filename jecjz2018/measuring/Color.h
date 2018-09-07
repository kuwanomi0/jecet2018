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
    ColorSensor* colorSensor;
    rgb_raw_t mRgbLevel;       /* RGB構造体 */
    int mRgbTotal;             /* LPF処理後のRGB合計値 */
    int mRgbBefore;            /* LPF処理用メンバー */
    float KLPF = 0.6F;         /* LPF処理用係数 */

public:
    Color();
    int getRed();
    int getGreen();
    int getBrue();
    int getNaturalTotalRGB();
    int getTotalRGB();
    void update();

};
#endif  // MEASURING_COLOR_H
