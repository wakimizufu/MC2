/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
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

#include "../pins.h"

void (*Gate_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x13;
    TRISC = 0x7;

    /**
    ANSELx registers
    */
    ANSELA = 0x13;
    ANSELC = 0x6;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUC = 0x0;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONC = 0x3F;
    /**
    INLVLx registers
    */
    INLVLA = 0x1B;
    INLVLC = 0x7;

    /**
    PPS registers
    */
    RC3PPS = 0x0B;  //RC3->PWM3:PWM3OUT;
    RC5PPS = 0x0D;  //RC5->PWM5:PWM5OUT;
    RC4PPS = 0x0C;  //RC4->PWM4:PWM4OUT;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCCP = 0x1;
    IOCCN = 0x0;
    IOCCF = 0x0;

    Gate_SetInterruptHandler(Gate_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin Gate}
    if(IOCCFbits.IOCCF0 == 1)
    {
        Gate_ISR();  
    }
}
   
/**
   Gate Interrupt Service Routine
*/
void Gate_ISR(void) {

    // Add custom IOCCF0 code

    // Call the interrupt handler for the callback registered at runtime
    if(Gate_InterruptHandler)
    {
        Gate_InterruptHandler();
    }
    IOCCFbits.IOCCF0 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF0 at application runtime
*/
void Gate_SetInterruptHandler(void (* InterruptHandler)(void)){
    Gate_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF0
*/
void Gate_DefaultInterruptHandler(void){
    // add your Gate interrupt custom code
    // or set custom function using Gate_SetInterruptHandler()
}
/**
 End of File
*/