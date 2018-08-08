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

#include "Color.h"
#include "StartSwitch.h"
#include "RunningDistance.h"
#include "SonarDistance.h"

class InstrumentPanel
{
private:
    Color* color;
    StartSwitch* sswitch;
    RunningDistance* runDistance;
    SonarDistance* sonarDistance;
    int white;
    int black;

public:
    InstrumentPanel();
    int pushColorButton();
    int pushTailButton();
    int pushButton();
    int getTotalRGB();
    void btUpdate();
    void stop();
    void update();
    int getRunDistance();
    int getBtCmd();
    int getSonarAlert();
    void setBtCmd(int mBtCmd);
};
#endif  // MEASURING_INSTRUMENT_PANEL_H
