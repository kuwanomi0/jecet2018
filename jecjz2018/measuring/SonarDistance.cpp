/**
 ******************************************************************************
 ** ファイル名 : SonarDistance.cpp
 ** クラス名   : SonarDistance
 **
 ** 概要 : 障害物との距離を図るクラス
 ******************************************************************************
 **/
#include "SonarDistance.h"
/**
 * コンストラクタ
 */
SonarDistance::SonarDistance() {
    sonarSensor = new SonarSensor(PORT_2);
}

/**
 * 障害物検知状態取得
 * @param 障害物検知状態
 */
int SonarDistance::alert() {
    static uint32_t counter = 0;
    int32_t alert = 0;
    int32_t distance;

    if (++counter == 4/4) {
        distance = sonarSensor->getDistance();
        if ((distance <= 10) && (distance >= 0)) {
            alert = 1;
        }
        else {
            alert = 0;
        }
        counter = 0;
    }

    return alert;
}

/**
 * 障害物検知距離取得
 * @param 障害物検知距離
 */
int SonarDistance::getSonarDis() {
    return sonarSensor->getDistance();
}
