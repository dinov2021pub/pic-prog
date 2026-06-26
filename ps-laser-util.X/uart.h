/* 
 * File:   uart.h
 * Author: shimi
 *
 * Created on 2026/06/25, 11:42
 */
/* ===========================
 * pigmeeシャッターコントローラ用 UART設定
 * FW Versiom 3.0でXC8 V2.5⇒V3.1に対応
 * C標準をC90⇒C99に変更
 * 内部クロック:4MHzを使用
 * ボーレート:9600bps
 * 低速高速モード　
 * 　※ボーレートの速度に合わせてボーレート誤差を調整する機能
 *      BRGH_BIT == 0:低速モード
 *      BRGH_BIT == 1:高速モード
 * データ長:
 *      TX9_RX9_BIT == 0:8bit
 *      TX9_RX9_BIT == 1:9bit
 * 以下はUARTペリフェラル固定
 *      スタートビット:1bit
 *      ストップビット:1bit
 * teratermで送信文字が表示されるようにgetche関数を実装
 * =========================== */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000 // 4MHz
#endif
 
#define BAUDRATE 9600       // 9.6kbps
#define TX9_RX9_BIT 0       // 0: 8bit, 1: 9bit
#define BRGH_BIT 1          // 0: 低速サンプル指定, 1: 高速サンプル指定
 
#if TX9_RX9_BIT == 1
#define TX9_RX9_DATA 0x40 // 9bit
#else
#define TX9_RX9_DATA 0x00 // 8bit
#endif
 
#if BRGH_BIT == 1
#define BRGH_DATA 0x04
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 16) / BAUDRATE) - 1))
#else
#define BRGH_DATA 0x00
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 64) / BAUDRATE) - 1))
#endif

void init_uart(void);
void putch(unsigned char byte);
unsigned char getch(void);
unsigned char uart_getche(void);
void uart_gets(char *buffer, uint16_t max_len);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */