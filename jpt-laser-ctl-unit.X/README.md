
# JPTレーザー制御CTLコマンド仕様

## 通信概要

PCからPICマイコンへコマンドを送信し、PICマイコンからPCへ実行結果または状態を返します。

### 制御文字

| 表記 | 16進数 | 意味 |
|---|---:|---|
| `<HT>` | `0x09` | 水平タブ |
| `<LF>` | `0x0A` | ラインフィード |
| `<CR>` | `0x0D` | キャリッジリターン |
| `<SPC>` | `0x20` | スペース |

## 共通フォーマット

### PC → PIC

- ヘッダー: なし
- フッター: `<CR>`

```text
COMMAND<CR>
```

数値パラメータを持つコマンドは、コマンド名と値を `/` で区切ります。

```text
COMMAND/VALUE<CR>
```

### PIC → PC

- ヘッダー: `C<HT>`
- フッター: `<CR><LF>`

```text
C<HT>RESPONSE<CR><LF>
```

## コマンド一覧

| 送信コマンド<br>PC → PIC | 戻り値<br>PIC → PC | 内容 | 備考 | 送受信例 |
|---|---|---|---|---|
| `電源投入` | `System initialization has been completed.!!` | `初期化終了メッセージ` | `電源投入後初期化終了時に自動出力` | `電源投入` → `System initialization has been completed.!!<CR><LF>` |
| `SF1/XXXX/XXX` | `SF1` | `SF1照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF1/XXXX/XXX<CR>` → `C<HT>SF1<CR><LF>` |
| `SF2/XXXX/XXX` | `SF2` | `SF2照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF2/XXXX/XXX<CR>` → `C<HT>SF2<CR><LF>` |
| `SF3/XXXX/XXX` | `SF3` | `SF3照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF3/XXXX/XXX<CR>` → `C<HT>SF3<CR><LF>` |
| `SF4/XXXX/XXX` | `SF4` | `SF4照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF4/XXXX/XXX<CR>` → `C<HT>SF4<CR><LF>` |
| `SF5/XXXX/XXX` | `SF5` | `SF5照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF5/XXXX/XXX<CR>` → `C<HT>SF5<CR><LF>` |
| `SF6/XXXX/XXX` | `SF6` | `SF6照射時間/出力設定` | `XXXXX=0～65536：照射時間設定値/XXX=0～255：出力設定値` | `<SPC>SF6/XXXX/XXX<CR>` → `C<HT>SF6<CR><LF>` |
| `SPO` | `TONを実行しているとき`<br>&nbsp;`SPO`<br>`TOFを実行しているとき`<br>&nbsp;`Emission is already disabled.!!` | `エミッション送信` | `` | `<SPC>SPO<CR>` → `TONを実行しているとき`<br>&nbsp;`C<HT>SPO<CR><LF>`<br>`TOFを実行しているとき`<br>&nbsp;`C<HT>Emission is already disabled.!!<CR><LF>` |


| `TON` | `TON` | `レーザーターンオン` | `` | `<SPC>TON<CR>` → `C<HT>TON<CR><LF>` |
| `TOF` | `TOF` | `レーザーターンオフ` | `` | `<SPC>TOF<CR>` → `C<HT>TOF<CR><LF>` |
| `VEW` | `SF1_TIME<HT>XXXXX<SPC><SPC><SPC>SF1_AMP<HT>XXX`<br>`SF2_TIME<HT>XXXXX<SPC><SPC><SPC>SF2_AMP<HT>XXX`<br>`SF3_TIME<HT>XXXXX<SPC><SPC><SPC>SF3_AMP<HT>XXX`<br>`SF4_TIME<HT>XXXXX<SPC><SPC><SPC>SF4_AMP<HT>XXX`<br>`SF5_TIME<HT>XXXXX<SPC><SPC><SPC>SF5_AMP<HT>XXX`<br>`SF6_TIME<HT>XXXXX<SPC><SPC><SPC>SF6_AMP<HT>XXX` | `照射時間/出力値表示` | `` | `<SPC>VEW<CR>` → `C<HT>SF1_TIME<HT>XXXXX<SPC><SPC><SPC>SF1_AMP<HT>XXX<CR><LF>`<br>`C<HT>SF2_TIME<HT>XXXXX<SPC><SPC><SPC>SF2_AMP<HT>XXX<CR><LF>`<br>`C<HT>SF3_TIME<HT>XXXXX<SPC><SPC><SPC>SF3_AMP<HT>XXX<CR><LF>`<br>`C<HT>SF4_TIME<HT>XXXXX<SPC><SPC><SPC>SF4_AMP<HT>XXX<CR><LF>`<br>`C<HT>SF5_TIME<HT>XXXXX<SPC><SPC><SPC>SF5_AMP<HT>XXX<CR><LF>`<br>`C<HT>SF6_TIME<HT>XXXXX<SPC><SPC><SPC>SF6_AMP<HT>XXX<CR><LF>` |
| `VER` | `VERSION<SPC>X.X` | `FWバージョン表示` | `X.X : FWバージョン` | `<SPC>VER<CR>` → `C<HT>VERSION<SPC>X.X<CR><LF>` |

## コマンド詳細

### `SF1/XXXX/XXX`

SF1に照射時間と出力値を格納

送信:

```text
<SPC>SF1/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF1<CR><LF>
```

### `SF2/XXXX/XXX`

SF2に照射時間と出力値を格納

送信:

```text
<SPC>SF2/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF2<CR><LF>
```

### `SF3/XXXX/XXX`

SF3に照射時間と出力値を格納

送信:

```text
<SPC>SF3/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF3<CR><LF>
```

### `SF4/XXXX/XXX`

SF4に照射時間と出力値を格納

送信:

```text
<SPC>SF4/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF4<CR><LF>
```

### `SF5/XXXX/XXX`

SF5に照射時間と出力値を格納

送信:

```text
<SPC>SF5/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF5<CR><LF>
```

### `SF6/XXXX/XXX`

SF6に照射時間と出力値を格納

送信:

```text
<SPC>SF6/XXXX/XXX<CR>
```

応答:

```text
C<HT>SF6<CR><LF>
```

### `SPO`

エミッション送信
SF1～SF6に格納された照射時間と出力値をJPTレーザーに送信してレーザーを照射する

送信:

```text
<SPC>SPO<CR>
```

応答:

```text
TONを実行しているとき
　C<HT>SPO<CR><LF>
TOFを実行しているとき
　C<HT>Emission is already disabled.!!<CR><LF>
```

### `TON`

レーザーターンオン
このコマンドはレーザーの安全キーを解除する

送信:

```text
<SPC>TON<CR>
```

応答:

```text
C<HT>TON<CR><LF>
```

### `TOF`

レーザーターンオフ
このコマンドはレーザーの安全キーを施錠する

送信:

```text
<SPC>TOF<CR>
```

応答:

```text
C<HT>TOF<CR><LF>
```

### `VEW`

照射時間/出力値表示
SF1～SF6に格納されている値を表示する

送信:

```text
<SPC>VEW<CR>
```

応答:

```text
C<HT>SF1_TIME<HT>XXXXX<SPC><SPC><SPC>SF1_AMP<HT>XXX<CR><LF>
C<HT>SF2_TIME<HT>XXXXX<SPC><SPC><SPC>SF2_AMP<HT>XXX<CR><LF>
C<HT>SF3_TIME<HT>XXXXX<SPC><SPC><SPC>SF3_AMP<HT>XXX<CR><LF>
C<HT>SF4_TIME<HT>XXXXX<SPC><SPC><SPC>SF4_AMP<HT>XXX<CR><LF>
C<HT>SF5_TIME<HT>XXXXX<SPC><SPC><SPC>SF5_AMP<HT>XXX<CR><LF>
C<HT>SF6_TIME<HT>XXXXX<SPC><SPC><SPC>SF6_AMP<HT>XXX<CR><LF>
```

### `VER`

FWバージョン表示

送信:

```text
<SPC>VER<CR>
```

応答:

```text
C<HT>VERSION<SPC>X.X<CR><LF>
```
