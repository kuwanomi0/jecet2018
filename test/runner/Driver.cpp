/**
 ******************************************************************************
 ** ファイル名 : Driver.cpp
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#include "Driver.h"

#include "ev3api.h"

Driver::Driver() {
    runner = new Runner();
}

void Driver::start() {
    runner->start(0, 0, 95);
}

void Driver::exec() {
    int forward = 80;
    int turn = 0;
    int tail = 5;



    runner->run(forward, turn, tail);
}

void Driver::bt_task() {
    runner->bt_task();
}
