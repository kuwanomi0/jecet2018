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

void Runner::start() {
    cm->tailInit();
    while (1) {
        cm->running(0, 0, 94);
        if (inspanel->pushButton()) {
            break;
        }
    }
    inspanel->init();
    cm->wheelInit();
    cm->balancerInit();
}

void Runner::run() {
    int totalRGB = inspanel->getTotalRGB();
    cm->running(80, 0, 3, inspanel->getGyro(), (int)ev3_battery_voltage_mV(), totalRGB);
    if (totalRGB <= 7) {
        ev3_led_set_color(LED_RED);
        wup_tsk(MAIN_TASK);
        ev3_stp_cyc(CYC_HANDLER);
        cm->stop();
        inspanel->stop();
    }
}

void Runner::bt_task() {
    inspanel->bt_task();
}
