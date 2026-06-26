#define _XTAL_FREQ 4000000      // システムクロック4MHz
#include <xc.h>
#include <string.h>
#include <stdio.h>
#include "uart.h"
 
void uart_init()
{
    SPBRG = SPBRG_DATA; // ボーレート設定
    TXSTA = (TX9_RX9_DATA | BRGH_DATA | 0x20); // 8or9bit, 低速or高速サンプル指定
    RCSTA = (TX9_RX9_DATA | 0x90); // 低速or高速サンプル指定
}

void putch(unsigned char byte) // 1byte送信
{
    while(!TXIF);
    TXREG = byte;
}

unsigned char getch(void)
{
    while(!RCIF)
    {
        // 受信待ち
    }
    
    // オーバーランエラーチェック（必須）
    if(RCSTAbits.OERR) {
        RCSTAbits.CREN = 0;  // 受信無効化
        RCSTAbits.CREN = 1;  // 再有効化してエラークリア
    }
    
    // フレーミングエラーチェック（推奨）
    if(RCSTAbits.FERR) {
        unsigned char dummy = RCREG;  // ダミーリードでクリア
        (void)dummy;  // 未使用警告抑制
    }
    
    return RCREG;
}

unsigned char uart_getche(void){
    unsigned char c;
    c = getch();   // 1文字受信
    putch(c);      // 受信した文字をそのまま送り返す（エコー）
    return c;
}

void uart_gets(char *buffer, uint16_t max_len)
{
    uint16_t idx = 0;
    char c;
    
    // NULLチェックを追加
    if(buffer == NULL || max_len == 0) {
        return;
    }
    
    while(idx < max_len - 1) {
        c = getch();
        
        if(c == '\r' || c == '\n') {
            putch('\r');
            putch('\n');
            buffer[idx] = '\0';
            return;
        }
        
        if((c == '\b' || c == 0x7F) && idx > 0) {
            idx--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        
        if(c < 0x20) continue;
        
        buffer[idx++] = c;
        putch(c);
    }
    
    buffer[idx] = '\0';
}
