/**
 ******************************************************************************
 ** ファイル名 : ImpactSensor.cpp
 ** クラス名   : ImpactSensor
 **
 ** 概要 : 衝撃検知の計算を行うクラス
 ******************************************************************************
 **/
#include "ImpactSensor.h"

ImpactSensor::ImpactSensor() {
	gyroSensor = new GyroSensor(PORT_4);
}

int ImpactSensor::alert() {
	return 0;
}
