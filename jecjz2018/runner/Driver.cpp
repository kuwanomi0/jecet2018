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
    clock = new Clock();
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
    beforeClock = clock->now();
}

/**
 * 走行
 */
void Driver::exec() {
    // TODO この処理は新たに作成するコースクラスで実装
    syslog(LOG_NOTICE, "TIME %d\r", clock->now() - beforeClock);
    if (courseChange()) {
        courseNumber++;
        runner->setStyle(mCourse[courseNumber].getStyle());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
        beforeClock = clock->now();
    }
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle(), mCourse[courseNumber].getKrgb());
}

/**
 * 区間変更条件確認
 * @param changeCnt 変更情報
 */
int Driver::courseChange() {
    int changeCnt = 0;
    if (mCourse[courseNumber].getDis() != 0) {
        if (runner->getDistance() >= mCourse[courseNumber].getDis()) {
            changeCnt = 1;
        }
    }

    if (mCourse[courseNumber].getTime() != 0) {
        if ((clock->now() - beforeClock) >= mCourse[courseNumber].getTime()) {
            changeCnt = 1;
        }
    }

    return changeCnt;
}

/**
 * BT更新
 */
void Driver::btUpdate() {
    runner->btUpdate();
}
