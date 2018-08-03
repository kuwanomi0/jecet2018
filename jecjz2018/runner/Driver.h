/**
 ******************************************************************************
 ** ファイル名 : Driver.h
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#ifndef RUNNER_DRIVER_H
#define RUNNER_DRIVER_H

#include "Runner.h"
#include "../scenario/Course.h"
// #include "scenario/シナリオ.h"

class Driver
{
private:
    Runner* runner;
    Course* mCourse;
    Course dCourse[2] = {
        {     0,  20,  0, 96, 0.0700F, 0.0001F, 0.7000F, 1},
        { 99999,  20,  0,  5, 0.0700F, 0.0001F, 0.7000F, 1}
    };
    Course lCourse[15] =  {
        {     0, 100,  0, 96, 0.0500F, 0.0000F, 1.0000F, 1 },  //  S
        {  2500, 100,  0,  5, 0.0500F, 0.0000F, 1.0000F, 1 },  //  1
        {  4000,  96,  0,  5, 0.1000F, 0.0001F, 1.0000F, 1 },  //  2
        {  5800,  80,  0,  5, 0.0500F, 0.0000F, 1.0000F, 1 },  //  3
        {  6350,  80,  0,  5, 0.1300F, 0.0001F, 1.3000F, 1 },  //  4
        {  6900,  80,  0,  5, 0.0500F, 0.0000F, 1.0000F, 1 },  //  5
        {  7600,  80,  0,  5, 0.1300F, 0.0001F, 1.3000F, 1 },  //  6
        { 10100, 100,  0,  5, 0.0500F, 0.0000F, 1.0000F, 1 },  //  7
        { 11050,  30,  0,  5, 0.0300F, 0.0001F, 0.2000F, 1 },  //  8G
        { 11150,  10,  0, 70, 0.0700F, 0.0001F, 0.7000F, 1 },  //  9L
        { 11200,  90,  0, 70, 0.0000F, 0.0000F, 0.0000F, 0 },  //  9L
        { 11750,  80,  0, 70, 0.8000F, 0.0007F, 6.0000F, 0 },  //  9L
        { 12000,  80,  0, 70, 0.0000F, 0.0000F, 0.0000F, 0 },  //  9L
        { 12110,  20,  0, 70, 0.8000F, 0.0007F, 6.0000F, 0 },  // 10G
        { 99999,   0,  0, 70, 0.0000F, 0.0000F, 0.0000F, 0 }   //  G
    };
    Course rCourse[11] =  {
        {     0, 100,  0, 96, 0.0700F, 0.0000F, 1.0000F, 1 },  //  S
        {  2000, 120,  0,  5, 0.1000F, 0.0001F, 1.0000F, 1 },  //  1
        {  3800, 100,  0, 55, 0.0500F, 0.0000F, 1.0000F, 1 },  //  2
        {  4200,  80,  0,  5, 0.1000F, 0.0000F, 1.0000F, 1 },  //  3
        {  4900,  80,  0, 55, 0.1000F, 0.0000F, 1.0000F, 1 },  //  4
        {  5600,  80,  0,  5, 0.1500F, 0.0000F, 1.4400F, 1 },  //  5
        {  6200,  80,  0, 55, 0.0500F, 0.0000F, 1.0000F, 1 },  //  6
        {  7400, 100,  0,  5, 0.1520F, 0.0000F, 1.4400F, 1 },  //  7
        {  9800, 120,  0, 55, 0.0700F, 0.0000F, 1.0000F, 1 },  //  8
        { 12000,  80,  0,  5, 0.0700F, 0.0001F, 0.7000F, 1 },  //  8G
        { 99999,  80,  0,  5, 0.0000F, 0.0000F, 0.0000F, 1 }   //  G
    };
    int courseNumber = 0;
    // scenario::シナリオ senarios[];
    // scenario::シナリオ シナリオ;

public:
    Driver();
    void start();
    void exec();
    void btTask();
    // void 区間を渡す();

};
#endif  // RUNNER_DRIVER_H
