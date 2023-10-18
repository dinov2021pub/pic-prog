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
- PIC 16F648A を使って、ステッピングモータを制御するプログラム
- USART により通信する。
- モータドライバは Melec DB-5410
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／Ｐ](https://akizukidenshi.com/catalog/g/gI-00466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発

## suruga-ctrl-compati.X
- PIC 16F648A を使って、ステッピングモータを制御するプログラム
- USART により通信する。
- モータドライバは Melec DB-5410
- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／Ｐ](https://akizukidenshi.com/catalog/g/gI-00466/)。[データシート](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- `RPS1`, `RPS2` で駿河精機の `D234` ドライバへパルスを送ってステージを制御する。
- `RPS3`では、`femto-Spotter` を制御する
