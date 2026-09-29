# hal-game-works

大槻 海斗（Ohtsuki Kaito）が HAL東京で制作したゲームのソースコード集です。
作品の紹介・プレイ動画は[作品集サイト](https://sand639.github.io/portfolio/)にあります。

| # | 作品 | 言語・環境 | 体制 | 制作時期 |
|---|---|---|---|---|
| [001](./001-monster-rush) | [Monster Rush](https://sand639.github.io/portfolio/works/001-monster-rush/) | C言語 | 個人制作 | 2023年5月（1週間） |
| [002](./002-monster-rush-2) | [Monster Rush2](https://sand639.github.io/portfolio/works/002-monster-rush-2/) | C言語 | 個人制作 | 2023年6月（1週間） |
| [005](./005-unity-quest) | [Unity Quest](https://sand639.github.io/portfolio/works/005-unity-quest/) | Unity / C# | 個人制作 | 2023年5月〜7月（2カ月） |
| [006](./006-spring) | [Spring](https://sand639.github.io/portfolio/works/006-spring/) | Unity / C# | 個人制作 | 2023年9月（10日間） |
| [007](./007-treasure-hunter) | [TREASUE HUNTER](https://sand639.github.io/portfolio/works/007-treasure-hunter/) | C言語 | 個人制作 | 2023年9月（2週間） |
| [008](./008-namebattler) | [Namebattler](https://sand639.github.io/portfolio/works/008-namebattler/) | C言語 | 個人制作 | 2023年12月（3週間） |
| [009](./009-unity-3d-game) | [Unity3DGame](https://sand639.github.io/portfolio/works/009-unity-3d-game/) | Unity / C# | 個人制作 | 2024年2月（1週間） |
| [010](./010-zombie-escape) | [ZOMBIE ESCAPE](https://sand639.github.io/portfolio/works/010-zombie-escape/) | Unity / C# | 個人制作 | 2024年1月（1週間） |
| [011](./011-pseudo-3d-maze) | [疑似3D迷路](https://sand639.github.io/portfolio/works/011-pseudo-3d-maze/) | C言語 / C++ | 個人制作 | 2024年2月（1週間） |
| [012](./012-tetris) | [テトリス](https://sand639.github.io/portfolio/works/012-tetris/) | C言語 | 個人制作 | 2024年2月（1週間） |
| [013](./013-colorful-box) | [ColorfulBox](https://sand639.github.io/portfolio/works/013-colorful-box/) | Unity / C# | 個人制作 | 2024年2月（1週間） |
| [014](./014-ballon-clicker) | [BALLON CLICKER](https://sand639.github.io/portfolio/works/014-ballon-clicker/) | Unity / C# | 個人制作 | 2024年2月（1週間） |
| [015](./015-space-shooter-console) | [SPACE SHOOTER](https://sand639.github.io/portfolio/works/015-space-shooter-console/) | C言語 | 個人制作 | 2023年5月（1週間） |
| [016](./016-natsu-no-shugekisha) | [夏の襲撃者](https://sand639.github.io/portfolio/works/016-natsu-no-shugekisha/) ※ | C言語 / C++ / DirectX11 | 2人チーム（プログラマー1・プランナー1） | 2024年8月（1日） |
| [018](./018-battle-colosseum) | [バトルコロシアム](https://sand639.github.io/portfolio/works/018-battle-colosseum/) | C++ | 個人制作 | 2024年9月（3週間） |
| [020](./020-animal-hunt) | [AnimalHunt](https://sand639.github.io/portfolio/works/020-animal-hunt/) ※ | C言語 / C++ / DirectX11 | 個人制作 | 2024年9月（3週間） |
| [022](./022-pop-ball) | [PopBall](https://sand639.github.io/portfolio/works/022-pop-ball/) ※ | C言語 / C++ / DirectX11 | 個人制作 | 2024年1月（3日） |
| [023](./023-hack-and-slash) | [ハック＆スラッシュ](https://sand639.github.io/portfolio/works/023-hack-and-slash/) | C言語 / C++ / Siv3D | 個人制作 | 2024年1月（2週間） |

※ 授業で配布された DirectX 11 のベース（`main.h`・`renderer`・`texture.h` など、ファイル冒頭の Author が自分以外のもの）の上に作っています。016 は2人チームの作品で、プログラムは自分が担当しました。

## このリポジトリについて

- 各フォルダには、ソースコードとプロジェクトファイル（.sln / .vcxproj）だけを置いています
- 画像・音声などの素材、ビルド成果物、セーブデータは含めていません。そのためこのままではビルド・実行できない作品があります
- 外部のライブラリ（`conioex.h`、Siv3D、DirectXTex、assimp など）は含めていません
- Unity の作品は C# スクリプトだけです（プロジェクト一式ではありません）
- 公開にあたり、元の Shift-JIS のファイルを UTF-8（BOM 付き）に変換し、コメントのクラス記号・出席番号を削除しています
