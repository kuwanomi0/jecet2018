/**
 ******************************************************************************
 ** ファイル名 : InstrumentPanel.cpp
 ** クラス名   : InstrumentPanel
 **
 ** 概要 : 走行情報を所持するクラス
 ******************************************************************************
 **/
#include "InstrumentPanel.h"

/**
 * コンストラクタ
 */
InstrumentPanel::InstrumentPanel() {
    color = new Color();
    sswitch = new StartSwitch();
    runDistance = new RunningDistance();
    sonarDistance = new SonarDistance();
    impactSensor = new ImpactSensor();
}

/**
 * 色所得
 * @return target 目標RGB値
 * @comment RGB目標値に必要な白、黒の値を取得する
 */
int InstrumentPanel::pushColorButton() {
    int target;
    if (sswitch->pushColorButton() == 1) {
        color->update();
        white = color->getNaturalTotalRGB();
    }
    if (sswitch->pushColorButton() == 2) {
        color->update();
        black = color->getNaturalTotalRGB();
    }

    target = (white + black) / 2;

    if (sswitch->pushColorButton() != 0) {
        syslog(LOG_NOTICE, "color: %3d   B: %3d   W: %3d\r", target, black, white);
        sswitch->setBtCmd(0);
    }

    return target;
}

/**
 * 尻尾角度指示取得
 * @return target 尻尾角度調整値
 * @comment スタート待機時に尻尾角度調整値を渡す
 */
int InstrumentPanel::pushTailButton() {
    int target = 0;
    if (sswitch->pushTailButton() == 1) {
        target = 1;
    }
    if (sswitch->pushTailButton() == 2) {
        target = -1;
    }

    if (target != 0) {
        sswitch->setBtCmd(0);
    }

    return target;
}

/**
 * スタート指示取得
 * @return スタート指示
 * @comment スタート命令を取得する
 */
int InstrumentPanel::pushButton() {
    if (sswitch->getBtCmd() == '\r') {
        color->update();
        syslog(LOG_NOTICE, "DIS %5d  R:%3d G:%3d B:%3d RGB:%3d\r", runDistance->getRunDistance(), color->getRed(), color->getGreen(), color->getBrue(), color->getTotalRGB());
        sswitch->setBtCmd(0);
    }
    return sswitch->pushButton();
}

/**
 * RGB値取得
 * @return RGB値
 */
int InstrumentPanel::getTotalRGB() {
    return color->getTotalRGB();
}

/**
 * BT更新
 */
void InstrumentPanel::btUpdate() {
    sswitch->btUpdate();
}

/**
 * BT停止
 */
void InstrumentPanel::stop() {
    sswitch->btStop();
}

/**
 * 走行情報更新
 */
void InstrumentPanel::update() {
    color->update();
    if (sswitch->getBtCmd() == '\r') {
        // syslog(LOG_NOTICE, "DIS %5d  R:%3d G:%3d B:%3d", runDistance->getRunDistance(), color->getRed(), color->getGreen(), color->getBrue());
        syslog(LOG_NOTICE, "DIS %5d RGB:%3d\r", runDistance->getRunDistance(), color->getTotalRGB());
        sswitch->setBtCmd(0);
    }
}

/**
 * 走行距離取得
 * @return 走行距離
 */
int InstrumentPanel::getRunDistance() {
    return runDistance->getRunDistance();
}

/**
 * BtCmd取得
 * @return BtCmd
 */
int InstrumentPanel::getBtCmd() {
    return sswitch->getBtCmd();
}

/**
 * BtCmd設定
 * @param Btcmd
 * @comment BTにBtCmd値を設定する
 *          主な用途は0を指定してリセットを行い、誤作動を防止させること
 */
void InstrumentPanel::setBtCmd(int btCmd) {
    sswitch->setBtCmd(btCmd);
}


/**
 * 障害物検知状態取得
 * @return 障害物検知状態
 */
int InstrumentPanel::getSonarAlert() {
    return sonarDistance->alert();
}

/**
 * 衝撃検知状態取得
 * @return 衝撃検知状態
 */
int InstrumentPanel::getImpactAlert() {
    return impactSensor->alert();
}

/**
 * 衝撃検知量取得
 * @return 衝撃検知量
 */
int InstrumentPanel::getGyroImpact() {
    return impactSensor->getGyroImpact();
}

/**
 * 障害物検知距離取得
 * @param 障害物検知距離
 */
int InstrumentPanel::getSonarDis() {
    return sonarDistance->getSonarDis();
}
