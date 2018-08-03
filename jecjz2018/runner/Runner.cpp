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
        cm->setTargetRgb(inspanel->pushColorButton());
    }
    inspanel->init();
    cm->wheelInit();
    cm->balancerInit();
}

void Runner::run(int forward, int turn, int tailAngle) {
    inspanel->update();

    lookupRun(&forward, &turn, &tailAngle);

    int totalRGB = inspanel->getTotalRGB();
    if (balanceOn == 1) {
        cm->running(forward, turn, tailAngle, inspanel->getGyro(), (int)ev3_battery_voltage_mV(), totalRGB);
    }
    else {
        cm->noBalanceRun(forward, turn, tailAngle, inspanel->getGyro(), (int)ev3_battery_voltage_mV(), totalRGB);
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

void Runner::lookupRun(int* forward, int* turn, int* tailAngle) {
    if (lookupLine == 0) {
        distanceTmp = getDistance();
    }

    if ((inspanel->getSonarAlert() && lookupLine == 0) || lookupLine == 1) {
        lookupLine = 1;
        balanceOn = 0;
        *tailAngle = 65;
        if (lookupLineC < 100/4) {
            *forward = 30;
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else if (lookupLineC < 700/4) {
            *forward = 0;
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else {
            *forward = 20;
            setPID(0.0F,0.0F,0.0F);
            // setPID(0.0100F, 0.0002F, 0.1000F);
        }
        if (getDistance() - distanceTmp > 400) {
            lookupLine = 2;
        }
    }

    if (lookupLine == 2) {
        lookupLine = 2;
        lookupLineC++;
        balanceOn = 0;
        *forward = 0;
        *tailAngle = 65;
        setPID(0.0F,0.0F,0.0F);
        if (lookupLineC > 1500/4) {
            lookupLine = 3;
        }
    }

    if (lookupLine == 3) {
        lookupLine = 3;
        balanceOn = 0;
        *forward = -30;
        *turn = 0;
        *tailAngle = 65;
        if (lookupLineC < 1800/4) {
            setPID(0.0F,0.0F,0.0F);
            lookupLineC++;
        }
        else {
            setPID(0.0100F, 0.0000F, 0.0000F);
        }
        if (getDistance() - distanceTmp < -50) {
            lookupLine = 44;
        }
    }

    if (lookupLine == 44) {
        lookupLine = 44;
        lookupLineC++;
        balanceOn = 0;
        *forward = 0;
        *tailAngle = 65;
        setPID(0.0F,0.0F,0.0F);
        if (lookupLineC > 3000/4) {
            lookupLine = 4;
        }
    }

    if (lookupLine == 4) {
        lookupLine = 4;
        balanceOn = 0;
        *forward = 15;
        *tailAngle = 65;
        setPID(0.0500F, 0.0002F, 0.3000F);
        if (getDistance() - distanceTmp > 440) {
            lookupLine = 5;
        }
    }
    if (lookupLine == 5) {
        lookupLine = 5;
        balanceOn = 0;
        *forward = 15;
        *tailAngle = 65;
        setPID(0.0000F, 0.0000F, 0.0000F);
        if (getDistance() - distanceTmp > 935) {
            lookupLine = 6;
        }
    }
    if (lookupLine == 6) {
        lookupLine = 6;
        lookupLineC++;
        balanceOn = 0;
        *forward = 0;
        *tailAngle = 75;
        setPID(0.0000F, 0.0000F, 0.0000F);
    }

    if (lookupLine == 6) {
        lookupLine = 6;
        balanceOn = 0;
        *forward = -10;
        *tailAngle = 82;
        setPID(0.0000F, 0.0000F, 0.0000F);
        if (lookupLineC > 3200/4) {
            inspanel->setBtCmd(6);
        }
    }
}
