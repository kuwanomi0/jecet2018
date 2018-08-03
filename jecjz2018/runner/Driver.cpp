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
    if (runner->getBtCmd() == 1) {
        mCourse = lCourse;
    }
    else if (runner->getBtCmd() == 2) {
        mCourse = rCourse;
    }
    else {
        mCourse = dCourse;
    }
}

void Driver::exec() {
    if (runner->getDistance() >= mCourse[courseNumber].getDis()) {
        courseNumber++;
        runner->setBalanceOn(mCourse[courseNumber].getBalanceOn());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
    }
    // runner->setPID(0.0500F, 0.0000F, 1.2000F);
    // runner->run(90, 0, 5);
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle());
}

void Driver::btTask() {
    runner->btTask();
}
