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
    runner->start(0, 0, 94);
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
    beforeDistance = runner->getDistance();
    beforeClock = clock->now();
}

/**
 * 走行
 */
void Driver::exec() {
    // TODO この処理は新たに作成するコースクラスで実装
    if (courseChange()) {
        courseNumber++;
        ev3_speaker_play_tone(NOTE_C4, 100);
        runner->setGyroOffset(mCourse[courseNumber].getGyroOffset());
        runner->setStyle(mCourse[courseNumber].getStyle());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
        beforeDistance = runner->getDistance();
        beforeClock = clock->now();
    }
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle(), mCourse[courseNumber].getKrgb());
    if ((mCourse[courseNumber].getDis() + mCourse[courseNumber].getTime() + mCourse[courseNumber].getImpact() + mCourse[courseNumber].getSonarDis()) == 0) {
        runner->stop();
    }
}

/**
 * 区間変更条件確認
 * @param changeCnt 変更情報
 */
int Driver::courseChange() {
    int changeCnt = 0;
    if (mCourse[courseNumber].getDis() != 0) {
        int tmpDis = runner->getDistance() - beforeDistance;
        if (tmpDis < 0) {
            tmpDis = tmpDis * (-1);
        }
        if (tmpDis >= mCourse[courseNumber].getDis()) {
            changeCnt = 1;
        }
    }

    if (mCourse[courseNumber].getTime() != 0) {
        if ((int)(clock->now() - beforeClock) >= mCourse[courseNumber].getTime()) {
            changeCnt = 1;
        }
    }

    if (mCourse[courseNumber].getImpact() != 0) {
        int tmpImacpt = runner->getGyroImpact();
        if (tmpImacpt < 0) {
            tmpImacpt = tmpImacpt * (-1);
        }
        if (tmpImacpt >= mCourse[courseNumber].getImpact()) {
            changeCnt = 1;
        }
    }

    if (mCourse[courseNumber].getSonarDis() != 0) {
        if (runner->getSonarDis() <= mCourse[courseNumber].getSonarDis()) {
            changeCnt = 1;
        }
    }
    // syslog(LOG_NOTICE, "DIS: %5d   TIME: %5d   G: %3d   S: %3d\r", (runner->getDistance() - beforeDistance), (int)(clock->now() - beforeClock), runner->getGyroImpact(), runner->getSonarDis());
    // syslog(LOG_NOTICE, "DIS: %5d   TIME: %5d   G: %3d   S: %3d\r", (runner->getDistance() - beforeDistance), (int)(clock->now() - beforeClock), runner->getGyroImpact(), runner->getSonarDis());

    return changeCnt;
}

/**
 * BT更新
 */
void Driver::btUpdate() {
    runner->btUpdate();
}
