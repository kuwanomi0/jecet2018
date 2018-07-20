jecet2018a
====
ETロボコン2018「苦しんで覚えるJEC」のリポジトリ

#### モデルについて
GoogleDriveで管理しています  https://drive.google.com/drive/folders/1Eer4xp2JzLclUbqO4qx5ejZr96So9AWI

#### コーディングルール
  - クラス名
    - 単語の一文字目を大文字にして連結(パスカル記法)
    ~~~~
    // 例
    class JecJzRobo
    {
    }
    ~~~~
  - 関数名
    - 2単語目から一文字目を大文字にして連結(キャメル記法)
    ~~~~
    // 例
    void jecJzRobo();
    ~~~~
  - 変数名
    - キャメル記法
    - メンバー変数には最初に`m`をつける
    ~~~~
    // 例
    int mJecJzRobo;
    ~~~~
  - オブジェクト名
    - キャメル記法
  最終的な例
  ~~~~
  #include "ev3api.h"
  #include "ColorSensor.h"

  class JecRobo
  {
  private:
    int8_t  mCount;
    int32_t mJecJz;
    int32_t mJecJy;
    ColorSensor* colorSensor;

  public:
    void start()
    int jecJzEtRobo();

  }
  ~~~~

#### 区間情報

  - Lコース

    |区間番号|距離(mm)|
    ----|----
    |1|2500|
    |2|4000|
    |3|5700|
    |4|6400|
    |5|6800|
    |6|7600|
    |7（ゴール）|10000|
    |8（灰色直前）|10700|


  - Rコース

    |区間番号|距離(mm)|
    ----|----
    |1|2000|
    |2|3800|
    |3|4200|
    |4|4900|
    |5|6100|
    |6|7400|
    |7|9000|
    |8（ゴール）|9300|
    |9（灰色直前）|10000|
