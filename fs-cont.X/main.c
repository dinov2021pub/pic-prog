/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/12/25, 15:26
 * Compatible to Kohzu Controller for femto-spotter
 * Ref: Operation_ManualJ_for_SC210_410_rev2.pdf
 * PIC : 16F1788
 * PCB : dino-con ver.001
 *  */

// CONFIG1
#pragma config FOSC = INTOSC  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdio.h>
#include "uart.h"
#include <stdlib.h>
#include <string.h>

#define _XTAL_FREQ 4000000      // 4MHz
//#define _XTAL_FREQ 160000000      // 16MHz


#define LEDON RA7 // LED ON
#define LMTON RA6 // Limit Sensor
#define N_NDO RB5 // Needle Detect Oscillation
#define N_NSC RB4 // Needle Oscillation
#define SLCT RB3 // Modeselec, 0:External IO mode, 1:InternalRS-232C command
#define N_NOS RB2 // Needle Origin Set
#define N_NTD RB1 // Needle Touch Detection
#define NTCH RB0 // Needle Touch detect switch
#define N_READY RA3 // READY / BUSY
#define ROLL_P3 RA2 // ROLLER Phase3
#define FS_CW RA1 // FS_CW
#define FS_CCW RA0 // FS_CCW
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1
//#define NPD_ADR 1   //npd parameter address

// __EEPROM_DATA(0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07);

enum command {
  RPS,
  WTB,
  WNI,
  WPD,
  OSC,
  NOS,
  NTD,
  NDO,
  NDD,
  NSP,
  NSD,
  NSC,
  RNP,
  RNI,
  RPD,
  RLM,
  VER,
  STS,
  DA0,
  DA1,
  DA2,
  NON
};

void write_data_eeprom(long adr, long value){
    long set_value;
    
    set_value = value & 0x00FF;
    eeprom_write(adr, set_value);

    set_value = value >> 8;
    set_value = set_value & 0x00FF;    
    eeprom_write(adr+1, set_value);
}

long read_data_eeprom(long adr){
    long set_value_h;
    long set_value_l;
    long set_value;
    
    set_value_l = eeprom_read(adr);
    set_value_h = eeprom_read(adr+1);

    set_value_h = set_value_h << 8;
    set_value = set_value_h | set_value_l;    
    
    return set_value;
}


void main(void) {

    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b01000000;     // PORTAの入出力設定 RA6 をリミットセンサ入力、それ以外は全て出力 0:出力, 1:入力
    TRISB = 0b10111111;     // PORTBの入出力設定 RB0:NTCH は接触検知入力, RB1:NTD入力, RB2:STOP入力, RB4:NDO入力, RB5:NSD入力, RB6:TxD出力, RB7:RxD入力　 0:出力, 1:入力
//    TRISB = 0b10100001;     // PORTBの入出力設定 RB0:NTCH は接触検知入力, RB1:NTD入力, RB2:STOP入力, RB4:NDO入力, RB5:NSD入力, RB6:TxD出力, RB7:RxD入力　 0:出力, 1:入力
    APFCON1 = 0b00000110;   // RB7=>RxD, RB6=>TxD
    PIE1 = 0b00110000;  //PERIPHERAL INTERRUPT ENABLE REGISTER 1
    OSCCON = 0b01101010;    // Set internal clock to 4MHz
    ANSELB = 0b00000000;    //すべてデジタル
    
    FVRCON = 0b00000000;   // アナログ出力　設定
    DAC1CON0 = 0b10100000;   // アナログ出力　設定
    DAC1CON1 = 0;   // アナログ出力　設定
    
    WPUB = 0b00111111;  // weak pull up
    OPTION_REG = 0x00;  // weak pull up enable
    
    initUART();             // 調歩同期式シリアル通信設定
    
    long INTVL_ADR = 8;   //intvl parameter address
    long NPD_ADR = 10;   //npd parameter address
    long NIP_ADR = 12;   //nip parameter address
 
    char tmp[40];
    int j = 10;
    int k = 0;
    int dist = 10;
    int intvl = 20;
    char rcmd[4];
    int mx_spd = 20250;
    int set_spd;
    long int npd = 2500;     // needle protrude distance
    int t_npd = 100;    // temporalneedle protrude distance
    int nsp = 500;
    char ln[4];
    int npos = 0;   // Needle Position
    int nip = 5000;     // Needle Initial Position
    long ans;
    
    char *ptr;

    enum command cmd; // enum型のオブジェクトを定義

    N_NTD = 1;
    N_NDO = 1;
    N_NSC = 1;
    SLCT = 1;
    N_NOS = 1;
    NTCH = 1;
    
    npd = read_data_eeprom(NPD_ADR);
    nip = read_data_eeprom(NIP_ADR);
    intvl = read_data_eeprom(INTVL_ADR);

    while(1){

//        ans = read_data_eeprom(NPD_ADR);
//        printf("C\tEEPROM %d\r\n", ans); // 送信
        
//        ans += 1;
//        eeprom_write(NPD_ADR, ans);
        
        cmd = NON;
        
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

        if (SLCT == 0){
            if(N_NDO == 0){
                cmd = NDO;
//            }else if(N_NTD == 0){
//                cmd = NTD;
            }else if(N_NSC == 0){
                cmd = NSC;
            }else if(N_NOS == 0){
                cmd = NOS;
            }
        } else {
            gets(tmp);
        }

 
        // LMT SW indicator = LED
//        if(LMTON == 1){
//            LEDON = 1;
//        } else{
//            LEDON = 0;
//        }       
//        gets(tmp);
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';


//        if(NTCH == 0){
//            LEDON = 1;
//        } else{
//            LEDON = 0;
//        }       

        
        if(strcmp(rcmd,"RPS") == 0) {
            cmd = RPS;
        }else if(strcmp(rcmd,"WTB") == 0){
            cmd = WTB;
        }else if(strcmp(rcmd,"WNI") == 0){
            cmd = WNI;
        }else if(strcmp(rcmd,"WPD") == 0){
            cmd = WPD;
        }else if(strcmp(rcmd,"OSC") == 0){
            cmd = OSC;
        }else if(strcmp(rcmd,"NOS") == 0){
            cmd = NOS;
        }else if(strcmp(rcmd,"NTD") == 0){
            cmd = NTD;
        }else if(strcmp(rcmd,"NDO") == 0){
            cmd = NDO;
        }else if(strcmp(rcmd,"NDD") == 0){
            cmd = NDD;
        }else if(strcmp(rcmd,"NSC") == 0){
            cmd = NSC;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }else if(strcmp(rcmd,"STS") == 0){
            cmd = STS;
        }else if(strcmp(rcmd,"NSP") == 0){
            cmd = NSP;
        }else if(strcmp(rcmd,"RNP") == 0){
            cmd = RNP;
        }else if(strcmp(rcmd,"RNI") == 0){
            cmd = RNI;
        }else if(strcmp(rcmd,"RPD") == 0){
            cmd = RPD;
        }else if(strcmp(rcmd,"RLM") == 0){
            cmd = RLM;
        }else if(strcmp(rcmd,"DA0") == 0){
            cmd = DA0;
        }else if(strcmp(rcmd,"DA1") == 0){
            cmd = DA1;
        }else if(strcmp(rcmd,"DA2") == 0){
            cmd = DA2;
        }else if(strcmp(rcmd,"NSD") == 0){
            cmd = NSD;
        }
        ptr = strtok(tmp, "/");

        N_READY = 1;
  
        switch(cmd){

            case RPS : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            npos += 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            if(npos > 1){
                                npos -= 1;
                            }else{
                                npos = 0;
                            }
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

//                    puts("C");
                    printf("C\tRPS\r\n"); // 送信
                    break;
                        
            case WTB : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        set_spd = atoi(ptr);
                    }
                    intvl = mx_spd / set_spd;
                    if (intvl == 0){
                        intvl = 1;
                    }

                    write_data_eeprom(INTVL_ADR, intvl);
                    printf("C\tWTB\t%d\r\n", intvl); // 送信

                    break;
 
            case WNI : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        nip = atoi(ptr);
                    }

                    write_data_eeprom(NIP_ADR, nip);
                    printf("C\tWNI\t%d\r\n", nip); // 送信
                    
                    break;
 
            case OSC : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            npos += 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            if(npos > 1){
                                npos -= 1;
                            }else{
                                npos = 0;
                            }
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            if(npos > 1){
                                npos -= 1;
                            }else{
                                npos = 0;
                            }
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            npos += 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

//                    puts("C");
                    printf("C\tOSC\r\n"); // 送信
                    break;

            case NOS : 
                    dist = 10000;
                    for(k = 0 ; k < dist ; k++){    // Needle Upward
                        if(LMTON == 0){     //LMT ON
                            npos = 0;
                            break;
                        }
                        FS_CW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }
                    for(k = 0 ; k < nip ; k++){     // Needle Downward
                        FS_CCW = 1;
                        npos += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }
                    printf("C\tNOS\t%d\r\n", npos); // 送信
                    break;

            case NTD : 
                    dist = 10000;
                    for(k = 0 ; k < dist ; k++){
                        FS_CCW = 1;
                        npos += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            LEDON = 1;
                            break;
                        }

                    }
//                    puts("C");
                    printf("C\tNTD\r\n"); // 送信

                    break;
                        
            case NDO : 

                    dist = 0;   //count moved distance
                    for(k = 0 ; k < 10000 ; k++){
                        FS_CCW = 1;
                        npos += 1;
                        dist += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            LEDON = 1;
                            break;
                        }

                    }
                    
                    for(k = 0 ; k < dist ; k++){
                        FS_CW = 1;
                        if(npos > 1){
                            npos -= 1;
                        }else{
                            npos = 0;
                        }
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

                    LEDON = 0;
//                    puts("C");
                    printf("C\tNDO\r\n"); // 送信
                    break;

            case NDD : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        t_npd = atoi(ptr);
                    }else{
                        t_npd = npd;
                    }
                    for(k = 0 ; k < 10000 ; k++){
                        FS_CCW = 1;
                        npos += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            LEDON = 1;
                            break;
                        }
                    }
                    
                    for(k = 0 ; k < t_npd ; k++){
                        FS_CW = 1;
                        if(npos > 1){
                            npos -= 1;
                        }else{
                            npos = 0;
                        }
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }
                    
                    LEDON = 0;
                    
//                    puts("C");
                    printf("C\tNDD\r\n"); // 送信
                    break;

            case NSD : 
                    
                    for(k = 0 ; k < nsp ; k++){
                        FS_CW = 1;
                        npos += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
                    printf("C\tNSD\r\n"); // 送信
                    break;

            case NSC : 
                    
                    for(k = 0 ; k < npd ; k++){
                        FS_CCW = 1;
                        npos += 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

                    for(k = 0 ; k < npd ; k++){
                        FS_CW = 1;
                        if(npos > 1){
                            npos -= 1;
                        }else{
                            npos = 0;
                        }
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
                    printf("C\tNSC\r\n"); // 送信
                    break;

            case WPD : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        npd = atoi(ptr);
                    }
                    write_data_eeprom(NPD_ADR, npd);
                    printf("C\tWPD\t%d\r\n", npd);
                    break;

            case NSP : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        nsp = atoi(ptr);
                    }
                    printf("C\tNSP\r\n");
                    break;

            case RNP : 
                    printf("C\tRNP/%d\r\n", npos);
                    break;
 
            case RNI : 
                    printf("C\tRNI/%d\r\n", nip);
                    break;
 
            case RPD : 
                    printf("C\tRPD/%d\r\n", npd);
                    break;

            case RLM : 
                    printf("C\tRLM/%d\r\n", LMTON);
                    break;
                    
            case DA0 : 
                    DAC1CON1 = 0;
                    break;

            case DA1 : 
                    DAC1CON1 = 100;
                    break;

            case DA2 : 
                    DAC1CON1 = 200;
                    break;

            case STS : 
                    printf("C\tREADY\r\n");
                    break;

            case VER : 
                    printf("C\tFS-CONT VERSION 0\r\n");
                    break;
                        
            default : break;
        }
        
//        if(NTCH == 0){
//            printf("SW OFF");
//        }else{
//            printf("SW ON");
//        }
        N_READY = 0;

    }
}

