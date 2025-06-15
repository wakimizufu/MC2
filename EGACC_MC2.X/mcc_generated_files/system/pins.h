/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

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
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA4 aliases
#define outFlt_TRIS                 TRISAbits.TRISA4
#define outFlt_LAT                  LATAbits.LATA4
#define outFlt_PORT                 PORTAbits.RA4
#define outFlt_WPU                  WPUAbits.WPUA4
#define outFlt_OD                   ODCONAbits.ODCA4
#define outFlt_ANS                  ANSELAbits.ANSA4
#define outFlt_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define outFlt_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define outFlt_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define outFlt_GetValue()           PORTAbits.RA4
#define outFlt_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define outFlt_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define outFlt_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define outFlt_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define outFlt_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define outFlt_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define outFlt_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define outFlt_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define outAMP_TRIS                 TRISAbits.TRISA5
#define outAMP_LAT                  LATAbits.LATA5
#define outAMP_PORT                 PORTAbits.RA5
#define outAMP_WPU                  WPUAbits.WPUA5
#define outAMP_OD                   ODCONAbits.ODCA5
#define outAMP_ANS                  ANSELAbits.ANSA5
#define outAMP_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define outAMP_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define outAMP_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define outAMP_GetValue()           PORTAbits.RA5
#define outAMP_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define outAMP_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define outAMP_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define outAMP_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define outAMP_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define outAMP_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define outAMP_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define outAMP_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
// get/set IO_RB4 aliases
#define accFlt_TRIS                 TRISBbits.TRISB4
#define accFlt_LAT                  LATBbits.LATB4
#define accFlt_PORT                 PORTBbits.RB4
#define accFlt_WPU                  WPUBbits.WPUB4
#define accFlt_OD                   ODCONBbits.ODCB4
#define accFlt_ANS                  ANSELBbits.ANSB4
#define accFlt_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define accFlt_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define accFlt_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define accFlt_GetValue()           PORTBbits.RB4
#define accFlt_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define accFlt_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define accFlt_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define accFlt_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define accFlt_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define accFlt_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define accFlt_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define accFlt_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define accAmp_TRIS                 TRISBbits.TRISB5
#define accAmp_LAT                  LATBbits.LATB5
#define accAmp_PORT                 PORTBbits.RB5
#define accAmp_WPU                  WPUBbits.WPUB5
#define accAmp_OD                   ODCONBbits.ODCB5
#define accAmp_ANS                  ANSELBbits.ANSB5
#define accAmp_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define accAmp_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define accAmp_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define accAmp_GetValue()           PORTBbits.RB5
#define accAmp_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define accAmp_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define accAmp_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define accAmp_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define accAmp_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define accAmp_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define accAmp_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define accAmp_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define Gate_TRIS                 TRISBbits.TRISB6
#define Gate_LAT                  LATBbits.LATB6
#define Gate_PORT                 PORTBbits.RB6
#define Gate_WPU                  WPUBbits.WPUB6
#define Gate_OD                   ODCONBbits.ODCB6
#define Gate_ANS                  ANSELBbits.ANSB6
#define Gate_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define Gate_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define Gate_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define Gate_GetValue()           PORTBbits.RB6
#define Gate_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define Gate_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define Gate_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define Gate_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define Gate_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define Gate_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define Gate_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define Gate_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
#define RB6_SetInterruptHandler  Gate_SetInterruptHandler
// get/set IO_RB7 aliases
#define Release_TRIS                 TRISBbits.TRISB7
#define Release_LAT                  LATBbits.LATB7
#define Release_PORT                 PORTBbits.RB7
#define Release_WPU                  WPUBbits.WPUB7
#define Release_OD                   ODCONBbits.ODCB7
#define Release_ANS                  ANSELBbits.ANSB7
#define Release_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Release_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Release_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Release_GetValue()           PORTBbits.RB7
#define Release_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Release_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Release_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Release_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Release_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Release_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Release_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define Release_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)
// get/set IO_RC2 aliases
#define ampWave_TRIS                 TRISCbits.TRISC2
#define ampWave_LAT                  LATCbits.LATC2
#define ampWave_PORT                 PORTCbits.RC2
#define ampWave_WPU                  WPUCbits.WPUC2
#define ampWave_OD                   ODCONCbits.ODCC2
#define ampWave_ANS                  ANSELCbits.ANSC2
#define ampWave_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ampWave_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ampWave_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ampWave_GetValue()           PORTCbits.RC2
#define ampWave_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ampWave_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define ampWave_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define ampWave_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define ampWave_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define ampWave_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define ampWave_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define ampWave_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define Attack_TRIS                 TRISCbits.TRISC3
#define Attack_LAT                  LATCbits.LATC3
#define Attack_PORT                 PORTCbits.RC3
#define Attack_WPU                  WPUCbits.WPUC3
#define Attack_OD                   ODCONCbits.ODCC3
#define Attack_ANS                  ANSELCbits.ANSC3
#define Attack_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Attack_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Attack_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Attack_GetValue()           PORTCbits.RC3
#define Attack_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Attack_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Attack_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Attack_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Attack_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Attack_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Attack_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Attack_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define AccLev_TRIS                 TRISCbits.TRISC4
#define AccLev_LAT                  LATCbits.LATC4
#define AccLev_PORT                 PORTCbits.RC4
#define AccLev_WPU                  WPUCbits.WPUC4
#define AccLev_OD                   ODCONCbits.ODCC4
#define AccLev_ANS                  ANSELCbits.ANSC4
#define AccLev_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define AccLev_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define AccLev_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define AccLev_GetValue()           PORTCbits.RC4
#define AccLev_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define AccLev_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define AccLev_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define AccLev_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define AccLev_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define AccLev_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define AccLev_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define AccLev_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC6 aliases
#define Decay_TRIS                 TRISCbits.TRISC6
#define Decay_LAT                  LATCbits.LATC6
#define Decay_PORT                 PORTCbits.RC6
#define Decay_WPU                  WPUCbits.WPUC6
#define Decay_OD                   ODCONCbits.ODCC6
#define Decay_ANS                  ANSELCbits.ANSC6
#define Decay_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Decay_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Decay_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Decay_GetValue()           PORTCbits.RC6
#define Decay_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Decay_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Decay_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Decay_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Decay_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Decay_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define Decay_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define Decay_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RC7 aliases
#define Sustain_TRIS                 TRISCbits.TRISC7
#define Sustain_LAT                  LATCbits.LATC7
#define Sustain_PORT                 PORTCbits.RC7
#define Sustain_WPU                  WPUCbits.WPUC7
#define Sustain_OD                   ODCONCbits.ODCC7
#define Sustain_ANS                  ANSELCbits.ANSC7
#define Sustain_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Sustain_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Sustain_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Sustain_GetValue()           PORTCbits.RC7
#define Sustain_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Sustain_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Sustain_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Sustain_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Sustain_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Sustain_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define Sustain_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define Sustain_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the Gate pin functionality
 * @param none
 * @return none
 */
void Gate_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Gate pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for Gate at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void Gate_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for Gate pin.
 *        This is a dynamic interrupt handler to be used together with the Gate_SetInterruptHandler() method.
 *        This handler is called every time the Gate ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*Gate_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Gate pin. 
 *        This is a predefined interrupt handler to be used together with the Gate_SetInterruptHandler() method.
 *        This handler is called every time the Gate ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void Gate_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/