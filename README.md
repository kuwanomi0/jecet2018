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
    - アンダースコアで単語と単語の区切る(スネーク記法)
    - メンバー変数には最初に`m_`をつける
    ~~~~
    // 例
    int m_jec_jz_robo;
    ~~~~
  最終的な例
  ~~~~
  #include "ev3api.h"

  class JecRobo
  {
  private:
    int8_t  m_count;
    int32_t m_jec_jz;
    int32_t m_jec_jy;

  public:
    void start()
    int jecJzEtRobo();

  }
  ~~~~
