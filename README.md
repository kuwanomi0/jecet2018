jecet2018a
====
ETロボコン2018「苦しんで覚えるJEC」のリポジトリ

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
