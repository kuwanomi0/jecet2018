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

int Color::getRed() {
    return mRgbLevel.r;
}
int Color::getGreen() {
    return mRgbLevel.g;
}
int Color::getBrue() {
    return mRgbLevel.b;
}

int Color::getTotalRGB() {
    return mRgbTotal;
}

void Color::update() {
    mRgbBefore = mRgbTotal;
    colorSensor->getRawColor(mRgbLevel);
    mRgbTotal = (mRgbLevel.r + mRgbLevel.g + mRgbLevel.b) * KLPF + mRgbBefore * (1 - KLPF);
}
