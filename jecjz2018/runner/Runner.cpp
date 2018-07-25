/**
 ******************************************************************************
 ** ファイル名 : Runner.cpp
 ** クラス名   : Runner
 **
 ** 概要 : 走行を管理するクラス
 ******************************************************************************
 **/
#include "Runner.h"

Runner::Runner() {
    cm = new ControlManager();
    inspanel = new InstrumentPanel();
}

void Runner::exec() {
}

void Runner::start(int forward, int turn, int tailAngle) {
    cm->tailInit();
    while (1) {
        if (inspanel->getSonarAlert() == 1) {
            ev3_led_set_color(LED_RED);
        }
        else {
            ev3_led_set_color(LED_GREEN);
        }
        cm->running(forward, turn, tailAngle);
        if (inspanel->pushButton()) {
            break;
        }
    }
    inspanel->init();
    cm->wheelInit();
    cm->balancerInit();
}

void Runner::run(int forward, int turn, int tailAngle) {
    inspanel->update();
    if ((inspanel->getSonarAlert() && sensen == 0) || sensen == 1) {
        sensen = 1;
        balanceOn = 0;
        forward = 40;
        tailAngle = 70;
        if (sensenC < 200/4) {
            setPID(0.0F,0.0F,0.0F);
            sensenC++;
        }
        else {
            setPID(0.0300F, 0.0000F, 0.3000F);
        }
        if (getDistance() > 700) {
            sensen = 2;
        }
    }

    if (sensen == 2) {
        sensen = 2;
        sensenC++;
        balanceOn = 0;
        forward = 0;
        tailAngle = 70;
                    setPID(0.0F,0.0F,0.0F);
        if (sensenC > 1500/4) {
            sensen = 3;
        }
    }

    if (sensen == 3) {
        sensen = 3;
        balanceOn = 0;
        forward = -20;
        turn = -1;
        tailAngle = 68;
        setPID(0.0F,0.0F,0.0F);
        if (getDistance() < 200) {
            sensen = 4;
        }
    }

    if (sensen == 4) {
        sensen = 4;
        balanceOn = 0;
        forward = 40;
        tailAngle = 70;
                    setPID(0.0300F, 0.0000F, 0.3000F);
    }

    int totalRGB = inspanel->getTotalRGB();
    if (balanceOn == 1) {
        cm->running(forward, turn, tailAngle, inspanel->getGyro(), (int)ev3_battery_voltage_mV(), totalRGB);
    }
    else {
        cm->noBalanceRun(forward, turn, tailAngle, totalRGB);
    }
    if (totalRGB <= 7 || inspanel->getBtCmd() == 6) {
        ev3_led_set_color(LED_RED);
        wup_tsk(MAIN_TASK);
        ev3_stp_cyc(CYC_HANDLER);
        cm->stop();
        inspanel->stop();
    }
}

void Runner::btTask() {
    inspanel->btTask();
}

void Runner::setPID(float kp, float ki, float kd) {
    cm->setPID(kp, ki, kd);
}

int Runner::getDistance() {
    return inspanel->getRunDistance();
}

void Runner::setBalanceOn(int balanceOn) {
    this->balanceOn = balanceOn;
}

int Runner::getBtCmd() {
    return inspanel->getBtCmd();
}
