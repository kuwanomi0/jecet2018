/**
 ******************************************************************************
 ** ファイル名 : GyroPanel.h
 ** クラス名   : GyroPanel
 **
 ** 概要 : ジャイロ管理クラス
 ******************************************************************************
 **/
#ifndef MEASURING_GYRO_PANEL_H
#define MEASURING_GYRO_PANEL_H

#include "GyroSensor.h"

using namespace ev3api;

class GyroPanel
{
private:
    GyroSensor* gyroSensor;

public:
    GyroPanel();
    void init();
    int32_t getGyro();
    // void getGyro();

};
#endif  // MEASURING_GYRO_PANEL_H
