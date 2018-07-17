/**
 ******************************************************************************
 ** ファイル名 : ControlManager.cpp
 ** クラス名   : ControlManager
 **
 ** 概要 : 制御を管理するクラス
 ******************************************************************************
 **/
#include "ControlManager.h"

ControlManager::ControlManager() {
    balancer = new Balancer();
    mc = new MotorControl();
    tc = new TailControl();
}

void ControlManager::tailInit() {
    tc->init();
}

void ControlManager::wheelInit() {
    mc->init();
}

void ControlManager::balancerInit() {
    balancer->init(2);
}

void ControlManager::running(int forward, int turn, int angle) {
    tc->setControl(angle);
}
