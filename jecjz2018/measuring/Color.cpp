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
	colorSensor->getRawColor(rgb_level);
	return rgb_level.r + rgb_level.g + rgb_level.b;
}
