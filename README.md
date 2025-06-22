# リアルタイム制御向けC++制御アルゴリズム Arduino Due環境

## 特徴

C++制御アルゴリズムのメモリ消費、計算時間を Arduino Due で検証できる環境です。

いわゆる Processor-in-the-Loop (PIL) の環境です。

## 環境構築

Visual Studio Codeをインストールし、「PlatformIO」という拡張機能をインストールしてください。

最初にビルドすると、「_B」や「_P」のDefine定義と、ライブラリ内の_B、_P変数定義が被っているため、エラーになります。

これを解消するため、「ctype_base.h」というファイルの末尾辺りに、以下のコードを追加してください。

```c
/* Undef */
#undef _U
#undef _L
#undef _N
#undef _S
#undef _P
#undef _C
#undef _X
#undef _B
```

「ctype_base.h」は、Windowsの場合「C:\\Users\\<ユーザー名>\\.platformio\\packages」の下にあるパッケージフォルダの中にあります。

## サポート

新規にissueを作成して、詳細をお知らせください。

## 貢献

コミュニティからのプルリクエストを歓迎します。もし大幅な変更を考えているのであれば、提案する修正についての議論を始めるために、issueを開くことから始めてください。

また、プルリクエストを提出する際には、関連するテストが必要に応じて更新または追加されていることを確認してください。

## ライセンス

[MIT License](./LICENSE.txt)
