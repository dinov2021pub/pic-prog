# pigmee シャッターコントローラ コマンド仕様
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
| `VER` | `VERSION<SPC>X.X` | FWバージョン取得 | `X.X`: FWバージョン | `<SPC>VER<CR>` → `C<HT>VERSION<SPC>X.X<CR><LF>` |
| `HAL` | `HAL<HT>X` | ホール素子状態取得 | `X=0`: ホール素子Hi、シャッターオープン<br>`X=1`: ホール素子Lo、シャッタークローズ | `<SPC>HAL<CR>` → `C<HT>HAL<HT>1<CR><LF>` |
| `SHT/X` | `SHT<HT>X<HT>HAL<HT>Y` | シャッター設定 + ホール素子状態取得 | `X=0`: シャッタークローズ<br>`X=1`: シャッターオープン<br>`Y=0`: ホール素子Hi<br>`Y=1`: ホール素子Lo | `<SPC>SHT/0<CR>` → `C<HT>SHT<HT>0<HT>HAL<HT>1<CR><LF>` |
| `LDP/X` | `LDP<HT>X` | レッドレーザー設定 | `X=0`: レッドレーザーOFF<br>`X=1`: レッドレーザーON | 例: `<SPC>LDP/1<CR>` → `C<HT>LDP<HT>1<CR><LF>` |
| `DCF/X` | `DCF<HT>X` | DCファン設定 | `X=0`: DCファンOFF<br>`X=1`: DCファンON | 例: `<SPC>DCF/1<CR>` → `C<HT>DCF<HT>1<CR><LF>` |
## コマンド詳細
### `VER`
FWバージョンを取得します。
送信:
```text
VER<CR>
```
応答:
```text
C<HT>VERSION<SPC>X.X<CR><LF>
```
### `HAL`
メカニカルシャッターに取り付けたホール素子の状態を取得します。
送信:
```text
HAL<CR>
```
応答:
```text
C<HT>HAL<HT>Y<CR><LF>
```
| Y | 意味 |
|---:|---|
| `0` | ホール素子Hi、シャッターオープン |
| `1` | ホール素子Lo、シャッタークローズ |
### `SHT/X`
シャッターを開閉し、動作後のホール素子状態を返します。
送信:
```text
SHT/X<CR>
```
| X | 動作 |
|---:|---|
| `0` | シャッタークローズ |
| `1` | シャッターオープン |
応答:
```text
C<HT>SHT<HT>X<HT>HAL<HT>Y<CR><LF>
```
| Y | 意味 |
|---:|---|
| `0` | ホール素子Hi、シャッターオープン |
| `1` | ホール素子Lo、シャッタークローズ |
### `LDP/X`
レッドレーザーのON/OFFを設定します。
送信:
```text
LDP/X<CR>
```
| X | 動作 |
|---:|---|
| `0` | レッドレーザーOFF |
| `1` | レッドレーザーON |
応答:
```text
C<HT>LDP<HT>X<CR><LF>
```
### `DCF/X`
DCファンのON/OFFを設定します。
送信:
```text
DCF/X<CR>
```
| X | 動作 |
|---:|---|
| `0` | DCファンOFF |
| `1` | DCファンON |
応答:
```text
C<HT>DCF<HT>X<CR><LF>
```