/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16F1508
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#define _XTAL_FREQ 16000000

#define MOTOR_MAX 250
#define MOTOR_MIN -250
#define MOTOR_STEP 50

#define MOTOR_RIGHT_FORWARD PORTBbits.RB4
#define MOTOR_RIGHT_BACK    PORTBbits.RB5
#define MOTOR_LEFT_FORWARD  PORTBbits.RB6
#define MOTOR_LEFT_BACK     PORTCbits.RC6
#define MOTOR_STOP          PORTCbits.RC7
#define MOTOR_ACTIVE        PORTBbits.RB7

int Motor1, Motor2;

void M1Drive(void);
void M2Drive(void);

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    /* クロック周波数設定 */
    OSCCONbits.IRCF = 15; // 16MHz
    
    /* 入出力モード設定 */
    LATC = 0b00000101; // ALL OFF
    LATA = 0b00110000; // ALL OFF
    ANSELA = 0;  // 全てデジタル
    ANSELB = 0;
    ANSELC = 0;
    TRISA = 0x08; // RA3のみ入力
    TRISB = 0xF0; // 全て入力
    TRISC = 0xC0; // RFC6,7 入力
    
    /* タイマ2の初期設定 */
    T2CON = 0x04; // POST=1/1 PRE=1/1 Start
    PR2 = 0xFF; // Duty 10bit
    
    /* PWMモジュールの初期設定 */
    PWM1CON = 0xC0;
    PWM1DCH = 0;
    PWM1DCL = 0;
    PWM2CON = 0xC0;
    PWM2DCH = 0;
    PWM2DCL = 0;
    PWM3CON = 0xC0;
    PWM3DCH = 0;
    PWM3DCL = 0;
    PWM4CON = 0xC0;
    PWM4DCH = 0;
    PWM4DCL = 0;
    
    /* モーターのスピード */
    Motor1 = 0;
    Motor2 = 0;

    while (1) {
        if (MOTOR_ACTIVE == 1) {
            /* モーターの正転/逆転 スピードの制御 */
            if (MOTOR_RIGHT_FORWARD == 1) {
                if (Motor1 < MOTOR_MAX) {
                    Motor1 += MOTOR_STEP;
                }
            }
            if (MOTOR_RIGHT_BACK == 1) {
                if (Motor1 > MOTOR_MIN) {
                    Motor1 -= MOTOR_STEP;
                }
            }
            if (MOTOR_RIGHT_FORWARD == 0 && MOTOR_RIGHT_BACK == 0) {
                Motor1 = 0;
            }
            if (MOTOR_RIGHT_FORWARD == 1 && MOTOR_RIGHT_BACK == 1) {
                Motor1 = 0;
            }
            if (MOTOR_LEFT_FORWARD == 1) {
                if (Motor2 < MOTOR_MAX) {
                    Motor2 += MOTOR_STEP;
                }
            }
            if (MOTOR_LEFT_BACK == 1) {
                if (Motor2 > MOTOR_MIN) {
                    Motor2 -= MOTOR_STEP;
                }
            }
            if (MOTOR_LEFT_FORWARD == 0 && MOTOR_LEFT_BACK == 0) {
                Motor2 = 0;
            }
            if (MOTOR_LEFT_FORWARD == 1 && MOTOR_LEFT_BACK == 1) {
                Motor2 = 0;
            }
        } else {
            Motor1 = 0;
            Motor2 = 0;
        }

        /* モーターの制御を実行 */
        M1Drive();
        M2Drive();
        __delay_ms(100);
    }
}

/* モーター1(RIGHT)の制御 */
void M1Drive(void) {
    PWM1DCH = 0;
    PWM2DCH = 0;
    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 1;
    if (Motor1 > 0) {
        PWM1DCH = Motor1;
        LATAbits.LATA4 = 0;
    } else if (Motor1 == 0) {
        LATAbits.LATA4 = 1;
        LATAbits.LATA5 = 1;
    } else if (Motor1 < 0) {
        PWM2DCH = Motor1 * -1;
        LATAbits.LATA5 = 0;
    }
}

/* モーター2(LEFT)の制御 */
void M2Drive(void) {
    PWM3DCH = 0;
    PWM4DCH = 0;
    LATCbits.LATC0 = 1;
    LATCbits.LATC2 = 1;
    if (Motor2 > 0) {
        PWM3DCH = Motor2;
        LATCbits.LATC2 = 0;
    } else if (Motor2 == 0) {
        LATCbits.LATC0 = 1;
        LATCbits.LATC2 = 1;
    } else if (Motor2 < 0) {
        PWM4DCH = Motor2 * -1;
        LATCbits.LATC0 = 0;
    }
}
