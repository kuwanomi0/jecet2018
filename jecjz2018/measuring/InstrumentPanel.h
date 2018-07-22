/**
 ******************************************************************************
 ** ファイル名 : InstrumentPanel.h
 ** クラス名   : InstrumentPanel
 **
 ** 概要 : 走行情報を所持するクラス
 ******************************************************************************
 **/
#ifndef MEASURING_INSTRUMENT_PANEL_H
#define MEASURING_INSTRUMENT_PANEL_H

#include "GyroPanel.h"
#include "Color.h"
#include "StartSwitch.h"
#include "RunningDistance.h"
#include "SonarDistance.h"
// #include "measuring/RunningDistance.h"
// #include "measuring/ImpactSensor.h"
// #include "measuring/RunningTime.h"

class InstrumentPanel
{
private:
    GyroPanel* gp;
    Color* color;
    StartSwitch* sswitch;
    RunningDistance* runDistance;
    SonarDistance* sonarDistance;
    // Color color;
    // ImpactSensor impact;
    // RunningTime time;
    // Color color;

public:
    InstrumentPanel();
    int pushButton();
    void init();
    int32_t getGyro();
    int getTotalRGB();
    void btTask();
    void stop();
    void update();
    int getRunDistance();
    int getBtCmd();
    int32_t getSonarAlert();
};
#endif  // MEASURING_INSTRUMENT_PANEL_H
