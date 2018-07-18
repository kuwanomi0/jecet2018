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
    int totalRGB = inspanel->getTotalRGB();
    cm->running(forward, turn, tailAngle, inspanel->getGyro(), (int)ev3_battery_voltage_mV(), totalRGB);
    if (totalRGB <= 7) {
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
