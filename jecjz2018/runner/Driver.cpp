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
    if (runner->getDistance() >= course[courseNumber].getDis()) {
        courseNumber++;
    }
    runner->setPID(course[courseNumber].getP(), course[courseNumber].getI(), course[courseNumber].getD());
    runner->run(course[courseNumber].getForward(), course[courseNumber].getTurn(), course[courseNumber].getTailAngle());
}

void Driver::btTask() {
    runner->btTask();
}
