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
    sonarDistance = new SonarDistance();
}

int InstrumentPanel::pushButton() {
    if (sswitch->getBtCmd() == '\r') {
        color->update();
        syslog(LOG_NOTICE, "DIS %5d  GYRO %3d   R:%3d G:%3d B:%3d", runDistance->getRunDistance(), gp->getGyro(), color->getRed(), color->getGreen(), color->getBrue());
        sswitch->setBtCmd(0);
    }
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
    if (sswitch->getBtCmd() == '\r') {
        syslog(LOG_NOTICE, "DIS %5d  GYRO %3d   R:%3d G:%3d B:%3d", runDistance->getRunDistance(), gp->getGyro(), color->getRed(), color->getGreen(), color->getBrue());
        sswitch->setBtCmd(0);
    }
}

int InstrumentPanel::getRunDistance() {
    return runDistance->getRunDistance();
}


int InstrumentPanel::getBtCmd() {
    return sswitch->getBtCmd();
}

int32_t InstrumentPanel::getSonarAlert() {
    return sonarDistance->alert();
}
