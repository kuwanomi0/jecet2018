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

/**
 * コンストラクタ
 */
Driver::Driver() {
    runner = new Runner();
}

/**
 * スタート待機
 */
void Driver::start() {
    runner->start(0, 0, 95);
    // TODO ここの処理は新たに作成するコースクラスで実装
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

/**
 * 走行
 */
void Driver::exec() {
    // TODO この処理は新たに作成するコースクラスで実装
    if (runner->getDistance() >= mCourse[courseNumber].getDis()) {
        courseNumber++;
        runner->setStyle(mCourse[courseNumber].getStyle());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
    }
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle(), mCourse[courseNumber].getKrgb());
}

/**
 * BT更新
 */
void Driver::btUpdate() {
    runner->btUpdate();
}
