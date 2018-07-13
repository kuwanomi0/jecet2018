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

#include "measuring/RunningDistance.h"
#include "measuring/Color.h"
#include "measuring/ImpactSensor.h"
#include "measuring/SonerDistance.h"
#include "measuring/RunningTime.h"

class InstrumentPanel
{
private:
    RunningDistance distance;
    Color color;
    ImpactSensor impact;
    SonerDistance sonar;
    RunningTime time;
    Color color;

public:


};
#endif  // MEASURING_INSTRUMENT_PANEL_H
