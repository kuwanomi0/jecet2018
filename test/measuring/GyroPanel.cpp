/**
 ******************************************************************************
 ** ファイル名 : GyroPanel.cpp
 ** クラス名   : GyroPanel
 **
 ** 概要 : ジャイロ管理クラス
 ******************************************************************************
 **/
#include "GyroPanel.h"

GyroPanel::GyroPanel() {
    gyroSensor  = new GyroSensor(PORT_4);
}

void GyroPanel::init() {
    gyroSensor->reset();
}

int32_t GyroPanel::getGyro() {
    return gyroSensor->getAnglerVelocity();
}
