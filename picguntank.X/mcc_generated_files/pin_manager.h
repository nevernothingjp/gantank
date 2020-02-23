/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16F1508
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set GPIO2 aliases
#define GPIO2_TRIS                 TRISBbits.TRISB4
#define GPIO2_LAT                  LATBbits.LATB4
#define GPIO2_PORT                 PORTBbits.RB4
#define GPIO2_WPU                  WPUBbits.WPUB4
#define GPIO2_ANS                  ANSELBbits.ANSB4
#define GPIO2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define GPIO2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define GPIO2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define GPIO2_GetValue()           PORTBbits.RB4
#define GPIO2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define GPIO2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define GPIO2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define GPIO2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define GPIO2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define GPIO2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set GPIO3 aliases
#define GPIO3_TRIS                 TRISBbits.TRISB5
#define GPIO3_LAT                  LATBbits.LATB5
#define GPIO3_PORT                 PORTBbits.RB5
#define GPIO3_WPU                  WPUBbits.WPUB5
#define GPIO3_ANS                  ANSELBbits.ANSB5
#define GPIO3_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define GPIO3_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define GPIO3_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define GPIO3_GetValue()           PORTBbits.RB5
#define GPIO3_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define GPIO3_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define GPIO3_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define GPIO3_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define GPIO3_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define GPIO3_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set GPIO4 aliases
#define GPIO4_TRIS                 TRISBbits.TRISB6
#define GPIO4_LAT                  LATBbits.LATB6
#define GPIO4_PORT                 PORTBbits.RB6
#define GPIO4_WPU                  WPUBbits.WPUB6
#define GPIO4_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define GPIO4_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define GPIO4_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define GPIO4_GetValue()           PORTBbits.RB6
#define GPIO4_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define GPIO4_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define GPIO4_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define GPIO4_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set GPIO14 aliases
#define GPIO14_TRIS                 TRISBbits.TRISB7
#define GPIO14_LAT                  LATBbits.LATB7
#define GPIO14_PORT                 PORTBbits.RB7
#define GPIO14_WPU                  WPUBbits.WPUB7
#define GPIO14_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define GPIO14_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define GPIO14_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define GPIO14_GetValue()           PORTBbits.RB7
#define GPIO14_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define GPIO14_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define GPIO14_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define GPIO14_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set GPIO15 aliases
#define GPIO15_TRIS                 TRISCbits.TRISC6
#define GPIO15_LAT                  LATCbits.LATC6
#define GPIO15_PORT                 PORTCbits.RC6
#define GPIO15_ANS                  ANSELCbits.ANSC6
#define GPIO15_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define GPIO15_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define GPIO15_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define GPIO15_GetValue()           PORTCbits.RC6
#define GPIO15_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define GPIO15_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define GPIO15_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define GPIO15_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set GPIO18 aliases
#define GPIO18_TRIS                 TRISCbits.TRISC7
#define GPIO18_LAT                  LATCbits.LATC7
#define GPIO18_PORT                 PORTCbits.RC7
#define GPIO18_ANS                  ANSELCbits.ANSC7
#define GPIO18_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define GPIO18_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define GPIO18_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define GPIO18_GetValue()           PORTCbits.RC7
#define GPIO18_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define GPIO18_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define GPIO18_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define GPIO18_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/