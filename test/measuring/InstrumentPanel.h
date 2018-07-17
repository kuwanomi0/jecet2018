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
// #include "measuring/RunningDistance.h"
// #include "measuring/ImpactSensor.h"
// #include "measuring/SonerDistance.h"
// #include "measuring/RunningTime.h"

class InstrumentPanel
{
private:
    GyroPanel* gp;
    Color* color;
    StartSwitch* sswitch;
    // RunningDistance distance;
    // Color color;
    // ImpactSensor impact;
    // SonerDistance sonar;
    // RunningTime time;
    // Color color;

public:
    InstrumentPanel();

};
#endif  // MEASURING_INSTRUMENT_PANEL_H
