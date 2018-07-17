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
