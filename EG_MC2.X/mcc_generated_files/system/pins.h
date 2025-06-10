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

// get/set IO_RA2 aliases
#define Attack_TRIS                 TRISAbits.TRISA2
#define Attack_LAT                  LATAbits.LATA2
#define Attack_PORT                 PORTAbits.RA2
#define Attack_WPU                  WPUAbits.WPUA2
#define Attack_OD                   ODCONAbits.ODCA2
#define Attack_ANS                  ANSELAbits.ANSA2
#define Attack_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Attack_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Attack_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Attack_GetValue()           PORTAbits.RA2
#define Attack_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Attack_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Attack_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Attack_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Attack_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Attack_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Attack_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define Attack_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RA4 aliases
#define outAmp_TRIS                 TRISAbits.TRISA4
#define outAmp_LAT                  LATAbits.LATA4
#define outAmp_PORT                 PORTAbits.RA4
#define outAmp_WPU                  WPUAbits.WPUA4
#define outAmp_OD                   ODCONAbits.ODCA4
#define outAmp_ANS                  ANSELAbits.ANSA4
#define outAmp_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define outAmp_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define outAmp_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define outAmp_GetValue()           PORTAbits.RA4
#define outAmp_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define outAmp_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define outAmp_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define outAmp_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define outAmp_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define outAmp_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define outAmp_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define outAmp_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define outFlt_TRIS                 TRISAbits.TRISA5
#define outFlt_LAT                  LATAbits.LATA5
#define outFlt_PORT                 PORTAbits.RA5
#define outFlt_WPU                  WPUAbits.WPUA5
#define outFlt_OD                   ODCONAbits.ODCA5
#define outFlt_ANS                  ANSELAbits.ANSA5
#define outFlt_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define outFlt_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define outFlt_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define outFlt_GetValue()           PORTAbits.RA5
#define outFlt_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define outFlt_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define outFlt_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define outFlt_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define outFlt_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define outFlt_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define outFlt_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define outFlt_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
// get/set IO_RC0 aliases
#define Decay_TRIS                 TRISCbits.TRISC0
#define Decay_LAT                  LATCbits.LATC0
#define Decay_PORT                 PORTCbits.RC0
#define Decay_WPU                  WPUCbits.WPUC0
#define Decay_OD                   ODCONCbits.ODCC0
#define Decay_ANS                  ANSELCbits.ANSC0
#define Decay_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Decay_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Decay_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Decay_GetValue()           PORTCbits.RC0
#define Decay_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Decay_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Decay_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Decay_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Decay_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Decay_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Decay_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define Decay_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define Sustain_TRIS                 TRISCbits.TRISC1
#define Sustain_LAT                  LATCbits.LATC1
#define Sustain_PORT                 PORTCbits.RC1
#define Sustain_WPU                  WPUCbits.WPUC1
#define Sustain_OD                   ODCONCbits.ODCC1
#define Sustain_ANS                  ANSELCbits.ANSC1
#define Sustain_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Sustain_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Sustain_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Sustain_GetValue()           PORTCbits.RC1
#define Sustain_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Sustain_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define Sustain_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define Sustain_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define Sustain_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define Sustain_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define Sustain_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define Sustain_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define Release_TRIS                 TRISCbits.TRISC2
#define Release_LAT                  LATCbits.LATC2
#define Release_PORT                 PORTCbits.RC2
#define Release_WPU                  WPUCbits.WPUC2
#define Release_OD                   ODCONCbits.ODCC2
#define Release_ANS                  ANSELCbits.ANSC2
#define Release_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Release_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Release_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Release_GetValue()           PORTCbits.RC2
#define Release_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Release_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Release_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Release_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Release_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Release_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Release_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Release_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define Gate_TRIS                 TRISCbits.TRISC3
#define Gate_LAT                  LATCbits.LATC3
#define Gate_PORT                 PORTCbits.RC3
#define Gate_WPU                  WPUCbits.WPUC3
#define Gate_OD                   ODCONCbits.ODCC3
#define Gate_ANS                  ANSELCbits.ANSC3
#define Gate_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Gate_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Gate_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Gate_GetValue()           PORTCbits.RC3
#define Gate_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Gate_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Gate_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Gate_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Gate_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Gate_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Gate_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Gate_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
#define RC3_SetInterruptHandler  Gate_SetInterruptHandler
// get/set IO_RC4 aliases
#define Accent_TRIS                 TRISCbits.TRISC4
#define Accent_LAT                  LATCbits.LATC4
#define Accent_PORT                 PORTCbits.RC4
#define Accent_WPU                  WPUCbits.WPUC4
#define Accent_OD                   ODCONCbits.ODCC4
#define Accent_ANS                  ANSELCbits.ANSC4
#define Accent_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Accent_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Accent_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Accent_GetValue()           PORTCbits.RC4
#define Accent_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Accent_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Accent_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Accent_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Accent_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Accent_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Accent_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define Accent_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define AmpWave_TRIS                 TRISCbits.TRISC5
#define AmpWave_LAT                  LATCbits.LATC5
#define AmpWave_PORT                 PORTCbits.RC5
#define AmpWave_WPU                  WPUCbits.WPUC5
#define AmpWave_OD                   ODCONCbits.ODCC5
#define AmpWave_ANS                  ANSELCbits.ANSC5
#define AmpWave_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define AmpWave_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define AmpWave_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define AmpWave_GetValue()           PORTCbits.RC5
#define AmpWave_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define AmpWave_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define AmpWave_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define AmpWave_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define AmpWave_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define AmpWave_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define AmpWave_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define AmpWave_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
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