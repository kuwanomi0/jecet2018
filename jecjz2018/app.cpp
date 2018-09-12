/**
 ******************************************************************************
 ** ファイル名 : app.cpp
 **
 ** 概要 : 2輪倒立振子ライントレースロボットのTOPPERS/HRP2用C++サンプルプログラム
 **
 ** 注記 : sample_cpp (ライントレース/尻尾モータ/超音波センサ/リモートスタート)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"

#include "runner/Driver.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

Driver* driver;

/**
 * メインタスク
 * @param unused 拡張情報
 */
void mainTask(intptr_t unused)
{
    char buf[64];
    driver = new Driver();

    act_tsk(BT_TASK);

    driver->start();

    ER er = ev3_sta_cyc(CYC_HANDLER);   //周期ハンドラを起動
    sprintf(buf, "main_task: error_code=%d", MERCD(er) );   // APIのエラーコードの表示の仕方です。

    slp_tsk();

    ext_tsk();
}

/**
 * コントロールタスク
 * @param unused 拡張情報
 */
void controllerTask(intptr_t unused)
{
    driver->exec();
}

/**
 * 周期ハンドラ(4ms)
 * @param unused 拡張情報
 */
void cycHandler(intptr_t unused)
{
    act_tsk(CONTROLLER_TASK);
}

/**
 * BTタスク
 * @param unused 拡張情報
 * @comment Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
 *          ASCIIコードで1を送信すると、リモートスタートする。
 */
void btTask(intptr_t unused)
{
    while(1) {
        driver->btUpdate();
    }
}
