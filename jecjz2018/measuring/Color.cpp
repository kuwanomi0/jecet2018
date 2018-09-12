/**
 ******************************************************************************
 ** ファイル名 : Color.cpp
 ** クラス名   : Color
 **
 ** 概要 : 色を測定するクラス
 ******************************************************************************
 **/
#include "Color.h"

/**
 * コンストラクタ
 */
Color::Color() {
    colorSensor = new ColorSensor(PORT_3);
}

/* ゲッター */
int Color::getRed() {
    return mRgbLevel.r;
}
int Color::getGreen() {
    return mRgbLevel.g;
}
int Color::getBrue() {
    return mRgbLevel.b;
}
int Color::getNaturalTotalRGB() {
    return (mRgbLevel.r + mRgbLevel.g + mRgbLevel.b);
}
int Color::getTotalRGB() {
    return mRgbTotal;
}

/**
 * 更新
 * @comment LPF計算もここで行っている
 */
void Color::update() {
    mRgbBefore = mRgbTotal;
    colorSensor->getRawColor(mRgbLevel);
    mRgbTotal = getNaturalTotalRGB() * KLPF + mRgbBefore * (1 - KLPF);
}
