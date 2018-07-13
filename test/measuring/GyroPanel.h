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

#include "ev3api/GyroSensor.h"

class GyroPanel
{
private:
    ev3api::GyroSensor gyroSensor;

public:
    void getGyro();

};
#endif  // MEASURING_GYRO_PANEL_H
