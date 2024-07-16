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


#define N_READY RA7 // LED ON -> N_READY
#define LMTON RA6 // Limit Sensor
//#define N_NDO RB5
//#define N_NSC RB4
#define N_MSW RB5 // Mode Switch
#define N_FSW RB4 // Foot Switch
#define SLCT RB3 // Modeselec, 0:External IO mode, 1:InternalRS-232C command
#define N_NOS RB2 // Needle Origin Set
#define N_NTD RB1 // Needle Touch Detection
#define NTCH RB0 // Needle Touch detect switch
#define MOD RA3 // MOD (Laser Modulation))
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
  WRP,
  RDC,
  WDC,
  VER,
  STS,
  DA0,
  DA1,
  DA2,
  PMV,  // PZT move triangle
  PMA,  // PZT move absolutely
  PMR,  // PZT move relatively
  RPP,  // Read PZT Position
  WLP,  // Write Laser Power
  WLW,  // Write Laser pulse Width
  WLT,  // Write Laser interval Time
  RLP,  // Read Laser Power
  RLW,  // Read Laser pulse Width
  RLT,  // Read Laser interval Time
  LPF,  // Laser Pulse Fire
  AIN,
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

/* ADconvert */
unsigned int AD_convert(unsigned char channel){
    //ADC Select Channel AN4
    ADCON0bits.CHS0 = 0;   //ADC Channel select
    ADCON0bits.CHS1 = 0;   //ADC Channel select
    ADCON0bits.CHS2 = 1;   //ADC Channel select
    ADCON0bits.CHS3 = 0;   //ADC Channel select
    ADCON0bits.CHS4 = 0;   //ADC Channel select
    __delay_us(20);         // wait for 20us
    ADCON0bits.GO_nDONE = 1;   //ADC start
    while(ADCON0bits.GO_nDONE){};   // Wait for the conversion to finish
    
	return (ADRESH<<8) + ADRESL;
}

void main(void) {

    PORTA = 0x00;           // initialize PORTA
    PORTB = 0x00;           // initialize PORTB
    TRISA = 0b01100000;     // PORTA in/output settings  RA6:limit sensor input, except output  0:output, 1:input => RA5 temporalily input
    TRISB = 0b10111111;     // PORTB in/output settings RB0:NTCH touch sensor input,  RB1:NTD input, RB2:STOP input, RB4:NDO input, RB5:NSD input, RB6:TxD output, RB7:RxD input　 0:output, 1:input
    APFCON1 = 0b00000110;   // RB7=>RxD, RB6=>TxD
    PIE1 = 0b00110000;  //PERIPHERAL INTERRUPT ENABLE REGISTER 1
    OSCCON = 0b01101010;    // Set internal clock to 4MHz
    ANSELB = 0b00000000;    // All digital
    
    FVRCON = 0b00000000;   // Analog outout settings
    DAC1CON0 = 0b10100000;   // Anaog output settings
    DAC1CON1 = 0;   // Analog output settings
    
    WPUB = 0b00111111;  // weak pull up
    OPTION_REG = 0x00;  // weak pull up enable
    
    ADCON0 = 0b00010001;       //ADC CONTROL REGISTER 0　AN4
    ADCON1 = 0b10100011;    // bit7(ADFM)=1(right justified), bit<6:4>=010 Fosc/32=1.0us
                            // bit<1:0>=00 VREF+=FVR
    FVRCON = 0b10000010;    // bit7(FVRON)=1,bit<1:0>=10 ADFVR×2=2.048V
    
    ADRESL = 0x00;  // ADRESL 0; 
    ADRESH = 0x00;  // ADRESH 0; 
//    ADCON0 = 0x01;    // GO_nDONE stop; ADON enabled; CHS AN0; 
    
    initUART();             // 調歩同期式シリアル通信設定

    long LP_ADR = 8; //Laser Power parameter address
    long LW_ADR = 10;  //Laser pulse Width parameter address
    long LT_ADR = 12;  //Laser interval Time parameter address
//    long INTVL_ADR = 8;   //intvl parameter address
//    long NPD_ADR = 10;   //npd parameter address
//    long NIP_ADR = 12;   //nip parameter address
    long INTVL_ADR = 16;   //intvl parameter address
    long NPD_ADR = 18;   //npd parameter address
    long NIP_ADR = 20;   //nip parameter address
    long NDCNT_ADR = 14; //dispensed count

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
    long int ndcnt = 0; // Dispensed count
    int pzt_l = 0;  // pzt displacement %
    double pzt_l_d = 0;  // pzt displacement %
    int pzt_t = 100;  // pzt displacement time ms
    double pzt_d = 0;
    int c_pzt = 0;  // current pzt position (0-255)
    char *ptr;

    enum command cmd; // enum型のオブジェクトを定義

    unsigned int val;
    
    int lp;
    int lw;
    int lt;
    lp = read_data_eeprom(LP_ADR);
    lw = read_data_eeprom(LW_ADR);
    lt = read_data_eeprom(LT_ADR);

    DAC1CON1 = (int)(lp * 255 / 100);
    
    MOD = 0;
    N_NTD = 1;
//    N_NDO = 1;
    N_MSW = 1;
    N_FSW = 1;
    //N_NSC = 1;
    SLCT = 1;
    N_NOS = 1;
    NTCH = 1;
    N_READY = 0;
    
    ndcnt = read_data_eeprom(NDCNT_ADR);
    npd = read_data_eeprom(NPD_ADR);
    nip = read_data_eeprom(NIP_ADR);
    intvl = read_data_eeprom(INTVL_ADR);

    while(1){

       
        cmd = NON;
        
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

//        printf("N_MSW = %d, N_FSW = %d\r\n", N_MSW, N_FSW); // Send

        
        if (N_MSW == 1){   // NOT Setting mode
            if(N_FSW == 0){
                cmd = LPF; // Laser Pulse Fire
            }
        } else {  // Setting mode
            gets(tmp);
        }
 
       
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';

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
        }else if(strcmp(rcmd,"WRP") == 0){
            cmd = WRP;
        }else if(strcmp(rcmd,"RDC") == 0){
            cmd = RDC;
        }else if(strcmp(rcmd,"WDC") == 0){
            cmd = WDC;        
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
        }else if(strcmp(rcmd,"PMV") == 0){
            cmd = PMV;
        }else if(strcmp(rcmd,"PMA") == 0){
            cmd = PMA;
        }else if(strcmp(rcmd,"PMR") == 0){
            cmd = PMR;
        }else if(strcmp(rcmd,"RPP") == 0){
            cmd = RPP;
        }else if(strcmp(rcmd,"WLP") == 0){
            cmd = WLP;
        }else if(strcmp(rcmd,"WLW") == 0){
            cmd = WLW;
        }else if(strcmp(rcmd,"WLT") == 0){
            cmd = WLT;
        }else if(strcmp(rcmd,"RLP") == 0){
            cmd = RLP;
        }else if(strcmp(rcmd,"RLW") == 0){
            cmd = RLW;
        }else if(strcmp(rcmd,"RLT") == 0){
            cmd = RLT;
        }else if(strcmp(rcmd,"LPF") == 0){
            cmd = LPF;
        }else if(strcmp(rcmd,"AIN") == 0){
            cmd = AIN;
        }else if(strcmp(rcmd,"NSD") == 0){
            cmd = NSD;
        }
        ptr = strtok(tmp, "/");

//        N_READY = 1;
  
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
                    printf("C\tRPS\r\n"); // Send
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
                    printf("C\tWTB\t%d\r\n", intvl); // Send

                    break;
 
            case WNI : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        nip = atoi(ptr);
                    }

                    write_data_eeprom(NIP_ADR, nip);
                    printf("C\tWNI\t%d\r\n", nip); // Send
                    
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
                    ndcnt += 1;
                    write_data_eeprom(NDCNT_ADR, ndcnt);
//                    puts("C");
                    printf("C\tOSC\r\n"); // Send
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
                    printf("C\tNOS\t%d\r\n", npos); // Send
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
                           // LEDON = 1;
                            break;
                        }

                    }
//                    puts("C");
                    printf("C\tNTD\r\n"); // Send

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
                          //  LEDON = 1;
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
                    ndcnt += 1;
                    write_data_eeprom(NDCNT_ADR, ndcnt);
//                    LEDON = 0;
//                    puts("C");
                    printf("C\tNDO\r\n"); // Send
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
//                            LEDON = 1;
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
                    
//                    LEDON = 0;
                    ndcnt += 1;
                    write_data_eeprom(NDCNT_ADR, ndcnt);
//                    puts("C");
                    printf("C\tNDD\r\n"); // Send
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
                    printf("C\tNSD\r\n"); // Send
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
                    ndcnt += 1;
                    write_data_eeprom(NDCNT_ADR, ndcnt);
                    printf("C\tNSC\r\n"); // Send
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
                    
            case WRP :
                    npos = 0;
                    printf("C\tWRP3/0\r\n");
                    break;

            case RDC :
                    printf("C\tRDC/%d\r\n", ndcnt);
                    break;

            case WDC :
                    ndcnt = 0;
                    write_data_eeprom(NDCNT_ADR, ndcnt);
                    printf("C\tWDC/%d\r\n", ndcnt);
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

            case PMV : 
                    DAC1CON1 = 0;
                    pzt_d = 0.0;
                    
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        pzt_l = atoi(ptr);
                    }
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        pzt_t = atoi(ptr);
                    }
                    pzt_l_d = 2.55 * pzt_l / pzt_t;
                    
                    for (int k = 0; k < pzt_t ; k++){     
                        __delay_us(100) ;
                        DAC1CON1 = (int)pzt_d;
                        pzt_d = pzt_d + pzt_l_d;
                    }
                    DAC1CON1 = 0;
                    printf("C\tPMV\r\n");                    
                    
                    break;

            case PMA : 
                    
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        pzt_l = atoi(ptr);
                    }
                    c_pzt = (int)(2.55 * pzt_l);
                    DAC1CON1 = c_pzt;
                    printf("C\tPMA\r\n");                    
                    
                    break;

            case PMR : 
                    
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        pzt_l = atoi(ptr);
                    }
                    c_pzt = c_pzt + (int)(2.55 * pzt_l);
                    if(c_pzt < 0){
                        c_pzt = 0;
                    }
                    if(c_pzt > 255){
                        c_pzt = 255;
                    }
                        
                    DAC1CON1 = c_pzt;
                    printf("C\tPMR\r\n");                    
                    
                    break;

            case RPP : 
                    printf("C\tRPP/%d\r\n", c_pzt);                    

                    break;

            case WLP :
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        lp = atoi(ptr);
                    }
                    if(lp > 100){
                        lp = 100;
                    }else if(lp < 0){
                        lp = 0;
                    }
                    write_data_eeprom(LP_ADR, lp);
                    DAC1CON1 = (int)(lp * 255 / 100);

                    printf("C\tWLP/%d\r\n", lp);
                    break;

            case WLW :
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        lw = atoi(ptr);
                    }
                    write_data_eeprom(LW_ADR, lw);
                    printf("C\tWLW/%d\r\n", lw);
                    break;

            case WLT :
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        lt = atoi(ptr);
                    }
                    write_data_eeprom(LT_ADR, lt);
                    printf("C\tWLT/%d\r\n", lt);
                    break;

            case RLP : 
                    printf("C\tRLP/%d\r\n", lp);
                    break;
 
            case RLW : 
                    printf("C\tRLW/%d\r\n", lw);
                    break;
 
            case RLT : 
                    printf("C\tRLT/%d\r\n", lt);
                    break;

            case LPF : 
                    __delay_ms(200) ;
                    DAC1CON1 = (int)(lp * 255 / 100);
                    for (int j = 0; j < 1000 ; j++){     
                        MOD = 1;
                        for (int k = 0; k < lw ; k++){     
                            __delay_us(60) ;
                        }                    
                        MOD = 0;
                        for (int k = 0; k < lt ; k++){     
                            __delay_ms(1) ;
                        }                    
                        if(N_FSW == 1){
                            printf("C\tLPF\r\n");
                            break;
                        }

                    }

                    printf("C\tLPF\r\n");

                    break;

            case AIN : 
                    val = 0;
                    for (int k = 0; k < 10 ; k++){     
                        val = AD_convert(1);
                        printf("C\tAIN = %u\n", val);                    
                        __delay_ms(500) ;
                    }                    
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
//        N_READY = 0;

//        if(NTCH == 0){
//            LEDON = 1;
//        }

    }
}

