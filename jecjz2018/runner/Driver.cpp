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
 * 関数名 : Driver
 * 引数   : なし
 * 概要   : コンストラクタ
 */
Driver::Driver() {
    runner = new Runner();
}

/**
 * 関数名 : start
 * 引数   : なし
 * 返り値 : なし
 * 概要   : スタート待機の指示を出す
 */
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

/**
 * 関数名 : exec
 * 引数   : なし
 * 返り値 : なし
 * 概要   : コースから値を取得し走行の指示を出す
 */
void Driver::exec() {
    if (runner->getDistance() >= mCourse[courseNumber].getDis()) {
        courseNumber++;
        runner->setStyle(mCourse[courseNumber].getStyle());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
    }
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle());
}

/**
 * 関数名 : btUpdate
 * 引数   : なし
 * 返り値 : なし
 * 概要   : Bluetoothからの情報を更新する
 */
void Driver::btUpdate() {
    runner->btUpdate();
}
