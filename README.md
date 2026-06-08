# Settings
- MPLAB X IDE でGithubにアクセスするには、access token が必要
- Push 時に表示される Password の欄に access token を入力する
- 詳細はこちら
   - https://homepage.noakobo.net/news/archives/70#google_vignette
 
# pic-prog
Repository of PIC micon program

## m-ctrl
- ステッピングモータを制御するプログラム
- USART により通信する。
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／Ｐ](https://akizukidenshi.com/catalog/g/gI-00466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- 

## encoderctrl.X
- エンコーダ出力を読み取るプログラム
- 秋月電子の[反射型２相光学エンコーダＤＩＰ化キット](https://akizukidenshi.com/catalog/g/gK-09249/)

## kohzu-ctrl-compati.X
- 神津精機のコントローラ SC-200/400, CRUX とコマンドがコンパチなコントローラ
- PIC 16F648A もしくは、16F1788 を使って、ステッピングモータを制御するプログラム
- USART により通信する。
- モータドライバは Melec DB-5410
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／Ｐ](https://akizukidenshi.com/catalog/g/gI-00466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発

## suruga-ctrl-compati.X
- 神津精機のコントローラ SC-200/400, CRUX とコマンドがコンパチなコントローラ
- PIC 16F648A を使って、ステッピングモータを制御するプログラム
- USART により通信する。
- モータドライバは Melec DB-5410
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)
- ＊－V1, V2 では、PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／Ｐ](https://akizukidenshi.com/catalog/g/gI-00466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- ＊－V3のみ、PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７８８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/gI-11885/)。[データシート](https://akizukidenshi.com/download/ds/microchip/pic16f1788.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- `RPS1`, `RPS2` で駿河精機の `D234` ドライバへパルスを送ってステージを制御する。
- `RPS3`では、`femto-Spotter` を制御する

## fs-cont.X
- kohzu-ctrl-compati-V3.X をベースに、本格的に femto-Spotter 用のコントローラとして開発開始
- 神津精機のコントローラ SC-200/400 とコマンドがコンパチなコントローラ（CRUXには対応しない）
- PIC 16F1788 を使って、ステッピングモータを制御するプログラム
- USART により通信する。
- モータドライバは Melec DB-5410
- PCとの接続は、RS-232C (内部にコンバータ https://akizukidenshi.com/catalog/g/gI-16063/ ) にて通信。基板(dino-con)には、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)を接続できる端子がある。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７８８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/gI-11885/)。[データシート](https://akizukidenshi.com/download/ds/microchip/pic16f1788.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発

## qcw-laser-cont.X
- Raycus ファイバーレーザ RFL-QCW-*** 向けにアナログ信号入力でQCWパルス発振するためのプログラム
- PIC 16F11788 を使用
- USART通信
- femto-Spotter コントローラ fs-cont をベースに開発
- 不要なコマンドが多く存在（短納期で仕上げる必要があったため）
- 2026/01/30 使用可能

## ps-laser-util.X
- ピコ秒グリーンレーザーの周辺機器の制御を行うコントロール基板のプログラム。
- PIC 16F648A を用い、冷却ファン、レッドレーザー、メカニカルシャッターの制御をする。
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)を使用した。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g100466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- ＊－V1, レッドレーザー、DCファンを制御
- ＊－V2, V1に追加でシャッター制御機能を追加してVersion 2.0とした(2026年1月9日現在)
- ＊－V2, シャッター破損によりシャッター回路を再検討(2026年6月6日現在)
- [回路図 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-001E-001.pdf)
- [ファームウェア仕様](https://github.com/dinov2021pub/pic-prog/tree/main/ps-laser-util.X)

## led-dimming-unit.X
- ピコ秒グリーンレーザーの照明の制御を行うコントロール基板のプログラム。
- PIC 16F1778 を用い、同軸・リング照明の制御をする。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７７８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g113552/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC16%28L%29F1777_8_9_Family_Data_Sheet_40001819D.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- [回路図 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-001E-003.pdf)

## jpt-ctl-unit.X
- JPTレーザーの制御を行うコントロール基板のプログラム。
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)を接続する。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７８８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g111885/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001675C.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- 回路図は以下に保存(https://www.dinov.tokyo/DD-DB/public/Data/Parts/1773195408_MP26-002E-001.pdf)
- [回路図 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP26-002E-001.pdf)
- [ファームウェア仕様](https://github.com/dinov2021pub/pic-prog/tree/main/jpt-laser-ctl-unit.X)

## uv-ps-laser-ctl-unit.X
- ピコ秒UVレーザーのMEP制御BOXを行うコントロール基板のプログラム。
- PIC16F1778 を用い、シャッター、レッドレーザー、同軸・リング照明の制御をする。
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)を使用した。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７７８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g113552/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC16%28L%29F1777_8_9_Family_Data_Sheet_40001819D.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- [リング照明基板 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-003E-001.pdf) |
- [マイコン基板 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-003E-002.pdf) |
- [LEDドライブ基板 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-003E-003.pdf) |
- [シャッター基板 🔗](https://www.dinov.tokyo/DD-DB/public/Data/Parts/MP25-003E-004.pdf) |
- [ファームウェア仕様](https://github.com/dinov2021pub/pic-prog/tree/main/ps-uv-laser-ctl-unit.X)
