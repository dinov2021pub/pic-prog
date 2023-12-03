
# 1 "C:\Program Files\Microchip\xc8\v2.41\pic\sources\c90\pic\__eeprom.c"

# 18 "C:\Program Files\Microchip\xc8\v2.41\pic\include\xc.h"
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);


# 13 "C:\Program Files\Microchip\xc8\v2.41\pic\include\c90\xc8debug.h"
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);

# 13 "C:\Program Files\Microchip\xc8\v2.41\pic\include\c90\stdint.h"
typedef signed char int8_t;

# 20
typedef signed int int16_t;

# 28
typedef __int24 int24_t;

# 36
typedef signed long int int32_t;

# 52
typedef unsigned char uint8_t;

# 58
typedef unsigned int uint16_t;

# 65
typedef __uint24 uint24_t;

# 72
typedef unsigned long int uint32_t;

# 88
typedef signed char int_least8_t;

# 96
typedef signed int int_least16_t;

# 109
typedef __int24 int_least24_t;

# 118
typedef signed long int int_least32_t;

# 136
typedef unsigned char uint_least8_t;

# 143
typedef unsigned int uint_least16_t;

# 154
typedef __uint24 uint_least24_t;

# 162
typedef unsigned long int uint_least32_t;

# 181
typedef signed char int_fast8_t;

# 188
typedef signed int int_fast16_t;

# 200
typedef __int24 int_fast24_t;

# 208
typedef signed long int int_fast32_t;

# 224
typedef unsigned char uint_fast8_t;

# 230
typedef unsigned int uint_fast16_t;

# 240
typedef __uint24 uint_fast24_t;

# 247
typedef unsigned long int uint_fast32_t;

# 268
typedef int32_t intmax_t;

# 282
typedef uint32_t uintmax_t;

# 289
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;


# 7 "C:\Program Files\Microchip\xc8\v2.41\pic\include\builtins.h"
#pragma intrinsic(__nop)
extern void __nop(void);


#pragma intrinsic(_delay)
extern __nonreentrant void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __nonreentrant void _delaywdt(uint32_t);

#pragma intrinsic(_delay3)
extern __nonreentrant void _delay3(uint8_t);

# 52 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC12-16F1xxx_DFP/1.6.241/xc8\pic\include\proc\pic16f1788.h"
extern volatile unsigned char INDF0 __at(0x000);

asm("INDF0 equ 00h");


typedef union {
struct {
unsigned INDF0 :8;
};
} INDF0bits_t;
extern volatile INDF0bits_t INDF0bits __at(0x000);

# 72
extern volatile unsigned char INDF1 __at(0x001);

asm("INDF1 equ 01h");


typedef union {
struct {
unsigned INDF1 :8;
};
} INDF1bits_t;
extern volatile INDF1bits_t INDF1bits __at(0x001);

# 92
extern volatile unsigned char PCL __at(0x002);

asm("PCL equ 02h");


typedef union {
struct {
unsigned PCL :8;
};
} PCLbits_t;
extern volatile PCLbits_t PCLbits __at(0x002);

# 112
extern volatile unsigned char STATUS __at(0x003);

asm("STATUS equ 03h");


typedef union {
struct {
unsigned C :1;
unsigned DC :1;
unsigned Z :1;
unsigned nPD :1;
unsigned nTO :1;
};
struct {
unsigned CARRY :1;
unsigned :1;
unsigned ZERO :1;
};
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __at(0x003);

# 171
extern volatile unsigned short FSR0 __at(0x004);



extern volatile unsigned char FSR0L __at(0x004);

asm("FSR0L equ 04h");


typedef union {
struct {
unsigned FSR0L :8;
};
} FSR0Lbits_t;
extern volatile FSR0Lbits_t FSR0Lbits __at(0x004);

# 195
extern volatile unsigned char FSR0H __at(0x005);

asm("FSR0H equ 05h");


typedef union {
struct {
unsigned FSR0H :8;
};
} FSR0Hbits_t;
extern volatile FSR0Hbits_t FSR0Hbits __at(0x005);

# 215
extern volatile unsigned short FSR1 __at(0x006);



extern volatile unsigned char FSR1L __at(0x006);

asm("FSR1L equ 06h");


typedef union {
struct {
unsigned FSR1L :8;
};
} FSR1Lbits_t;
extern volatile FSR1Lbits_t FSR1Lbits __at(0x006);

# 239
extern volatile unsigned char FSR1H __at(0x007);

asm("FSR1H equ 07h");


typedef union {
struct {
unsigned FSR1H :8;
};
} FSR1Hbits_t;
extern volatile FSR1Hbits_t FSR1Hbits __at(0x007);

# 259
extern volatile unsigned char BSR __at(0x008);

asm("BSR equ 08h");


typedef union {
struct {
unsigned BSR0 :1;
unsigned BSR1 :1;
unsigned BSR2 :1;
unsigned BSR3 :1;
unsigned BSR4 :1;
};
struct {
unsigned BSR :5;
};
} BSRbits_t;
extern volatile BSRbits_t BSRbits __at(0x008);

# 311
extern volatile unsigned char WREG __at(0x009);

asm("WREG equ 09h");


typedef union {
struct {
unsigned WREG0 :8;
};
} WREGbits_t;
extern volatile WREGbits_t WREGbits __at(0x009);

# 331
extern volatile unsigned char PCLATH __at(0x00A);

asm("PCLATH equ 0Ah");


typedef union {
struct {
unsigned PCLATH :7;
};
} PCLATHbits_t;
extern volatile PCLATHbits_t PCLATHbits __at(0x00A);

# 351
extern volatile unsigned char INTCON __at(0x00B);

asm("INTCON equ 0Bh");


typedef union {
struct {
unsigned IOCIF :1;
unsigned INTF :1;
unsigned TMR0IF :1;
unsigned IOCIE :1;
unsigned INTE :1;
unsigned TMR0IE :1;
unsigned PEIE :1;
unsigned GIE :1;
};
struct {
unsigned :2;
unsigned T0IF :1;
unsigned :2;
unsigned T0IE :1;
};
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __at(0x00B);

# 429
extern volatile unsigned char PORTA __at(0x00C);

asm("PORTA equ 0Ch");


typedef union {
struct {
unsigned RA0 :1;
unsigned RA1 :1;
unsigned RA2 :1;
unsigned RA3 :1;
unsigned RA4 :1;
unsigned RA5 :1;
unsigned RA6 :1;
unsigned RA7 :1;
};
struct {
unsigned PORTA :8;
};
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __at(0x00C);

# 499
extern volatile unsigned char PORTB __at(0x00D);

asm("PORTB equ 0Dh");


typedef union {
struct {
unsigned RB0 :1;
unsigned RB1 :1;
unsigned RB2 :1;
unsigned RB3 :1;
unsigned RB4 :1;
unsigned RB5 :1;
unsigned RB6 :1;
unsigned RB7 :1;
};
struct {
unsigned PORTB :8;
};
} PORTBbits_t;
extern volatile PORTBbits_t PORTBbits __at(0x00D);

# 569
extern volatile unsigned char PORTC __at(0x00E);

asm("PORTC equ 0Eh");


typedef union {
struct {
unsigned RC0 :1;
unsigned RC1 :1;
unsigned RC2 :1;
unsigned RC3 :1;
unsigned RC4 :1;
unsigned RC5 :1;
unsigned RC6 :1;
unsigned RC7 :1;
};
struct {
unsigned PORTC :8;
};
} PORTCbits_t;
extern volatile PORTCbits_t PORTCbits __at(0x00E);

# 639
extern volatile unsigned char PORTE __at(0x010);

asm("PORTE equ 010h");


typedef union {
struct {
unsigned :3;
unsigned RE3 :1;
};
struct {
unsigned PORTE :8;
};
} PORTEbits_t;
extern volatile PORTEbits_t PORTEbits __at(0x010);

# 668
extern volatile unsigned char PIR1 __at(0x011);

asm("PIR1 equ 011h");


typedef union {
struct {
unsigned TMR1IF :1;
unsigned TMR2IF :1;
unsigned CCP1IF :1;
unsigned SSP1IF :1;
unsigned TXIF :1;
unsigned RCIF :1;
unsigned ADIF :1;
unsigned TMR1GIF :1;
};
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __at(0x011);

# 730
extern volatile unsigned char PIR2 __at(0x012);

asm("PIR2 equ 012h");


typedef union {
struct {
unsigned CCP2IF :1;
unsigned C3IF :1;
unsigned C4IF :1;
unsigned BCL1IF :1;
unsigned EEIF :1;
unsigned C1IF :1;
unsigned C2IF :1;
unsigned OSFIF :1;
};
} PIR2bits_t;
extern volatile PIR2bits_t PIR2bits __at(0x012);

# 792
extern volatile unsigned char PIR3 __at(0x013);

asm("PIR3 equ 013h");


typedef union {
struct {
unsigned :4;
unsigned CCP3IF :1;
};
} PIR3bits_t;
extern volatile PIR3bits_t PIR3bits __at(0x013);

# 813
extern volatile unsigned char PIR4 __at(0x014);

asm("PIR4 equ 014h");


typedef union {
struct {
unsigned PSMC1SIF :1;
unsigned PSMC2SIF :1;
unsigned PSMC3SIF :1;
unsigned PSMC4SIF :1;
unsigned PSMC1TIF :1;
unsigned PSMC2TIF :1;
unsigned PSMC3TIF :1;
unsigned PSMC4TIF :1;
};
} PIR4bits_t;
extern volatile PIR4bits_t PIR4bits __at(0x014);

# 875
extern volatile unsigned char TMR0 __at(0x015);

asm("TMR0 equ 015h");


typedef union {
struct {
unsigned TMR0 :8;
};
} TMR0bits_t;
extern volatile TMR0bits_t TMR0bits __at(0x015);

# 895
extern volatile unsigned short TMR1 __at(0x016);

asm("TMR1 equ 016h");




extern volatile unsigned char TMR1L __at(0x016);

asm("TMR1L equ 016h");


typedef union {
struct {
unsigned TMR1L :8;
};
} TMR1Lbits_t;
extern volatile TMR1Lbits_t TMR1Lbits __at(0x016);

# 922
extern volatile unsigned char TMR1H __at(0x017);

asm("TMR1H equ 017h");


typedef union {
struct {
unsigned TMR1H :8;
};
} TMR1Hbits_t;
extern volatile TMR1Hbits_t TMR1Hbits __at(0x017);

# 942
extern volatile unsigned char T1CON __at(0x018);

asm("T1CON equ 018h");


typedef union {
struct {
unsigned TMR1ON :1;
unsigned :1;
unsigned nT1SYNC :1;
unsigned T1OSCEN :1;
unsigned T1CKPS0 :1;
unsigned T1CKPS1 :1;
unsigned TMR1CS0 :1;
unsigned TMR1CS1 :1;
};
struct {
unsigned :4;
unsigned T1CKPS :2;
unsigned TMR1CS :2;
};
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __at(0x018);

# 1014
extern volatile unsigned char T1GCON __at(0x019);

asm("T1GCON equ 019h");


typedef union {
struct {
unsigned T1GSS0 :1;
unsigned T1GSS1 :1;
unsigned T1GVAL :1;
unsigned T1GGO :1;
unsigned T1GSPM :1;
unsigned T1GTM :1;
unsigned T1GPOL :1;
unsigned TMR1GE :1;
};
struct {
unsigned T1GSS :2;
};
} T1GCONbits_t;
extern volatile T1GCONbits_t T1GCONbits __at(0x019);

# 1084
extern volatile unsigned char TMR2 __at(0x01A);

asm("TMR2 equ 01Ah");


typedef union {
struct {
unsigned TMR2 :8;
};
} TMR2bits_t;
extern volatile TMR2bits_t TMR2bits __at(0x01A);

# 1104
extern volatile unsigned char PR2 __at(0x01B);

asm("PR2 equ 01Bh");


typedef union {
struct {
unsigned PR2 :8;
};
} PR2bits_t;
extern volatile PR2bits_t PR2bits __at(0x01B);

# 1124
extern volatile unsigned char T2CON __at(0x01C);

asm("T2CON equ 01Ch");


typedef union {
struct {
unsigned T2CKPS0 :1;
unsigned T2CKPS1 :1;
unsigned TMR2ON :1;
unsigned T2OUTPS0 :1;
unsigned T2OUTPS1 :1;
unsigned T2OUTPS2 :1;
unsigned T2OUTPS3 :1;
};
struct {
unsigned T2CKPS :2;
unsigned :1;
unsigned T2OUTPS :4;
};
} T2CONbits_t;
extern volatile T2CONbits_t T2CONbits __at(0x01C);

# 1195
extern volatile unsigned char TRISA __at(0x08C);

asm("TRISA equ 08Ch");


typedef union {
struct {
unsigned TRISA0 :1;
unsigned TRISA1 :1;
unsigned TRISA2 :1;
unsigned TRISA3 :1;
unsigned TRISA4 :1;
unsigned TRISA5 :1;
unsigned TRISA6 :1;
unsigned TRISA7 :1;
};
struct {
unsigned TRISA :8;
};
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __at(0x08C);

# 1265
extern volatile unsigned char TRISB __at(0x08D);

asm("TRISB equ 08Dh");


typedef union {
struct {
unsigned TRISB0 :1;
unsigned TRISB1 :1;
unsigned TRISB2 :1;
unsigned TRISB3 :1;
unsigned TRISB4 :1;
unsigned TRISB5 :1;
unsigned TRISB6 :1;
unsigned TRISB7 :1;
};
struct {
unsigned TRISB :8;
};
} TRISBbits_t;
extern volatile TRISBbits_t TRISBbits __at(0x08D);

# 1335
extern volatile unsigned char TRISC __at(0x08E);

asm("TRISC equ 08Eh");


typedef union {
struct {
unsigned TRISC0 :1;
unsigned TRISC1 :1;
unsigned TRISC2 :1;
unsigned TRISC3 :1;
unsigned TRISC4 :1;
unsigned TRISC5 :1;
unsigned TRISC6 :1;
unsigned TRISC7 :1;
};
struct {
unsigned TRISC :8;
};
} TRISCbits_t;
extern volatile TRISCbits_t TRISCbits __at(0x08E);

# 1405
extern volatile unsigned char TRISE __at(0x090);

asm("TRISE equ 090h");


typedef union {
struct {
unsigned :3;
unsigned TRISE3 :1;
};
struct {
unsigned TRISE :8;
};
} TRISEbits_t;
extern volatile TRISEbits_t TRISEbits __at(0x090);

# 1434
extern volatile unsigned char PIE1 __at(0x091);

asm("PIE1 equ 091h");


typedef union {
struct {
unsigned TMR1IE :1;
unsigned TMR2IE :1;
unsigned CCP1IE :1;
unsigned SSP1IE :1;
unsigned TXIE :1;
unsigned RCIE :1;
unsigned ADIE :1;
unsigned TMR1GIE :1;
};
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __at(0x091);

# 1496
extern volatile unsigned char PIE2 __at(0x092);

asm("PIE2 equ 092h");


typedef union {
struct {
unsigned CCP2IE :1;
unsigned C3IE :1;
unsigned C4IE :1;
unsigned BCL1IE :1;
unsigned EEIE :1;
unsigned C1IE :1;
unsigned C2IE :1;
unsigned OSFIE :1;
};
} PIE2bits_t;
extern volatile PIE2bits_t PIE2bits __at(0x092);

# 1558
extern volatile unsigned char PIE3 __at(0x093);

asm("PIE3 equ 093h");


typedef union {
struct {
unsigned :4;
unsigned CCP3IE :1;
};
} PIE3bits_t;
extern volatile PIE3bits_t PIE3bits __at(0x093);

# 1579
extern volatile unsigned char PIE4 __at(0x094);

asm("PIE4 equ 094h");


typedef union {
struct {
unsigned PSMC1SIE :1;
unsigned PSMC2SIE :1;
unsigned PSMC3SIE :1;
unsigned PSMC4SIE :1;
unsigned PSMC1TIE :1;
unsigned PSMC2TIE :1;
unsigned PSMC3TIE :1;
unsigned PSMC4TIE :1;
};
struct {
unsigned :6;
unsigned PMSC3TIE :1;
};
} PIE4bits_t;
extern volatile PIE4bits_t PIE4bits __at(0x094);

# 1650
extern volatile unsigned char OPTION_REG __at(0x095);

asm("OPTION_REG equ 095h");


typedef union {
struct {
unsigned PS0 :1;
unsigned PS1 :1;
unsigned PS2 :1;
unsigned PSA :1;
unsigned TMR0SE :1;
unsigned TMR0CS :1;
unsigned INTEDG :1;
unsigned nWPUEN :1;
};
struct {
unsigned PS :3;
unsigned :1;
unsigned T0SE :1;
unsigned T0CS :1;
};
} OPTION_REGbits_t;
extern volatile OPTION_REGbits_t OPTION_REGbits __at(0x095);

# 1733
extern volatile unsigned char PCON __at(0x096);

asm("PCON equ 096h");


typedef union {
struct {
unsigned nBOR :1;
unsigned nPOR :1;
unsigned nRI :1;
unsigned nRMCLR :1;
unsigned nRWDT :1;
unsigned :1;
unsigned STKUNF :1;
unsigned STKOVF :1;
};
} PCONbits_t;
extern volatile PCONbits_t PCONbits __at(0x096);

# 1790
extern volatile unsigned char WDTCON __at(0x097);

asm("WDTCON equ 097h");


typedef union {
struct {
unsigned SWDTEN :1;
unsigned WDTPS0 :1;
unsigned WDTPS1 :1;
unsigned WDTPS2 :1;
unsigned WDTPS3 :1;
unsigned WDTPS4 :1;
};
struct {
unsigned :1;
unsigned WDTPS :5;
};
} WDTCONbits_t;
extern volatile WDTCONbits_t WDTCONbits __at(0x097);

# 1849
extern volatile unsigned char OSCTUNE __at(0x098);

asm("OSCTUNE equ 098h");


typedef union {
struct {
unsigned TUN0 :1;
unsigned TUN1 :1;
unsigned TUN2 :1;
unsigned TUN3 :1;
unsigned TUN4 :1;
unsigned TUN5 :1;
};
struct {
unsigned TUN :6;
};
} OSCTUNEbits_t;
extern volatile OSCTUNEbits_t OSCTUNEbits __at(0x098);

# 1907
extern volatile unsigned char OSCCON __at(0x099);

asm("OSCCON equ 099h");


typedef union {
struct {
unsigned SCS0 :1;
unsigned SCS1 :1;
unsigned :1;
unsigned IRCF0 :1;
unsigned IRCF1 :1;
unsigned IRCF2 :1;
unsigned IRCF3 :1;
unsigned SPLLEN :1;
};
struct {
unsigned SCS :2;
unsigned :1;
unsigned IRCF :4;
};
} OSCCONbits_t;
extern volatile OSCCONbits_t OSCCONbits __at(0x099);

# 1979
extern volatile unsigned char OSCSTAT __at(0x09A);

asm("OSCSTAT equ 09Ah");


typedef union {
struct {
unsigned HFIOFS :1;
unsigned LFIOFR :1;
unsigned MFIOFR :1;
unsigned HFIOFL :1;
unsigned HFIOFR :1;
unsigned OSTS :1;
unsigned PLLR :1;
unsigned T1OSCR :1;
};
} OSCSTATbits_t;
extern volatile OSCSTATbits_t OSCSTATbits __at(0x09A);

# 2041
extern volatile unsigned short ADRES __at(0x09B);

asm("ADRES equ 09Bh");




extern volatile unsigned char ADRESL __at(0x09B);

asm("ADRESL equ 09Bh");


typedef union {
struct {
unsigned ADRESL :8;
};
} ADRESLbits_t;
extern volatile ADRESLbits_t ADRESLbits __at(0x09B);

# 2068
extern volatile unsigned char ADRESH __at(0x09C);

asm("ADRESH equ 09Ch");


typedef union {
struct {
unsigned ADRESH :8;
};
} ADRESHbits_t;
extern volatile ADRESHbits_t ADRESHbits __at(0x09C);

# 2088
extern volatile unsigned char ADCON0 __at(0x09D);

asm("ADCON0 equ 09Dh");


typedef union {
struct {
unsigned ADON :1;
unsigned GO_nDONE :1;
unsigned CHS0 :1;
unsigned CHS1 :1;
unsigned CHS2 :1;
unsigned CHS3 :1;
unsigned CHS4 :1;
unsigned ADRMD :1;
};
struct {
unsigned :1;
unsigned ADGO :1;
unsigned CHS :5;
};
struct {
unsigned :1;
unsigned GO :1;
};
struct {
unsigned :1;
unsigned DONE :1;
};
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __at(0x09D);

# 2183
extern volatile unsigned char ADCON1 __at(0x09E);

asm("ADCON1 equ 09Eh");


typedef union {
struct {
unsigned ADPREF0 :1;
unsigned ADPREF1 :1;
unsigned ADNREF :1;
unsigned :1;
unsigned ADCS0 :1;
unsigned ADCS1 :1;
unsigned ADCS2 :1;
unsigned ADFM :1;
};
struct {
unsigned ADPREF :2;
unsigned :2;
unsigned ADCS :3;
};
} ADCON1bits_t;
extern volatile ADCON1bits_t ADCON1bits __at(0x09E);

# 2255
extern volatile unsigned char ADCON2 __at(0x09F);

asm("ADCON2 equ 09Fh");


typedef union {
struct {
unsigned CHSN0 :1;
unsigned CHSN1 :1;
unsigned CHSN2 :1;
unsigned CHSN3 :1;
unsigned TRIGSEL0 :1;
unsigned TRIGSEL1 :1;
unsigned TRIGSEL2 :1;
unsigned TRIGSEL3 :1;
};
struct {
unsigned CHSN :4;
unsigned TRIGSEL :4;
};
} ADCON2bits_t;
extern volatile ADCON2bits_t ADCON2bits __at(0x09F);

# 2331
extern volatile unsigned char LATA __at(0x10C);

asm("LATA equ 010Ch");


typedef union {
struct {
unsigned LATA0 :1;
unsigned LATA1 :1;
unsigned LATA2 :1;
unsigned LATA3 :1;
unsigned LATA4 :1;
unsigned LATA5 :1;
unsigned LATA6 :1;
unsigned LATA7 :1;
};
struct {
unsigned LATA :8;
};
} LATAbits_t;
extern volatile LATAbits_t LATAbits __at(0x10C);

# 2401
extern volatile unsigned char LATB __at(0x10D);

asm("LATB equ 010Dh");


typedef union {
struct {
unsigned LATB0 :1;
unsigned LATB1 :1;
unsigned LATB2 :1;
unsigned LATB3 :1;
unsigned LATB4 :1;
unsigned LATB5 :1;
unsigned LATB6 :1;
unsigned LATB7 :1;
};
struct {
unsigned LATB :8;
};
} LATBbits_t;
extern volatile LATBbits_t LATBbits __at(0x10D);

# 2471
extern volatile unsigned char LATC __at(0x10E);

asm("LATC equ 010Eh");


typedef union {
struct {
unsigned LATC0 :1;
unsigned LATC1 :1;
unsigned LATC2 :1;
unsigned LATC3 :1;
unsigned LATC4 :1;
unsigned LATC5 :1;
unsigned LATC6 :1;
unsigned LATC7 :1;
};
struct {
unsigned LATC :8;
};
} LATCbits_t;
extern volatile LATCbits_t LATCbits __at(0x10E);

# 2541
extern volatile unsigned char CM1CON0 __at(0x111);

asm("CM1CON0 equ 0111h");


typedef union {
struct {
unsigned C1SYNC :1;
unsigned C1HYS :1;
unsigned C1SP :1;
unsigned C1ZLF :1;
unsigned C1POL :1;
unsigned C1OE :1;
unsigned C1OUT :1;
unsigned C1ON :1;
};
} CM1CON0bits_t;
extern volatile CM1CON0bits_t CM1CON0bits __at(0x111);

# 2603
extern volatile unsigned char CM1CON1 __at(0x112);

asm("CM1CON1 equ 0112h");


typedef union {
struct {
unsigned C1NCH :3;
unsigned C1PCH :3;
unsigned C1INTN :1;
unsigned C1INTP :1;
};
struct {
unsigned C1NCH0 :1;
unsigned C1NCH1 :1;
unsigned C1NCH2 :1;
unsigned C1PCH0 :1;
unsigned C1PCH1 :1;
unsigned C1PCH2 :1;
};
} CM1CON1bits_t;
extern volatile CM1CON1bits_t CM1CON1bits __at(0x112);

# 2679
extern volatile unsigned char CM2CON0 __at(0x113);

asm("CM2CON0 equ 0113h");


typedef union {
struct {
unsigned C2SYNC :1;
unsigned C2HYS :1;
unsigned C2SP :1;
unsigned C2ZLF :1;
unsigned C2POL :1;
unsigned C2OE :1;
unsigned C2OUT :1;
unsigned C2ON :1;
};
} CM2CON0bits_t;
extern volatile CM2CON0bits_t CM2CON0bits __at(0x113);

# 2741
extern volatile unsigned char CM2CON1 __at(0x114);

asm("CM2CON1 equ 0114h");


typedef union {
struct {
unsigned C2NCH :3;
unsigned C2PCH :3;
unsigned C2INTN :1;
unsigned C2INTP :1;
};
struct {
unsigned C2NCH0 :1;
unsigned C2NCH1 :1;
unsigned C2NCH2 :1;
unsigned C2PCH0 :1;
unsigned C2PCH1 :1;
unsigned C2PCH2 :1;
};
} CM2CON1bits_t;
extern volatile CM2CON1bits_t CM2CON1bits __at(0x114);

# 2817
extern volatile unsigned char CMOUT __at(0x115);

asm("CMOUT equ 0115h");


typedef union {
struct {
unsigned MC1OUT :1;
unsigned MC2OUT :1;
unsigned MC3OUT :1;
unsigned MC4OUT :1;
};
} CMOUTbits_t;
extern volatile CMOUTbits_t CMOUTbits __at(0x115);

# 2855
extern volatile unsigned char BORCON __at(0x116);

asm("BORCON equ 0116h");


typedef union {
struct {
unsigned BORRDY :1;
unsigned :5;
unsigned BORFS :1;
unsigned SBOREN :1;
};
} BORCONbits_t;
extern volatile BORCONbits_t BORCONbits __at(0x116);

# 2888
extern volatile unsigned char FVRCON __at(0x117);

asm("FVRCON equ 0117h");


typedef union {
struct {
unsigned ADFVR0 :1;
unsigned ADFVR1 :1;
unsigned CDAFVR0 :1;
unsigned CDAFVR1 :1;
unsigned TSRNG :1;
unsigned TSEN :1;
unsigned FVRRDY :1;
unsigned FVREN :1;
};
struct {
unsigned ADFVR :2;
unsigned CDAFVR :2;
};
} FVRCONbits_t;
extern volatile FVRCONbits_t FVRCONbits __at(0x117);

# 2964
extern volatile unsigned char DAC1CON0 __at(0x118);

asm("DAC1CON0 equ 0118h");


typedef union {
struct {
unsigned DAC1NSS :1;
unsigned :1;
unsigned DAC1PSS :2;
unsigned DAC1OE2 :1;
unsigned DAC1OE1 :1;
unsigned :1;
unsigned DAC1EN :1;
};
struct {
unsigned :2;
unsigned DAC1PSS0 :1;
unsigned DAC1PSS1 :1;
};
struct {
unsigned DACNSS :1;
unsigned :1;
unsigned DACPSS :2;
unsigned DACOE0 :1;
unsigned DACOE1 :1;
unsigned :1;
unsigned DACEN :1;
};
struct {
unsigned :2;
unsigned DACPSS0 :1;
unsigned DACPSS1 :1;
};
} DAC1CON0bits_t;
extern volatile DAC1CON0bits_t DAC1CON0bits __at(0x118);

# 3074
extern volatile unsigned char DAC1CON1 __at(0x119);

asm("DAC1CON1 equ 0119h");


typedef union {
struct {
unsigned DAC1R :8;
};
struct {
unsigned DAC1R0 :1;
unsigned DAC1R1 :1;
unsigned DAC1R2 :1;
unsigned DAC1R3 :1;
unsigned DAC1R4 :1;
unsigned DAC1R5 :1;
unsigned DAC1R6 :1;
unsigned DAC1R7 :1;
};
struct {
unsigned DACR0 :1;
unsigned DACR1 :1;
unsigned DACR2 :1;
unsigned DACR3 :1;
unsigned DACR4 :1;
unsigned DACR5 :1;
unsigned DACR6 :1;
unsigned DACR7 :1;
};
} DAC1CON1bits_t;
extern volatile DAC1CON1bits_t DAC1CON1bits __at(0x119);

# 3194
extern volatile unsigned char CM4CON0 __at(0x11A);

asm("CM4CON0 equ 011Ah");


typedef union {
struct {
unsigned C4SYNC :1;
unsigned C4HYS :1;
unsigned C4SP :1;
unsigned C4ZLF :1;
unsigned C4POL :1;
unsigned C4OE :1;
unsigned C4OUT :1;
unsigned C4ON :1;
};
} CM4CON0bits_t;
extern volatile CM4CON0bits_t CM4CON0bits __at(0x11A);

# 3256
extern volatile unsigned char CM4CON1 __at(0x11B);

asm("CM4CON1 equ 011Bh");


typedef union {
struct {
unsigned C4NCH :3;
unsigned C4PCH :3;
unsigned C4INTN :1;
unsigned C4INTP :1;
};
struct {
unsigned C4NCH0 :1;
unsigned C4NCH1 :1;
unsigned C4NCH2 :1;
unsigned C4PCH0 :1;
unsigned C4PCH1 :1;
unsigned C4PCH2 :1;
};
} CM4CON1bits_t;
extern volatile CM4CON1bits_t CM4CON1bits __at(0x11B);

# 3332
extern volatile unsigned char APFCON2 __at(0x11C);

asm("APFCON2 equ 011Ch");


typedef union {
struct {
unsigned CCP3SEL :1;
unsigned SSSEL :2;
};
} APFCON2bits_t;
extern volatile APFCON2bits_t APFCON2bits __at(0x11C);

# 3358
extern volatile unsigned char APFCON1 __at(0x11D);

asm("APFCON1 equ 011Dh");


extern volatile unsigned char APFCON0 __at(0x11D);

asm("APFCON0 equ 011Dh");

extern volatile unsigned char APFCON __at(0x11D);

asm("APFCON equ 011Dh");


typedef union {
struct {
unsigned CCP2SEL :1;
unsigned RXSEL :1;
unsigned TXSEL :1;
unsigned SDISEL :1;
unsigned SCKSEL :1;
unsigned SDOSEL :1;
unsigned CCP1SEL :1;
unsigned C2OUTSEL :1;
};
} APFCON1bits_t;
extern volatile APFCON1bits_t APFCON1bits __at(0x11D);

# 3427
typedef union {
struct {
unsigned CCP2SEL :1;
unsigned RXSEL :1;
unsigned TXSEL :1;
unsigned SDISEL :1;
unsigned SCKSEL :1;
unsigned SDOSEL :1;
unsigned CCP1SEL :1;
unsigned C2OUTSEL :1;
};
} APFCON0bits_t;
extern volatile APFCON0bits_t APFCON0bits __at(0x11D);

# 3481
typedef union {
struct {
unsigned CCP2SEL :1;
unsigned RXSEL :1;
unsigned TXSEL :1;
unsigned SDISEL :1;
unsigned SCKSEL :1;
unsigned SDOSEL :1;
unsigned CCP1SEL :1;
unsigned C2OUTSEL :1;
};
} APFCONbits_t;
extern volatile APFCONbits_t APFCONbits __at(0x11D);

# 3538
extern volatile unsigned char CM3CON0 __at(0x11E);

asm("CM3CON0 equ 011Eh");


typedef union {
struct {
unsigned C3SYNC :1;
unsigned C3HYS :1;
unsigned C3SP :1;
unsigned C3ZLF :1;
unsigned C3POL :1;
unsigned C3OE :1;
unsigned C3OUT :1;
unsigned C3ON :1;
};
} CM3CON0bits_t;
extern volatile CM3CON0bits_t CM3CON0bits __at(0x11E);

# 3600
extern volatile unsigned char CM3CON1 __at(0x11F);

asm("CM3CON1 equ 011Fh");


typedef union {
struct {
unsigned C3NCH :3;
unsigned C3PCH :3;
unsigned C3INTN :1;
unsigned C3INTP :1;
};
struct {
unsigned C3NCH0 :1;
unsigned C3NCH1 :1;
unsigned C3NCH2 :1;
unsigned C3PCH0 :1;
unsigned C3PCH1 :1;
unsigned C3PCH2 :1;
};
} CM3CON1bits_t;
extern volatile CM3CON1bits_t CM3CON1bits __at(0x11F);

# 3676
extern volatile unsigned char ANSELA __at(0x18C);

asm("ANSELA equ 018Ch");


typedef union {
struct {
unsigned ANSA0 :1;
unsigned ANSA1 :1;
unsigned ANSA2 :1;
unsigned ANSA3 :1;
unsigned ANSA4 :1;
unsigned ANSA5 :1;
unsigned :1;
unsigned ANSA7 :1;
};
struct {
unsigned ANSELA :8;
};
} ANSELAbits_t;
extern volatile ANSELAbits_t ANSELAbits __at(0x18C);

# 3741
extern volatile unsigned char ANSELB __at(0x18D);

asm("ANSELB equ 018Dh");


typedef union {
struct {
unsigned ANSB0 :1;
unsigned ANSB1 :1;
unsigned ANSB2 :1;
unsigned ANSB3 :1;
unsigned ANSB4 :1;
unsigned ANSB5 :1;
unsigned ANSB6 :1;
};
struct {
unsigned ANSELB :6;
};
} ANSELBbits_t;
extern volatile ANSELBbits_t ANSELBbits __at(0x18D);

# 3805
extern volatile unsigned char ANSELC __at(0x18E);

asm("ANSELC equ 018Eh");


typedef union {
struct {
unsigned ANSC0 :1;
unsigned ANSC1 :1;
unsigned ANSC2 :1;
unsigned ANSC3 :1;
unsigned ANSC4 :1;
unsigned ANSC5 :1;
unsigned ANSC6 :1;
unsigned ANSC7 :1;
};
} ANSELCbits_t;
extern volatile ANSELCbits_t ANSELCbits __at(0x18E);

# 3867
extern volatile unsigned short EEADR __at(0x191);

asm("EEADR equ 0191h");




extern volatile unsigned char EEADRL __at(0x191);

asm("EEADRL equ 0191h");


typedef union {
struct {
unsigned EEADRL :8;
};
} EEADRLbits_t;
extern volatile EEADRLbits_t EEADRLbits __at(0x191);

# 3894
extern volatile unsigned char EEADRH __at(0x192);

asm("EEADRH equ 0192h");


typedef union {
struct {
unsigned EEADRH :7;
};
} EEADRHbits_t;
extern volatile EEADRHbits_t EEADRHbits __at(0x192);

# 3914
extern volatile unsigned short EEDAT __at(0x193);

asm("EEDAT equ 0193h");




extern volatile unsigned char EEDATL __at(0x193);

asm("EEDATL equ 0193h");


extern volatile unsigned char EEDATA __at(0x193);

asm("EEDATA equ 0193h");


typedef union {
struct {
unsigned EEDATL :8;
};
} EEDATLbits_t;
extern volatile EEDATLbits_t EEDATLbits __at(0x193);

# 3944
typedef union {
struct {
unsigned EEDATL :8;
};
} EEDATAbits_t;
extern volatile EEDATAbits_t EEDATAbits __at(0x193);

# 3959
extern volatile unsigned char EEDATH __at(0x194);

asm("EEDATH equ 0194h");


typedef union {
struct {
unsigned EEDATH :6;
};
} EEDATHbits_t;
extern volatile EEDATHbits_t EEDATHbits __at(0x194);

# 3979
extern volatile unsigned char EECON1 __at(0x195);

asm("EECON1 equ 0195h");


typedef union {
struct {
unsigned RD :1;
unsigned WR :1;
unsigned WREN :1;
unsigned WRERR :1;
unsigned FREE :1;
unsigned LWLO :1;
unsigned CFGS :1;
unsigned EEPGD :1;
};
} EECON1bits_t;
extern volatile EECON1bits_t EECON1bits __at(0x195);

# 4041
extern volatile unsigned char EECON2 __at(0x196);

asm("EECON2 equ 0196h");


typedef union {
struct {
unsigned EECON2 :8;
};
} EECON2bits_t;
extern volatile EECON2bits_t EECON2bits __at(0x196);

# 4061
extern volatile unsigned char VREGCON __at(0x197);

asm("VREGCON equ 0197h");


typedef union {
struct {
unsigned :1;
unsigned VREGPM :1;
};
} VREGCONbits_t;
extern volatile VREGCONbits_t VREGCONbits __at(0x197);

# 4082
extern volatile unsigned char RC1REG __at(0x199);

asm("RC1REG equ 0199h");


extern volatile unsigned char RCREG __at(0x199);

asm("RCREG equ 0199h");

extern volatile unsigned char RCREG1 __at(0x199);

asm("RCREG1 equ 0199h");


typedef union {
struct {
unsigned RC1REG :8;
};
} RC1REGbits_t;
extern volatile RC1REGbits_t RC1REGbits __at(0x199);

# 4109
typedef union {
struct {
unsigned RC1REG :8;
};
} RCREGbits_t;
extern volatile RCREGbits_t RCREGbits __at(0x199);

# 4121
typedef union {
struct {
unsigned RC1REG :8;
};
} RCREG1bits_t;
extern volatile RCREG1bits_t RCREG1bits __at(0x199);

# 4136
extern volatile unsigned char TX1REG __at(0x19A);

asm("TX1REG equ 019Ah");


extern volatile unsigned char TXREG1 __at(0x19A);

asm("TXREG1 equ 019Ah");

extern volatile unsigned char TXREG __at(0x19A);

asm("TXREG equ 019Ah");


typedef union {
struct {
unsigned TX1REG :8;
};
} TX1REGbits_t;
extern volatile TX1REGbits_t TX1REGbits __at(0x19A);

# 4163
typedef union {
struct {
unsigned TX1REG :8;
};
} TXREG1bits_t;
extern volatile TXREG1bits_t TXREG1bits __at(0x19A);

# 4175
typedef union {
struct {
unsigned TX1REG :8;
};
} TXREGbits_t;
extern volatile TXREGbits_t TXREGbits __at(0x19A);

# 4190
extern volatile unsigned short SP1BRG __at(0x19B);

asm("SP1BRG equ 019Bh");




extern volatile unsigned char SP1BRGL __at(0x19B);

asm("SP1BRGL equ 019Bh");


extern volatile unsigned char SPBRG __at(0x19B);

asm("SPBRG equ 019Bh");

extern volatile unsigned char SPBRG1 __at(0x19B);

asm("SPBRG1 equ 019Bh");

extern volatile unsigned char SPBRGL __at(0x19B);

asm("SPBRGL equ 019Bh");


typedef union {
struct {
unsigned SP1BRGL :8;
};
} SP1BRGLbits_t;
extern volatile SP1BRGLbits_t SP1BRGLbits __at(0x19B);

# 4228
typedef union {
struct {
unsigned SP1BRGL :8;
};
} SPBRGbits_t;
extern volatile SPBRGbits_t SPBRGbits __at(0x19B);

# 4240
typedef union {
struct {
unsigned SP1BRGL :8;
};
} SPBRG1bits_t;
extern volatile SPBRG1bits_t SPBRG1bits __at(0x19B);

# 4252
typedef union {
struct {
unsigned SP1BRGL :8;
};
} SPBRGLbits_t;
extern volatile SPBRGLbits_t SPBRGLbits __at(0x19B);

# 4267
extern volatile unsigned char SP1BRGH __at(0x19C);

asm("SP1BRGH equ 019Ch");


extern volatile unsigned char SPBRGH __at(0x19C);

asm("SPBRGH equ 019Ch");

extern volatile unsigned char SPBRGH1 __at(0x19C);

asm("SPBRGH1 equ 019Ch");


typedef union {
struct {
unsigned SP1BRGH :8;
};
} SP1BRGHbits_t;
extern volatile SP1BRGHbits_t SP1BRGHbits __at(0x19C);

# 4294
typedef union {
struct {
unsigned SP1BRGH :8;
};
} SPBRGHbits_t;
extern volatile SPBRGHbits_t SPBRGHbits __at(0x19C);

# 4306
typedef union {
struct {
unsigned SP1BRGH :8;
};
} SPBRGH1bits_t;
extern volatile SPBRGH1bits_t SPBRGH1bits __at(0x19C);

# 4321
extern volatile unsigned char RC1STA __at(0x19D);

asm("RC1STA equ 019Dh");


extern volatile unsigned char RCSTA1 __at(0x19D);

asm("RCSTA1 equ 019Dh");

extern volatile unsigned char RCSTA __at(0x19D);

asm("RCSTA equ 019Dh");


typedef union {
struct {
unsigned RX9D :1;
unsigned OERR :1;
unsigned FERR :1;
unsigned ADDEN :1;
unsigned CREN :1;
unsigned SREN :1;
unsigned RX9 :1;
unsigned SPEN :1;
};
} RC1STAbits_t;
extern volatile RC1STAbits_t RC1STAbits __at(0x19D);

# 4390
typedef union {
struct {
unsigned RX9D :1;
unsigned OERR :1;
unsigned FERR :1;
unsigned ADDEN :1;
unsigned CREN :1;
unsigned SREN :1;
unsigned RX9 :1;
unsigned SPEN :1;
};
} RCSTA1bits_t;
extern volatile RCSTA1bits_t RCSTA1bits __at(0x19D);

# 4444
typedef union {
struct {
unsigned RX9D :1;
unsigned OERR :1;
unsigned FERR :1;
unsigned ADDEN :1;
unsigned CREN :1;
unsigned SREN :1;
unsigned RX9 :1;
unsigned SPEN :1;
};
} RCSTAbits_t;
extern volatile RCSTAbits_t RCSTAbits __at(0x19D);

# 4501
extern volatile unsigned char TX1STA __at(0x19E);

asm("TX1STA equ 019Eh");


extern volatile unsigned char TXSTA1 __at(0x19E);

asm("TXSTA1 equ 019Eh");

extern volatile unsigned char TXSTA __at(0x19E);

asm("TXSTA equ 019Eh");


typedef union {
struct {
unsigned TX9D :1;
unsigned TRMT :1;
unsigned BRGH :1;
unsigned SENDB :1;
unsigned SYNC :1;
unsigned TXEN :1;
unsigned TX9 :1;
unsigned CSRC :1;
};
} TX1STAbits_t;
extern volatile TX1STAbits_t TX1STAbits __at(0x19E);

# 4570
typedef union {
struct {
unsigned TX9D :1;
unsigned TRMT :1;
unsigned BRGH :1;
unsigned SENDB :1;
unsigned SYNC :1;
unsigned TXEN :1;
unsigned TX9 :1;
unsigned CSRC :1;
};
} TXSTA1bits_t;
extern volatile TXSTA1bits_t TXSTA1bits __at(0x19E);

# 4624
typedef union {
struct {
unsigned TX9D :1;
unsigned TRMT :1;
unsigned BRGH :1;
unsigned SENDB :1;
unsigned SYNC :1;
unsigned TXEN :1;
unsigned TX9 :1;
unsigned CSRC :1;
};
} TXSTAbits_t;
extern volatile TXSTAbits_t TXSTAbits __at(0x19E);

# 4681
extern volatile unsigned char BAUD1CON __at(0x19F);

asm("BAUD1CON equ 019Fh");


extern volatile unsigned char BAUDCON1 __at(0x19F);

asm("BAUDCON1 equ 019Fh");

extern volatile unsigned char BAUDCTL1 __at(0x19F);

asm("BAUDCTL1 equ 019Fh");

extern volatile unsigned char BAUDCON __at(0x19F);

asm("BAUDCON equ 019Fh");

extern volatile unsigned char BAUDCTL __at(0x19F);

asm("BAUDCTL equ 019Fh");


typedef union {
struct {
unsigned ABDEN :1;
unsigned WUE :1;
unsigned :1;
unsigned BRG16 :1;
unsigned SCKP :1;
unsigned :1;
unsigned RCIDL :1;
unsigned ABDOVF :1;
};
} BAUD1CONbits_t;
extern volatile BAUD1CONbits_t BAUD1CONbits __at(0x19F);

# 4748
typedef union {
struct {
unsigned ABDEN :1;
unsigned WUE :1;
unsigned :1;
unsigned BRG16 :1;
unsigned SCKP :1;
unsigned :1;
unsigned RCIDL :1;
unsigned ABDOVF :1;
};
} BAUDCON1bits_t;
extern volatile BAUDCON1bits_t BAUDCON1bits __at(0x19F);

# 4792
typedef union {
struct {
unsigned ABDEN :1;
unsigned WUE :1;
unsigned :1;
unsigned BRG16 :1;
unsigned SCKP :1;
unsigned :1;
unsigned RCIDL :1;
unsigned ABDOVF :1;
};
} BAUDCTL1bits_t;
extern volatile BAUDCTL1bits_t BAUDCTL1bits __at(0x19F);

# 4836
typedef union {
struct {
unsigned ABDEN :1;
unsigned WUE :1;
unsigned :1;
unsigned BRG16 :1;
unsigned SCKP :1;
unsigned :1;
unsigned RCIDL :1;
unsigned ABDOVF :1;
};
} BAUDCONbits_t;
extern volatile BAUDCONbits_t BAUDCONbits __at(0x19F);

# 4880
typedef union {
struct {
unsigned ABDEN :1;
unsigned WUE :1;
unsigned :1;
unsigned BRG16 :1;
unsigned SCKP :1;
unsigned :1;
unsigned RCIDL :1;
unsigned ABDOVF :1;
};
} BAUDCTLbits_t;
extern volatile BAUDCTLbits_t BAUDCTLbits __at(0x19F);

# 4927
extern volatile unsigned char WPUA __at(0x20C);

asm("WPUA equ 020Ch");


typedef union {
struct {
unsigned WPUA0 :1;
unsigned WPUA1 :1;
unsigned WPUA2 :1;
unsigned WPUA3 :1;
unsigned WPUA4 :1;
unsigned WPUA5 :1;
unsigned WPUA6 :1;
unsigned WPUA7 :1;
};
struct {
unsigned WPUA :8;
};
} WPUAbits_t;
extern volatile WPUAbits_t WPUAbits __at(0x20C);

# 4997
extern volatile unsigned char WPUB __at(0x20D);

asm("WPUB equ 020Dh");


typedef union {
struct {
unsigned WPUB0 :1;
unsigned WPUB1 :1;
unsigned WPUB2 :1;
unsigned WPUB3 :1;
unsigned WPUB4 :1;
unsigned WPUB5 :1;
unsigned WPUB6 :1;
unsigned WPUB7 :1;
};
struct {
unsigned WPUB :8;
};
} WPUBbits_t;
extern volatile WPUBbits_t WPUBbits __at(0x20D);

# 5067
extern volatile unsigned char WPUC __at(0x20E);

asm("WPUC equ 020Eh");


typedef union {
struct {
unsigned WPUC0 :1;
unsigned WPUC1 :1;
unsigned WPUC2 :1;
unsigned WPUC3 :1;
unsigned WPUC4 :1;
unsigned WPUC5 :1;
unsigned WPUC6 :1;
unsigned WPUC7 :1;
};
struct {
unsigned WPUC :8;
};
} WPUCbits_t;
extern volatile WPUCbits_t WPUCbits __at(0x20E);

# 5137
extern volatile unsigned char WPUE __at(0x210);

asm("WPUE equ 0210h");


typedef union {
struct {
unsigned :3;
unsigned WPUE3 :1;
};
struct {
unsigned WPUE :8;
};
} WPUEbits_t;
extern volatile WPUEbits_t WPUEbits __at(0x210);

# 5166
extern volatile unsigned char SSP1BUF __at(0x211);

asm("SSP1BUF equ 0211h");


extern volatile unsigned char SSPBUF __at(0x211);

asm("SSPBUF equ 0211h");


typedef union {
struct {
unsigned SSP1BUF0 :1;
unsigned SSP1BUF1 :1;
unsigned SSP1BUF2 :1;
unsigned SSP1BUF3 :1;
unsigned SSP1BUF4 :1;
unsigned SSP1BUF5 :1;
unsigned SSP1BUF6 :1;
unsigned SSP1BUF7 :1;
};
struct {
unsigned BUF :8;
};
struct {
unsigned BUF0 :1;
unsigned BUF1 :1;
unsigned BUF2 :1;
unsigned BUF3 :1;
unsigned BUF4 :1;
unsigned BUF5 :1;
unsigned BUF6 :1;
unsigned BUF7 :1;
};
struct {
unsigned SSP1BUF :8;
};
} SSP1BUFbits_t;
extern volatile SSP1BUFbits_t SSP1BUFbits __at(0x211);

# 5297
typedef union {
struct {
unsigned SSP1BUF0 :1;
unsigned SSP1BUF1 :1;
unsigned SSP1BUF2 :1;
unsigned SSP1BUF3 :1;
unsigned SSP1BUF4 :1;
unsigned SSP1BUF5 :1;
unsigned SSP1BUF6 :1;
unsigned SSP1BUF7 :1;
};
struct {
unsigned BUF :8;
};
struct {
unsigned BUF0 :1;
unsigned BUF1 :1;
unsigned BUF2 :1;
unsigned BUF3 :1;
unsigned BUF4 :1;
unsigned BUF5 :1;
unsigned BUF6 :1;
unsigned BUF7 :1;
};
struct {
unsigned SSP1BUF :8;
};
} SSPBUFbits_t;
extern volatile SSPBUFbits_t SSPBUFbits __at(0x211);

# 5420
extern volatile unsigned char SSP1ADD __at(0x212);

asm("SSP1ADD equ 0212h");


extern volatile unsigned char SSPADD __at(0x212);

asm("SSPADD equ 0212h");


typedef union {
struct {
unsigned SSP1ADD0 :1;
unsigned SSP1ADD1 :1;
unsigned SSP1ADD2 :1;
unsigned SSP1ADD3 :1;
unsigned SSP1ADD4 :1;
unsigned SSP1ADD5 :1;
unsigned SSP1ADD6 :1;
unsigned SSP1ADD7 :1;
};
struct {
unsigned ADD :8;
};
struct {
unsigned ADD0 :1;
unsigned ADD1 :1;
unsigned ADD2 :1;
unsigned ADD3 :1;
unsigned ADD4 :1;
unsigned ADD5 :1;
unsigned ADD6 :1;
unsigned ADD7 :1;
};
struct {
unsigned SSP1ADD :8;
};
} SSP1ADDbits_t;
extern volatile SSP1ADDbits_t SSP1ADDbits __at(0x212);

# 5551
typedef union {
struct {
unsigned SSP1ADD0 :1;
unsigned SSP1ADD1 :1;
unsigned SSP1ADD2 :1;
unsigned SSP1ADD3 :1;
unsigned SSP1ADD4 :1;
unsigned SSP1ADD5 :1;
unsigned SSP1ADD6 :1;
unsigned SSP1ADD7 :1;
};
struct {
unsigned ADD :8;
};
struct {
unsigned ADD0 :1;
unsigned ADD1 :1;
unsigned ADD2 :1;
unsigned ADD3 :1;
unsigned ADD4 :1;
unsigned ADD5 :1;
unsigned ADD6 :1;
unsigned ADD7 :1;
};
struct {
unsigned SSP1ADD :8;
};
} SSPADDbits_t;
extern volatile SSPADDbits_t SSPADDbits __at(0x212);

# 5674
extern volatile unsigned char SSP1MSK __at(0x213);

asm("SSP1MSK equ 0213h");


extern volatile unsigned char SSPMSK __at(0x213);

asm("SSPMSK equ 0213h");


typedef union {
struct {
unsigned SSP1MSK0 :1;
unsigned SSP1MSK1 :1;
unsigned SSP1MSK2 :1;
unsigned SSP1MSK3 :1;
unsigned SSP1MSK4 :1;
unsigned SSP1MSK5 :1;
unsigned SSP1MSK6 :1;
unsigned SSP1MSK7 :1;
};
struct {
unsigned MSK :8;
};
struct {
unsigned MSK0 :1;
unsigned MSK1 :1;
unsigned MSK2 :1;
unsigned MSK3 :1;
unsigned MSK4 :1;
unsigned MSK5 :1;
unsigned MSK6 :1;
unsigned MSK7 :1;
};
struct {
unsigned SSP1MSK :8;
};
} SSP1MSKbits_t;
extern volatile SSP1MSKbits_t SSP1MSKbits __at(0x213);

# 5805
typedef union {
struct {
unsigned SSP1MSK0 :1;
unsigned SSP1MSK1 :1;
unsigned SSP1MSK2 :1;
unsigned SSP1MSK3 :1;
unsigned SSP1MSK4 :1;
unsigned SSP1MSK5 :1;
unsigned SSP1MSK6 :1;
unsigned SSP1MSK7 :1;
};
struct {
unsigned MSK :8;
};
struct {
unsigned MSK0 :1;
unsigned MSK1 :1;
unsigned MSK2 :1;
unsigned MSK3 :1;
unsigned MSK4 :1;
unsigned MSK5 :1;
unsigned MSK6 :1;
unsigned MSK7 :1;
};
struct {
unsigned SSP1MSK :8;
};
} SSPMSKbits_t;
extern volatile SSPMSKbits_t SSPMSKbits __at(0x213);

# 5928
extern volatile unsigned char SSP1STAT __at(0x214);

asm("SSP1STAT equ 0214h");


extern volatile unsigned char SSPSTAT __at(0x214);

asm("SSPSTAT equ 0214h");


typedef union {
struct {
unsigned BF :1;
unsigned UA :1;
unsigned R_nW :1;
unsigned S :1;
unsigned P :1;
unsigned D_nA :1;
unsigned CKE :1;
unsigned SMP :1;
};
} SSP1STATbits_t;
extern volatile SSP1STATbits_t SSP1STATbits __at(0x214);

# 5993
typedef union {
struct {
unsigned BF :1;
unsigned UA :1;
unsigned R_nW :1;
unsigned S :1;
unsigned P :1;
unsigned D_nA :1;
unsigned CKE :1;
unsigned SMP :1;
};
} SSPSTATbits_t;
extern volatile SSPSTATbits_t SSPSTATbits __at(0x214);

# 6050
extern volatile unsigned char SSP1CON1 __at(0x215);

asm("SSP1CON1 equ 0215h");


extern volatile unsigned char SSPCON __at(0x215);

asm("SSPCON equ 0215h");

extern volatile unsigned char SSPCON1 __at(0x215);

asm("SSPCON1 equ 0215h");

extern volatile unsigned char SSP1CON __at(0x215);

asm("SSP1CON equ 0215h");


typedef union {
struct {
unsigned SSPM :4;
unsigned CKP :1;
unsigned SSPEN :1;
unsigned SSPOV :1;
unsigned WCOL :1;
};
struct {
unsigned SSPM0 :1;
unsigned SSPM1 :1;
unsigned SSPM2 :1;
unsigned SSPM3 :1;
};
} SSP1CON1bits_t;
extern volatile SSP1CON1bits_t SSP1CON1bits __at(0x215);

# 6131
typedef union {
struct {
unsigned SSPM :4;
unsigned CKP :1;
unsigned SSPEN :1;
unsigned SSPOV :1;
unsigned WCOL :1;
};
struct {
unsigned SSPM0 :1;
unsigned SSPM1 :1;
unsigned SSPM2 :1;
unsigned SSPM3 :1;
};
} SSPCONbits_t;
extern volatile SSPCONbits_t SSPCONbits __at(0x215);

# 6193
typedef union {
struct {
unsigned SSPM :4;
unsigned CKP :1;
unsigned SSPEN :1;
unsigned SSPOV :1;
unsigned WCOL :1;
};
struct {
unsigned SSPM0 :1;
unsigned SSPM1 :1;
unsigned SSPM2 :1;
unsigned SSPM3 :1;
};
} SSPCON1bits_t;
extern volatile SSPCON1bits_t SSPCON1bits __at(0x215);

# 6255
typedef union {
struct {
unsigned SSPM :4;
unsigned CKP :1;
unsigned SSPEN :1;
unsigned SSPOV :1;
unsigned WCOL :1;
};
struct {
unsigned SSPM0 :1;
unsigned SSPM1 :1;
unsigned SSPM2 :1;
unsigned SSPM3 :1;
};
} SSP1CONbits_t;
extern volatile SSP1CONbits_t SSP1CONbits __at(0x215);

# 6320
extern volatile unsigned char SSP1CON2 __at(0x216);

asm("SSP1CON2 equ 0216h");


extern volatile unsigned char SSPCON2 __at(0x216);

asm("SSPCON2 equ 0216h");


typedef union {
struct {
unsigned SEN :1;
unsigned RSEN :1;
unsigned PEN :1;
unsigned RCEN :1;
unsigned ACKEN :1;
unsigned ACKDT :1;
unsigned ACKSTAT :1;
unsigned GCEN :1;
};
} SSP1CON2bits_t;
extern volatile SSP1CON2bits_t SSP1CON2bits __at(0x216);

# 6385
typedef union {
struct {
unsigned SEN :1;
unsigned RSEN :1;
unsigned PEN :1;
unsigned RCEN :1;
unsigned ACKEN :1;
unsigned ACKDT :1;
unsigned ACKSTAT :1;
unsigned GCEN :1;
};
} SSPCON2bits_t;
extern volatile SSPCON2bits_t SSPCON2bits __at(0x216);

# 6442
extern volatile unsigned char SSP1CON3 __at(0x217);

asm("SSP1CON3 equ 0217h");


extern volatile unsigned char SSPCON3 __at(0x217);

asm("SSPCON3 equ 0217h");


typedef union {
struct {
unsigned DHEN :1;
unsigned AHEN :1;
unsigned SBCDE :1;
unsigned SDAHT :1;
unsigned BOEN :1;
unsigned SCIE :1;
unsigned PCIE :1;
unsigned ACKTIM :1;
};
} SSP1CON3bits_t;
extern volatile SSP1CON3bits_t SSP1CON3bits __at(0x217);

# 6507
typedef union {
struct {
unsigned DHEN :1;
unsigned AHEN :1;
unsigned SBCDE :1;
unsigned SDAHT :1;
unsigned BOEN :1;
unsigned SCIE :1;
unsigned PCIE :1;
unsigned ACKTIM :1;
};
} SSPCON3bits_t;
extern volatile SSPCON3bits_t SSPCON3bits __at(0x217);

# 6564
extern volatile unsigned char ODCONA __at(0x28C);

asm("ODCONA equ 028Ch");


typedef union {
struct {
unsigned ODCONA0 :1;
unsigned ODCONA1 :1;
unsigned ODCONA2 :1;
unsigned ODCONA3 :1;
unsigned ODCONA4 :1;
unsigned ODCONA5 :1;
unsigned ODCONA6 :1;
unsigned ODCONA7 :1;
};
struct {
unsigned ODCONA :8;
};
} ODCONAbits_t;
extern volatile ODCONAbits_t ODCONAbits __at(0x28C);

# 6634
extern volatile unsigned char ODCONB __at(0x28D);

asm("ODCONB equ 028Dh");


typedef union {
struct {
unsigned ODCONB0 :1;
unsigned ODCONB1 :1;
unsigned ODCONB2 :1;
unsigned ODCONB3 :1;
unsigned ODCONB4 :1;
unsigned ODCONB5 :1;
unsigned ODCONB6 :1;
unsigned ODCONB7 :1;
};
struct {
unsigned ODCONB :8;
};
} ODCONBbits_t;
extern volatile ODCONBbits_t ODCONBbits __at(0x28D);

# 6704
extern volatile unsigned char ODCONC __at(0x28E);

asm("ODCONC equ 028Eh");


typedef union {
struct {
unsigned ODCONC0 :1;
unsigned ODCONC1 :1;
unsigned ODCONC2 :1;
unsigned ODCONC3 :1;
unsigned ODCONC4 :1;
unsigned ODCONC5 :1;
unsigned ODCONC6 :1;
unsigned ODCONC7 :1;
};
struct {
unsigned ODCONC :8;
};
} ODCONCbits_t;
extern volatile ODCONCbits_t ODCONCbits __at(0x28E);

# 6774
extern volatile unsigned short CCPR1 __at(0x291);

asm("CCPR1 equ 0291h");




extern volatile unsigned char CCPR1L __at(0x291);

asm("CCPR1L equ 0291h");


typedef union {
struct {
unsigned CCPR1L :8;
};
} CCPR1Lbits_t;
extern volatile CCPR1Lbits_t CCPR1Lbits __at(0x291);

# 6801
extern volatile unsigned char CCPR1H __at(0x292);

asm("CCPR1H equ 0292h");


typedef union {
struct {
unsigned CCPR1H :8;
};
} CCPR1Hbits_t;
extern volatile CCPR1Hbits_t CCPR1Hbits __at(0x292);

# 6821
extern volatile unsigned char CCP1CON __at(0x293);

asm("CCP1CON equ 0293h");


typedef union {
struct {
unsigned CCP1M :4;
unsigned DC1B :2;
};
struct {
unsigned CCP1M0 :1;
unsigned CCP1M1 :1;
unsigned CCP1M2 :1;
unsigned CCP1M3 :1;
unsigned DC1B0 :1;
unsigned DC1B1 :1;
};
} CCP1CONbits_t;
extern volatile CCP1CONbits_t CCP1CONbits __at(0x293);

# 6885
extern volatile unsigned short CCPR2 __at(0x298);

asm("CCPR2 equ 0298h");




extern volatile unsigned char CCPR2L __at(0x298);

asm("CCPR2L equ 0298h");


typedef union {
struct {
unsigned CCPR2L :8;
};
} CCPR2Lbits_t;
extern volatile CCPR2Lbits_t CCPR2Lbits __at(0x298);

# 6912
extern volatile unsigned char CCPR2H __at(0x299);

asm("CCPR2H equ 0299h");


typedef union {
struct {
unsigned CCPR2H :8;
};
} CCPR2Hbits_t;
extern volatile CCPR2Hbits_t CCPR2Hbits __at(0x299);

# 6932
extern volatile unsigned char CCP2CON __at(0x29A);

asm("CCP2CON equ 029Ah");


typedef union {
struct {
unsigned CCP2M :4;
unsigned DC2B :2;
};
struct {
unsigned CCP2M0 :1;
unsigned CCP2M1 :1;
unsigned CCP2M2 :1;
unsigned CCP2M3 :1;
unsigned DC2B0 :1;
unsigned DC2B1 :1;
};
} CCP2CONbits_t;
extern volatile CCP2CONbits_t CCP2CONbits __at(0x29A);

# 6996
extern volatile unsigned char SLRCONA __at(0x30C);

asm("SLRCONA equ 030Ch");


typedef union {
struct {
unsigned SLRCONA0 :1;
unsigned SLRCONA1 :1;
unsigned SLRCONA2 :1;
unsigned SLRCONA3 :1;
unsigned SLRCONA4 :1;
unsigned SLRCONA5 :1;
unsigned SLRCONA6 :1;
unsigned SLRCONA7 :1;
};
struct {
unsigned SLRCONA :8;
};
} SLRCONAbits_t;
extern volatile SLRCONAbits_t SLRCONAbits __at(0x30C);

# 7066
extern volatile unsigned char SLRCONB __at(0x30D);

asm("SLRCONB equ 030Dh");


typedef union {
struct {
unsigned SLRCONB0 :1;
unsigned SLRCONB1 :1;
unsigned SLRCONB2 :1;
unsigned SLRCONB3 :1;
unsigned SLRCONB4 :1;
unsigned SLRCONB5 :1;
unsigned SLRCONB6 :1;
unsigned SLRCONB7 :1;
};
struct {
unsigned SLRCONB :8;
};
} SLRCONBbits_t;
extern volatile SLRCONBbits_t SLRCONBbits __at(0x30D);

# 7136
extern volatile unsigned char SLRCONC __at(0x30E);

asm("SLRCONC equ 030Eh");


typedef union {
struct {
unsigned SLRCONC0 :1;
unsigned SLRCONC1 :1;
unsigned SLRCONC2 :1;
unsigned SLRCONC3 :1;
unsigned SLRCONC4 :1;
unsigned SLRCONC5 :1;
unsigned SLRCONC6 :1;
unsigned SLRCONC7 :1;
};
struct {
unsigned SLRCONC :8;
};
} SLRCONCbits_t;
extern volatile SLRCONCbits_t SLRCONCbits __at(0x30E);

# 7206
extern volatile unsigned short CCPR3 __at(0x311);

asm("CCPR3 equ 0311h");




extern volatile unsigned char CCPR3L __at(0x311);

asm("CCPR3L equ 0311h");


typedef union {
struct {
unsigned CCPR3L :8;
};
} CCPR3Lbits_t;
extern volatile CCPR3Lbits_t CCPR3Lbits __at(0x311);

# 7233
extern volatile unsigned char CCPR3H __at(0x312);

asm("CCPR3H equ 0312h");


typedef union {
struct {
unsigned CCPR3H :8;
};
} CCPR3Hbits_t;
extern volatile CCPR3Hbits_t CCPR3Hbits __at(0x312);

# 7253
extern volatile unsigned char CCP3CON __at(0x313);

asm("CCP3CON equ 0313h");


typedef union {
struct {
unsigned CCP3M :4;
unsigned DC3B :2;
};
struct {
unsigned CCP3M0 :1;
unsigned CCP3M1 :1;
unsigned CCP3M2 :1;
unsigned CCP3M3 :1;
unsigned DC3B0 :1;
unsigned DC3B1 :1;
};
} CCP3CONbits_t;
extern volatile CCP3CONbits_t CCP3CONbits __at(0x313);

# 7317
extern volatile unsigned char INLVLA __at(0x38C);

asm("INLVLA equ 038Ch");


typedef union {
struct {
unsigned INLVLA0 :1;
unsigned INLVLA1 :1;
unsigned INLVLA2 :1;
unsigned INLVLA3 :1;
unsigned INLVLA4 :1;
unsigned INLVLA5 :1;
unsigned INLVLA6 :1;
unsigned INLVLA7 :1;
};
struct {
unsigned INLVLA :8;
};
} INLVLAbits_t;
extern volatile INLVLAbits_t INLVLAbits __at(0x38C);

# 7387
extern volatile unsigned char INLVLB __at(0x38D);

asm("INLVLB equ 038Dh");


typedef union {
struct {
unsigned INLVLB0 :1;
unsigned INLVLB1 :1;
unsigned INLVLB2 :1;
unsigned INLVLB3 :1;
unsigned INLVLB4 :1;
unsigned INLVLB5 :1;
unsigned INLVLB6 :1;
unsigned INLVLB7 :1;
};
struct {
unsigned INLVLB :8;
};
} INLVLBbits_t;
extern volatile INLVLBbits_t INLVLBbits __at(0x38D);

# 7457
extern volatile unsigned char INLVLC __at(0x38E);

asm("INLVLC equ 038Eh");


typedef union {
struct {
unsigned INLVLC0 :1;
unsigned INLVLC1 :1;
unsigned INLVLC2 :1;
unsigned INLVLC3 :1;
unsigned INLVLC4 :1;
unsigned INLVLC5 :1;
unsigned INLVLC6 :1;
unsigned INLVLC7 :1;
};
struct {
unsigned INLVLC :8;
};
} INLVLCbits_t;
extern volatile INLVLCbits_t INLVLCbits __at(0x38E);

# 7527
extern volatile unsigned char INLVLE __at(0x390);

asm("INLVLE equ 0390h");


typedef union {
struct {
unsigned :3;
unsigned INLVLE3 :1;
};
struct {
unsigned INLVLE :8;
};
} INLVLEbits_t;
extern volatile INLVLEbits_t INLVLEbits __at(0x390);

# 7556
extern volatile unsigned char IOCAP __at(0x391);

asm("IOCAP equ 0391h");


typedef union {
struct {
unsigned IOCAP0 :1;
unsigned IOCAP1 :1;
unsigned IOCAP2 :1;
unsigned IOCAP3 :1;
unsigned IOCAP4 :1;
unsigned IOCAP5 :1;
unsigned IOCAP6 :1;
unsigned IOCAP7 :1;
};
struct {
unsigned IOCAP :8;
};
} IOCAPbits_t;
extern volatile IOCAPbits_t IOCAPbits __at(0x391);

# 7626
extern volatile unsigned char IOCAN __at(0x392);

asm("IOCAN equ 0392h");


typedef union {
struct {
unsigned IOCAN0 :1;
unsigned IOCAN1 :1;
unsigned IOCAN2 :1;
unsigned IOCAN3 :1;
unsigned IOCAN4 :1;
unsigned IOCAN5 :1;
unsigned IOCAN6 :1;
unsigned IOCAN7 :1;
};
struct {
unsigned IOCAN :8;
};
} IOCANbits_t;
extern volatile IOCANbits_t IOCANbits __at(0x392);

# 7696
extern volatile unsigned char IOCAF __at(0x393);

asm("IOCAF equ 0393h");


typedef union {
struct {
unsigned IOCAF0 :1;
unsigned IOCAF1 :1;
unsigned IOCAF2 :1;
unsigned IOCAF3 :1;
unsigned IOCAF4 :1;
unsigned IOCAF5 :1;
unsigned IOCAF6 :1;
unsigned IOCAF7 :1;
};
struct {
unsigned IOCAF :8;
};
} IOCAFbits_t;
extern volatile IOCAFbits_t IOCAFbits __at(0x393);

# 7766
extern volatile unsigned char IOCBP __at(0x394);

asm("IOCBP equ 0394h");


typedef union {
struct {
unsigned IOCBP0 :1;
unsigned IOCBP1 :1;
unsigned IOCBP2 :1;
unsigned IOCBP3 :1;
unsigned IOCBP4 :1;
unsigned IOCBP5 :1;
unsigned IOCBP6 :1;
unsigned IOCBP7 :1;
};
struct {
unsigned IOCBP :8;
};
} IOCBPbits_t;
extern volatile IOCBPbits_t IOCBPbits __at(0x394);

# 7836
extern volatile unsigned char IOCBN __at(0x395);

asm("IOCBN equ 0395h");


typedef union {
struct {
unsigned IOCBN0 :1;
unsigned IOCBN1 :1;
unsigned IOCBN2 :1;
unsigned IOCBN3 :1;
unsigned IOCBN4 :1;
unsigned IOCBN5 :1;
unsigned IOCBN6 :1;
unsigned IOCBN7 :1;
};
struct {
unsigned IOCBN :8;
};
} IOCBNbits_t;
extern volatile IOCBNbits_t IOCBNbits __at(0x395);

# 7906
extern volatile unsigned char IOCBF __at(0x396);

asm("IOCBF equ 0396h");


typedef union {
struct {
unsigned IOCBF0 :1;
unsigned IOCBF1 :1;
unsigned IOCBF2 :1;
unsigned IOCBF3 :1;
unsigned IOCBF4 :1;
unsigned IOCBF5 :1;
unsigned IOCBF6 :1;
unsigned IOCBF7 :1;
};
struct {
unsigned IOCBF :8;
};
} IOCBFbits_t;
extern volatile IOCBFbits_t IOCBFbits __at(0x396);

# 7976
extern volatile unsigned char IOCCP __at(0x397);

asm("IOCCP equ 0397h");


typedef union {
struct {
unsigned IOCCP0 :1;
unsigned IOCCP1 :1;
unsigned IOCCP2 :1;
unsigned IOCCP3 :1;
unsigned IOCCP4 :1;
unsigned IOCCP5 :1;
unsigned IOCCP6 :1;
unsigned IOCCP7 :1;
};
struct {
unsigned IOCCP :8;
};
} IOCCPbits_t;
extern volatile IOCCPbits_t IOCCPbits __at(0x397);

# 8046
extern volatile unsigned char IOCCN __at(0x398);

asm("IOCCN equ 0398h");


typedef union {
struct {
unsigned IOCCN0 :1;
unsigned IOCCN1 :1;
unsigned IOCCN2 :1;
unsigned IOCCN3 :1;
unsigned IOCCN4 :1;
unsigned IOCCN5 :1;
unsigned IOCCN6 :1;
unsigned IOCCN7 :1;
};
struct {
unsigned IOCCN :8;
};
} IOCCNbits_t;
extern volatile IOCCNbits_t IOCCNbits __at(0x398);

# 8116
extern volatile unsigned char IOCCF __at(0x399);

asm("IOCCF equ 0399h");


typedef union {
struct {
unsigned IOCCF0 :1;
unsigned IOCCF1 :1;
unsigned IOCCF2 :1;
unsigned IOCCF3 :1;
unsigned IOCCF4 :1;
unsigned IOCCF5 :1;
unsigned IOCCF6 :1;
unsigned IOCCF7 :1;
};
struct {
unsigned IOCCF :8;
};
} IOCCFbits_t;
extern volatile IOCCFbits_t IOCCFbits __at(0x399);

# 8186
extern volatile unsigned char IOCEP __at(0x39D);

asm("IOCEP equ 039Dh");


typedef union {
struct {
unsigned :3;
unsigned IOCEP3 :1;
};
} IOCEPbits_t;
extern volatile IOCEPbits_t IOCEPbits __at(0x39D);

# 8207
extern volatile unsigned char IOCEN __at(0x39E);

asm("IOCEN equ 039Eh");


typedef union {
struct {
unsigned :3;
unsigned IOCEN3 :1;
};
} IOCENbits_t;
extern volatile IOCENbits_t IOCENbits __at(0x39E);

# 8228
extern volatile unsigned char IOCEF __at(0x39F);

asm("IOCEF equ 039Fh");


typedef union {
struct {
unsigned :3;
unsigned IOCEF3 :1;
};
} IOCEFbits_t;
extern volatile IOCEFbits_t IOCEFbits __at(0x39F);

# 8249
extern volatile unsigned char OPA1CON __at(0x511);

asm("OPA1CON equ 0511h");


typedef union {
struct {
unsigned OPA1PCH0 :1;
unsigned OPA1PCH1 :1;
unsigned OPA1PCH2 :1;
};
struct {
unsigned OPA1PCH :3;
unsigned :3;
unsigned OPA1SP :1;
unsigned OPA1EN :1;
};
struct {
unsigned PCH :3;
unsigned :3;
unsigned SP :1;
unsigned EN :1;
};
struct {
unsigned PCH0 :1;
unsigned PCH1 :1;
unsigned PCH2 :1;
};
} OPA1CONbits_t;
extern volatile OPA1CONbits_t OPA1CONbits __at(0x511);

# 8343
extern volatile unsigned char OPA2CON __at(0x513);

asm("OPA2CON equ 0513h");


typedef union {
struct {
unsigned OPA2PCH0 :1;
unsigned OPA2PCH1 :1;
unsigned OPA2PCH2 :1;
};
struct {
unsigned OPA2PCH :3;
unsigned :3;
unsigned OPA2SP :1;
unsigned OPA2EN :1;
};
struct {
unsigned PCH :3;
unsigned :3;
unsigned SP :1;
unsigned EN :1;
};
struct {
unsigned PCH0 :1;
unsigned PCH1 :1;
unsigned PCH2 :1;
};
} OPA2CONbits_t;
extern volatile OPA2CONbits_t OPA2CONbits __at(0x513);

# 8437
extern volatile unsigned char CLKRCON __at(0x51A);

asm("CLKRCON equ 051Ah");


typedef union {
struct {
unsigned CLKRDIV0 :1;
unsigned CLKRDIV1 :1;
unsigned CLKRDIV2 :1;
unsigned CLKRDC0 :1;
unsigned CLKRDC1 :1;
unsigned CLKRSLR :1;
unsigned CLKROE :1;
unsigned CLKREN :1;
};
struct {
unsigned CLKRDIV :3;
unsigned CLKRDC :2;
};
} CLKRCONbits_t;
extern volatile CLKRCONbits_t CLKRCONbits __at(0x51A);

# 8513
extern volatile unsigned char DAC2CON0 __at(0x591);

asm("DAC2CON0 equ 0591h");


typedef union {
struct {
unsigned :2;
unsigned DAC2PSS :2;
unsigned DAC2OE2 :1;
unsigned DAC2OE1 :1;
unsigned :1;
unsigned DAC2EN :1;
};
} DAC2CON0bits_t;
extern volatile DAC2CON0bits_t DAC2CON0bits __at(0x591);

# 8553
extern volatile unsigned char DAC2REF __at(0x592);

asm("DAC2REF equ 0592h");


extern volatile unsigned char DAC2CON1 __at(0x592);

asm("DAC2CON1 equ 0592h");


typedef union {
struct {
unsigned DAC2R :5;
};
} DAC2REFbits_t;
extern volatile DAC2REFbits_t DAC2REFbits __at(0x592);

# 8576
typedef union {
struct {
unsigned DAC2R :5;
};
} DAC2CON1bits_t;
extern volatile DAC2CON1bits_t DAC2CON1bits __at(0x592);

# 8591
extern volatile unsigned char DAC3CON0 __at(0x593);

asm("DAC3CON0 equ 0593h");


typedef union {
struct {
unsigned :2;
unsigned DAC3PSS :2;
unsigned DAC3OE2 :1;
unsigned DAC3OE1 :1;
unsigned :1;
unsigned DAC3EN :1;
};
} DAC3CON0bits_t;
extern volatile DAC3CON0bits_t DAC3CON0bits __at(0x593);

# 8631
extern volatile unsigned char DAC3REF __at(0x594);

asm("DAC3REF equ 0594h");


extern volatile unsigned char DAC3CON1 __at(0x594);

asm("DAC3CON1 equ 0594h");


typedef union {
struct {
unsigned DAC3R :5;
};
} DAC3REFbits_t;
extern volatile DAC3REFbits_t DAC3REFbits __at(0x594);

# 8654
typedef union {
struct {
unsigned DAC3R :5;
};
} DAC3CON1bits_t;
extern volatile DAC3CON1bits_t DAC3CON1bits __at(0x594);

# 8669
extern volatile unsigned char DAC4CON0 __at(0x595);

asm("DAC4CON0 equ 0595h");


typedef union {
struct {
unsigned :2;
unsigned DAC4PSS :2;
unsigned DAC4OE2 :1;
unsigned DAC4OE1 :1;
unsigned :1;
unsigned DAC4EN :1;
};
} DAC4CON0bits_t;
extern volatile DAC4CON0bits_t DAC4CON0bits __at(0x595);

# 8709
extern volatile unsigned char DAC4REF __at(0x596);

asm("DAC4REF equ 0596h");


extern volatile unsigned char DAC4CON1 __at(0x596);

asm("DAC4CON1 equ 0596h");


typedef union {
struct {
unsigned DAC4R :5;
};
} DAC4REFbits_t;
extern volatile DAC4REFbits_t DAC4REFbits __at(0x596);

# 8732
typedef union {
struct {
unsigned DAC4R :5;
};
} DAC4CON1bits_t;
extern volatile DAC4CON1bits_t DAC4CON1bits __at(0x596);

# 8747
extern volatile unsigned char PSMC1CON __at(0xE91);

asm("PSMC1CON equ 0E91h");


typedef union {
struct {
unsigned P1MODE :4;
unsigned P1DBRE :1;
unsigned P1DBFE :1;
unsigned PSMC1LD :1;
unsigned PSMC1EN :1;
};
struct {
unsigned P1MODE0 :1;
unsigned P1MODE1 :1;
unsigned P1MODE2 :1;
unsigned P1MODE3 :1;
};
} PSMC1CONbits_t;
extern volatile PSMC1CONbits_t PSMC1CONbits __at(0xE91);

# 8817
extern volatile unsigned char PSMC1MDL __at(0xE92);

asm("PSMC1MDL equ 0E92h");


typedef union {
struct {
unsigned P1MSRC :4;
unsigned :1;
unsigned P1MDLBIT :1;
unsigned P1MDLPOL :1;
unsigned P1MDLEN :1;
};
struct {
unsigned P1MSRC0 :1;
unsigned P1MSRC1 :1;
unsigned P1MSRC2 :1;
unsigned P1MSRC3 :1;
};
} PSMC1MDLbits_t;
extern volatile PSMC1MDLbits_t PSMC1MDLbits __at(0xE92);

# 8882
extern volatile unsigned char PSMC1SYNC __at(0xE93);

asm("PSMC1SYNC equ 0E93h");


typedef union {
struct {
unsigned P1SYNC0 :1;
unsigned P1SYNC1 :1;
unsigned P1SYNC2 :1;
unsigned :2;
unsigned P1DCPOL :1;
unsigned P1PRPOL :1;
unsigned P1POFST :1;
};
} PSMC1SYNCbits_t;
extern volatile PSMC1SYNCbits_t PSMC1SYNCbits __at(0xE93);

# 8933
extern volatile unsigned char PSMC1CLK __at(0xE94);

asm("PSMC1CLK equ 0E94h");


typedef union {
struct {
unsigned P1CSRC0 :1;
unsigned P1CSRC1 :1;
unsigned :2;
unsigned P1CPRE0 :1;
unsigned P1CPRE1 :1;
};
struct {
unsigned P1CSRC :2;
unsigned :2;
unsigned P1CPRE :2;
};
} PSMC1CLKbits_t;
extern volatile PSMC1CLKbits_t PSMC1CLKbits __at(0xE94);

# 8987
extern volatile unsigned char PSMC1OEN __at(0xE95);

asm("PSMC1OEN equ 0E95h");


typedef union {
struct {
unsigned P1OEA :1;
unsigned P1OEB :1;
unsigned P1OEC :1;
unsigned P1OED :1;
unsigned P1OEE :1;
unsigned P1OEF :1;
};
} PSMC1OENbits_t;
extern volatile PSMC1OENbits_t PSMC1OENbits __at(0xE95);

# 9037
extern volatile unsigned char PSMC1POL __at(0xE96);

asm("PSMC1POL equ 0E96h");


typedef union {
struct {
unsigned P1POLA :1;
unsigned P1POLB :1;
unsigned P1POLC :1;
unsigned P1POLD :1;
unsigned P1POLE :1;
unsigned P1POLF :1;
unsigned P1INPOL :1;
};
} PSMC1POLbits_t;
extern volatile PSMC1POLbits_t PSMC1POLbits __at(0xE96);

# 9093
extern volatile unsigned char PSMC1BLNK __at(0xE97);

asm("PSMC1BLNK equ 0E97h");


typedef union {
struct {
unsigned P1REBM :2;
unsigned :2;
unsigned P1FEBM :2;
};
struct {
unsigned P1REBM0 :1;
unsigned P1REBM1 :1;
unsigned :2;
unsigned P1FEBM0 :1;
unsigned P1FEBM1 :1;
};
} PSMC1BLNKbits_t;
extern volatile PSMC1BLNKbits_t PSMC1BLNKbits __at(0xE97);

# 9147
extern volatile unsigned char PSMC1REBS __at(0xE98);

asm("PSMC1REBS equ 0E98h");


typedef union {
struct {
unsigned :1;
unsigned P1REBSC1 :1;
unsigned P1REBSC2 :1;
unsigned P1REBSC3 :1;
unsigned P1REBSC4 :1;
unsigned :2;
unsigned P1REBSIN :1;
};
} PSMC1REBSbits_t;
extern volatile PSMC1REBSbits_t PSMC1REBSbits __at(0xE98);

# 9193
extern volatile unsigned char PSMC1FEBS __at(0xE99);

asm("PSMC1FEBS equ 0E99h");


typedef union {
struct {
unsigned :1;
unsigned P1FEBSC1 :1;
unsigned P1FEBSC2 :1;
unsigned P1FEBSC3 :1;
unsigned P1FEBSC4 :1;
unsigned :2;
unsigned P1FEBSIN :1;
};
} PSMC1FEBSbits_t;
extern volatile PSMC1FEBSbits_t PSMC1FEBSbits __at(0xE99);

# 9239
extern volatile unsigned char PSMC1PHS __at(0xE9A);

asm("PSMC1PHS equ 0E9Ah");


typedef union {
struct {
unsigned P1PHST :1;
unsigned P1PHSC1 :1;
unsigned P1PHSC2 :1;
unsigned P1PHSC3 :1;
unsigned P1PHSC4 :1;
unsigned :2;
unsigned P1PHSIN :1;
};
} PSMC1PHSbits_t;
extern volatile PSMC1PHSbits_t PSMC1PHSbits __at(0xE9A);

# 9290
extern volatile unsigned char PSMC1DCS __at(0xE9B);

asm("PSMC1DCS equ 0E9Bh");


typedef union {
struct {
unsigned P1DCST :1;
unsigned P1DCSC1 :1;
unsigned P1DCSC2 :1;
unsigned P1DCSC3 :1;
unsigned P1DCSC4 :1;
unsigned :2;
unsigned P1DCSIN :1;
};
} PSMC1DCSbits_t;
extern volatile PSMC1DCSbits_t PSMC1DCSbits __at(0xE9B);

# 9341
extern volatile unsigned char PSMC1PRS __at(0xE9C);

asm("PSMC1PRS equ 0E9Ch");


typedef union {
struct {
unsigned P1PRST :1;
unsigned P1PRSC1 :1;
unsigned P1PRSC2 :1;
unsigned P1PRSC3 :1;
unsigned P1PRSC4 :1;
unsigned :2;
unsigned P1PRSIN :1;
};
} PSMC1PRSbits_t;
extern volatile PSMC1PRSbits_t PSMC1PRSbits __at(0xE9C);

# 9392
extern volatile unsigned char PSMC1ASDC __at(0xE9D);

asm("PSMC1ASDC equ 0E9Dh");


typedef union {
struct {
unsigned P1ASDOV :1;
unsigned :4;
unsigned P1ARSEN :1;
unsigned P1ASDEN :1;
unsigned P1ASE :1;
};
} PSMC1ASDCbits_t;
extern volatile PSMC1ASDCbits_t PSMC1ASDCbits __at(0xE9D);

# 9431
extern volatile unsigned char PSMC1ASDL __at(0xE9E);

asm("PSMC1ASDL equ 0E9Eh");


typedef union {
struct {
unsigned P1ASDLA :1;
unsigned P1ASDLB :1;
unsigned P1ASDLC :1;
unsigned P1ASDLD :1;
unsigned P1ASDLE :1;
unsigned P1ASDLF :1;
};
} PSMC1ASDLbits_t;
extern volatile PSMC1ASDLbits_t PSMC1ASDLbits __at(0xE9E);

# 9481
extern volatile unsigned char PSMC1ASDS __at(0xE9F);

asm("PSMC1ASDS equ 0E9Fh");


typedef union {
struct {
unsigned :1;
unsigned P1ASDSC1 :1;
unsigned P1ASDSC2 :1;
unsigned P1ASDSC3 :1;
unsigned P1ASDSC4 :1;
unsigned :2;
unsigned P1ASDSIN :1;
};
} PSMC1ASDSbits_t;
extern volatile PSMC1ASDSbits_t PSMC1ASDSbits __at(0xE9F);

# 9527
extern volatile unsigned char PSMC1INT __at(0xEA0);

asm("PSMC1INT equ 0EA0h");


typedef union {
struct {
unsigned P1TPRIF :1;
unsigned P1TDCIF :1;
unsigned P1TPHIF :1;
unsigned P1TOVIF :1;
unsigned P1TPRIE :1;
unsigned P1TDCIE :1;
unsigned P1TPHIE :1;
unsigned P1TOVIE :1;
};
} PSMC1INTbits_t;
extern volatile PSMC1INTbits_t PSMC1INTbits __at(0xEA0);

# 9589
extern volatile unsigned short PSMC1PH __at(0xEA1);

asm("PSMC1PH equ 0EA1h");




extern volatile unsigned char PSMC1PHL __at(0xEA1);

asm("PSMC1PHL equ 0EA1h");


typedef union {
struct {
unsigned PSMC1PH0 :1;
unsigned PSMC1PH1 :1;
unsigned PSMC1PH2 :1;
unsigned PSMC1PH3 :1;
unsigned PSMC1PH4 :1;
unsigned PSMC1PH5 :1;
unsigned PSMC1PH6 :1;
unsigned PSMC1PH7 :1;
};
} PSMC1PHLbits_t;
extern volatile PSMC1PHLbits_t PSMC1PHLbits __at(0xEA1);

# 9658
extern volatile unsigned char PSMC1PHH __at(0xEA2);

asm("PSMC1PHH equ 0EA2h");


typedef union {
struct {
unsigned PSMC1PH8 :1;
unsigned PSMC1PH9 :1;
unsigned PSMC1PH10 :1;
unsigned PSMC1PH11 :1;
unsigned PSMC1PH12 :1;
unsigned PSMC1PH13 :1;
unsigned PSMC1PH14 :1;
unsigned PSMC1PH15 :1;
};
} PSMC1PHHbits_t;
extern volatile PSMC1PHHbits_t PSMC1PHHbits __at(0xEA2);

# 9720
extern volatile unsigned short PSMC1DC __at(0xEA3);

asm("PSMC1DC equ 0EA3h");




extern volatile unsigned char PSMC1DCL __at(0xEA3);

asm("PSMC1DCL equ 0EA3h");


typedef union {
struct {
unsigned PSMC1DC0 :1;
unsigned PSMC1DC1 :1;
unsigned PSMC1DC2 :1;
unsigned PSMC1DC3 :1;
unsigned PSMC1DC4 :1;
unsigned PSMC1DC5 :1;
unsigned PSMC1DC6 :1;
unsigned PSMC1DC7 :1;
};
} PSMC1DCLbits_t;
extern volatile PSMC1DCLbits_t PSMC1DCLbits __at(0xEA3);

# 9789
extern volatile unsigned char PSMC1DCH __at(0xEA4);

asm("PSMC1DCH equ 0EA4h");


typedef union {
struct {
unsigned PSMC1DC8 :1;
unsigned PSMC1DC9 :1;
unsigned PSMC1DC10 :1;
unsigned PSMC1DC11 :1;
unsigned PSMC1DC12 :1;
unsigned PSMC1DC13 :1;
unsigned PSMC1DC14 :1;
unsigned PSMC1DC15 :1;
};
} PSMC1DCHbits_t;
extern volatile PSMC1DCHbits_t PSMC1DCHbits __at(0xEA4);

# 9851
extern volatile unsigned short PSMC1PR __at(0xEA5);

asm("PSMC1PR equ 0EA5h");




extern volatile unsigned char PSMC1PRL __at(0xEA5);

asm("PSMC1PRL equ 0EA5h");


typedef union {
struct {
unsigned PSMC1PR0 :1;
unsigned PSMC1PR1 :1;
unsigned PSMC1PR2 :1;
unsigned PSMC1PR3 :1;
unsigned PSMC1PR4 :1;
unsigned PSMC1PR5 :1;
unsigned PSMC1PR6 :1;
unsigned PSMC1PR7 :1;
};
} PSMC1PRLbits_t;
extern volatile PSMC1PRLbits_t PSMC1PRLbits __at(0xEA5);

# 9920
extern volatile unsigned char PSMC1PRH __at(0xEA6);

asm("PSMC1PRH equ 0EA6h");


typedef union {
struct {
unsigned PSMC1PR8 :1;
unsigned PSMC1PR9 :1;
unsigned PSMC1PR10 :1;
unsigned PSMC1PR11 :1;
unsigned PSMC1PR12 :1;
unsigned PSMC1PR13 :1;
unsigned PSMC1PR14 :1;
unsigned PSMC1PR15 :1;
};
} PSMC1PRHbits_t;
extern volatile PSMC1PRHbits_t PSMC1PRHbits __at(0xEA6);

# 9982
extern volatile unsigned short PSMC1TMR __at(0xEA7);

asm("PSMC1TMR equ 0EA7h");




extern volatile unsigned char PSMC1TMRL __at(0xEA7);

asm("PSMC1TMRL equ 0EA7h");


typedef union {
struct {
unsigned PSMC1TMR0 :1;
unsigned PSMC1TMR1 :1;
unsigned PSMC1TMR2 :1;
unsigned PSMC1TMR3 :1;
unsigned PSMC1TMR4 :1;
unsigned PSMC1TMR5 :1;
unsigned PSMC1TMR6 :1;
unsigned PSMC1TMR7 :1;
};
} PSMC1TMRLbits_t;
extern volatile PSMC1TMRLbits_t PSMC1TMRLbits __at(0xEA7);

# 10051
extern volatile unsigned char PSMC1TMRH __at(0xEA8);

asm("PSMC1TMRH equ 0EA8h");


typedef union {
struct {
unsigned PSMC1TMR8 :1;
unsigned PSMC1TMR9 :1;
unsigned PSMC1TMR10 :1;
unsigned PSMC1TMR11 :1;
unsigned PSMC1TMR12 :1;
unsigned PSMC1TMR13 :1;
unsigned PSMC1TMR14 :1;
unsigned PSMC1TMR15 :1;
};
} PSMC1TMRHbits_t;
extern volatile PSMC1TMRHbits_t PSMC1TMRHbits __at(0xEA8);

# 10113
extern volatile unsigned char PSMC1DBR __at(0xEA9);

asm("PSMC1DBR equ 0EA9h");


typedef union {
struct {
unsigned PSMC1DBR0 :1;
unsigned PSMC1DBR1 :1;
unsigned PSMC1DBR2 :1;
unsigned PSMC1DBR3 :1;
unsigned PSMC1DBR4 :1;
unsigned PSMC1DBR5 :1;
unsigned PSMC1DBR6 :1;
unsigned PSMC1DBR7 :1;
};
} PSMC1DBRbits_t;
extern volatile PSMC1DBRbits_t PSMC1DBRbits __at(0xEA9);

# 10175
extern volatile unsigned char PSMC1DBF __at(0xEAA);

asm("PSMC1DBF equ 0EAAh");


typedef union {
struct {
unsigned PSMC1DBF0 :1;
unsigned PSMC1DBF1 :1;
unsigned PSMC1DBF2 :1;
unsigned PSMC1DBF3 :1;
unsigned PSMC1DBF4 :1;
unsigned PSMC1DBF5 :1;
unsigned PSMC1DBF6 :1;
unsigned PSMC1DBF7 :1;
};
} PSMC1DBFbits_t;
extern volatile PSMC1DBFbits_t PSMC1DBFbits __at(0xEAA);

# 10237
extern volatile unsigned char PSMC1BLKR __at(0xEAB);

asm("PSMC1BLKR equ 0EABh");


typedef union {
struct {
unsigned PSMC1BLKR0 :1;
unsigned PSMC1BLKR1 :1;
unsigned PSMC1BLKR2 :1;
unsigned PSMC1BLKR3 :1;
unsigned PSMC1BLKR4 :1;
unsigned PSMC1BLKR5 :1;
unsigned PSMC1BLKR6 :1;
unsigned PSMC1BLKR7 :1;
};
} PSMC1BLKRbits_t;
extern volatile PSMC1BLKRbits_t PSMC1BLKRbits __at(0xEAB);

# 10299
extern volatile unsigned char PSMC1BLKF __at(0xEAC);

asm("PSMC1BLKF equ 0EACh");


typedef union {
struct {
unsigned PSMC1BLKF0 :1;
unsigned PSMC1BLKF1 :1;
unsigned PSMC1BLKF2 :1;
unsigned PSMC1BLKF3 :1;
unsigned PSMC1BLKF4 :1;
unsigned PSMC1BLKF5 :1;
unsigned PSMC1BLKF6 :1;
unsigned PSMC1BLKF7 :1;
};
} PSMC1BLKFbits_t;
extern volatile PSMC1BLKFbits_t PSMC1BLKFbits __at(0xEAC);

# 10361
extern volatile unsigned char PSMC1FFA __at(0xEAD);

asm("PSMC1FFA equ 0EADh");


typedef union {
struct {
unsigned PSMC1FFA0 :1;
unsigned PSMC1FFA1 :1;
unsigned PSMC1FFA2 :1;
unsigned PSMC1FFA3 :1;
};
} PSMC1FFAbits_t;
extern volatile PSMC1FFAbits_t PSMC1FFAbits __at(0xEAD);

# 10399
extern volatile unsigned char PSMC1STR0 __at(0xEAE);

asm("PSMC1STR0 equ 0EAEh");


typedef union {
struct {
unsigned P1STRA :1;
unsigned P1STRB :1;
unsigned P1STRC :1;
unsigned P1STRD :1;
unsigned P1STRE :1;
unsigned P1STRF :1;
};
} PSMC1STR0bits_t;
extern volatile PSMC1STR0bits_t PSMC1STR0bits __at(0xEAE);

# 10449
extern volatile unsigned char PSMC1STR1 __at(0xEAF);

asm("PSMC1STR1 equ 0EAFh");


typedef union {
struct {
unsigned P1HSMEN :1;
unsigned P1LSMEN :1;
unsigned :5;
unsigned P1SSYNC :1;
};
} PSMC1STR1bits_t;
extern volatile PSMC1STR1bits_t PSMC1STR1bits __at(0xEAF);

# 10482
extern volatile unsigned char PSMC2CON __at(0xEB1);

asm("PSMC2CON equ 0EB1h");


typedef union {
struct {
unsigned P2MODE :4;
unsigned P2DBRE :1;
unsigned P2DBFE :1;
unsigned PSMC2LD :1;
unsigned PSMC2EN :1;
};
struct {
unsigned P2MODE0 :1;
unsigned P2MODE1 :1;
unsigned P2MODE2 :1;
unsigned P2MODE3 :1;
};
} PSMC2CONbits_t;
extern volatile PSMC2CONbits_t PSMC2CONbits __at(0xEB1);

# 10552
extern volatile unsigned char PSMC2MDL __at(0xEB2);

asm("PSMC2MDL equ 0EB2h");


typedef union {
struct {
unsigned P2MSRC :4;
unsigned :1;
unsigned P2MDLBIT :1;
unsigned P2MDLPOL :1;
unsigned P2MDLEN :1;
};
struct {
unsigned P2MSRC0 :1;
unsigned P2MSRC1 :1;
unsigned P2MSRC2 :1;
unsigned P2MSRC3 :1;
};
} PSMC2MDLbits_t;
extern volatile PSMC2MDLbits_t PSMC2MDLbits __at(0xEB2);

# 10617
extern volatile unsigned char PSMC2SYNC __at(0xEB3);

asm("PSMC2SYNC equ 0EB3h");


typedef union {
struct {
unsigned P2SYNC0 :1;
unsigned P2SYNC1 :1;
unsigned P2SYNC2 :1;
unsigned :2;
unsigned P2DCPOL :1;
unsigned P2PRPOL :1;
unsigned P2POFST :1;
};
} PSMC2SYNCbits_t;
extern volatile PSMC2SYNCbits_t PSMC2SYNCbits __at(0xEB3);

# 10668
extern volatile unsigned char PSMC2CLK __at(0xEB4);

asm("PSMC2CLK equ 0EB4h");


typedef union {
struct {
unsigned P2CSRC0 :1;
unsigned P2CSRC1 :1;
unsigned :2;
unsigned P2CPRE0 :1;
unsigned P2CPRE1 :1;
};
struct {
unsigned P2CSRC :2;
unsigned :2;
unsigned P2CPRE :2;
};
} PSMC2CLKbits_t;
extern volatile PSMC2CLKbits_t PSMC2CLKbits __at(0xEB4);

# 10722
extern volatile unsigned char PSMC2OEN __at(0xEB5);

asm("PSMC2OEN equ 0EB5h");


typedef union {
struct {
unsigned P2OEA :1;
unsigned P2OEB :1;
};
} PSMC2OENbits_t;
extern volatile PSMC2OENbits_t PSMC2OENbits __at(0xEB5);

# 10748
extern volatile unsigned char PSMC2POL __at(0xEB6);

asm("PSMC2POL equ 0EB6h");


typedef union {
struct {
unsigned P2POLA :1;
unsigned P2POLB :1;
unsigned :4;
unsigned P2INPOL :1;
};
} PSMC2POLbits_t;
extern volatile PSMC2POLbits_t PSMC2POLbits __at(0xEB6);

# 10781
extern volatile unsigned char PSMC2BLNK __at(0xEB7);

asm("PSMC2BLNK equ 0EB7h");


typedef union {
struct {
unsigned P2REBM :2;
unsigned :2;
unsigned P2FEBM :2;
};
struct {
unsigned P2REBM0 :1;
unsigned P2REBM1 :1;
unsigned :2;
unsigned P2FEBM0 :1;
unsigned P2FEBM1 :1;
};
} PSMC2BLNKbits_t;
extern volatile PSMC2BLNKbits_t PSMC2BLNKbits __at(0xEB7);

# 10835
extern volatile unsigned char PSMC2REBS __at(0xEB8);

asm("PSMC2REBS equ 0EB8h");


typedef union {
struct {
unsigned :1;
unsigned P2REBSC1 :1;
unsigned P2REBSC2 :1;
unsigned P2REBSC3 :1;
unsigned P2REBSC4 :1;
unsigned :2;
unsigned P2REBSIN :1;
};
} PSMC2REBSbits_t;
extern volatile PSMC2REBSbits_t PSMC2REBSbits __at(0xEB8);

# 10881
extern volatile unsigned char PSMC2FEBS __at(0xEB9);

asm("PSMC2FEBS equ 0EB9h");


typedef union {
struct {
unsigned :1;
unsigned P2FEBSC1 :1;
unsigned P2FEBSC2 :1;
unsigned P2FEBSC3 :1;
unsigned P2FEBSC4 :1;
unsigned :2;
unsigned P2FEBSIN :1;
};
} PSMC2FEBSbits_t;
extern volatile PSMC2FEBSbits_t PSMC2FEBSbits __at(0xEB9);

# 10927
extern volatile unsigned char PSMC2PHS __at(0xEBA);

asm("PSMC2PHS equ 0EBAh");


typedef union {
struct {
unsigned P2PHST :1;
unsigned P2PHSC1 :1;
unsigned P2PHSC2 :1;
unsigned P2PHSC3 :1;
unsigned P2PHSC4 :1;
unsigned :2;
unsigned P2PHSIN :1;
};
} PSMC2PHSbits_t;
extern volatile PSMC2PHSbits_t PSMC2PHSbits __at(0xEBA);

# 10978
extern volatile unsigned char PSMC2DCS __at(0xEBB);

asm("PSMC2DCS equ 0EBBh");


typedef union {
struct {
unsigned P2DCST :1;
unsigned P2DCSC1 :1;
unsigned P2DCSC2 :1;
unsigned P2DCSC3 :1;
unsigned P2DCSC4 :1;
unsigned :2;
unsigned P2DCSIN :1;
};
} PSMC2DCSbits_t;
extern volatile PSMC2DCSbits_t PSMC2DCSbits __at(0xEBB);

# 11029
extern volatile unsigned char PSMC2PRS __at(0xEBC);

asm("PSMC2PRS equ 0EBCh");


typedef union {
struct {
unsigned P2PRST :1;
unsigned P2PRSC1 :1;
unsigned P2PRSC2 :1;
unsigned P2PRSC3 :1;
unsigned P2PRSC4 :1;
unsigned :2;
unsigned P2PRSIN :1;
};
} PSMC2PRSbits_t;
extern volatile PSMC2PRSbits_t PSMC2PRSbits __at(0xEBC);

# 11080
extern volatile unsigned char PSMC2ASDC __at(0xEBD);

asm("PSMC2ASDC equ 0EBDh");


typedef union {
struct {
unsigned P2ASDOV :1;
unsigned :4;
unsigned P2ARSEN :1;
unsigned P2ASDEN :1;
unsigned P2ASE :1;
};
} PSMC2ASDCbits_t;
extern volatile PSMC2ASDCbits_t PSMC2ASDCbits __at(0xEBD);

# 11119
extern volatile unsigned char PSMC2ASDL __at(0xEBE);

asm("PSMC2ASDL equ 0EBEh");


typedef union {
struct {
unsigned P2ASDLA :1;
unsigned P2ASDLB :1;
};
} PSMC2ASDLbits_t;
extern volatile PSMC2ASDLbits_t PSMC2ASDLbits __at(0xEBE);

# 11145
extern volatile unsigned char PSMC2ASDS __at(0xEBF);

asm("PSMC2ASDS equ 0EBFh");


typedef union {
struct {
unsigned :1;
unsigned P2ASDSC1 :1;
unsigned P2ASDSC2 :1;
unsigned P2ASDSC3 :1;
unsigned P2ASDSC4 :1;
unsigned :2;
unsigned P2ASDSIN :1;
};
} PSMC2ASDSbits_t;
extern volatile PSMC2ASDSbits_t PSMC2ASDSbits __at(0xEBF);

# 11191
extern volatile unsigned char PSMC2INT __at(0xEC0);

asm("PSMC2INT equ 0EC0h");


typedef union {
struct {
unsigned P2TPRIF :1;
unsigned P2TDCIF :1;
unsigned P2TPHIF :1;
unsigned P2TOVIF :1;
unsigned P2TPRIE :1;
unsigned P2TDCIE :1;
unsigned P2TPHIE :1;
unsigned P2TOVIE :1;
};
} PSMC2INTbits_t;
extern volatile PSMC2INTbits_t PSMC2INTbits __at(0xEC0);

# 11253
extern volatile unsigned short PSMC2PH __at(0xEC1);

asm("PSMC2PH equ 0EC1h");




extern volatile unsigned char PSMC2PHL __at(0xEC1);

asm("PSMC2PHL equ 0EC1h");


typedef union {
struct {
unsigned PSMC2PH0 :1;
unsigned PSMC2PH1 :1;
unsigned PSMC2PH2 :1;
unsigned PSMC2PH3 :1;
unsigned PSMC2PH4 :1;
unsigned PSMC2PH5 :1;
unsigned PSMC2PH6 :1;
unsigned PSMC2PH7 :1;
};
} PSMC2PHLbits_t;
extern volatile PSMC2PHLbits_t PSMC2PHLbits __at(0xEC1);

# 11322
extern volatile unsigned char PSMC2PHH __at(0xEC2);

asm("PSMC2PHH equ 0EC2h");


typedef union {
struct {
unsigned PSMC2PH8 :1;
unsigned PSMC2PH9 :1;
unsigned PSMC2PH10 :1;
unsigned PSMC2PH11 :1;
unsigned PSMC2PH12 :1;
unsigned PSMC2PH13 :1;
unsigned PSMC2PH14 :1;
unsigned PSMC2PH15 :1;
};
} PSMC2PHHbits_t;
extern volatile PSMC2PHHbits_t PSMC2PHHbits __at(0xEC2);

# 11384
extern volatile unsigned short PSMC2DC __at(0xEC3);

asm("PSMC2DC equ 0EC3h");




extern volatile unsigned char PSMC2DCL __at(0xEC3);

asm("PSMC2DCL equ 0EC3h");


typedef union {
struct {
unsigned PSMC2DC0 :1;
unsigned PSMC2DC1 :1;
unsigned PSMC2DC2 :1;
unsigned PSMC2DC3 :1;
unsigned PSMC2DC4 :1;
unsigned PSMC2DC5 :1;
unsigned PSMC2DC6 :1;
unsigned PSMC2DC7 :1;
};
} PSMC2DCLbits_t;
extern volatile PSMC2DCLbits_t PSMC2DCLbits __at(0xEC3);

# 11453
extern volatile unsigned char PSMC2DCH __at(0xEC4);

asm("PSMC2DCH equ 0EC4h");


typedef union {
struct {
unsigned PSMC2DC8 :1;
unsigned PSMC2DC9 :1;
unsigned PSMC2DC10 :1;
unsigned PSMC2DC11 :1;
unsigned PSMC2DC12 :1;
unsigned PSMC2DC13 :1;
unsigned PSMC2DC14 :1;
unsigned PSMC2DC15 :1;
};
} PSMC2DCHbits_t;
extern volatile PSMC2DCHbits_t PSMC2DCHbits __at(0xEC4);

# 11515
extern volatile unsigned short PSMC2PR __at(0xEC5);

asm("PSMC2PR equ 0EC5h");




extern volatile unsigned char PSMC2PRL __at(0xEC5);

asm("PSMC2PRL equ 0EC5h");


typedef union {
struct {
unsigned PSMC2PR0 :1;
unsigned PSMC2PR1 :1;
unsigned PSMC2PR2 :1;
unsigned PSMC2PR3 :1;
unsigned PSMC2PR4 :1;
unsigned PSMC2PR5 :1;
unsigned PSMC2PR6 :1;
unsigned PSMC2PR7 :1;
};
} PSMC2PRLbits_t;
extern volatile PSMC2PRLbits_t PSMC2PRLbits __at(0xEC5);

# 11584
extern volatile unsigned char PSMC2PRH __at(0xEC6);

asm("PSMC2PRH equ 0EC6h");


typedef union {
struct {
unsigned PSMC2PR8 :1;
unsigned PSMC2PR9 :1;
unsigned PSMC2PR10 :1;
unsigned PSMC2PR11 :1;
unsigned PSMC2PR12 :1;
unsigned PSMC2PR13 :1;
unsigned PSMC2PR14 :1;
unsigned PSMC2PR15 :1;
};
} PSMC2PRHbits_t;
extern volatile PSMC2PRHbits_t PSMC2PRHbits __at(0xEC6);

# 11646
extern volatile unsigned short PSMC2TMR __at(0xEC7);

asm("PSMC2TMR equ 0EC7h");




extern volatile unsigned char PSMC2TMRL __at(0xEC7);

asm("PSMC2TMRL equ 0EC7h");


typedef union {
struct {
unsigned PSMC2TMR0 :1;
unsigned PSMC2TMR1 :1;
unsigned PSMC2TMR2 :1;
unsigned PSMC2TMR3 :1;
unsigned PSMC2TMR4 :1;
unsigned PSMC2TMR5 :1;
unsigned PSMC2TMR6 :1;
unsigned PSMC2TMR7 :1;
};
} PSMC2TMRLbits_t;
extern volatile PSMC2TMRLbits_t PSMC2TMRLbits __at(0xEC7);

# 11715
extern volatile unsigned char PSMC2TMRH __at(0xEC8);

asm("PSMC2TMRH equ 0EC8h");


typedef union {
struct {
unsigned PSMC2TMR8 :1;
unsigned PSMC2TMR9 :1;
unsigned PSMC2TMR10 :1;
unsigned PSMC2TMR11 :1;
unsigned PSMC2TMR12 :1;
unsigned PSMC2TMR13 :1;
unsigned PSMC2TMR14 :1;
unsigned PSMC2TMR15 :1;
};
} PSMC2TMRHbits_t;
extern volatile PSMC2TMRHbits_t PSMC2TMRHbits __at(0xEC8);

# 11777
extern volatile unsigned char PSMC2DBR __at(0xEC9);

asm("PSMC2DBR equ 0EC9h");


typedef union {
struct {
unsigned PSMC2DBR0 :1;
unsigned PSMC2DBR1 :1;
unsigned PSMC2DBR2 :1;
unsigned PSMC2DBR3 :1;
unsigned PSMC2DBR4 :1;
unsigned PSMC2DBR5 :1;
unsigned PSMC2DBR6 :1;
unsigned PSMC2DBR7 :1;
};
} PSMC2DBRbits_t;
extern volatile PSMC2DBRbits_t PSMC2DBRbits __at(0xEC9);

# 11839
extern volatile unsigned char PSMC2DBF __at(0xECA);

asm("PSMC2DBF equ 0ECAh");


typedef union {
struct {
unsigned PSMC2DBF0 :1;
unsigned PSMC2DBF1 :1;
unsigned PSMC2DBF2 :1;
unsigned PSMC2DBF3 :1;
unsigned PSMC2DBF4 :1;
unsigned PSMC2DBF5 :1;
unsigned PSMC2DBF6 :1;
unsigned PSMC2DBF7 :1;
};
} PSMC2DBFbits_t;
extern volatile PSMC2DBFbits_t PSMC2DBFbits __at(0xECA);

# 11901
extern volatile unsigned char PSMC2BLKR __at(0xECB);

asm("PSMC2BLKR equ 0ECBh");


typedef union {
struct {
unsigned PSMC2BLKR0 :1;
unsigned PSMC2BLKR1 :1;
unsigned PSMC2BLKR2 :1;
unsigned PSMC2BLKR3 :1;
unsigned PSMC2BLKR4 :1;
unsigned PSMC2BLKR5 :1;
unsigned PSMC2BLKR6 :1;
unsigned PSMC2BLKR7 :1;
};
} PSMC2BLKRbits_t;
extern volatile PSMC2BLKRbits_t PSMC2BLKRbits __at(0xECB);

# 11963
extern volatile unsigned char PSMC2BLKF __at(0xECC);

asm("PSMC2BLKF equ 0ECCh");


typedef union {
struct {
unsigned PSMC2BLKF0 :1;
unsigned PSMC2BLKF1 :1;
unsigned PSMC2BLKF2 :1;
unsigned PSMC2BLKF3 :1;
unsigned PSMC2BLKF4 :1;
unsigned PSMC2BLKF5 :1;
unsigned PSMC2BLKF6 :1;
unsigned PSMC2BLKF7 :1;
};
} PSMC2BLKFbits_t;
extern volatile PSMC2BLKFbits_t PSMC2BLKFbits __at(0xECC);

# 12025
extern volatile unsigned char PSMC2FFA __at(0xECD);

asm("PSMC2FFA equ 0ECDh");


typedef union {
struct {
unsigned PSMC2FFA0 :1;
unsigned PSMC2FFA1 :1;
unsigned PSMC2FFA2 :1;
unsigned PSMC2FFA3 :1;
};
} PSMC2FFAbits_t;
extern volatile PSMC2FFAbits_t PSMC2FFAbits __at(0xECD);

# 12063
extern volatile unsigned char PSMC2STR0 __at(0xECE);

asm("PSMC2STR0 equ 0ECEh");


typedef union {
struct {
unsigned P2STRA :1;
unsigned P2STRB :1;
};
} PSMC2STR0bits_t;
extern volatile PSMC2STR0bits_t PSMC2STR0bits __at(0xECE);

# 12089
extern volatile unsigned char PSMC2STR1 __at(0xECF);

asm("PSMC2STR1 equ 0ECFh");


typedef union {
struct {
unsigned P2HSMEN :1;
unsigned P2LSMEN :1;
unsigned :5;
unsigned P2SSYNC :1;
};
} PSMC2STR1bits_t;
extern volatile PSMC2STR1bits_t PSMC2STR1bits __at(0xECF);

# 12122
extern volatile unsigned char PSMC3CON __at(0xED1);

asm("PSMC3CON equ 0ED1h");


typedef union {
struct {
unsigned P3MODE :4;
unsigned P3DBRE :1;
unsigned P3DBFE :1;
unsigned PSMC3LD :1;
unsigned PSMC3EN :1;
};
struct {
unsigned P3MODE0 :1;
unsigned P3MODE1 :1;
unsigned P3MODE2 :1;
unsigned P3MODE3 :1;
};
} PSMC3CONbits_t;
extern volatile PSMC3CONbits_t PSMC3CONbits __at(0xED1);

# 12192
extern volatile unsigned char PSMC3MDL __at(0xED2);

asm("PSMC3MDL equ 0ED2h");


typedef union {
struct {
unsigned P3MSRC :4;
unsigned :1;
unsigned P3MDLBIT :1;
unsigned P3MDLPOL :1;
unsigned P3MDLEN :1;
};
struct {
unsigned P3MSRC0 :1;
unsigned P3MSRC1 :1;
unsigned P3MSRC2 :1;
unsigned P3MSRC3 :1;
};
} PSMC3MDLbits_t;
extern volatile PSMC3MDLbits_t PSMC3MDLbits __at(0xED2);

# 12257
extern volatile unsigned char PSMC3SYNC __at(0xED3);

asm("PSMC3SYNC equ 0ED3h");


typedef union {
struct {
unsigned P3SYNC0 :1;
unsigned P3SYNC1 :1;
unsigned P3SYNC2 :1;
unsigned :2;
unsigned P3DCPOL :1;
unsigned P3PRPOL :1;
unsigned P3POFST :1;
};
} PSMC3SYNCbits_t;
extern volatile PSMC3SYNCbits_t PSMC3SYNCbits __at(0xED3);

# 12308
extern volatile unsigned char PSMC3CLK __at(0xED4);

asm("PSMC3CLK equ 0ED4h");


typedef union {
struct {
unsigned P3CSRC0 :1;
unsigned P3CSRC1 :1;
unsigned :2;
unsigned P3CPRE0 :1;
unsigned P3CPRE1 :1;
};
struct {
unsigned P3CSRC :2;
unsigned :2;
unsigned P3CPRE :2;
};
} PSMC3CLKbits_t;
extern volatile PSMC3CLKbits_t PSMC3CLKbits __at(0xED4);

# 12362
extern volatile unsigned char PSMC3OEN __at(0xED5);

asm("PSMC3OEN equ 0ED5h");


typedef union {
struct {
unsigned P3OEA :1;
unsigned P3OEB :1;
};
} PSMC3OENbits_t;
extern volatile PSMC3OENbits_t PSMC3OENbits __at(0xED5);

# 12388
extern volatile unsigned char PSMC3POL __at(0xED6);

asm("PSMC3POL equ 0ED6h");


typedef union {
struct {
unsigned P3POLA :1;
unsigned P3POLB :1;
unsigned :4;
unsigned P3INPOL :1;
};
} PSMC3POLbits_t;
extern volatile PSMC3POLbits_t PSMC3POLbits __at(0xED6);

# 12421
extern volatile unsigned char PSMC3BLNK __at(0xED7);

asm("PSMC3BLNK equ 0ED7h");


typedef union {
struct {
unsigned P3REBM :2;
unsigned :2;
unsigned P3FEBM :2;
};
struct {
unsigned P3REBM0 :1;
unsigned P3REBM1 :1;
unsigned :2;
unsigned P3FEBM0 :1;
unsigned P3FEBM1 :1;
};
} PSMC3BLNKbits_t;
extern volatile PSMC3BLNKbits_t PSMC3BLNKbits __at(0xED7);

# 12475
extern volatile unsigned char PSMC3REBS __at(0xED8);

asm("PSMC3REBS equ 0ED8h");


typedef union {
struct {
unsigned :1;
unsigned P3REBSC1 :1;
unsigned P3REBSC2 :1;
unsigned P3REBSC3 :1;
unsigned P3REBSC4 :1;
unsigned :2;
unsigned P3REBSIN :1;
};
} PSMC3REBSbits_t;
extern volatile PSMC3REBSbits_t PSMC3REBSbits __at(0xED8);

# 12521
extern volatile unsigned char PSMC3FEBS __at(0xED9);

asm("PSMC3FEBS equ 0ED9h");


typedef union {
struct {
unsigned :1;
unsigned P3FEBSC1 :1;
unsigned P3FEBSC2 :1;
unsigned P3FEBSC3 :1;
unsigned P3FEBSC4 :1;
unsigned :2;
unsigned P3FEBSIN :1;
};
} PSMC3FEBSbits_t;
extern volatile PSMC3FEBSbits_t PSMC3FEBSbits __at(0xED9);

# 12567
extern volatile unsigned char PSMC3PHS __at(0xEDA);

asm("PSMC3PHS equ 0EDAh");


typedef union {
struct {
unsigned P3PHST :1;
unsigned P3PHSC1 :1;
unsigned P3PHSC2 :1;
unsigned P3PHSC3 :1;
unsigned P3PHSC4 :1;
unsigned :2;
unsigned P3PHSIN :1;
};
} PSMC3PHSbits_t;
extern volatile PSMC3PHSbits_t PSMC3PHSbits __at(0xEDA);

# 12618
extern volatile unsigned char PSMC3DCS __at(0xEDB);

asm("PSMC3DCS equ 0EDBh");


typedef union {
struct {
unsigned P3DCST :1;
unsigned P3DCSC1 :1;
unsigned P3DCSC2 :1;
unsigned P3DCSC3 :1;
unsigned P3DCSC4 :1;
unsigned :2;
unsigned P3DCSIN :1;
};
} PSMC3DCSbits_t;
extern volatile PSMC3DCSbits_t PSMC3DCSbits __at(0xEDB);

# 12669
extern volatile unsigned char PSMC3PRS __at(0xEDC);

asm("PSMC3PRS equ 0EDCh");


typedef union {
struct {
unsigned P3PRST :1;
unsigned P3PRSC1 :1;
unsigned P3PRSC2 :1;
unsigned P3PRSC3 :1;
unsigned P3PRSC4 :1;
unsigned :2;
unsigned P3PRSIN :1;
};
} PSMC3PRSbits_t;
extern volatile PSMC3PRSbits_t PSMC3PRSbits __at(0xEDC);

# 12720
extern volatile unsigned char PSMC3ASDC __at(0xEDD);

asm("PSMC3ASDC equ 0EDDh");


typedef union {
struct {
unsigned P3ASDOV :1;
unsigned :4;
unsigned P3ARSEN :1;
unsigned P3ASDEN :1;
unsigned P3ASE :1;
};
} PSMC3ASDCbits_t;
extern volatile PSMC3ASDCbits_t PSMC3ASDCbits __at(0xEDD);

# 12759
extern volatile unsigned char PSMC3ASDL __at(0xEDE);

asm("PSMC3ASDL equ 0EDEh");


typedef union {
struct {
unsigned P3ASDLA :1;
unsigned P3ASDLB :1;
};
} PSMC3ASDLbits_t;
extern volatile PSMC3ASDLbits_t PSMC3ASDLbits __at(0xEDE);

# 12785
extern volatile unsigned char PSMC3ASDS __at(0xEDF);

asm("PSMC3ASDS equ 0EDFh");


typedef union {
struct {
unsigned :1;
unsigned P3ASDSC1 :1;
unsigned P3ASDSC2 :1;
unsigned P3ASDSC3 :1;
unsigned P3ASDSC4 :1;
unsigned :2;
unsigned P3ASDSIN :1;
};
} PSMC3ASDSbits_t;
extern volatile PSMC3ASDSbits_t PSMC3ASDSbits __at(0xEDF);

# 12831
extern volatile unsigned char PSMC3INT __at(0xEE0);

asm("PSMC3INT equ 0EE0h");


typedef union {
struct {
unsigned P3TPRIF :1;
unsigned P3TDCIF :1;
unsigned P3TPHIF :1;
unsigned P3TOVIF :1;
unsigned P3TPRIE :1;
unsigned P3TDCIE :1;
unsigned P3TPHIE :1;
unsigned P3TOVIE :1;
};
} PSMC3INTbits_t;
extern volatile PSMC3INTbits_t PSMC3INTbits __at(0xEE0);

# 12893
extern volatile unsigned short PSMC3PH __at(0xEE1);

asm("PSMC3PH equ 0EE1h");




extern volatile unsigned char PSMC3PHL __at(0xEE1);

asm("PSMC3PHL equ 0EE1h");


typedef union {
struct {
unsigned PSMC3PH0 :1;
unsigned PSMC3PH1 :1;
unsigned PSMC3PH2 :1;
unsigned PSMC3PH3 :1;
unsigned PSMC3PH4 :1;
unsigned PSMC3PH5 :1;
unsigned PSMC3PH6 :1;
unsigned PSMC3PH7 :1;
};
} PSMC3PHLbits_t;
extern volatile PSMC3PHLbits_t PSMC3PHLbits __at(0xEE1);

# 12962
extern volatile unsigned char PSMC3PHH __at(0xEE2);

asm("PSMC3PHH equ 0EE2h");


typedef union {
struct {
unsigned PSMC3PH8 :1;
unsigned PSMC3PH9 :1;
unsigned PSMC3PH10 :1;
unsigned PSMC3PH11 :1;
unsigned PSMC3PH12 :1;
unsigned PSMC3PH13 :1;
unsigned PSMC3PH14 :1;
unsigned PSMC3PH15 :1;
};
} PSMC3PHHbits_t;
extern volatile PSMC3PHHbits_t PSMC3PHHbits __at(0xEE2);

# 13024
extern volatile unsigned short PSMC3DC __at(0xEE3);

asm("PSMC3DC equ 0EE3h");




extern volatile unsigned char PSMC3DCL __at(0xEE3);

asm("PSMC3DCL equ 0EE3h");


typedef union {
struct {
unsigned PSMC3DC0 :1;
unsigned PSMC3DC1 :1;
unsigned PSMC3DC2 :1;
unsigned PSMC3DC3 :1;
unsigned PSMC3DC4 :1;
unsigned PSMC3DC5 :1;
unsigned PSMC3DC6 :1;
unsigned PSMC3DC7 :1;
};
} PSMC3DCLbits_t;
extern volatile PSMC3DCLbits_t PSMC3DCLbits __at(0xEE3);

# 13093
extern volatile unsigned char PSMC3DCH __at(0xEE4);

asm("PSMC3DCH equ 0EE4h");


typedef union {
struct {
unsigned PSMC3DC8 :1;
unsigned PSMC3DC9 :1;
unsigned PSMC3DC10 :1;
unsigned PSMC3DC11 :1;
unsigned PSMC3DC12 :1;
unsigned PSMC3DC13 :1;
unsigned PSMC3DC14 :1;
unsigned PSMC3DC15 :1;
};
} PSMC3DCHbits_t;
extern volatile PSMC3DCHbits_t PSMC3DCHbits __at(0xEE4);

# 13155
extern volatile unsigned short PSMC3PR __at(0xEE5);

asm("PSMC3PR equ 0EE5h");




extern volatile unsigned char PSMC3PRL __at(0xEE5);

asm("PSMC3PRL equ 0EE5h");


typedef union {
struct {
unsigned PSMC3PR0 :1;
unsigned PSMC3PR1 :1;
unsigned PSMC3PR2 :1;
unsigned PSMC3PR3 :1;
unsigned PSMC3PR4 :1;
unsigned PSMC3PR5 :1;
unsigned PSMC3PR6 :1;
unsigned PSMC3PR7 :1;
};
} PSMC3PRLbits_t;
extern volatile PSMC3PRLbits_t PSMC3PRLbits __at(0xEE5);

# 13224
extern volatile unsigned char PSMC3PRH __at(0xEE6);

asm("PSMC3PRH equ 0EE6h");


typedef union {
struct {
unsigned PSMC3PR8 :1;
unsigned PSMC3PR9 :1;
unsigned PSMC3PR10 :1;
unsigned PSMC3PR11 :1;
unsigned PSMC3PR12 :1;
unsigned PSMC3PR13 :1;
unsigned PSMC3PR14 :1;
unsigned PSMC3PR15 :1;
};
} PSMC3PRHbits_t;
extern volatile PSMC3PRHbits_t PSMC3PRHbits __at(0xEE6);

# 13286
extern volatile unsigned short PSMC3TMR __at(0xEE7);

asm("PSMC3TMR equ 0EE7h");




extern volatile unsigned char PSMC3TMRL __at(0xEE7);

asm("PSMC3TMRL equ 0EE7h");


typedef union {
struct {
unsigned PSMC3TMR0 :1;
unsigned PSMC3TMR1 :1;
unsigned PSMC3TMR2 :1;
unsigned PSMC3TMR3 :1;
unsigned PSMC3TMR4 :1;
unsigned PSMC3TMR5 :1;
unsigned PSMC3TMR6 :1;
unsigned PSMC3TMR7 :1;
};
} PSMC3TMRLbits_t;
extern volatile PSMC3TMRLbits_t PSMC3TMRLbits __at(0xEE7);

# 13355
extern volatile unsigned char PSMC3TMRH __at(0xEE8);

asm("PSMC3TMRH equ 0EE8h");


typedef union {
struct {
unsigned PSMC3TMR8 :1;
unsigned PSMC3TMR9 :1;
unsigned PSMC3TMR10 :1;
unsigned PSMC3TMR11 :1;
unsigned PSMC3TMR12 :1;
unsigned PSMC3TMR13 :1;
unsigned PSMC3TMR14 :1;
unsigned PSMC3TMR15 :1;
};
} PSMC3TMRHbits_t;
extern volatile PSMC3TMRHbits_t PSMC3TMRHbits __at(0xEE8);

# 13417
extern volatile unsigned char PSMC3DBR __at(0xEE9);

asm("PSMC3DBR equ 0EE9h");


typedef union {
struct {
unsigned PSMC3DBR0 :1;
unsigned PSMC3DBR1 :1;
unsigned PSMC3DBR2 :1;
unsigned PSMC3DBR3 :1;
unsigned PSMC3DBR4 :1;
unsigned PSMC3DBR5 :1;
unsigned PSMC3DBR6 :1;
unsigned PSMC3DBR7 :1;
};
} PSMC3DBRbits_t;
extern volatile PSMC3DBRbits_t PSMC3DBRbits __at(0xEE9);

# 13479
extern volatile unsigned char PSMC3DBF __at(0xEEA);

asm("PSMC3DBF equ 0EEAh");


typedef union {
struct {
unsigned PSMC3DBF0 :1;
unsigned PSMC3DBF1 :1;
unsigned PSMC3DBF2 :1;
unsigned PSMC3DBF3 :1;
unsigned PSMC3DBF4 :1;
unsigned PSMC3DBF5 :1;
unsigned PSMC3DBF6 :1;
unsigned PSMC3DBF7 :1;
};
} PSMC3DBFbits_t;
extern volatile PSMC3DBFbits_t PSMC3DBFbits __at(0xEEA);

# 13541
extern volatile unsigned char PSMC3BLKR __at(0xEEB);

asm("PSMC3BLKR equ 0EEBh");


typedef union {
struct {
unsigned PSMC3BLKR0 :1;
unsigned PSMC3BLKR1 :1;
unsigned PSMC3BLKR2 :1;
unsigned PSMC3BLKR3 :1;
unsigned PSMC3BLKR4 :1;
unsigned PSMC3BLKR5 :1;
unsigned PSMC3BLKR6 :1;
unsigned PSMC3BLKR7 :1;
};
} PSMC3BLKRbits_t;
extern volatile PSMC3BLKRbits_t PSMC3BLKRbits __at(0xEEB);

# 13603
extern volatile unsigned char PSMC3BLKF __at(0xEEC);

asm("PSMC3BLKF equ 0EECh");


typedef union {
struct {
unsigned PSMC3BLKF0 :1;
unsigned PSMC3BLKF1 :1;
unsigned PSMC3BLKF2 :1;
unsigned PSMC3BLKF3 :1;
unsigned PSMC3BLKF4 :1;
unsigned PSMC3BLKF5 :1;
unsigned PSMC3BLKF6 :1;
unsigned PSMC3BLKF7 :1;
};
} PSMC3BLKFbits_t;
extern volatile PSMC3BLKFbits_t PSMC3BLKFbits __at(0xEEC);

# 13665
extern volatile unsigned char PSMC3FFA __at(0xEED);

asm("PSMC3FFA equ 0EEDh");


typedef union {
struct {
unsigned PSMC3FFA0 :1;
unsigned PSMC3FFA1 :1;
unsigned PSMC3FFA2 :1;
unsigned PSMC3FFA3 :1;
};
} PSMC3FFAbits_t;
extern volatile PSMC3FFAbits_t PSMC3FFAbits __at(0xEED);

# 13703
extern volatile unsigned char PSMC3STR0 __at(0xEEE);

asm("PSMC3STR0 equ 0EEEh");


typedef union {
struct {
unsigned P3STRA :1;
unsigned P3STRB :1;
};
} PSMC3STR0bits_t;
extern volatile PSMC3STR0bits_t PSMC3STR0bits __at(0xEEE);

# 13729
extern volatile unsigned char PSMC3STR1 __at(0xEEF);

asm("PSMC3STR1 equ 0EEFh");


typedef union {
struct {
unsigned P3HSMEN :1;
unsigned P3LSMEN :1;
unsigned :5;
unsigned P3SSYNC :1;
};
} PSMC3STR1bits_t;
extern volatile PSMC3STR1bits_t PSMC3STR1bits __at(0xEEF);

# 13762
extern volatile unsigned char PSMC4CON __at(0xF11);

asm("PSMC4CON equ 0F11h");


typedef union {
struct {
unsigned P4MODE :4;
unsigned P4DBRE :1;
unsigned P4DBFE :1;
unsigned PSMC4LD :1;
unsigned PSMC4EN :1;
};
struct {
unsigned P4MODE0 :1;
unsigned P4MODE1 :1;
unsigned P4MODE2 :1;
unsigned P4MODE3 :1;
};
} PSMC4CONbits_t;
extern volatile PSMC4CONbits_t PSMC4CONbits __at(0xF11);

# 13832
extern volatile unsigned char PSMC4MDL __at(0xF12);

asm("PSMC4MDL equ 0F12h");


typedef union {
struct {
unsigned P4MSRC :4;
unsigned :1;
unsigned P4MDLBIT :1;
unsigned P4MDLPOL :1;
unsigned P4MDLEN :1;
};
struct {
unsigned P4MSRC0 :1;
unsigned P4MSRC1 :1;
unsigned P4MSRC2 :1;
unsigned P4MSRC3 :1;
};
} PSMC4MDLbits_t;
extern volatile PSMC4MDLbits_t PSMC4MDLbits __at(0xF12);

# 13897
extern volatile unsigned char PSMC4SYNC __at(0xF13);

asm("PSMC4SYNC equ 0F13h");


typedef union {
struct {
unsigned P4SYNC0 :1;
unsigned P4SYNC1 :1;
unsigned P4SYNC2 :1;
unsigned :2;
unsigned P4DCPOL :1;
unsigned P4PRPOL :1;
unsigned P4POFST :1;
};
} PSMC4SYNCbits_t;
extern volatile PSMC4SYNCbits_t PSMC4SYNCbits __at(0xF13);

# 13948
extern volatile unsigned char PSMC4CLK __at(0xF14);

asm("PSMC4CLK equ 0F14h");


typedef union {
struct {
unsigned P4CSRC0 :1;
unsigned P4CSRC1 :1;
unsigned :2;
unsigned P4CPRE0 :1;
unsigned P4CPRE1 :1;
};
struct {
unsigned P4CSRC :2;
unsigned :2;
unsigned P4CPRE :2;
};
} PSMC4CLKbits_t;
extern volatile PSMC4CLKbits_t PSMC4CLKbits __at(0xF14);

# 14002
extern volatile unsigned char PSMC4OEN __at(0xF15);

asm("PSMC4OEN equ 0F15h");


typedef union {
struct {
unsigned P4OEA :1;
unsigned P4OEB :1;
};
} PSMC4OENbits_t;
extern volatile PSMC4OENbits_t PSMC4OENbits __at(0xF15);

# 14028
extern volatile unsigned char PSMC4POL __at(0xF16);

asm("PSMC4POL equ 0F16h");


typedef union {
struct {
unsigned P4POLA :1;
unsigned P4POLB :1;
unsigned :4;
unsigned P4INPOL :1;
};
} PSMC4POLbits_t;
extern volatile PSMC4POLbits_t PSMC4POLbits __at(0xF16);

# 14061
extern volatile unsigned char PSMC4BLNK __at(0xF17);

asm("PSMC4BLNK equ 0F17h");


typedef union {
struct {
unsigned P4REBM :2;
unsigned :2;
unsigned P4FEBM :2;
};
struct {
unsigned P4REBM0 :1;
unsigned P4REBM1 :1;
unsigned :2;
unsigned P4FEBM0 :1;
unsigned P4FEBM1 :1;
};
} PSMC4BLNKbits_t;
extern volatile PSMC4BLNKbits_t PSMC4BLNKbits __at(0xF17);

# 14115
extern volatile unsigned char PSMC4REBS __at(0xF18);

asm("PSMC4REBS equ 0F18h");


typedef union {
struct {
unsigned :1;
unsigned P4REBSC1 :1;
unsigned P4REBSC2 :1;
unsigned P4REBSC3 :1;
unsigned P4REBSC4 :1;
unsigned :2;
unsigned P4REBSIN :1;
};
} PSMC4REBSbits_t;
extern volatile PSMC4REBSbits_t PSMC4REBSbits __at(0xF18);

# 14161
extern volatile unsigned char PSMC4FEBS __at(0xF19);

asm("PSMC4FEBS equ 0F19h");


typedef union {
struct {
unsigned :1;
unsigned P4FEBSC1 :1;
unsigned P4FEBSC2 :1;
unsigned P4FEBSC3 :1;
unsigned P4FEBSC4 :1;
unsigned :2;
unsigned P4FEBSIN :1;
};
} PSMC4FEBSbits_t;
extern volatile PSMC4FEBSbits_t PSMC4FEBSbits __at(0xF19);

# 14207
extern volatile unsigned char PSMC4PHS __at(0xF1A);

asm("PSMC4PHS equ 0F1Ah");


typedef union {
struct {
unsigned P4PHST :1;
unsigned P4PHSC1 :1;
unsigned P4PHSC2 :1;
unsigned P4PHSC3 :1;
unsigned P4PHSC4 :1;
unsigned :2;
unsigned P4PHSIN :1;
};
} PSMC4PHSbits_t;
extern volatile PSMC4PHSbits_t PSMC4PHSbits __at(0xF1A);

# 14258
extern volatile unsigned char PSMC4DCS __at(0xF1B);

asm("PSMC4DCS equ 0F1Bh");


typedef union {
struct {
unsigned P4DCST :1;
unsigned P4DCSC1 :1;
unsigned P4DCSC2 :1;
unsigned P4DCSC3 :1;
unsigned P4DCSC4 :1;
unsigned :2;
unsigned P4DCSIN :1;
};
} PSMC4DCSbits_t;
extern volatile PSMC4DCSbits_t PSMC4DCSbits __at(0xF1B);

# 14309
extern volatile unsigned char PSMC4PRS __at(0xF1C);

asm("PSMC4PRS equ 0F1Ch");


typedef union {
struct {
unsigned P4PRST :1;
unsigned P4PRSC1 :1;
unsigned P4PRSC2 :1;
unsigned P4PRSC3 :1;
unsigned P4PRSC4 :1;
unsigned :2;
unsigned P4PRSIN :1;
};
} PSMC4PRSbits_t;
extern volatile PSMC4PRSbits_t PSMC4PRSbits __at(0xF1C);

# 14360
extern volatile unsigned char PSMC4ASDC __at(0xF1D);

asm("PSMC4ASDC equ 0F1Dh");


typedef union {
struct {
unsigned P4ASDOV :1;
unsigned :4;
unsigned P4ARSEN :1;
unsigned P4ASDEN :1;
unsigned P4ASE :1;
};
} PSMC4ASDCbits_t;
extern volatile PSMC4ASDCbits_t PSMC4ASDCbits __at(0xF1D);

# 14399
extern volatile unsigned char PSMC4ASDL __at(0xF1E);

asm("PSMC4ASDL equ 0F1Eh");


typedef union {
struct {
unsigned P4ASDLA :1;
unsigned P4ASDLB :1;
};
} PSMC4ASDLbits_t;
extern volatile PSMC4ASDLbits_t PSMC4ASDLbits __at(0xF1E);

# 14425
extern volatile unsigned char PSMC4ASDS __at(0xF1F);

asm("PSMC4ASDS equ 0F1Fh");


typedef union {
struct {
unsigned :1;
unsigned P4ASDSC1 :1;
unsigned P4ASDSC2 :1;
unsigned P4ASDSC3 :1;
unsigned P4ASDSC4 :1;
unsigned :2;
unsigned P4ASDSIN :1;
};
} PSMC4ASDSbits_t;
extern volatile PSMC4ASDSbits_t PSMC4ASDSbits __at(0xF1F);

# 14471
extern volatile unsigned char PSMC4INT __at(0xF20);

asm("PSMC4INT equ 0F20h");


typedef union {
struct {
unsigned P4TPRIF :1;
unsigned P4TDCIF :1;
unsigned P4TPHIF :1;
unsigned P4TOVIF :1;
unsigned P4TPRIE :1;
unsigned P4TDCIE :1;
unsigned P4TPHIE :1;
unsigned P4TOVIE :1;
};
} PSMC4INTbits_t;
extern volatile PSMC4INTbits_t PSMC4INTbits __at(0xF20);

# 14533
extern volatile unsigned short PSMC4PH __at(0xF21);

asm("PSMC4PH equ 0F21h");




extern volatile unsigned char PSMC4PHL __at(0xF21);

asm("PSMC4PHL equ 0F21h");


typedef union {
struct {
unsigned PSMC4PH0 :1;
unsigned PSMC4PH1 :1;
unsigned PSMC4PH2 :1;
unsigned PSMC4PH3 :1;
unsigned PSMC4PH4 :1;
unsigned PSMC4PH5 :1;
unsigned PSMC4PH6 :1;
unsigned PSMC4PH7 :1;
};
} PSMC4PHLbits_t;
extern volatile PSMC4PHLbits_t PSMC4PHLbits __at(0xF21);

# 14602
extern volatile unsigned char PSMC4PHH __at(0xF22);

asm("PSMC4PHH equ 0F22h");


typedef union {
struct {
unsigned PSMC4PH8 :1;
unsigned PSMC4PH9 :1;
unsigned PSMC4PH10 :1;
unsigned PSMC4PH11 :1;
unsigned PSMC4PH12 :1;
unsigned PSMC4PH13 :1;
unsigned PSMC4PH14 :1;
unsigned PSMC4PH15 :1;
};
} PSMC4PHHbits_t;
extern volatile PSMC4PHHbits_t PSMC4PHHbits __at(0xF22);

# 14664
extern volatile unsigned short PSMC4DC __at(0xF23);

asm("PSMC4DC equ 0F23h");




extern volatile unsigned char PSMC4DCL __at(0xF23);

asm("PSMC4DCL equ 0F23h");


typedef union {
struct {
unsigned PSMC4DC0 :1;
unsigned PSMC4DC1 :1;
unsigned PSMC4DC2 :1;
unsigned PSMC4DC3 :1;
unsigned PSMC4DC4 :1;
unsigned PSMC4DC5 :1;
unsigned PSMC4DC6 :1;
unsigned PSMC4DC7 :1;
};
} PSMC4DCLbits_t;
extern volatile PSMC4DCLbits_t PSMC4DCLbits __at(0xF23);

# 14733
extern volatile unsigned char PSMC4DCH __at(0xF24);

asm("PSMC4DCH equ 0F24h");


typedef union {
struct {
unsigned PSMC4DC8 :1;
unsigned PSMC4DC9 :1;
unsigned PSMC4DC10 :1;
unsigned PSMC4DC11 :1;
unsigned PSMC4DC12 :1;
unsigned PSMC4DC13 :1;
unsigned PSMC4DC14 :1;
unsigned PSMC4DC15 :1;
};
} PSMC4DCHbits_t;
extern volatile PSMC4DCHbits_t PSMC4DCHbits __at(0xF24);

# 14795
extern volatile unsigned short PSMC4PR __at(0xF25);

asm("PSMC4PR equ 0F25h");




extern volatile unsigned char PSMC4PRL __at(0xF25);

asm("PSMC4PRL equ 0F25h");


typedef union {
struct {
unsigned PSMC4PR0 :1;
unsigned PSMC4PR1 :1;
unsigned PSMC4PR2 :1;
unsigned PSMC4PR3 :1;
unsigned PSMC4PR4 :1;
unsigned PSMC4PR5 :1;
unsigned PSMC4PR6 :1;
unsigned PSMC4PR7 :1;
};
} PSMC4PRLbits_t;
extern volatile PSMC4PRLbits_t PSMC4PRLbits __at(0xF25);

# 14864
extern volatile unsigned char PSMC4PRH __at(0xF26);

asm("PSMC4PRH equ 0F26h");


typedef union {
struct {
unsigned PSMC4PR8 :1;
unsigned PSMC4PR9 :1;
unsigned PSMC4PR10 :1;
unsigned PSMC4PR11 :1;
unsigned PSMC4PR12 :1;
unsigned PSMC4PR13 :1;
unsigned PSMC4PR14 :1;
unsigned PSMC4PR15 :1;
};
} PSMC4PRHbits_t;
extern volatile PSMC4PRHbits_t PSMC4PRHbits __at(0xF26);

# 14926
extern volatile unsigned short PSMC4TMR __at(0xF27);

asm("PSMC4TMR equ 0F27h");




extern volatile unsigned char PSMC4TMRL __at(0xF27);

asm("PSMC4TMRL equ 0F27h");


typedef union {
struct {
unsigned PSMC4TMR0 :1;
unsigned PSMC4TMR1 :1;
unsigned PSMC4TMR2 :1;
unsigned PSMC4TMR3 :1;
unsigned PSMC4TMR4 :1;
unsigned PSMC4TMR5 :1;
unsigned PSMC4TMR6 :1;
unsigned PSMC4TMR7 :1;
};
} PSMC4TMRLbits_t;
extern volatile PSMC4TMRLbits_t PSMC4TMRLbits __at(0xF27);

# 14995
extern volatile unsigned char PSMC4TMRH __at(0xF28);

asm("PSMC4TMRH equ 0F28h");


typedef union {
struct {
unsigned PSMC4TMR8 :1;
unsigned PSMC4TMR9 :1;
unsigned PSMC4TMR10 :1;
unsigned PSMC4TMR11 :1;
unsigned PSMC4TMR12 :1;
unsigned PSMC4TMR13 :1;
unsigned PSMC4TMR14 :1;
unsigned PSMC4TMR15 :1;
};
} PSMC4TMRHbits_t;
extern volatile PSMC4TMRHbits_t PSMC4TMRHbits __at(0xF28);

# 15057
extern volatile unsigned char PSMC4DBR __at(0xF29);

asm("PSMC4DBR equ 0F29h");


typedef union {
struct {
unsigned PSMC4DBR0 :1;
unsigned PSMC4DBR1 :1;
unsigned PSMC4DBR2 :1;
unsigned PSMC4DBR3 :1;
unsigned PSMC4DBR4 :1;
unsigned PSMC4DBR5 :1;
unsigned PSMC4DBR6 :1;
unsigned PSMC4DBR7 :1;
};
} PSMC4DBRbits_t;
extern volatile PSMC4DBRbits_t PSMC4DBRbits __at(0xF29);

# 15119
extern volatile unsigned char PSMC4DBF __at(0xF2A);

asm("PSMC4DBF equ 0F2Ah");


typedef union {
struct {
unsigned PSMC4DBF0 :1;
unsigned PSMC4DBF1 :1;
unsigned PSMC4DBF2 :1;
unsigned PSMC4DBF3 :1;
unsigned PSMC4DBF4 :1;
unsigned PSMC4DBF5 :1;
unsigned PSMC4DBF6 :1;
unsigned PSMC4DBF7 :1;
};
} PSMC4DBFbits_t;
extern volatile PSMC4DBFbits_t PSMC4DBFbits __at(0xF2A);

# 15181
extern volatile unsigned char PSMC4BLKR __at(0xF2B);

asm("PSMC4BLKR equ 0F2Bh");


typedef union {
struct {
unsigned PSMC4BLKR0 :1;
unsigned PSMC4BLKR1 :1;
unsigned PSMC4BLKR2 :1;
unsigned PSMC4BLKR3 :1;
unsigned PSMC4BLKR4 :1;
unsigned PSMC4BLKR5 :1;
unsigned PSMC4BLKR6 :1;
unsigned PSMC4BLKR7 :1;
};
} PSMC4BLKRbits_t;
extern volatile PSMC4BLKRbits_t PSMC4BLKRbits __at(0xF2B);

# 15243
extern volatile unsigned char PSMC4BLKF __at(0xF2C);

asm("PSMC4BLKF equ 0F2Ch");


typedef union {
struct {
unsigned PSMC4BLKF0 :1;
unsigned PSMC4BLKF1 :1;
unsigned PSMC4BLKF2 :1;
unsigned PSMC4BLKF3 :1;
unsigned PSMC4BLKF4 :1;
unsigned PSMC4BLKF5 :1;
unsigned PSMC4BLKF6 :1;
unsigned PSMC4BLKF7 :1;
};
} PSMC4BLKFbits_t;
extern volatile PSMC4BLKFbits_t PSMC4BLKFbits __at(0xF2C);

# 15305
extern volatile unsigned char PSMC4FFA __at(0xF2D);

asm("PSMC4FFA equ 0F2Dh");


typedef union {
struct {
unsigned PSMC4FFA0 :1;
unsigned PSMC4FFA1 :1;
unsigned PSMC4FFA2 :1;
unsigned PSMC4FFA3 :1;
};
} PSMC4FFAbits_t;
extern volatile PSMC4FFAbits_t PSMC4FFAbits __at(0xF2D);

# 15343
extern volatile unsigned char PSMC4STR0 __at(0xF2E);

asm("PSMC4STR0 equ 0F2Eh");


typedef union {
struct {
unsigned P4STRA :1;
unsigned P4STRB :1;
};
} PSMC4STR0bits_t;
extern volatile PSMC4STR0bits_t PSMC4STR0bits __at(0xF2E);

# 15369
extern volatile unsigned char PSMC4STR1 __at(0xF2F);

asm("PSMC4STR1 equ 0F2Fh");


typedef union {
struct {
unsigned P4HSMEN :1;
unsigned P4LSMEN :1;
unsigned :5;
unsigned P4SSYNC :1;
};
} PSMC4STR1bits_t;
extern volatile PSMC4STR1bits_t PSMC4STR1bits __at(0xF2F);

# 15402
extern volatile unsigned char STATUS_SHAD __at(0xFE4);

asm("STATUS_SHAD equ 0FE4h");


typedef union {
struct {
unsigned C_SHAD :1;
unsigned DC_SHAD :1;
unsigned Z_SHAD :1;
};
} STATUS_SHADbits_t;
extern volatile STATUS_SHADbits_t STATUS_SHADbits __at(0xFE4);

# 15434
extern volatile unsigned char WREG_SHAD __at(0xFE5);

asm("WREG_SHAD equ 0FE5h");


typedef union {
struct {
unsigned WREG_SHAD :8;
};
} WREG_SHADbits_t;
extern volatile WREG_SHADbits_t WREG_SHADbits __at(0xFE5);

# 15454
extern volatile unsigned char BSR_SHAD __at(0xFE6);

asm("BSR_SHAD equ 0FE6h");


typedef union {
struct {
unsigned BSR_SHAD :5;
};
} BSR_SHADbits_t;
extern volatile BSR_SHADbits_t BSR_SHADbits __at(0xFE6);

# 15474
extern volatile unsigned char PCLATH_SHAD __at(0xFE7);

asm("PCLATH_SHAD equ 0FE7h");


typedef union {
struct {
unsigned PCLATH_SHAD :7;
};
} PCLATH_SHADbits_t;
extern volatile PCLATH_SHADbits_t PCLATH_SHADbits __at(0xFE7);

# 15494
extern volatile unsigned char FSR0L_SHAD __at(0xFE8);

asm("FSR0L_SHAD equ 0FE8h");


typedef union {
struct {
unsigned FSR0L_SHAD :8;
};
} FSR0L_SHADbits_t;
extern volatile FSR0L_SHADbits_t FSR0L_SHADbits __at(0xFE8);

# 15514
extern volatile unsigned char FSR0H_SHAD __at(0xFE9);

asm("FSR0H_SHAD equ 0FE9h");


typedef union {
struct {
unsigned FSR0H_SHAD :8;
};
} FSR0H_SHADbits_t;
extern volatile FSR0H_SHADbits_t FSR0H_SHADbits __at(0xFE9);

# 15534
extern volatile unsigned char FSR1L_SHAD __at(0xFEA);

asm("FSR1L_SHAD equ 0FEAh");


typedef union {
struct {
unsigned FSR1L_SHAD :8;
};
} FSR1L_SHADbits_t;
extern volatile FSR1L_SHADbits_t FSR1L_SHADbits __at(0xFEA);

# 15554
extern volatile unsigned char FSR1H_SHAD __at(0xFEB);

asm("FSR1H_SHAD equ 0FEBh");


typedef union {
struct {
unsigned FSR1H_SHAD :8;
};
} FSR1H_SHADbits_t;
extern volatile FSR1H_SHADbits_t FSR1H_SHADbits __at(0xFEB);

# 15574
extern volatile unsigned char STKPTR __at(0xFED);

asm("STKPTR equ 0FEDh");


typedef union {
struct {
unsigned STKPTR :5;
};
} STKPTRbits_t;
extern volatile STKPTRbits_t STKPTRbits __at(0xFED);

# 15594
extern volatile unsigned char TOSL __at(0xFEE);

asm("TOSL equ 0FEEh");


typedef union {
struct {
unsigned TOSL :8;
};
} TOSLbits_t;
extern volatile TOSLbits_t TOSLbits __at(0xFEE);

# 15614
extern volatile unsigned char TOSH __at(0xFEF);

asm("TOSH equ 0FEFh");


typedef union {
struct {
unsigned TOSH :7;
};
} TOSHbits_t;
extern volatile TOSHbits_t TOSHbits __at(0xFEF);

# 15644
extern volatile __bit ABDEN __at(0xCF8);


extern volatile __bit ABDOVF __at(0xCFF);


extern volatile __bit ACKDT __at(0x10B5);


extern volatile __bit ACKEN __at(0x10B4);


extern volatile __bit ACKSTAT __at(0x10B6);


extern volatile __bit ACKTIM __at(0x10BF);


extern volatile __bit ADCS0 __at(0x4F4);


extern volatile __bit ADCS1 __at(0x4F5);


extern volatile __bit ADCS2 __at(0x4F6);


extern volatile __bit ADD0 __at(0x1090);


extern volatile __bit ADD1 __at(0x1091);


extern volatile __bit ADD2 __at(0x1092);


extern volatile __bit ADD3 __at(0x1093);


extern volatile __bit ADD4 __at(0x1094);


extern volatile __bit ADD5 __at(0x1095);


extern volatile __bit ADD6 __at(0x1096);


extern volatile __bit ADD7 __at(0x1097);


extern volatile __bit ADDEN __at(0xCEB);


extern volatile __bit ADFM __at(0x4F7);


extern volatile __bit ADFVR0 __at(0x8B8);


extern volatile __bit ADFVR1 __at(0x8B9);


extern volatile __bit ADGO __at(0x4E9);


extern volatile __bit ADIE __at(0x48E);


extern volatile __bit ADIF __at(0x8E);


extern volatile __bit ADNREF __at(0x4F2);


extern volatile __bit ADON __at(0x4E8);


extern volatile __bit ADPREF0 __at(0x4F0);


extern volatile __bit ADPREF1 __at(0x4F1);


extern volatile __bit ADRMD __at(0x4EF);


extern volatile __bit AHEN __at(0x10B9);


extern volatile __bit ANSA0 __at(0xC60);


extern volatile __bit ANSA1 __at(0xC61);


extern volatile __bit ANSA2 __at(0xC62);


extern volatile __bit ANSA3 __at(0xC63);


extern volatile __bit ANSA4 __at(0xC64);


extern volatile __bit ANSA5 __at(0xC65);


extern volatile __bit ANSA7 __at(0xC67);


extern volatile __bit ANSB0 __at(0xC68);


extern volatile __bit ANSB1 __at(0xC69);


extern volatile __bit ANSB2 __at(0xC6A);


extern volatile __bit ANSB3 __at(0xC6B);


extern volatile __bit ANSB4 __at(0xC6C);


extern volatile __bit ANSB5 __at(0xC6D);


extern volatile __bit ANSB6 __at(0xC6E);


extern volatile __bit ANSC0 __at(0xC70);


extern volatile __bit ANSC1 __at(0xC71);


extern volatile __bit ANSC2 __at(0xC72);


extern volatile __bit ANSC3 __at(0xC73);


extern volatile __bit ANSC4 __at(0xC74);


extern volatile __bit ANSC5 __at(0xC75);


extern volatile __bit ANSC6 __at(0xC76);


extern volatile __bit ANSC7 __at(0xC77);


extern volatile __bit BCL1IE __at(0x493);


extern volatile __bit BCL1IF __at(0x93);


extern volatile __bit BF __at(0x10A0);


extern volatile __bit BOEN __at(0x10BC);


extern volatile __bit BORFS __at(0x8B6);


extern volatile __bit BORRDY __at(0x8B0);


extern volatile __bit BRG16 __at(0xCFB);


extern volatile __bit BRGH __at(0xCF2);


extern volatile __bit BSR0 __at(0x40);


extern volatile __bit BSR1 __at(0x41);


extern volatile __bit BSR2 __at(0x42);


extern volatile __bit BSR3 __at(0x43);


extern volatile __bit BSR4 __at(0x44);


extern volatile __bit BUF0 __at(0x1088);


extern volatile __bit BUF1 __at(0x1089);


extern volatile __bit BUF2 __at(0x108A);


extern volatile __bit BUF3 __at(0x108B);


extern volatile __bit BUF4 __at(0x108C);


extern volatile __bit BUF5 __at(0x108D);


extern volatile __bit BUF6 __at(0x108E);


extern volatile __bit BUF7 __at(0x108F);


extern volatile __bit C1HYS __at(0x889);


extern volatile __bit C1IE __at(0x495);


extern volatile __bit C1IF __at(0x95);


extern volatile __bit C1INTN __at(0x896);


extern volatile __bit C1INTP __at(0x897);


extern volatile __bit C1NCH0 __at(0x890);


extern volatile __bit C1NCH1 __at(0x891);


extern volatile __bit C1NCH2 __at(0x892);


extern volatile __bit C1OE __at(0x88D);


extern volatile __bit C1ON __at(0x88F);


extern volatile __bit C1OUT __at(0x88E);


extern volatile __bit C1PCH0 __at(0x893);


extern volatile __bit C1PCH1 __at(0x894);


extern volatile __bit C1PCH2 __at(0x895);


extern volatile __bit C1POL __at(0x88C);


extern volatile __bit C1SP __at(0x88A);


extern volatile __bit C1SYNC __at(0x888);


extern volatile __bit C1ZLF __at(0x88B);


extern volatile __bit C2HYS __at(0x899);


extern volatile __bit C2IE __at(0x496);


extern volatile __bit C2IF __at(0x96);


extern volatile __bit C2INTN __at(0x8A6);


extern volatile __bit C2INTP __at(0x8A7);


extern volatile __bit C2NCH0 __at(0x8A0);


extern volatile __bit C2NCH1 __at(0x8A1);


extern volatile __bit C2NCH2 __at(0x8A2);


extern volatile __bit C2OE __at(0x89D);


extern volatile __bit C2ON __at(0x89F);


extern volatile __bit C2OUT __at(0x89E);


extern volatile __bit C2OUTSEL __at(0x8EF);


extern volatile __bit C2PCH0 __at(0x8A3);


extern volatile __bit C2PCH1 __at(0x8A4);


extern volatile __bit C2PCH2 __at(0x8A5);


extern volatile __bit C2POL __at(0x89C);


extern volatile __bit C2SP __at(0x89A);


extern volatile __bit C2SYNC __at(0x898);


extern volatile __bit C2ZLF __at(0x89B);


extern volatile __bit C3HYS __at(0x8F1);


extern volatile __bit C3IE __at(0x491);


extern volatile __bit C3IF __at(0x91);


extern volatile __bit C3INTN __at(0x8FE);


extern volatile __bit C3INTP __at(0x8FF);


extern volatile __bit C3NCH0 __at(0x8F8);


extern volatile __bit C3NCH1 __at(0x8F9);


extern volatile __bit C3NCH2 __at(0x8FA);


extern volatile __bit C3OE __at(0x8F5);


extern volatile __bit C3ON __at(0x8F7);


extern volatile __bit C3OUT __at(0x8F6);


extern volatile __bit C3PCH0 __at(0x8FB);


extern volatile __bit C3PCH1 __at(0x8FC);


extern volatile __bit C3PCH2 __at(0x8FD);


extern volatile __bit C3POL __at(0x8F4);


extern volatile __bit C3SP __at(0x8F2);


extern volatile __bit C3SYNC __at(0x8F0);


extern volatile __bit C3ZLF __at(0x8F3);


extern volatile __bit C4HYS __at(0x8D1);


extern volatile __bit C4IE __at(0x492);


extern volatile __bit C4IF __at(0x92);


extern volatile __bit C4INTN __at(0x8DE);


extern volatile __bit C4INTP __at(0x8DF);


extern volatile __bit C4NCH0 __at(0x8D8);


extern volatile __bit C4NCH1 __at(0x8D9);


extern volatile __bit C4NCH2 __at(0x8DA);


extern volatile __bit C4OE __at(0x8D5);


extern volatile __bit C4ON __at(0x8D7);


extern volatile __bit C4OUT __at(0x8D6);


extern volatile __bit C4PCH0 __at(0x8DB);


extern volatile __bit C4PCH1 __at(0x8DC);


extern volatile __bit C4PCH2 __at(0x8DD);


extern volatile __bit C4POL __at(0x8D4);


extern volatile __bit C4SP __at(0x8D2);


extern volatile __bit C4SYNC __at(0x8D0);


extern volatile __bit C4ZLF __at(0x8D3);


extern volatile __bit CARRY __at(0x18);


extern volatile __bit CCP1IE __at(0x48A);


extern volatile __bit CCP1IF __at(0x8A);


extern volatile __bit CCP1M0 __at(0x1498);


extern volatile __bit CCP1M1 __at(0x1499);


extern volatile __bit CCP1M2 __at(0x149A);


extern volatile __bit CCP1M3 __at(0x149B);


extern volatile __bit CCP1SEL __at(0x8EE);


extern volatile __bit CCP2IE __at(0x490);


extern volatile __bit CCP2IF __at(0x90);


extern volatile __bit CCP2M0 __at(0x14D0);


extern volatile __bit CCP2M1 __at(0x14D1);


extern volatile __bit CCP2M2 __at(0x14D2);


extern volatile __bit CCP2M3 __at(0x14D3);


extern volatile __bit CCP2SEL __at(0x8E8);


extern volatile __bit CCP3IE __at(0x49C);


extern volatile __bit CCP3IF __at(0x9C);


extern volatile __bit CCP3M0 __at(0x1898);


extern volatile __bit CCP3M1 __at(0x1899);


extern volatile __bit CCP3M2 __at(0x189A);


extern volatile __bit CCP3M3 __at(0x189B);


extern volatile __bit CCP3SEL __at(0x8E0);


extern volatile __bit CDAFVR0 __at(0x8BA);


extern volatile __bit CDAFVR1 __at(0x8BB);


extern volatile __bit CFGS __at(0xCAE);


extern volatile __bit CHS0 __at(0x4EA);


extern volatile __bit CHS1 __at(0x4EB);


extern volatile __bit CHS2 __at(0x4EC);


extern volatile __bit CHS3 __at(0x4ED);


extern volatile __bit CHS4 __at(0x4EE);


extern volatile __bit CHSN0 __at(0x4F8);


extern volatile __bit CHSN1 __at(0x4F9);


extern volatile __bit CHSN2 __at(0x4FA);


extern volatile __bit CHSN3 __at(0x4FB);


extern volatile __bit CKE __at(0x10A6);


extern volatile __bit CKP __at(0x10AC);


extern volatile __bit CLKRDC0 __at(0x28D3);


extern volatile __bit CLKRDC1 __at(0x28D4);


extern volatile __bit CLKRDIV0 __at(0x28D0);


extern volatile __bit CLKRDIV1 __at(0x28D1);


extern volatile __bit CLKRDIV2 __at(0x28D2);


extern volatile __bit CLKREN __at(0x28D7);


extern volatile __bit CLKROE __at(0x28D6);


extern volatile __bit CLKRSLR __at(0x28D5);


extern volatile __bit CREN __at(0xCEC);


extern volatile __bit CSRC __at(0xCF7);


extern volatile __bit C_SHAD __at(0x7F20);


extern volatile __bit DAC1EN __at(0x8C7);


extern volatile __bit DAC1NSS __at(0x8C0);


extern volatile __bit DAC1OE1 __at(0x8C5);


extern volatile __bit DAC1OE2 __at(0x8C4);


extern volatile __bit DAC1PSS0 __at(0x8C2);


extern volatile __bit DAC1PSS1 __at(0x8C3);


extern volatile __bit DAC1R0 __at(0x8C8);


extern volatile __bit DAC1R1 __at(0x8C9);


extern volatile __bit DAC1R2 __at(0x8CA);


extern volatile __bit DAC1R3 __at(0x8CB);


extern volatile __bit DAC1R4 __at(0x8CC);


extern volatile __bit DAC1R5 __at(0x8CD);


extern volatile __bit DAC1R6 __at(0x8CE);


extern volatile __bit DAC1R7 __at(0x8CF);


extern volatile __bit DAC2EN __at(0x2C8F);


extern volatile __bit DAC2OE1 __at(0x2C8D);


extern volatile __bit DAC2OE2 __at(0x2C8C);


extern volatile __bit DAC3EN __at(0x2C9F);


extern volatile __bit DAC3OE1 __at(0x2C9D);


extern volatile __bit DAC3OE2 __at(0x2C9C);


extern volatile __bit DAC4EN __at(0x2CAF);


extern volatile __bit DAC4OE1 __at(0x2CAD);


extern volatile __bit DAC4OE2 __at(0x2CAC);


extern volatile __bit DACEN __at(0x8C7);


extern volatile __bit DACNSS __at(0x8C0);


extern volatile __bit DACOE0 __at(0x8C4);


extern volatile __bit DACOE1 __at(0x8C5);


extern volatile __bit DACPSS0 __at(0x8C2);


extern volatile __bit DACPSS1 __at(0x8C3);


extern volatile __bit DACR0 __at(0x8C8);


extern volatile __bit DACR1 __at(0x8C9);


extern volatile __bit DACR2 __at(0x8CA);


extern volatile __bit DACR3 __at(0x8CB);


extern volatile __bit DACR4 __at(0x8CC);


extern volatile __bit DACR5 __at(0x8CD);


extern volatile __bit DACR6 __at(0x8CE);


extern volatile __bit DACR7 __at(0x8CF);


extern volatile __bit DC __at(0x19);


extern volatile __bit DC1B0 __at(0x149C);


extern volatile __bit DC1B1 __at(0x149D);


extern volatile __bit DC2B0 __at(0x14D4);


extern volatile __bit DC2B1 __at(0x14D5);


extern volatile __bit DC3B0 __at(0x189C);


extern volatile __bit DC3B1 __at(0x189D);


extern volatile __bit DC_SHAD __at(0x7F21);


extern volatile __bit DHEN __at(0x10B8);


extern volatile __bit DONE __at(0x4E9);


extern volatile __bit D_nA __at(0x10A5);


extern volatile __bit EEIE __at(0x494);


extern volatile __bit EEIF __at(0x94);


extern volatile __bit EEPGD __at(0xCAF);


extern volatile __bit FERR __at(0xCEA);


extern volatile __bit FREE __at(0xCAC);


extern volatile __bit FVREN __at(0x8BF);


extern volatile __bit FVRRDY __at(0x8BE);


extern volatile __bit GCEN __at(0x10B7);


extern volatile __bit GIE __at(0x5F);


extern volatile __bit GO __at(0x4E9);


extern volatile __bit GO_nDONE __at(0x4E9);


extern volatile __bit HFIOFL __at(0x4D3);


extern volatile __bit HFIOFR __at(0x4D4);


extern volatile __bit HFIOFS __at(0x4D0);


extern volatile __bit INLVLA0 __at(0x1C60);


extern volatile __bit INLVLA1 __at(0x1C61);


extern volatile __bit INLVLA2 __at(0x1C62);


extern volatile __bit INLVLA3 __at(0x1C63);


extern volatile __bit INLVLA4 __at(0x1C64);


extern volatile __bit INLVLA5 __at(0x1C65);


extern volatile __bit INLVLA6 __at(0x1C66);


extern volatile __bit INLVLA7 __at(0x1C67);


extern volatile __bit INLVLB0 __at(0x1C68);


extern volatile __bit INLVLB1 __at(0x1C69);


extern volatile __bit INLVLB2 __at(0x1C6A);


extern volatile __bit INLVLB3 __at(0x1C6B);


extern volatile __bit INLVLB4 __at(0x1C6C);


extern volatile __bit INLVLB5 __at(0x1C6D);


extern volatile __bit INLVLB6 __at(0x1C6E);


extern volatile __bit INLVLB7 __at(0x1C6F);


extern volatile __bit INLVLC0 __at(0x1C70);


extern volatile __bit INLVLC1 __at(0x1C71);


extern volatile __bit INLVLC2 __at(0x1C72);


extern volatile __bit INLVLC3 __at(0x1C73);


extern volatile __bit INLVLC4 __at(0x1C74);


extern volatile __bit INLVLC5 __at(0x1C75);


extern volatile __bit INLVLC6 __at(0x1C76);


extern volatile __bit INLVLC7 __at(0x1C77);


extern volatile __bit INLVLE3 __at(0x1C83);


extern volatile __bit INTE __at(0x5C);


extern volatile __bit INTEDG __at(0x4AE);


extern volatile __bit INTF __at(0x59);


extern volatile __bit IOCAF0 __at(0x1C98);


extern volatile __bit IOCAF1 __at(0x1C99);


extern volatile __bit IOCAF2 __at(0x1C9A);


extern volatile __bit IOCAF3 __at(0x1C9B);


extern volatile __bit IOCAF4 __at(0x1C9C);


extern volatile __bit IOCAF5 __at(0x1C9D);


extern volatile __bit IOCAF6 __at(0x1C9E);


extern volatile __bit IOCAF7 __at(0x1C9F);


extern volatile __bit IOCAN0 __at(0x1C90);


extern volatile __bit IOCAN1 __at(0x1C91);


extern volatile __bit IOCAN2 __at(0x1C92);


extern volatile __bit IOCAN3 __at(0x1C93);


extern volatile __bit IOCAN4 __at(0x1C94);


extern volatile __bit IOCAN5 __at(0x1C95);


extern volatile __bit IOCAN6 __at(0x1C96);


extern volatile __bit IOCAN7 __at(0x1C97);


extern volatile __bit IOCAP0 __at(0x1C88);


extern volatile __bit IOCAP1 __at(0x1C89);


extern volatile __bit IOCAP2 __at(0x1C8A);


extern volatile __bit IOCAP3 __at(0x1C8B);


extern volatile __bit IOCAP4 __at(0x1C8C);


extern volatile __bit IOCAP5 __at(0x1C8D);


extern volatile __bit IOCAP6 __at(0x1C8E);


extern volatile __bit IOCAP7 __at(0x1C8F);


extern volatile __bit IOCBF0 __at(0x1CB0);


extern volatile __bit IOCBF1 __at(0x1CB1);


extern volatile __bit IOCBF2 __at(0x1CB2);


extern volatile __bit IOCBF3 __at(0x1CB3);


extern volatile __bit IOCBF4 __at(0x1CB4);


extern volatile __bit IOCBF5 __at(0x1CB5);


extern volatile __bit IOCBF6 __at(0x1CB6);


extern volatile __bit IOCBF7 __at(0x1CB7);


extern volatile __bit IOCBN0 __at(0x1CA8);


extern volatile __bit IOCBN1 __at(0x1CA9);


extern volatile __bit IOCBN2 __at(0x1CAA);


extern volatile __bit IOCBN3 __at(0x1CAB);


extern volatile __bit IOCBN4 __at(0x1CAC);


extern volatile __bit IOCBN5 __at(0x1CAD);


extern volatile __bit IOCBN6 __at(0x1CAE);


extern volatile __bit IOCBN7 __at(0x1CAF);


extern volatile __bit IOCBP0 __at(0x1CA0);


extern volatile __bit IOCBP1 __at(0x1CA1);


extern volatile __bit IOCBP2 __at(0x1CA2);


extern volatile __bit IOCBP3 __at(0x1CA3);


extern volatile __bit IOCBP4 __at(0x1CA4);


extern volatile __bit IOCBP5 __at(0x1CA5);


extern volatile __bit IOCBP6 __at(0x1CA6);


extern volatile __bit IOCBP7 __at(0x1CA7);


extern volatile __bit IOCCF0 __at(0x1CC8);


extern volatile __bit IOCCF1 __at(0x1CC9);


extern volatile __bit IOCCF2 __at(0x1CCA);


extern volatile __bit IOCCF3 __at(0x1CCB);


extern volatile __bit IOCCF4 __at(0x1CCC);


extern volatile __bit IOCCF5 __at(0x1CCD);


extern volatile __bit IOCCF6 __at(0x1CCE);


extern volatile __bit IOCCF7 __at(0x1CCF);


extern volatile __bit IOCCN0 __at(0x1CC0);


extern volatile __bit IOCCN1 __at(0x1CC1);


extern volatile __bit IOCCN2 __at(0x1CC2);


extern volatile __bit IOCCN3 __at(0x1CC3);


extern volatile __bit IOCCN4 __at(0x1CC4);


extern volatile __bit IOCCN5 __at(0x1CC5);


extern volatile __bit IOCCN6 __at(0x1CC6);


extern volatile __bit IOCCN7 __at(0x1CC7);


extern volatile __bit IOCCP0 __at(0x1CB8);


extern volatile __bit IOCCP1 __at(0x1CB9);


extern volatile __bit IOCCP2 __at(0x1CBA);


extern volatile __bit IOCCP3 __at(0x1CBB);


extern volatile __bit IOCCP4 __at(0x1CBC);


extern volatile __bit IOCCP5 __at(0x1CBD);


extern volatile __bit IOCCP6 __at(0x1CBE);


extern volatile __bit IOCCP7 __at(0x1CBF);


extern volatile __bit IOCEF3 __at(0x1CFB);


extern volatile __bit IOCEN3 __at(0x1CF3);


extern volatile __bit IOCEP3 __at(0x1CEB);


extern volatile __bit IOCIE __at(0x5B);


extern volatile __bit IOCIF __at(0x58);


extern volatile __bit IRCF0 __at(0x4CB);


extern volatile __bit IRCF1 __at(0x4CC);


extern volatile __bit IRCF2 __at(0x4CD);


extern volatile __bit IRCF3 __at(0x4CE);


extern volatile __bit LATA0 __at(0x860);


extern volatile __bit LATA1 __at(0x861);


extern volatile __bit LATA2 __at(0x862);


extern volatile __bit LATA3 __at(0x863);


extern volatile __bit LATA4 __at(0x864);


extern volatile __bit LATA5 __at(0x865);


extern volatile __bit LATA6 __at(0x866);


extern volatile __bit LATA7 __at(0x867);


extern volatile __bit LATB0 __at(0x868);


extern volatile __bit LATB1 __at(0x869);


extern volatile __bit LATB2 __at(0x86A);


extern volatile __bit LATB3 __at(0x86B);


extern volatile __bit LATB4 __at(0x86C);


extern volatile __bit LATB5 __at(0x86D);


extern volatile __bit LATB6 __at(0x86E);


extern volatile __bit LATB7 __at(0x86F);


extern volatile __bit LATC0 __at(0x870);


extern volatile __bit LATC1 __at(0x871);


extern volatile __bit LATC2 __at(0x872);


extern volatile __bit LATC3 __at(0x873);


extern volatile __bit LATC4 __at(0x874);


extern volatile __bit LATC5 __at(0x875);


extern volatile __bit LATC6 __at(0x876);


extern volatile __bit LATC7 __at(0x877);


extern volatile __bit LFIOFR __at(0x4D1);


extern volatile __bit LWLO __at(0xCAD);


extern volatile __bit MC1OUT __at(0x8A8);


extern volatile __bit MC2OUT __at(0x8A9);


extern volatile __bit MC3OUT __at(0x8AA);


extern volatile __bit MC4OUT __at(0x8AB);


extern volatile __bit MFIOFR __at(0x4D2);


extern volatile __bit MSK0 __at(0x1098);


extern volatile __bit MSK1 __at(0x1099);


extern volatile __bit MSK2 __at(0x109A);


extern volatile __bit MSK3 __at(0x109B);


extern volatile __bit MSK4 __at(0x109C);


extern volatile __bit MSK5 __at(0x109D);


extern volatile __bit MSK6 __at(0x109E);


extern volatile __bit MSK7 __at(0x109F);


extern volatile __bit ODCONA0 __at(0x1460);


extern volatile __bit ODCONA1 __at(0x1461);


extern volatile __bit ODCONA2 __at(0x1462);


extern volatile __bit ODCONA3 __at(0x1463);


extern volatile __bit ODCONA4 __at(0x1464);


extern volatile __bit ODCONA5 __at(0x1465);


extern volatile __bit ODCONA6 __at(0x1466);


extern volatile __bit ODCONA7 __at(0x1467);


extern volatile __bit ODCONB0 __at(0x1468);


extern volatile __bit ODCONB1 __at(0x1469);


extern volatile __bit ODCONB2 __at(0x146A);


extern volatile __bit ODCONB3 __at(0x146B);


extern volatile __bit ODCONB4 __at(0x146C);


extern volatile __bit ODCONB5 __at(0x146D);


extern volatile __bit ODCONB6 __at(0x146E);


extern volatile __bit ODCONB7 __at(0x146F);


extern volatile __bit ODCONC0 __at(0x1470);


extern volatile __bit ODCONC1 __at(0x1471);


extern volatile __bit ODCONC2 __at(0x1472);


extern volatile __bit ODCONC3 __at(0x1473);


extern volatile __bit ODCONC4 __at(0x1474);


extern volatile __bit ODCONC5 __at(0x1475);


extern volatile __bit ODCONC6 __at(0x1476);


extern volatile __bit ODCONC7 __at(0x1477);


extern volatile __bit OERR __at(0xCE9);


extern volatile __bit OPA1EN __at(0x288F);


extern volatile __bit OPA1PCH0 __at(0x2888);


extern volatile __bit OPA1PCH1 __at(0x2889);


extern volatile __bit OPA1PCH2 __at(0x288A);


extern volatile __bit OPA1SP __at(0x288E);


extern volatile __bit OPA2EN __at(0x289F);


extern volatile __bit OPA2PCH0 __at(0x2898);


extern volatile __bit OPA2PCH1 __at(0x2899);


extern volatile __bit OPA2PCH2 __at(0x289A);


extern volatile __bit OPA2SP __at(0x289E);


extern volatile __bit OSFIE __at(0x497);


extern volatile __bit OSFIF __at(0x97);


extern volatile __bit OSTS __at(0x4D5);


extern volatile __bit P1ARSEN __at(0x74ED);


extern volatile __bit P1ASDEN __at(0x74EE);


extern volatile __bit P1ASDLA __at(0x74F0);


extern volatile __bit P1ASDLB __at(0x74F1);


extern volatile __bit P1ASDLC __at(0x74F2);


extern volatile __bit P1ASDLD __at(0x74F3);


extern volatile __bit P1ASDLE __at(0x74F4);


extern volatile __bit P1ASDLF __at(0x74F5);


extern volatile __bit P1ASDOV __at(0x74E8);


extern volatile __bit P1ASDSC1 __at(0x74F9);


extern volatile __bit P1ASDSC2 __at(0x74FA);


extern volatile __bit P1ASDSC3 __at(0x74FB);


extern volatile __bit P1ASDSC4 __at(0x74FC);


extern volatile __bit P1ASDSIN __at(0x74FF);


extern volatile __bit P1ASE __at(0x74EF);


extern volatile __bit P1CPRE0 __at(0x74A4);


extern volatile __bit P1CPRE1 __at(0x74A5);


extern volatile __bit P1CSRC0 __at(0x74A0);


extern volatile __bit P1CSRC1 __at(0x74A1);


extern volatile __bit P1DBFE __at(0x748D);


extern volatile __bit P1DBRE __at(0x748C);


extern volatile __bit P1DCPOL __at(0x749D);


extern volatile __bit P1DCSC1 __at(0x74D9);


extern volatile __bit P1DCSC2 __at(0x74DA);


extern volatile __bit P1DCSC3 __at(0x74DB);


extern volatile __bit P1DCSC4 __at(0x74DC);


extern volatile __bit P1DCSIN __at(0x74DF);


extern volatile __bit P1DCST __at(0x74D8);


extern volatile __bit P1FEBM0 __at(0x74BC);


extern volatile __bit P1FEBM1 __at(0x74BD);


extern volatile __bit P1FEBSC1 __at(0x74C9);


extern volatile __bit P1FEBSC2 __at(0x74CA);


extern volatile __bit P1FEBSC3 __at(0x74CB);


extern volatile __bit P1FEBSC4 __at(0x74CC);


extern volatile __bit P1FEBSIN __at(0x74CF);


extern volatile __bit P1HSMEN __at(0x7578);


extern volatile __bit P1INPOL __at(0x74B6);


extern volatile __bit P1LSMEN __at(0x7579);


extern volatile __bit P1MDLBIT __at(0x7495);


extern volatile __bit P1MDLEN __at(0x7497);


extern volatile __bit P1MDLPOL __at(0x7496);


extern volatile __bit P1MODE0 __at(0x7488);


extern volatile __bit P1MODE1 __at(0x7489);


extern volatile __bit P1MODE2 __at(0x748A);


extern volatile __bit P1MODE3 __at(0x748B);


extern volatile __bit P1MSRC0 __at(0x7490);


extern volatile __bit P1MSRC1 __at(0x7491);


extern volatile __bit P1MSRC2 __at(0x7492);


extern volatile __bit P1MSRC3 __at(0x7493);


extern volatile __bit P1OEA __at(0x74A8);


extern volatile __bit P1OEB __at(0x74A9);


extern volatile __bit P1OEC __at(0x74AA);


extern volatile __bit P1OED __at(0x74AB);


extern volatile __bit P1OEE __at(0x74AC);


extern volatile __bit P1OEF __at(0x74AD);


extern volatile __bit P1PHSC1 __at(0x74D1);


extern volatile __bit P1PHSC2 __at(0x74D2);


extern volatile __bit P1PHSC3 __at(0x74D3);


extern volatile __bit P1PHSC4 __at(0x74D4);


extern volatile __bit P1PHSIN __at(0x74D7);


extern volatile __bit P1PHST __at(0x74D0);


extern volatile __bit P1POFST __at(0x749F);


extern volatile __bit P1POLA __at(0x74B0);


extern volatile __bit P1POLB __at(0x74B1);


extern volatile __bit P1POLC __at(0x74B2);


extern volatile __bit P1POLD __at(0x74B3);


extern volatile __bit P1POLE __at(0x74B4);


extern volatile __bit P1POLF __at(0x74B5);


extern volatile __bit P1PRPOL __at(0x749E);


extern volatile __bit P1PRSC1 __at(0x74E1);


extern volatile __bit P1PRSC2 __at(0x74E2);


extern volatile __bit P1PRSC3 __at(0x74E3);


extern volatile __bit P1PRSC4 __at(0x74E4);


extern volatile __bit P1PRSIN __at(0x74E7);


extern volatile __bit P1PRST __at(0x74E0);


extern volatile __bit P1REBM0 __at(0x74B8);


extern volatile __bit P1REBM1 __at(0x74B9);


extern volatile __bit P1REBSC1 __at(0x74C1);


extern volatile __bit P1REBSC2 __at(0x74C2);


extern volatile __bit P1REBSC3 __at(0x74C3);


extern volatile __bit P1REBSC4 __at(0x74C4);


extern volatile __bit P1REBSIN __at(0x74C7);


extern volatile __bit P1SSYNC __at(0x757F);


extern volatile __bit P1STRA __at(0x7570);


extern volatile __bit P1STRB __at(0x7571);


extern volatile __bit P1STRC __at(0x7572);


extern volatile __bit P1STRD __at(0x7573);


extern volatile __bit P1STRE __at(0x7574);


extern volatile __bit P1STRF __at(0x7575);


extern volatile __bit P1SYNC0 __at(0x7498);


extern volatile __bit P1SYNC1 __at(0x7499);


extern volatile __bit P1SYNC2 __at(0x749A);


extern volatile __bit P1TDCIE __at(0x7505);


extern volatile __bit P1TDCIF __at(0x7501);


extern volatile __bit P1TOVIE __at(0x7507);


extern volatile __bit P1TOVIF __at(0x7503);


extern volatile __bit P1TPHIE __at(0x7506);


extern volatile __bit P1TPHIF __at(0x7502);


extern volatile __bit P1TPRIE __at(0x7504);


extern volatile __bit P1TPRIF __at(0x7500);


extern volatile __bit P2ARSEN __at(0x75ED);


extern volatile __bit P2ASDEN __at(0x75EE);


extern volatile __bit P2ASDLA __at(0x75F0);


extern volatile __bit P2ASDLB __at(0x75F1);


extern volatile __bit P2ASDOV __at(0x75E8);


extern volatile __bit P2ASDSC1 __at(0x75F9);


extern volatile __bit P2ASDSC2 __at(0x75FA);


extern volatile __bit P2ASDSC3 __at(0x75FB);


extern volatile __bit P2ASDSC4 __at(0x75FC);


extern volatile __bit P2ASDSIN __at(0x75FF);


extern volatile __bit P2ASE __at(0x75EF);


extern volatile __bit P2CPRE0 __at(0x75A4);


extern volatile __bit P2CPRE1 __at(0x75A5);


extern volatile __bit P2CSRC0 __at(0x75A0);


extern volatile __bit P2CSRC1 __at(0x75A1);


extern volatile __bit P2DBFE __at(0x758D);


extern volatile __bit P2DBRE __at(0x758C);


extern volatile __bit P2DCPOL __at(0x759D);


extern volatile __bit P2DCSC1 __at(0x75D9);


extern volatile __bit P2DCSC2 __at(0x75DA);


extern volatile __bit P2DCSC3 __at(0x75DB);


extern volatile __bit P2DCSC4 __at(0x75DC);


extern volatile __bit P2DCSIN __at(0x75DF);


extern volatile __bit P2DCST __at(0x75D8);


extern volatile __bit P2FEBM0 __at(0x75BC);


extern volatile __bit P2FEBM1 __at(0x75BD);


extern volatile __bit P2FEBSC1 __at(0x75C9);


extern volatile __bit P2FEBSC2 __at(0x75CA);


extern volatile __bit P2FEBSC3 __at(0x75CB);


extern volatile __bit P2FEBSC4 __at(0x75CC);


extern volatile __bit P2FEBSIN __at(0x75CF);


extern volatile __bit P2HSMEN __at(0x7678);


extern volatile __bit P2INPOL __at(0x75B6);


extern volatile __bit P2LSMEN __at(0x7679);


extern volatile __bit P2MDLBIT __at(0x7595);


extern volatile __bit P2MDLEN __at(0x7597);


extern volatile __bit P2MDLPOL __at(0x7596);


extern volatile __bit P2MODE0 __at(0x7588);


extern volatile __bit P2MODE1 __at(0x7589);


extern volatile __bit P2MODE2 __at(0x758A);


extern volatile __bit P2MODE3 __at(0x758B);


extern volatile __bit P2MSRC0 __at(0x7590);


extern volatile __bit P2MSRC1 __at(0x7591);


extern volatile __bit P2MSRC2 __at(0x7592);


extern volatile __bit P2MSRC3 __at(0x7593);


extern volatile __bit P2OEA __at(0x75A8);


extern volatile __bit P2OEB __at(0x75A9);


extern volatile __bit P2PHSC1 __at(0x75D1);


extern volatile __bit P2PHSC2 __at(0x75D2);


extern volatile __bit P2PHSC3 __at(0x75D3);


extern volatile __bit P2PHSC4 __at(0x75D4);


extern volatile __bit P2PHSIN __at(0x75D7);


extern volatile __bit P2PHST __at(0x75D0);


extern volatile __bit P2POFST __at(0x759F);


extern volatile __bit P2POLA __at(0x75B0);


extern volatile __bit P2POLB __at(0x75B1);


extern volatile __bit P2PRPOL __at(0x759E);


extern volatile __bit P2PRSC1 __at(0x75E1);


extern volatile __bit P2PRSC2 __at(0x75E2);


extern volatile __bit P2PRSC3 __at(0x75E3);


extern volatile __bit P2PRSC4 __at(0x75E4);


extern volatile __bit P2PRSIN __at(0x75E7);


extern volatile __bit P2PRST __at(0x75E0);


extern volatile __bit P2REBM0 __at(0x75B8);


extern volatile __bit P2REBM1 __at(0x75B9);


extern volatile __bit P2REBSC1 __at(0x75C1);


extern volatile __bit P2REBSC2 __at(0x75C2);


extern volatile __bit P2REBSC3 __at(0x75C3);


extern volatile __bit P2REBSC4 __at(0x75C4);


extern volatile __bit P2REBSIN __at(0x75C7);


extern volatile __bit P2SSYNC __at(0x767F);


extern volatile __bit P2STRA __at(0x7670);


extern volatile __bit P2STRB __at(0x7671);


extern volatile __bit P2SYNC0 __at(0x7598);


extern volatile __bit P2SYNC1 __at(0x7599);


extern volatile __bit P2SYNC2 __at(0x759A);


extern volatile __bit P2TDCIE __at(0x7605);


extern volatile __bit P2TDCIF __at(0x7601);


extern volatile __bit P2TOVIE __at(0x7607);


extern volatile __bit P2TOVIF __at(0x7603);


extern volatile __bit P2TPHIE __at(0x7606);


extern volatile __bit P2TPHIF __at(0x7602);


extern volatile __bit P2TPRIE __at(0x7604);


extern volatile __bit P2TPRIF __at(0x7600);


extern volatile __bit P3ARSEN __at(0x76ED);


extern volatile __bit P3ASDEN __at(0x76EE);


extern volatile __bit P3ASDLA __at(0x76F0);


extern volatile __bit P3ASDLB __at(0x76F1);


extern volatile __bit P3ASDOV __at(0x76E8);


extern volatile __bit P3ASDSC1 __at(0x76F9);


extern volatile __bit P3ASDSC2 __at(0x76FA);


extern volatile __bit P3ASDSC3 __at(0x76FB);


extern volatile __bit P3ASDSC4 __at(0x76FC);


extern volatile __bit P3ASDSIN __at(0x76FF);


extern volatile __bit P3ASE __at(0x76EF);


extern volatile __bit P3CPRE0 __at(0x76A4);


extern volatile __bit P3CPRE1 __at(0x76A5);


extern volatile __bit P3CSRC0 __at(0x76A0);


extern volatile __bit P3CSRC1 __at(0x76A1);


extern volatile __bit P3DBFE __at(0x768D);


extern volatile __bit P3DBRE __at(0x768C);


extern volatile __bit P3DCPOL __at(0x769D);


extern volatile __bit P3DCSC1 __at(0x76D9);


extern volatile __bit P3DCSC2 __at(0x76DA);


extern volatile __bit P3DCSC3 __at(0x76DB);


extern volatile __bit P3DCSC4 __at(0x76DC);


extern volatile __bit P3DCSIN __at(0x76DF);


extern volatile __bit P3DCST __at(0x76D8);


extern volatile __bit P3FEBM0 __at(0x76BC);


extern volatile __bit P3FEBM1 __at(0x76BD);


extern volatile __bit P3FEBSC1 __at(0x76C9);


extern volatile __bit P3FEBSC2 __at(0x76CA);


extern volatile __bit P3FEBSC3 __at(0x76CB);


extern volatile __bit P3FEBSC4 __at(0x76CC);


extern volatile __bit P3FEBSIN __at(0x76CF);


extern volatile __bit P3HSMEN __at(0x7778);


extern volatile __bit P3INPOL __at(0x76B6);


extern volatile __bit P3LSMEN __at(0x7779);


extern volatile __bit P3MDLBIT __at(0x7695);


extern volatile __bit P3MDLEN __at(0x7697);


extern volatile __bit P3MDLPOL __at(0x7696);


extern volatile __bit P3MODE0 __at(0x7688);


extern volatile __bit P3MODE1 __at(0x7689);


extern volatile __bit P3MODE2 __at(0x768A);


extern volatile __bit P3MODE3 __at(0x768B);


extern volatile __bit P3MSRC0 __at(0x7690);


extern volatile __bit P3MSRC1 __at(0x7691);


extern volatile __bit P3MSRC2 __at(0x7692);


extern volatile __bit P3MSRC3 __at(0x7693);


extern volatile __bit P3OEA __at(0x76A8);


extern volatile __bit P3OEB __at(0x76A9);


extern volatile __bit P3PHSC1 __at(0x76D1);


extern volatile __bit P3PHSC2 __at(0x76D2);


extern volatile __bit P3PHSC3 __at(0x76D3);


extern volatile __bit P3PHSC4 __at(0x76D4);


extern volatile __bit P3PHSIN __at(0x76D7);


extern volatile __bit P3PHST __at(0x76D0);


extern volatile __bit P3POFST __at(0x769F);


extern volatile __bit P3POLA __at(0x76B0);


extern volatile __bit P3POLB __at(0x76B1);


extern volatile __bit P3PRPOL __at(0x769E);


extern volatile __bit P3PRSC1 __at(0x76E1);


extern volatile __bit P3PRSC2 __at(0x76E2);


extern volatile __bit P3PRSC3 __at(0x76E3);


extern volatile __bit P3PRSC4 __at(0x76E4);


extern volatile __bit P3PRSIN __at(0x76E7);


extern volatile __bit P3PRST __at(0x76E0);


extern volatile __bit P3REBM0 __at(0x76B8);


extern volatile __bit P3REBM1 __at(0x76B9);


extern volatile __bit P3REBSC1 __at(0x76C1);


extern volatile __bit P3REBSC2 __at(0x76C2);


extern volatile __bit P3REBSC3 __at(0x76C3);


extern volatile __bit P3REBSC4 __at(0x76C4);


extern volatile __bit P3REBSIN __at(0x76C7);


extern volatile __bit P3SSYNC __at(0x777F);


extern volatile __bit P3STRA __at(0x7770);


extern volatile __bit P3STRB __at(0x7771);


extern volatile __bit P3SYNC0 __at(0x7698);


extern volatile __bit P3SYNC1 __at(0x7699);


extern volatile __bit P3SYNC2 __at(0x769A);


extern volatile __bit P3TDCIE __at(0x7705);


extern volatile __bit P3TDCIF __at(0x7701);


extern volatile __bit P3TOVIE __at(0x7707);


extern volatile __bit P3TOVIF __at(0x7703);


extern volatile __bit P3TPHIE __at(0x7706);


extern volatile __bit P3TPHIF __at(0x7702);


extern volatile __bit P3TPRIE __at(0x7704);


extern volatile __bit P3TPRIF __at(0x7700);


extern volatile __bit P4ARSEN __at(0x78ED);


extern volatile __bit P4ASDEN __at(0x78EE);


extern volatile __bit P4ASDLA __at(0x78F0);


extern volatile __bit P4ASDLB __at(0x78F1);


extern volatile __bit P4ASDOV __at(0x78E8);


extern volatile __bit P4ASDSC1 __at(0x78F9);


extern volatile __bit P4ASDSC2 __at(0x78FA);


extern volatile __bit P4ASDSC3 __at(0x78FB);


extern volatile __bit P4ASDSC4 __at(0x78FC);


extern volatile __bit P4ASDSIN __at(0x78FF);


extern volatile __bit P4ASE __at(0x78EF);


extern volatile __bit P4CPRE0 __at(0x78A4);


extern volatile __bit P4CPRE1 __at(0x78A5);


extern volatile __bit P4CSRC0 __at(0x78A0);


extern volatile __bit P4CSRC1 __at(0x78A1);


extern volatile __bit P4DBFE __at(0x788D);


extern volatile __bit P4DBRE __at(0x788C);


extern volatile __bit P4DCPOL __at(0x789D);


extern volatile __bit P4DCSC1 __at(0x78D9);


extern volatile __bit P4DCSC2 __at(0x78DA);


extern volatile __bit P4DCSC3 __at(0x78DB);


extern volatile __bit P4DCSC4 __at(0x78DC);


extern volatile __bit P4DCSIN __at(0x78DF);


extern volatile __bit P4DCST __at(0x78D8);


extern volatile __bit P4FEBM0 __at(0x78BC);


extern volatile __bit P4FEBM1 __at(0x78BD);


extern volatile __bit P4FEBSC1 __at(0x78C9);


extern volatile __bit P4FEBSC2 __at(0x78CA);


extern volatile __bit P4FEBSC3 __at(0x78CB);


extern volatile __bit P4FEBSC4 __at(0x78CC);


extern volatile __bit P4FEBSIN __at(0x78CF);


extern volatile __bit P4HSMEN __at(0x7978);


extern volatile __bit P4INPOL __at(0x78B6);


extern volatile __bit P4LSMEN __at(0x7979);


extern volatile __bit P4MDLBIT __at(0x7895);


extern volatile __bit P4MDLEN __at(0x7897);


extern volatile __bit P4MDLPOL __at(0x7896);


extern volatile __bit P4MODE0 __at(0x7888);


extern volatile __bit P4MODE1 __at(0x7889);


extern volatile __bit P4MODE2 __at(0x788A);


extern volatile __bit P4MODE3 __at(0x788B);


extern volatile __bit P4MSRC0 __at(0x7890);


extern volatile __bit P4MSRC1 __at(0x7891);


extern volatile __bit P4MSRC2 __at(0x7892);


extern volatile __bit P4MSRC3 __at(0x7893);


extern volatile __bit P4OEA __at(0x78A8);


extern volatile __bit P4OEB __at(0x78A9);


extern volatile __bit P4PHSC1 __at(0x78D1);


extern volatile __bit P4PHSC2 __at(0x78D2);


extern volatile __bit P4PHSC3 __at(0x78D3);


extern volatile __bit P4PHSC4 __at(0x78D4);


extern volatile __bit P4PHSIN __at(0x78D7);


extern volatile __bit P4PHST __at(0x78D0);


extern volatile __bit P4POFST __at(0x789F);


extern volatile __bit P4POLA __at(0x78B0);


extern volatile __bit P4POLB __at(0x78B1);


extern volatile __bit P4PRPOL __at(0x789E);


extern volatile __bit P4PRSC1 __at(0x78E1);


extern volatile __bit P4PRSC2 __at(0x78E2);


extern volatile __bit P4PRSC3 __at(0x78E3);


extern volatile __bit P4PRSC4 __at(0x78E4);


extern volatile __bit P4PRSIN __at(0x78E7);


extern volatile __bit P4PRST __at(0x78E0);


extern volatile __bit P4REBM0 __at(0x78B8);


extern volatile __bit P4REBM1 __at(0x78B9);


extern volatile __bit P4REBSC1 __at(0x78C1);


extern volatile __bit P4REBSC2 __at(0x78C2);


extern volatile __bit P4REBSC3 __at(0x78C3);


extern volatile __bit P4REBSC4 __at(0x78C4);


extern volatile __bit P4REBSIN __at(0x78C7);


extern volatile __bit P4SSYNC __at(0x797F);


extern volatile __bit P4STRA __at(0x7970);


extern volatile __bit P4STRB __at(0x7971);


extern volatile __bit P4SYNC0 __at(0x7898);


extern volatile __bit P4SYNC1 __at(0x7899);


extern volatile __bit P4SYNC2 __at(0x789A);


extern volatile __bit P4TDCIE __at(0x7905);


extern volatile __bit P4TDCIF __at(0x7901);


extern volatile __bit P4TOVIE __at(0x7907);


extern volatile __bit P4TOVIF __at(0x7903);


extern volatile __bit P4TPHIE __at(0x7906);


extern volatile __bit P4TPHIF __at(0x7902);


extern volatile __bit P4TPRIE __at(0x7904);


extern volatile __bit P4TPRIF __at(0x7900);


extern volatile __bit PCIE __at(0x10BE);


extern volatile __bit PEIE __at(0x5E);


extern volatile __bit PEN __at(0x10B2);


extern volatile __bit PLLR __at(0x4D6);


extern volatile __bit PMSC3TIE __at(0x4A6);


extern volatile __bit PS0 __at(0x4A8);


extern volatile __bit PS1 __at(0x4A9);


extern volatile __bit PS2 __at(0x4AA);


extern volatile __bit PSA __at(0x4AB);


extern volatile __bit PSMC1BLKF0 __at(0x7560);


extern volatile __bit PSMC1BLKF1 __at(0x7561);


extern volatile __bit PSMC1BLKF2 __at(0x7562);


extern volatile __bit PSMC1BLKF3 __at(0x7563);


extern volatile __bit PSMC1BLKF4 __at(0x7564);


extern volatile __bit PSMC1BLKF5 __at(0x7565);


extern volatile __bit PSMC1BLKF6 __at(0x7566);


extern volatile __bit PSMC1BLKF7 __at(0x7567);


extern volatile __bit PSMC1BLKR0 __at(0x7558);


extern volatile __bit PSMC1BLKR1 __at(0x7559);


extern volatile __bit PSMC1BLKR2 __at(0x755A);


extern volatile __bit PSMC1BLKR3 __at(0x755B);


extern volatile __bit PSMC1BLKR4 __at(0x755C);


extern volatile __bit PSMC1BLKR5 __at(0x755D);


extern volatile __bit PSMC1BLKR6 __at(0x755E);


extern volatile __bit PSMC1BLKR7 __at(0x755F);


extern volatile __bit PSMC1DBF0 __at(0x7550);


extern volatile __bit PSMC1DBF1 __at(0x7551);


extern volatile __bit PSMC1DBF2 __at(0x7552);


extern volatile __bit PSMC1DBF3 __at(0x7553);


extern volatile __bit PSMC1DBF4 __at(0x7554);


extern volatile __bit PSMC1DBF5 __at(0x7555);


extern volatile __bit PSMC1DBF6 __at(0x7556);


extern volatile __bit PSMC1DBF7 __at(0x7557);


extern volatile __bit PSMC1DBR0 __at(0x7548);


extern volatile __bit PSMC1DBR1 __at(0x7549);


extern volatile __bit PSMC1DBR2 __at(0x754A);


extern volatile __bit PSMC1DBR3 __at(0x754B);


extern volatile __bit PSMC1DBR4 __at(0x754C);


extern volatile __bit PSMC1DBR5 __at(0x754D);


extern volatile __bit PSMC1DBR6 __at(0x754E);


extern volatile __bit PSMC1DBR7 __at(0x754F);


extern volatile __bit PSMC1DC0 __at(0x7518);


extern volatile __bit PSMC1DC1 __at(0x7519);


extern volatile __bit PSMC1DC10 __at(0x7522);


extern volatile __bit PSMC1DC11 __at(0x7523);


extern volatile __bit PSMC1DC12 __at(0x7524);


extern volatile __bit PSMC1DC13 __at(0x7525);


extern volatile __bit PSMC1DC14 __at(0x7526);


extern volatile __bit PSMC1DC15 __at(0x7527);


extern volatile __bit PSMC1DC2 __at(0x751A);


extern volatile __bit PSMC1DC3 __at(0x751B);


extern volatile __bit PSMC1DC4 __at(0x751C);


extern volatile __bit PSMC1DC5 __at(0x751D);


extern volatile __bit PSMC1DC6 __at(0x751E);


extern volatile __bit PSMC1DC7 __at(0x751F);


extern volatile __bit PSMC1DC8 __at(0x7520);


extern volatile __bit PSMC1DC9 __at(0x7521);


extern volatile __bit PSMC1EN __at(0x748F);


extern volatile __bit PSMC1FFA0 __at(0x7568);


extern volatile __bit PSMC1FFA1 __at(0x7569);


extern volatile __bit PSMC1FFA2 __at(0x756A);


extern volatile __bit PSMC1FFA3 __at(0x756B);


extern volatile __bit PSMC1LD __at(0x748E);


extern volatile __bit PSMC1PH0 __at(0x7508);


extern volatile __bit PSMC1PH1 __at(0x7509);


extern volatile __bit PSMC1PH10 __at(0x7512);


extern volatile __bit PSMC1PH11 __at(0x7513);


extern volatile __bit PSMC1PH12 __at(0x7514);


extern volatile __bit PSMC1PH13 __at(0x7515);


extern volatile __bit PSMC1PH14 __at(0x7516);


extern volatile __bit PSMC1PH15 __at(0x7517);


extern volatile __bit PSMC1PH2 __at(0x750A);


extern volatile __bit PSMC1PH3 __at(0x750B);


extern volatile __bit PSMC1PH4 __at(0x750C);


extern volatile __bit PSMC1PH5 __at(0x750D);


extern volatile __bit PSMC1PH6 __at(0x750E);


extern volatile __bit PSMC1PH7 __at(0x750F);


extern volatile __bit PSMC1PH8 __at(0x7510);


extern volatile __bit PSMC1PH9 __at(0x7511);


extern volatile __bit PSMC1PR0 __at(0x7528);


extern volatile __bit PSMC1PR1 __at(0x7529);


extern volatile __bit PSMC1PR10 __at(0x7532);


extern volatile __bit PSMC1PR11 __at(0x7533);


extern volatile __bit PSMC1PR12 __at(0x7534);


extern volatile __bit PSMC1PR13 __at(0x7535);


extern volatile __bit PSMC1PR14 __at(0x7536);


extern volatile __bit PSMC1PR15 __at(0x7537);


extern volatile __bit PSMC1PR2 __at(0x752A);


extern volatile __bit PSMC1PR3 __at(0x752B);


extern volatile __bit PSMC1PR4 __at(0x752C);


extern volatile __bit PSMC1PR5 __at(0x752D);


extern volatile __bit PSMC1PR6 __at(0x752E);


extern volatile __bit PSMC1PR7 __at(0x752F);


extern volatile __bit PSMC1PR8 __at(0x7530);


extern volatile __bit PSMC1PR9 __at(0x7531);


extern volatile __bit PSMC1SIE __at(0x4A0);


extern volatile __bit PSMC1SIF __at(0xA0);


extern volatile __bit PSMC1TIE __at(0x4A4);


extern volatile __bit PSMC1TIF __at(0xA4);


extern volatile __bit PSMC1TMR0 __at(0x7538);


extern volatile __bit PSMC1TMR1 __at(0x7539);


extern volatile __bit PSMC1TMR10 __at(0x7542);


extern volatile __bit PSMC1TMR11 __at(0x7543);


extern volatile __bit PSMC1TMR12 __at(0x7544);


extern volatile __bit PSMC1TMR13 __at(0x7545);


extern volatile __bit PSMC1TMR14 __at(0x7546);


extern volatile __bit PSMC1TMR15 __at(0x7547);


extern volatile __bit PSMC1TMR2 __at(0x753A);


extern volatile __bit PSMC1TMR3 __at(0x753B);


extern volatile __bit PSMC1TMR4 __at(0x753C);


extern volatile __bit PSMC1TMR5 __at(0x753D);


extern volatile __bit PSMC1TMR6 __at(0x753E);


extern volatile __bit PSMC1TMR7 __at(0x753F);


extern volatile __bit PSMC1TMR8 __at(0x7540);


extern volatile __bit PSMC1TMR9 __at(0x7541);


extern volatile __bit PSMC2BLKF0 __at(0x7660);


extern volatile __bit PSMC2BLKF1 __at(0x7661);


extern volatile __bit PSMC2BLKF2 __at(0x7662);


extern volatile __bit PSMC2BLKF3 __at(0x7663);


extern volatile __bit PSMC2BLKF4 __at(0x7664);


extern volatile __bit PSMC2BLKF5 __at(0x7665);


extern volatile __bit PSMC2BLKF6 __at(0x7666);


extern volatile __bit PSMC2BLKF7 __at(0x7667);


extern volatile __bit PSMC2BLKR0 __at(0x7658);


extern volatile __bit PSMC2BLKR1 __at(0x7659);


extern volatile __bit PSMC2BLKR2 __at(0x765A);


extern volatile __bit PSMC2BLKR3 __at(0x765B);


extern volatile __bit PSMC2BLKR4 __at(0x765C);


extern volatile __bit PSMC2BLKR5 __at(0x765D);


extern volatile __bit PSMC2BLKR6 __at(0x765E);


extern volatile __bit PSMC2BLKR7 __at(0x765F);


extern volatile __bit PSMC2DBF0 __at(0x7650);


extern volatile __bit PSMC2DBF1 __at(0x7651);


extern volatile __bit PSMC2DBF2 __at(0x7652);


extern volatile __bit PSMC2DBF3 __at(0x7653);


extern volatile __bit PSMC2DBF4 __at(0x7654);


extern volatile __bit PSMC2DBF5 __at(0x7655);


extern volatile __bit PSMC2DBF6 __at(0x7656);


extern volatile __bit PSMC2DBF7 __at(0x7657);


extern volatile __bit PSMC2DBR0 __at(0x7648);


extern volatile __bit PSMC2DBR1 __at(0x7649);


extern volatile __bit PSMC2DBR2 __at(0x764A);


extern volatile __bit PSMC2DBR3 __at(0x764B);


extern volatile __bit PSMC2DBR4 __at(0x764C);


extern volatile __bit PSMC2DBR5 __at(0x764D);


extern volatile __bit PSMC2DBR6 __at(0x764E);


extern volatile __bit PSMC2DBR7 __at(0x764F);


extern volatile __bit PSMC2DC0 __at(0x7618);


extern volatile __bit PSMC2DC1 __at(0x7619);


extern volatile __bit PSMC2DC10 __at(0x7622);


extern volatile __bit PSMC2DC11 __at(0x7623);


extern volatile __bit PSMC2DC12 __at(0x7624);


extern volatile __bit PSMC2DC13 __at(0x7625);


extern volatile __bit PSMC2DC14 __at(0x7626);


extern volatile __bit PSMC2DC15 __at(0x7627);


extern volatile __bit PSMC2DC2 __at(0x761A);


extern volatile __bit PSMC2DC3 __at(0x761B);


extern volatile __bit PSMC2DC4 __at(0x761C);


extern volatile __bit PSMC2DC5 __at(0x761D);


extern volatile __bit PSMC2DC6 __at(0x761E);


extern volatile __bit PSMC2DC7 __at(0x761F);


extern volatile __bit PSMC2DC8 __at(0x7620);


extern volatile __bit PSMC2DC9 __at(0x7621);


extern volatile __bit PSMC2EN __at(0x758F);


extern volatile __bit PSMC2FFA0 __at(0x7668);


extern volatile __bit PSMC2FFA1 __at(0x7669);


extern volatile __bit PSMC2FFA2 __at(0x766A);


extern volatile __bit PSMC2FFA3 __at(0x766B);


extern volatile __bit PSMC2LD __at(0x758E);


extern volatile __bit PSMC2PH0 __at(0x7608);


extern volatile __bit PSMC2PH1 __at(0x7609);


extern volatile __bit PSMC2PH10 __at(0x7612);


extern volatile __bit PSMC2PH11 __at(0x7613);


extern volatile __bit PSMC2PH12 __at(0x7614);


extern volatile __bit PSMC2PH13 __at(0x7615);


extern volatile __bit PSMC2PH14 __at(0x7616);


extern volatile __bit PSMC2PH15 __at(0x7617);


extern volatile __bit PSMC2PH2 __at(0x760A);


extern volatile __bit PSMC2PH3 __at(0x760B);


extern volatile __bit PSMC2PH4 __at(0x760C);


extern volatile __bit PSMC2PH5 __at(0x760D);


extern volatile __bit PSMC2PH6 __at(0x760E);


extern volatile __bit PSMC2PH7 __at(0x760F);


extern volatile __bit PSMC2PH8 __at(0x7610);


extern volatile __bit PSMC2PH9 __at(0x7611);


extern volatile __bit PSMC2PR0 __at(0x7628);


extern volatile __bit PSMC2PR1 __at(0x7629);


extern volatile __bit PSMC2PR10 __at(0x7632);


extern volatile __bit PSMC2PR11 __at(0x7633);


extern volatile __bit PSMC2PR12 __at(0x7634);


extern volatile __bit PSMC2PR13 __at(0x7635);


extern volatile __bit PSMC2PR14 __at(0x7636);


extern volatile __bit PSMC2PR15 __at(0x7637);


extern volatile __bit PSMC2PR2 __at(0x762A);


extern volatile __bit PSMC2PR3 __at(0x762B);


extern volatile __bit PSMC2PR4 __at(0x762C);


extern volatile __bit PSMC2PR5 __at(0x762D);


extern volatile __bit PSMC2PR6 __at(0x762E);


extern volatile __bit PSMC2PR7 __at(0x762F);


extern volatile __bit PSMC2PR8 __at(0x7630);


extern volatile __bit PSMC2PR9 __at(0x7631);


extern volatile __bit PSMC2SIE __at(0x4A1);


extern volatile __bit PSMC2SIF __at(0xA1);


extern volatile __bit PSMC2TIE __at(0x4A5);


extern volatile __bit PSMC2TIF __at(0xA5);


extern volatile __bit PSMC2TMR0 __at(0x7638);


extern volatile __bit PSMC2TMR1 __at(0x7639);


extern volatile __bit PSMC2TMR10 __at(0x7642);


extern volatile __bit PSMC2TMR11 __at(0x7643);


extern volatile __bit PSMC2TMR12 __at(0x7644);


extern volatile __bit PSMC2TMR13 __at(0x7645);


extern volatile __bit PSMC2TMR14 __at(0x7646);


extern volatile __bit PSMC2TMR15 __at(0x7647);


extern volatile __bit PSMC2TMR2 __at(0x763A);


extern volatile __bit PSMC2TMR3 __at(0x763B);


extern volatile __bit PSMC2TMR4 __at(0x763C);


extern volatile __bit PSMC2TMR5 __at(0x763D);


extern volatile __bit PSMC2TMR6 __at(0x763E);


extern volatile __bit PSMC2TMR7 __at(0x763F);


extern volatile __bit PSMC2TMR8 __at(0x7640);


extern volatile __bit PSMC2TMR9 __at(0x7641);


extern volatile __bit PSMC3BLKF0 __at(0x7760);


extern volatile __bit PSMC3BLKF1 __at(0x7761);


extern volatile __bit PSMC3BLKF2 __at(0x7762);


extern volatile __bit PSMC3BLKF3 __at(0x7763);


extern volatile __bit PSMC3BLKF4 __at(0x7764);


extern volatile __bit PSMC3BLKF5 __at(0x7765);


extern volatile __bit PSMC3BLKF6 __at(0x7766);


extern volatile __bit PSMC3BLKF7 __at(0x7767);


extern volatile __bit PSMC3BLKR0 __at(0x7758);


extern volatile __bit PSMC3BLKR1 __at(0x7759);


extern volatile __bit PSMC3BLKR2 __at(0x775A);


extern volatile __bit PSMC3BLKR3 __at(0x775B);


extern volatile __bit PSMC3BLKR4 __at(0x775C);


extern volatile __bit PSMC3BLKR5 __at(0x775D);


extern volatile __bit PSMC3BLKR6 __at(0x775E);


extern volatile __bit PSMC3BLKR7 __at(0x775F);


extern volatile __bit PSMC3DBF0 __at(0x7750);


extern volatile __bit PSMC3DBF1 __at(0x7751);


extern volatile __bit PSMC3DBF2 __at(0x7752);


extern volatile __bit PSMC3DBF3 __at(0x7753);


extern volatile __bit PSMC3DBF4 __at(0x7754);


extern volatile __bit PSMC3DBF5 __at(0x7755);


extern volatile __bit PSMC3DBF6 __at(0x7756);


extern volatile __bit PSMC3DBF7 __at(0x7757);


extern volatile __bit PSMC3DBR0 __at(0x7748);


extern volatile __bit PSMC3DBR1 __at(0x7749);


extern volatile __bit PSMC3DBR2 __at(0x774A);


extern volatile __bit PSMC3DBR3 __at(0x774B);


extern volatile __bit PSMC3DBR4 __at(0x774C);


extern volatile __bit PSMC3DBR5 __at(0x774D);


extern volatile __bit PSMC3DBR6 __at(0x774E);


extern volatile __bit PSMC3DBR7 __at(0x774F);


extern volatile __bit PSMC3DC0 __at(0x7718);


extern volatile __bit PSMC3DC1 __at(0x7719);


extern volatile __bit PSMC3DC10 __at(0x7722);


extern volatile __bit PSMC3DC11 __at(0x7723);


extern volatile __bit PSMC3DC12 __at(0x7724);


extern volatile __bit PSMC3DC13 __at(0x7725);


extern volatile __bit PSMC3DC14 __at(0x7726);


extern volatile __bit PSMC3DC15 __at(0x7727);


extern volatile __bit PSMC3DC2 __at(0x771A);


extern volatile __bit PSMC3DC3 __at(0x771B);


extern volatile __bit PSMC3DC4 __at(0x771C);


extern volatile __bit PSMC3DC5 __at(0x771D);


extern volatile __bit PSMC3DC6 __at(0x771E);


extern volatile __bit PSMC3DC7 __at(0x771F);


extern volatile __bit PSMC3DC8 __at(0x7720);


extern volatile __bit PSMC3DC9 __at(0x7721);


extern volatile __bit PSMC3EN __at(0x768F);


extern volatile __bit PSMC3FFA0 __at(0x7768);


extern volatile __bit PSMC3FFA1 __at(0x7769);


extern volatile __bit PSMC3FFA2 __at(0x776A);


extern volatile __bit PSMC3FFA3 __at(0x776B);


extern volatile __bit PSMC3LD __at(0x768E);


extern volatile __bit PSMC3PH0 __at(0x7708);


extern volatile __bit PSMC3PH1 __at(0x7709);


extern volatile __bit PSMC3PH10 __at(0x7712);


extern volatile __bit PSMC3PH11 __at(0x7713);


extern volatile __bit PSMC3PH12 __at(0x7714);


extern volatile __bit PSMC3PH13 __at(0x7715);


extern volatile __bit PSMC3PH14 __at(0x7716);


extern volatile __bit PSMC3PH15 __at(0x7717);


extern volatile __bit PSMC3PH2 __at(0x770A);


extern volatile __bit PSMC3PH3 __at(0x770B);


extern volatile __bit PSMC3PH4 __at(0x770C);


extern volatile __bit PSMC3PH5 __at(0x770D);


extern volatile __bit PSMC3PH6 __at(0x770E);


extern volatile __bit PSMC3PH7 __at(0x770F);


extern volatile __bit PSMC3PH8 __at(0x7710);


extern volatile __bit PSMC3PH9 __at(0x7711);


extern volatile __bit PSMC3PR0 __at(0x7728);


extern volatile __bit PSMC3PR1 __at(0x7729);


extern volatile __bit PSMC3PR10 __at(0x7732);


extern volatile __bit PSMC3PR11 __at(0x7733);


extern volatile __bit PSMC3PR12 __at(0x7734);


extern volatile __bit PSMC3PR13 __at(0x7735);


extern volatile __bit PSMC3PR14 __at(0x7736);


extern volatile __bit PSMC3PR15 __at(0x7737);


extern volatile __bit PSMC3PR2 __at(0x772A);


extern volatile __bit PSMC3PR3 __at(0x772B);


extern volatile __bit PSMC3PR4 __at(0x772C);


extern volatile __bit PSMC3PR5 __at(0x772D);


extern volatile __bit PSMC3PR6 __at(0x772E);


extern volatile __bit PSMC3PR7 __at(0x772F);


extern volatile __bit PSMC3PR8 __at(0x7730);


extern volatile __bit PSMC3PR9 __at(0x7731);


extern volatile __bit PSMC3SIE __at(0x4A2);


extern volatile __bit PSMC3SIF __at(0xA2);


extern volatile __bit PSMC3TIE __at(0x4A6);


extern volatile __bit PSMC3TIF __at(0xA6);


extern volatile __bit PSMC3TMR0 __at(0x7738);


extern volatile __bit PSMC3TMR1 __at(0x7739);


extern volatile __bit PSMC3TMR10 __at(0x7742);


extern volatile __bit PSMC3TMR11 __at(0x7743);


extern volatile __bit PSMC3TMR12 __at(0x7744);


extern volatile __bit PSMC3TMR13 __at(0x7745);


extern volatile __bit PSMC3TMR14 __at(0x7746);


extern volatile __bit PSMC3TMR15 __at(0x7747);


extern volatile __bit PSMC3TMR2 __at(0x773A);


extern volatile __bit PSMC3TMR3 __at(0x773B);


extern volatile __bit PSMC3TMR4 __at(0x773C);


extern volatile __bit PSMC3TMR5 __at(0x773D);


extern volatile __bit PSMC3TMR6 __at(0x773E);


extern volatile __bit PSMC3TMR7 __at(0x773F);


extern volatile __bit PSMC3TMR8 __at(0x7740);


extern volatile __bit PSMC3TMR9 __at(0x7741);


extern volatile __bit PSMC4BLKF0 __at(0x7960);


extern volatile __bit PSMC4BLKF1 __at(0x7961);


extern volatile __bit PSMC4BLKF2 __at(0x7962);


extern volatile __bit PSMC4BLKF3 __at(0x7963);


extern volatile __bit PSMC4BLKF4 __at(0x7964);


extern volatile __bit PSMC4BLKF5 __at(0x7965);


extern volatile __bit PSMC4BLKF6 __at(0x7966);


extern volatile __bit PSMC4BLKF7 __at(0x7967);


extern volatile __bit PSMC4BLKR0 __at(0x7958);


extern volatile __bit PSMC4BLKR1 __at(0x7959);


extern volatile __bit PSMC4BLKR2 __at(0x795A);


extern volatile __bit PSMC4BLKR3 __at(0x795B);


extern volatile __bit PSMC4BLKR4 __at(0x795C);


extern volatile __bit PSMC4BLKR5 __at(0x795D);


extern volatile __bit PSMC4BLKR6 __at(0x795E);


extern volatile __bit PSMC4BLKR7 __at(0x795F);


extern volatile __bit PSMC4DBF0 __at(0x7950);


extern volatile __bit PSMC4DBF1 __at(0x7951);


extern volatile __bit PSMC4DBF2 __at(0x7952);


extern volatile __bit PSMC4DBF3 __at(0x7953);


extern volatile __bit PSMC4DBF4 __at(0x7954);


extern volatile __bit PSMC4DBF5 __at(0x7955);


extern volatile __bit PSMC4DBF6 __at(0x7956);


extern volatile __bit PSMC4DBF7 __at(0x7957);


extern volatile __bit PSMC4DBR0 __at(0x7948);


extern volatile __bit PSMC4DBR1 __at(0x7949);


extern volatile __bit PSMC4DBR2 __at(0x794A);


extern volatile __bit PSMC4DBR3 __at(0x794B);


extern volatile __bit PSMC4DBR4 __at(0x794C);


extern volatile __bit PSMC4DBR5 __at(0x794D);


extern volatile __bit PSMC4DBR6 __at(0x794E);


extern volatile __bit PSMC4DBR7 __at(0x794F);


extern volatile __bit PSMC4DC0 __at(0x7918);


extern volatile __bit PSMC4DC1 __at(0x7919);


extern volatile __bit PSMC4DC10 __at(0x7922);


extern volatile __bit PSMC4DC11 __at(0x7923);


extern volatile __bit PSMC4DC12 __at(0x7924);


extern volatile __bit PSMC4DC13 __at(0x7925);


extern volatile __bit PSMC4DC14 __at(0x7926);


extern volatile __bit PSMC4DC15 __at(0x7927);


extern volatile __bit PSMC4DC2 __at(0x791A);


extern volatile __bit PSMC4DC3 __at(0x791B);


extern volatile __bit PSMC4DC4 __at(0x791C);


extern volatile __bit PSMC4DC5 __at(0x791D);


extern volatile __bit PSMC4DC6 __at(0x791E);


extern volatile __bit PSMC4DC7 __at(0x791F);


extern volatile __bit PSMC4DC8 __at(0x7920);


extern volatile __bit PSMC4DC9 __at(0x7921);


extern volatile __bit PSMC4EN __at(0x788F);


extern volatile __bit PSMC4FFA0 __at(0x7968);


extern volatile __bit PSMC4FFA1 __at(0x7969);


extern volatile __bit PSMC4FFA2 __at(0x796A);


extern volatile __bit PSMC4FFA3 __at(0x796B);


extern volatile __bit PSMC4LD __at(0x788E);


extern volatile __bit PSMC4PH0 __at(0x7908);


extern volatile __bit PSMC4PH1 __at(0x7909);


extern volatile __bit PSMC4PH10 __at(0x7912);


extern volatile __bit PSMC4PH11 __at(0x7913);


extern volatile __bit PSMC4PH12 __at(0x7914);


extern volatile __bit PSMC4PH13 __at(0x7915);


extern volatile __bit PSMC4PH14 __at(0x7916);


extern volatile __bit PSMC4PH15 __at(0x7917);


extern volatile __bit PSMC4PH2 __at(0x790A);


extern volatile __bit PSMC4PH3 __at(0x790B);


extern volatile __bit PSMC4PH4 __at(0x790C);


extern volatile __bit PSMC4PH5 __at(0x790D);


extern volatile __bit PSMC4PH6 __at(0x790E);


extern volatile __bit PSMC4PH7 __at(0x790F);


extern volatile __bit PSMC4PH8 __at(0x7910);


extern volatile __bit PSMC4PH9 __at(0x7911);


extern volatile __bit PSMC4PR0 __at(0x7928);


extern volatile __bit PSMC4PR1 __at(0x7929);


extern volatile __bit PSMC4PR10 __at(0x7932);


extern volatile __bit PSMC4PR11 __at(0x7933);


extern volatile __bit PSMC4PR12 __at(0x7934);


extern volatile __bit PSMC4PR13 __at(0x7935);


extern volatile __bit PSMC4PR14 __at(0x7936);


extern volatile __bit PSMC4PR15 __at(0x7937);


extern volatile __bit PSMC4PR2 __at(0x792A);


extern volatile __bit PSMC4PR3 __at(0x792B);


extern volatile __bit PSMC4PR4 __at(0x792C);


extern volatile __bit PSMC4PR5 __at(0x792D);


extern volatile __bit PSMC4PR6 __at(0x792E);


extern volatile __bit PSMC4PR7 __at(0x792F);


extern volatile __bit PSMC4PR8 __at(0x7930);


extern volatile __bit PSMC4PR9 __at(0x7931);


extern volatile __bit PSMC4SIE __at(0x4A3);


extern volatile __bit PSMC4SIF __at(0xA3);


extern volatile __bit PSMC4TIE __at(0x4A7);


extern volatile __bit PSMC4TIF __at(0xA7);


extern volatile __bit PSMC4TMR0 __at(0x7938);


extern volatile __bit PSMC4TMR1 __at(0x7939);


extern volatile __bit PSMC4TMR10 __at(0x7942);


extern volatile __bit PSMC4TMR11 __at(0x7943);


extern volatile __bit PSMC4TMR12 __at(0x7944);


extern volatile __bit PSMC4TMR13 __at(0x7945);


extern volatile __bit PSMC4TMR14 __at(0x7946);


extern volatile __bit PSMC4TMR15 __at(0x7947);


extern volatile __bit PSMC4TMR2 __at(0x793A);


extern volatile __bit PSMC4TMR3 __at(0x793B);


extern volatile __bit PSMC4TMR4 __at(0x793C);


extern volatile __bit PSMC4TMR5 __at(0x793D);


extern volatile __bit PSMC4TMR6 __at(0x793E);


extern volatile __bit PSMC4TMR7 __at(0x793F);


extern volatile __bit PSMC4TMR8 __at(0x7940);


extern volatile __bit PSMC4TMR9 __at(0x7941);


extern volatile __bit RA0 __at(0x60);


extern volatile __bit RA1 __at(0x61);


extern volatile __bit RA2 __at(0x62);


extern volatile __bit RA3 __at(0x63);


extern volatile __bit RA4 __at(0x64);


extern volatile __bit RA5 __at(0x65);


extern volatile __bit RA6 __at(0x66);


extern volatile __bit RA7 __at(0x67);


extern volatile __bit RB0 __at(0x68);


extern volatile __bit RB1 __at(0x69);


extern volatile __bit RB2 __at(0x6A);


extern volatile __bit RB3 __at(0x6B);


extern volatile __bit RB4 __at(0x6C);


extern volatile __bit RB5 __at(0x6D);


extern volatile __bit RB6 __at(0x6E);


extern volatile __bit RB7 __at(0x6F);


extern volatile __bit RC0 __at(0x70);


extern volatile __bit RC1 __at(0x71);


extern volatile __bit RC2 __at(0x72);


extern volatile __bit RC3 __at(0x73);


extern volatile __bit RC4 __at(0x74);


extern volatile __bit RC5 __at(0x75);


extern volatile __bit RC6 __at(0x76);


extern volatile __bit RC7 __at(0x77);


extern volatile __bit RCEN __at(0x10B3);


extern volatile __bit RCIDL __at(0xCFE);


extern volatile __bit RCIE __at(0x48D);


extern volatile __bit RCIF __at(0x8D);


extern volatile __bit RD __at(0xCA8);


extern volatile __bit RE3 __at(0x83);


extern volatile __bit RSEN __at(0x10B1);


extern volatile __bit RX9 __at(0xCEE);


extern volatile __bit RX9D __at(0xCE8);


extern volatile __bit RXSEL __at(0x8E9);


extern volatile __bit R_nW __at(0x10A2);


extern volatile __bit SBCDE __at(0x10BA);


extern volatile __bit SBOREN __at(0x8B7);


extern volatile __bit SCIE __at(0x10BD);


extern volatile __bit SCKP __at(0xCFC);


extern volatile __bit SCKSEL __at(0x8EC);


extern volatile __bit SCS0 __at(0x4C8);


extern volatile __bit SCS1 __at(0x4C9);


extern volatile __bit SDAHT __at(0x10BB);


extern volatile __bit SDISEL __at(0x8EB);


extern volatile __bit SDOSEL __at(0x8ED);


extern volatile __bit SEN __at(0x10B0);


extern volatile __bit SENDB __at(0xCF3);


extern volatile __bit SLRCONA0 __at(0x1860);


extern volatile __bit SLRCONA1 __at(0x1861);


extern volatile __bit SLRCONA2 __at(0x1862);


extern volatile __bit SLRCONA3 __at(0x1863);


extern volatile __bit SLRCONA4 __at(0x1864);


extern volatile __bit SLRCONA5 __at(0x1865);


extern volatile __bit SLRCONA6 __at(0x1866);


extern volatile __bit SLRCONA7 __at(0x1867);


extern volatile __bit SLRCONB0 __at(0x1868);


extern volatile __bit SLRCONB1 __at(0x1869);


extern volatile __bit SLRCONB2 __at(0x186A);


extern volatile __bit SLRCONB3 __at(0x186B);


extern volatile __bit SLRCONB4 __at(0x186C);


extern volatile __bit SLRCONB5 __at(0x186D);


extern volatile __bit SLRCONB6 __at(0x186E);


extern volatile __bit SLRCONB7 __at(0x186F);


extern volatile __bit SLRCONC0 __at(0x1870);


extern volatile __bit SLRCONC1 __at(0x1871);


extern volatile __bit SLRCONC2 __at(0x1872);


extern volatile __bit SLRCONC3 __at(0x1873);


extern volatile __bit SLRCONC4 __at(0x1874);


extern volatile __bit SLRCONC5 __at(0x1875);


extern volatile __bit SLRCONC6 __at(0x1876);


extern volatile __bit SLRCONC7 __at(0x1877);


extern volatile __bit SMP __at(0x10A7);


extern volatile __bit SPEN __at(0xCEF);


extern volatile __bit SPLLEN __at(0x4CF);


extern volatile __bit SREN __at(0xCED);


extern volatile __bit SSP1ADD0 __at(0x1090);


extern volatile __bit SSP1ADD1 __at(0x1091);


extern volatile __bit SSP1ADD2 __at(0x1092);


extern volatile __bit SSP1ADD3 __at(0x1093);


extern volatile __bit SSP1ADD4 __at(0x1094);


extern volatile __bit SSP1ADD5 __at(0x1095);


extern volatile __bit SSP1ADD6 __at(0x1096);


extern volatile __bit SSP1ADD7 __at(0x1097);


extern volatile __bit SSP1BUF0 __at(0x1088);


extern volatile __bit SSP1BUF1 __at(0x1089);


extern volatile __bit SSP1BUF2 __at(0x108A);


extern volatile __bit SSP1BUF3 __at(0x108B);


extern volatile __bit SSP1BUF4 __at(0x108C);


extern volatile __bit SSP1BUF5 __at(0x108D);


extern volatile __bit SSP1BUF6 __at(0x108E);


extern volatile __bit SSP1BUF7 __at(0x108F);


extern volatile __bit SSP1IE __at(0x48B);


extern volatile __bit SSP1IF __at(0x8B);


extern volatile __bit SSP1MSK0 __at(0x1098);


extern volatile __bit SSP1MSK1 __at(0x1099);


extern volatile __bit SSP1MSK2 __at(0x109A);


extern volatile __bit SSP1MSK3 __at(0x109B);


extern volatile __bit SSP1MSK4 __at(0x109C);


extern volatile __bit SSP1MSK5 __at(0x109D);


extern volatile __bit SSP1MSK6 __at(0x109E);


extern volatile __bit SSP1MSK7 __at(0x109F);


extern volatile __bit SSPEN __at(0x10AD);


extern volatile __bit SSPM0 __at(0x10A8);


extern volatile __bit SSPM1 __at(0x10A9);


extern volatile __bit SSPM2 __at(0x10AA);


extern volatile __bit SSPM3 __at(0x10AB);


extern volatile __bit SSPOV __at(0x10AE);


extern volatile __bit STKOVF __at(0x4B7);


extern volatile __bit STKUNF __at(0x4B6);


extern volatile __bit SWDTEN __at(0x4B8);


extern volatile __bit SYNC __at(0xCF4);


extern volatile __bit T0CS __at(0x4AD);


extern volatile __bit T0IE __at(0x5D);


extern volatile __bit T0IF __at(0x5A);


extern volatile __bit T0SE __at(0x4AC);


extern volatile __bit T1CKPS0 __at(0xC4);


extern volatile __bit T1CKPS1 __at(0xC5);


extern volatile __bit T1GGO __at(0xCB);


extern volatile __bit T1GPOL __at(0xCE);


extern volatile __bit T1GSPM __at(0xCC);


extern volatile __bit T1GSS0 __at(0xC8);


extern volatile __bit T1GSS1 __at(0xC9);


extern volatile __bit T1GTM __at(0xCD);


extern volatile __bit T1GVAL __at(0xCA);


extern volatile __bit T1OSCEN __at(0xC3);


extern volatile __bit T1OSCR __at(0x4D7);


extern volatile __bit T2CKPS0 __at(0xE0);


extern volatile __bit T2CKPS1 __at(0xE1);


extern volatile __bit T2OUTPS0 __at(0xE3);


extern volatile __bit T2OUTPS1 __at(0xE4);


extern volatile __bit T2OUTPS2 __at(0xE5);


extern volatile __bit T2OUTPS3 __at(0xE6);


extern volatile __bit TMR0CS __at(0x4AD);


extern volatile __bit TMR0IE __at(0x5D);


extern volatile __bit TMR0IF __at(0x5A);


extern volatile __bit TMR0SE __at(0x4AC);


extern volatile __bit TMR1CS0 __at(0xC6);


extern volatile __bit TMR1CS1 __at(0xC7);


extern volatile __bit TMR1GE __at(0xCF);


extern volatile __bit TMR1GIE __at(0x48F);


extern volatile __bit TMR1GIF __at(0x8F);


extern volatile __bit TMR1IE __at(0x488);


extern volatile __bit TMR1IF __at(0x88);


extern volatile __bit TMR1ON __at(0xC0);


extern volatile __bit TMR2IE __at(0x489);


extern volatile __bit TMR2IF __at(0x89);


extern volatile __bit TMR2ON __at(0xE2);


extern volatile __bit TRIGSEL0 __at(0x4FC);


extern volatile __bit TRIGSEL1 __at(0x4FD);


extern volatile __bit TRIGSEL2 __at(0x4FE);


extern volatile __bit TRIGSEL3 __at(0x4FF);


extern volatile __bit TRISA0 __at(0x460);


extern volatile __bit TRISA1 __at(0x461);


extern volatile __bit TRISA2 __at(0x462);


extern volatile __bit TRISA3 __at(0x463);


extern volatile __bit TRISA4 __at(0x464);


extern volatile __bit TRISA5 __at(0x465);


extern volatile __bit TRISA6 __at(0x466);


extern volatile __bit TRISA7 __at(0x467);


extern volatile __bit TRISB0 __at(0x468);


extern volatile __bit TRISB1 __at(0x469);


extern volatile __bit TRISB2 __at(0x46A);


extern volatile __bit TRISB3 __at(0x46B);


extern volatile __bit TRISB4 __at(0x46C);


extern volatile __bit TRISB5 __at(0x46D);


extern volatile __bit TRISB6 __at(0x46E);


extern volatile __bit TRISB7 __at(0x46F);


extern volatile __bit TRISC0 __at(0x470);


extern volatile __bit TRISC1 __at(0x471);


extern volatile __bit TRISC2 __at(0x472);


extern volatile __bit TRISC3 __at(0x473);


extern volatile __bit TRISC4 __at(0x474);


extern volatile __bit TRISC5 __at(0x475);


extern volatile __bit TRISC6 __at(0x476);


extern volatile __bit TRISC7 __at(0x477);


extern volatile __bit TRISE3 __at(0x483);


extern volatile __bit TRMT __at(0xCF1);


extern volatile __bit TSEN __at(0x8BD);


extern volatile __bit TSRNG __at(0x8BC);


extern volatile __bit TUN0 __at(0x4C0);


extern volatile __bit TUN1 __at(0x4C1);


extern volatile __bit TUN2 __at(0x4C2);


extern volatile __bit TUN3 __at(0x4C3);


extern volatile __bit TUN4 __at(0x4C4);


extern volatile __bit TUN5 __at(0x4C5);


extern volatile __bit TX9 __at(0xCF6);


extern volatile __bit TX9D __at(0xCF0);


extern volatile __bit TXEN __at(0xCF5);


extern volatile __bit TXIE __at(0x48C);


extern volatile __bit TXIF __at(0x8C);


extern volatile __bit TXSEL __at(0x8EA);


extern volatile __bit UA __at(0x10A1);


extern volatile __bit VREGPM __at(0xCB9);


extern volatile __bit WCOL __at(0x10AF);


extern volatile __bit WDTPS0 __at(0x4B9);


extern volatile __bit WDTPS1 __at(0x4BA);


extern volatile __bit WDTPS2 __at(0x4BB);


extern volatile __bit WDTPS3 __at(0x4BC);


extern volatile __bit WDTPS4 __at(0x4BD);


extern volatile __bit WPUA0 __at(0x1060);


extern volatile __bit WPUA1 __at(0x1061);


extern volatile __bit WPUA2 __at(0x1062);


extern volatile __bit WPUA3 __at(0x1063);


extern volatile __bit WPUA4 __at(0x1064);


extern volatile __bit WPUA5 __at(0x1065);


extern volatile __bit WPUA6 __at(0x1066);


extern volatile __bit WPUA7 __at(0x1067);


extern volatile __bit WPUB0 __at(0x1068);


extern volatile __bit WPUB1 __at(0x1069);


extern volatile __bit WPUB2 __at(0x106A);


extern volatile __bit WPUB3 __at(0x106B);


extern volatile __bit WPUB4 __at(0x106C);


extern volatile __bit WPUB5 __at(0x106D);


extern volatile __bit WPUB6 __at(0x106E);


extern volatile __bit WPUB7 __at(0x106F);


extern volatile __bit WPUC0 __at(0x1070);


extern volatile __bit WPUC1 __at(0x1071);


extern volatile __bit WPUC2 __at(0x1072);


extern volatile __bit WPUC3 __at(0x1073);


extern volatile __bit WPUC4 __at(0x1074);


extern volatile __bit WPUC5 __at(0x1075);


extern volatile __bit WPUC6 __at(0x1076);


extern volatile __bit WPUC7 __at(0x1077);


extern volatile __bit WPUE3 __at(0x1083);


extern volatile __bit WR __at(0xCA9);


extern volatile __bit WREN __at(0xCAA);


extern volatile __bit WRERR __at(0xCAB);


extern volatile __bit WUE __at(0xCF9);


extern volatile __bit ZERO __at(0x1A);


extern volatile __bit Z_SHAD __at(0x7F22);


extern volatile __bit nBOR __at(0x4B0);


extern volatile __bit nPD __at(0x1B);


extern volatile __bit nPOR __at(0x4B1);


extern volatile __bit nRI __at(0x4B2);


extern volatile __bit nRMCLR __at(0x4B3);


extern volatile __bit nRWDT __at(0x4B4);


extern volatile __bit nT1SYNC __at(0xC2);


extern volatile __bit nTO __at(0x1C);


extern volatile __bit nWPUEN __at(0x4AF);

# 76 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC12-16F1xxx_DFP/1.6.241/xc8\pic\include\pic.h"
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);

# 114 "C:\Program Files\Microchip\xc8\v2.41\pic\include\eeprom_routines.h"
extern void eeprom_write(unsigned char addr, unsigned char value);
extern unsigned char eeprom_read(unsigned char addr);

# 118 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC12-16F1xxx_DFP/1.6.241/xc8\pic\include\pic.h"
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;

# 5 "C:\Program Files\Microchip\xc8\v2.41\pic\sources\c90\pic\__eeprom.c"
void
__eecpymem(volatile unsigned char *to, __eeprom unsigned char * from, unsigned char size)
{
volatile unsigned char *cp = to;

while (EECON1bits.WR) continue;
EEADR = (unsigned char)from;
while(size--) {
while (EECON1bits.WR) continue;

EECON1 &= 0x7F;

EECON1bits.RD = 1;
*cp++ = EEDATA;
++EEADR;
}

# 36
}

void
__memcpyee(__eeprom unsigned char * to, const unsigned char *from, unsigned char size)
{
const unsigned char *ptr =from;

while (EECON1bits.WR) continue;
EEADR = (unsigned char)to - 1U;

EECON1 &= 0x7F;

while(size--) {
while (EECON1bits.WR) {
continue;
}
EEDATA = *ptr++;
++EEADR;
STATUSbits.CARRY = 0;
if (INTCONbits.GIE) {
STATUSbits.CARRY = 1;
}
INTCONbits.GIE = 0;
EECON1bits.WREN = 1;
EECON2 = 0x55;
EECON2 = 0xAA;
EECON1bits.WR = 1;
EECON1bits.WREN = 0;
if (STATUSbits.CARRY) {
INTCONbits.GIE = 1;
}
}

# 101
}

unsigned char
__eetoc(__eeprom void *addr)
{
unsigned char data;
__eecpymem((unsigned char *) &data,addr,1);
return data;
}

unsigned int
__eetoi(__eeprom void *addr)
{
unsigned int data;
__eecpymem((unsigned char *) &data,addr,2);
return data;
}

#pragma warning push
#pragma warning disable 2040
__uint24
__eetom(__eeprom void *addr)
{
__uint24 data;
__eecpymem((unsigned char *) &data,addr,3);
return data;
}
#pragma warning pop

unsigned long
__eetol(__eeprom void *addr)
{
unsigned long data;
__eecpymem((unsigned char *) &data,addr,4);
return data;
}

#pragma warning push
#pragma warning disable 1516
unsigned long long
__eetoo(__eeprom void *addr)
{
unsigned long long data;
__eecpymem((unsigned char *) &data,addr,8);
return data;
}
#pragma warning pop

unsigned char
__ctoee(__eeprom void *addr, unsigned char data)
{
__memcpyee(addr,(unsigned char *) &data,1);
return data;
}

unsigned int
__itoee(__eeprom void *addr, unsigned int data)
{
__memcpyee(addr,(unsigned char *) &data,2);
return data;
}

#pragma warning push
#pragma warning disable 2040
__uint24
__mtoee(__eeprom void *addr, __uint24 data)
{
__memcpyee(addr,(unsigned char *) &data,3);
return data;
}
#pragma warning pop

unsigned long
__ltoee(__eeprom void *addr, unsigned long data)
{
__memcpyee(addr,(unsigned char *) &data,4);
return data;
}

#pragma warning push
#pragma warning disable 1516
unsigned long long
__otoee(__eeprom void *addr, unsigned long long data)
{
__memcpyee(addr,(unsigned char *) &data,8);
return data;
}
#pragma warning pop

float
__eetoft(__eeprom void *addr)
{
float data;
__eecpymem((unsigned char *) &data,addr,3);
return data;
}

double
__eetofl(__eeprom void *addr)
{
double data;
__eecpymem((unsigned char *) &data,addr,4);
return data;
}

float
__fttoee(__eeprom void *addr, float data)
{
__memcpyee(addr,(unsigned char *) &data,3);
return data;
}

double
__fltoee(__eeprom void *addr, double data)
{
__memcpyee(addr,(unsigned char *) &data,4);
return data;
}

