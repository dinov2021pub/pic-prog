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

## ps-laser-util.X
- ピコ秒グリーンレーザーの周辺機器の制御を行うコントロール基板のプログラム。
- PIC 16F648A を用い、冷却ファン、位置合わせレーザー、メカニカルシャッターの制御をする。
- USART により通信する。通信仕様は以下。
>- ボーレート：9600bps
>- データ：8bit
>- パリティ：none
>- ストップビット：１

- PCとの接続は、秋月電子の [ＦＴ２３４Ｘ　超小型ＵＳＢシリアル変換モジュール](https://akizukidenshi.com/catalog/g/gM-08461/)を使用した。
- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ６４８Ａ－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g100466/)。[データシート](https://akizukidenshi.com/goodsaffix/pic16f627a_628a_648a.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)。両方をインストールして使う。C言語にて開発
- 開発環境のバージョンを以下に示す。
>- MPLAB X バージョン：v6.25
>- XC8 バージョン：v2.50
>- teraterm バージョン：v5.4.1
- ファームウェア バージョンを以下に示す。
>- ＊－V1, 位置合わせレーザー、DCファンを制御
>- ＊－V2,V1に追加でシャッター制御機能を追加してVersion 2.0とした(2026年1月9日現在)
- teratermでの動作確認
>- コマンドのフォーマット
>>- スペース、コマンド、/、1または0
>- コマンドについて
>>- VER:ファームウェアバージョン確認
>>- LDP:位置合わせレーザーON/OFF
>>>- 1:位置合わせレーザーON、0:位置合わせレーザーOFF
>>- DCF:DCファンON/OFF
>>>- 1:DCファンON、0:DCファンOFF
>>- SHT:シャッター閉(レーザー遮断)/開(レーザー解放)とフォトインタラプタの状態を返す。
>>>- 1:シャッター閉(レーザー遮断)、0:シャッター開(レーザー解放)
>>>- 0:フォトインタラプタ開、1:フォトインタラプタ閉
>>- PHO:フォトインタラプタ状態確認
>>>- 0:フォトインタラプタ開、1:フォトインタラプタ閉
>>- NON:何もしない
<img width="822" height="546" alt="スクリーンショット 2026-01-13 120324" src="https://github.com/user-attachments/assets/9dc75af9-0613-4c93-9f67-4e3112fea1a2" />

## led-dimming-unit.X
- ピコ秒グリーンレーザーの照明の制御を行うコントロール基板のプログラム。
- PIC 16F1778 を用い、同軸照明、リング照明の制御をする。

- PICは、[ＰＩＣマイコン　ＰＩＣ１６Ｆ１７７８－Ｉ／ＳＰ](https://akizukidenshi.com/catalog/g/g113552/)。[データシート](https://akizukidenshi.com/goodsaffix/pic16f1778.pdf)
- 開発は、Microchip Technology の[MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)と[MPLAB® XC Compilers](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-
- 開発環境のバージョンを以下に示す。
>- MPLAB X バージョン：v6.25
>- XC8 バージョン：v2.50
>- teraterm バージョン：v5.4.1
- ファームウェア バージョンを以下に示す。
>- ＊－V1
-
-　手書き

<img width="931" height="702" alt="スクリーンショット 2026-01-27 153537" src="https://github.com/user-attachments/assets/28057800-3afc-4e2e-834f-35d24742f1af" />



- compilers)。両方をインストールして使う。C言語にて開発

