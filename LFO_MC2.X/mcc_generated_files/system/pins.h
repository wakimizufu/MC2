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
#define RandumSeed_TRIS                 TRISAbits.TRISA4
#define RandumSeed_LAT                  LATAbits.LATA4
#define RandumSeed_PORT                 PORTAbits.RA4
#define RandumSeed_WPU                  WPUAbits.WPUA4
#define RandumSeed_OD                   ODCONAbits.ODCA4
#define RandumSeed_ANS                  ANSELAbits.ANSA4
#define RandumSeed_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RandumSeed_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RandumSeed_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RandumSeed_GetValue()           PORTAbits.RA4
#define RandumSeed_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RandumSeed_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RandumSeed_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RandumSeed_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RandumSeed_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RandumSeed_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RandumSeed_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RandumSeed_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define Square_TRIS                 TRISAbits.TRISA5
#define Square_LAT                  LATAbits.LATA5
#define Square_PORT                 PORTAbits.RA5
#define Square_WPU                  WPUAbits.WPUA5
#define Square_OD                   ODCONAbits.ODCA5
#define Square_ANS                  ANSELAbits.ANSA5
#define Square_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Square_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Square_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Square_GetValue()           PORTAbits.RA5
#define Square_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Square_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Square_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define Square_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define Square_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define Square_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define Square_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define Square_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
// get/set IO_RC0 aliases
#define Gate_TRIS                 TRISCbits.TRISC0
#define Gate_LAT                  LATCbits.LATC0
#define Gate_PORT                 PORTCbits.RC0
#define Gate_WPU                  WPUCbits.WPUC0
#define Gate_OD                   ODCONCbits.ODCC0
#define Gate_ANS                  ANSELCbits.ANSC0
#define Gate_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Gate_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Gate_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Gate_GetValue()           PORTCbits.RC0
#define Gate_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Gate_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Gate_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Gate_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Gate_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Gate_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Gate_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define Gate_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
#define RC0_SetInterruptHandler  Gate_SetInterruptHandler
// get/set IO_RC1 aliases
#define Rate_TRIS                 TRISCbits.TRISC1
#define Rate_LAT                  LATCbits.LATC1
#define Rate_PORT                 PORTCbits.RC1
#define Rate_WPU                  WPUCbits.WPUC1
#define Rate_OD                   ODCONCbits.ODCC1
#define Rate_ANS                  ANSELCbits.ANSC1
#define Rate_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Rate_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Rate_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Rate_GetValue()           PORTCbits.RC1
#define Rate_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Rate_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define Rate_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define Rate_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define Rate_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define Rate_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define Rate_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define Rate_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define Delay_TRIS                 TRISCbits.TRISC2
#define Delay_LAT                  LATCbits.LATC2
#define Delay_PORT                 PORTCbits.RC2
#define Delay_WPU                  WPUCbits.WPUC2
#define Delay_OD                   ODCONCbits.ODCC2
#define Delay_ANS                  ANSELCbits.ANSC2
#define Delay_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Delay_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Delay_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Delay_GetValue()           PORTCbits.RC2
#define Delay_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Delay_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Delay_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Delay_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Delay_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Delay_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Delay_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Delay_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define Randum_TRIS                 TRISCbits.TRISC3
#define Randum_LAT                  LATCbits.LATC3
#define Randum_PORT                 PORTCbits.RC3
#define Randum_WPU                  WPUCbits.WPUC3
#define Randum_OD                   ODCONCbits.ODCC3
#define Randum_ANS                  ANSELCbits.ANSC3
#define Randum_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Randum_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Randum_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Randum_GetValue()           PORTCbits.RC3
#define Randum_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Randum_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Randum_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Randum_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Randum_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Randum_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Randum_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Randum_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define Triangle_TRIS                 TRISCbits.TRISC4
#define Triangle_LAT                  LATCbits.LATC4
#define Triangle_PORT                 PORTCbits.RC4
#define Triangle_WPU                  WPUCbits.WPUC4
#define Triangle_OD                   ODCONCbits.ODCC4
#define Triangle_ANS                  ANSELCbits.ANSC4
#define Triangle_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Triangle_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Triangle_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Triangle_GetValue()           PORTCbits.RC4
#define Triangle_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Triangle_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Triangle_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Triangle_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Triangle_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Triangle_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Triangle_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define Triangle_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define Sine_TRIS                 TRISCbits.TRISC5
#define Sine_LAT                  LATCbits.LATC5
#define Sine_PORT                 PORTCbits.RC5
#define Sine_WPU                  WPUCbits.WPUC5
#define Sine_OD                   ODCONCbits.ODCC5
#define Sine_ANS                  ANSELCbits.ANSC5
#define Sine_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Sine_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Sine_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Sine_GetValue()           PORTCbits.RC5
#define Sine_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Sine_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Sine_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Sine_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Sine_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define Sine_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define Sine_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define Sine_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
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