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
    color = new Color();
    sswitch = new StartSwitch();
    runDistance = new RunningDistance();
    sonarDistance = new SonarDistance();
}

int InstrumentPanel::pushColorButton() {
    int target;
    if (sswitch->pushColorButton() == 1) {
        color->update();
        white = color->getTotalRGB();
    }
    if (sswitch->pushColorButton() == 2) {
        color->update();
        black = color->getTotalRGB();
    }

    target = (white + black) / 2;

    if (sswitch->pushColorButton() != 0) {
        syslog(LOG_NOTICE, "color: %3d   B: %3d   W: %3d\r", target, black, white);
        sswitch->setBtCmd(0);
    }

    return target;
}

int InstrumentPanel::pushTailButton() {
    int target = 0;
    if (sswitch->pushTailButton() == 1) {
        target = 1;
    }
    if (sswitch->pushTailButton() == 2) {
        target = -1;
    }

    if (target != 0) {
        sswitch->setBtCmd(0);
    }

    return target;
}

int InstrumentPanel::pushButton() {
    if (sswitch->getBtCmd() == '\r') {
        color->update();
        syslog(LOG_NOTICE, "DIS %5d  R:%3d G:%3d B:%3d\r", runDistance->getRunDistance(), color->getRed(), color->getGreen(), color->getBrue(), getSonarAlert());
        sswitch->setBtCmd(0);
    }
    return sswitch->pushButton();
}

int InstrumentPanel::getTotalRGB() {
    return color->getTotalRGB();
}

void InstrumentPanel::btUpdate() {
    sswitch->btUpdate();
}

void InstrumentPanel::stop() {
    sswitch->btStop();
}

void InstrumentPanel::update() {
    color->update();
    if (sswitch->getBtCmd() == '\r') {
        syslog(LOG_NOTICE, "DIS %5d  R:%3d G:%3d B:%3d", runDistance->getRunDistance(), color->getRed(), color->getGreen(), color->getBrue());
        sswitch->setBtCmd(0);
    }
}

int InstrumentPanel::getRunDistance() {
    return runDistance->getRunDistance();
}


int InstrumentPanel::getBtCmd() {
    return sswitch->getBtCmd();
}

void InstrumentPanel::setBtCmd(int btCmd) {
    sswitch->setBtCmd(btCmd);
}

int InstrumentPanel::getSonarAlert() {
    return sonarDistance->alert();
}
