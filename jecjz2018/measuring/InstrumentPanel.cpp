/**
 ******************************************************************************
 ** ファイル名 : InstrumentPanel.cpp
 ** クラス名   : InstrumentPanel
 **
 ** 概要 : 走行情報を所持するクラス
 ******************************************************************************
 **/
#include "InstrumentPanel.h"

InstrumentPanel::InstrumentPanel() {
    gp = new GyroPanel();
    color = new Color();
    sswitch = new StartSwitch();
    runDistance = new RunningDistance();
}

int InstrumentPanel::pushButton() {
    return sswitch->pushButton();
}

void InstrumentPanel::init() {
    gp->init();
}

int32_t InstrumentPanel::getGyro() {
    return gp->getGyro();
}

int InstrumentPanel::getTotalRGB() {
    return color->getTotalRGB();
}

void InstrumentPanel::btTask() {
    sswitch->btTask();
}

void InstrumentPanel::stop() {
    sswitch->btStop();
}

void InstrumentPanel::update() {
    color->update();
}

int InstrumentPanel::getRunDistance() {
    return runDistance->getRunDistance();
}
