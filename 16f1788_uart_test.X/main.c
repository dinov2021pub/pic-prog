 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
? [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARESOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE., HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE 
*/
#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*============================================================
 * テストレベル選択（1つだけ有効にする）
 *============================================================*/
#define TEST_LEVEL_1    // 起動メッセージのみ
//#define TEST_LEVEL_2    // 1文字ループバック
//#define TEST_LEVEL_3    // 文字列ループバック
//#define TEST_LEVEL_4    // コマンド認識テスト

/*============================================================
 * 文字列受信関数（レベル3以上で使用）
 *============================================================*/
#if defined(TEST_LEVEL_3) || defined(TEST_LEVEL_4)

uint8_t receiveString(char *buffer, uint8_t maxLen)
{
    uint8_t i = 0;
    char c;
    
    while(i < maxLen - 1) {
        // 受信待ち
        while(!EUSART_IsRxReady());
        
        c = EUSART_Read();
        
        // エコーバック
        EUSART_Write(c);
        
        // Enterキーで終了
        if(c == '\r' || c == '\n') {
            printf("\r\n");
            break;
        }
        
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    
    return i;
}

#endif

/*============================================================
 * メイン関数
 *============================================================*/
int main(void)
{
    SYSTEM_Initialize();
    EUSART_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    /*--------------------------------------------------------
     * レベル1: 起動メッセージのみ（送信テスト）
     *--------------------------------------------------------*/
    #ifdef TEST_LEVEL_1
    
    printf("=== LEVEL 1: TX Test ===\r\n");
    printf("If you see this, TX is OK!\r\n");
    
    while(1)
    {
        // 何もしない
    }
    
    #endif

    /*--------------------------------------------------------
     * レベル2: 1文字ループバック（受信テスト）
     *--------------------------------------------------------*/
    #ifdef TEST_LEVEL_2
    
    printf("=== LEVEL 2: 1 Char Loopback ===\r\n");
    printf("Press any key...\r\n");
    
    while(1)
    {
        if(EUSART_IsRxReady()) {
            char c = EUSART_Read();
            printf("Received: '%c' (0x%02X)\r\n", c, c);
        }
    }
    
    #endif

    /*--------------------------------------------------------
     * レベル3: 文字列ループバック
     *--------------------------------------------------------*/
    #ifdef TEST_LEVEL_3
    
    char buffer[40];
    uint8_t len;
    
    printf("=== LEVEL 3: String Loopback ===\r\n");
    printf("Type and press Enter\r\n");
    
    while(1)
    {
        printf("> ");
        len = receiveString(buffer, sizeof(buffer));
        printf("Received %d chars: [%s]\r\n", len, buffer);
    }
    
    #endif

    /*--------------------------------------------------------
     * レベル4: コマンド認識テスト
     *--------------------------------------------------------*/
    #ifdef TEST_LEVEL_4
    
    char cmd[20];
    
    printf("=== LEVEL 4: Command Test ===\r\n");
    printf("Commands: VER, LED1, LED2, HELP\r\n");
    
    while(1)
    {
        printf("> ");
        receiveString(cmd, sizeof(cmd));
        
        if(strcmp(cmd, "VER") == 0) {
            printf("Version 1.0\r\n");
        }
        else if(strcmp(cmd, "LED1") == 0) {
            printf("LED1 command executed\r\n");
        }
        else if(strcmp(cmd, "LED2") == 0) {
            printf("LED2 command executed\r\n");
        }
        else if(strcmp(cmd, "HELP") == 0) {
            printf("Available commands:\r\n");
            printf("  VER  - Show version\r\n");
            printf("  LED1 - Control LED1\r\n");
            printf("  LED2 - Control LED2\r\n");
            printf("  HELP - Show this help\r\n");
        }
        else if(strlen(cmd) > 0) {
            printf("Unknown: [%s]\r\n", cmd);
        }
    }
    
    #endif

    return 0;
}