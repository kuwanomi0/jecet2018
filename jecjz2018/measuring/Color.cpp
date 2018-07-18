/**
 ******************************************************************************
 ** ファイル名 : Color.cpp
 ** クラス名   : Color
 **
 ** 概要 : 色を測定するクラス
 ******************************************************************************
 **/
#include "Color.h"

Color::Color() {
    colorSensor = new ColorSensor(PORT_3);
}

int Color::getTotalRGB() {
    return rgb_total;
}

void Color::update() {
    rgb_before = rgb_total;
    colorSensor->getRawColor(rgb_level);
    rgb_total = (rgb_level.r + rgb_level.g + rgb_level.b) * KLPF + rgb_before * (1 - KLPF);
}
