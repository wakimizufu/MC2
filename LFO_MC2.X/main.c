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
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/system.h"
#include <stdbool.h>
#include <stdlib.h>

/*
    Main application
*/
//�ϐ�
_Bool onTMR1; 

//LFO �T�C���g�e�[�u��
# define SINE_CURVE_LENGTH 256
const unsigned int sineTbl[SINE_CURVE_LENGTH] = {
512,524,536,548,560,576,588,600,612,624,636,648,660,672,684,696,708,
716,728,740,752,764,772,784,796,804,816,824,836,844,852,864,872,880,
888,896,904,912,920,928,936,940,948,952,960,964,972,976,980,984,992,
996,1000,1000,1004,1008,1012,1012,1016,1016,1016,1020,1020,1020,1020,1020,1020,1020,
1016,1016,1016,1012,1012,1008,1004,1000,1000,996,992,984,980,976,972,964,960,
952,948,940,936,928,920,912,904,896,888,880,872,864,852,844,836,824,
816,804,796,784,772,764,752,740,728,716,708,696,684,672,660,648,636,
624,612,600,588,576,560,548,536,524,512,500,488,476,464,448,436,424,
412,400,388,376,364,352,340,328,316,308,296,284,272,260,252,240,228,
220,208,200,188,180,172,160,152,144,136,128,120,112,104,96,88,84,
76,72,64,60,52,48,44,40,32,28,24,24,20,16,12,12,8,
8,8,4,4,4,4,4,4,4,8,8,8,12,12,16,20,24,
24,28,32,40,44,48,52,60,64,72,76,84,88,96,104,112,120,
128,136,144,152,160,172,180,188,200,208,220,228,240,252,260,272,284,
296,308,316,328,340,352,364,376,388,400,412,424,436,448,464,476,488,500};

//ADC�ϊ��^�C�~���O(�P��:2msec)
#define ADC_CONVERT_TIME 100 

//ADC 8bit�ɑ΂���LFO�X�e�b�v���g��(�P��:Hz))
#define LFO_STEP_TIME 0.117 

//LFO�֘A
//DDS�쓮���g��
#define DDS_CLOCK 4000

double fout;
double tuningWord;               //double tuningWord = (pow(2, 32) * fout) / clock;
uint16_t LFODEtm = 0;           //LFO�f�B���C�^�C�� 0ms:0-1.25s:256
uint16_t LFODelayCount = 0;     //LFO�f�B���C�^�C���p�J�E���g
uint16_t LFORndSeed = 0;     //�����_���V�[�h(0-1023)

//ADC �X�e�[�^�X
enum ADC_ST {
    TmLFO,    //LFO���g��
    DeLFO,    //LFO�f�B���C�^�C��
    RndSe,    //�����_���V�[�h
    TmATK,    //�A�^�b�N�^�C��
    TmDCY,    //�f�B�P�C�^�C��
    LvSUS,    //�T�X�e�B�����x��
    TmREL     //�����[�X�^�C��
};
enum ADC_ST adc_ST = TmLFO;  //���݂�ADC�X�e�[�^�X


// �֐��v���g�^�C�v
void MyTMR1_ISR(void);
void onEdgeGate_ISR(void);
void cnvADC(void);

// 2000Hz=0.5ms �^�C�}�[������
void MyTMR1_ISR(void){
    onTMR1 = true;
}

// GATE ���͊�����
void onEdgeGate_ISR(void){
    
    _Bool envGate = Gate_GetValue();
    
    if ( envGate ){
        LFODelayCount = LFODEtm;     //LFO�f�B���C�^�C���p�J�E���g
    } else if (!envGate) {
    }
}

//ADC�R���o�[�^�ˊe�ϐ����X�V
void cnvADC(){

	switch ( adc_ST ) {
		case TmLFO:    //LFO���g��
			ADC_SelectChannel(Rate); //ADC_CHANNEL_ANA0
			break;
		case DeLFO:    //LFO�f�B���C�^�C��
			ADC_SelectChannel(Delay); //ADC_CHANNEL_ANA1
			break;
		case RndSe:    //�����_���V�[�h
			ADC_SelectChannel(LFORndSeed); //ADC_CHANNEL_ANA1
			break;
		default:
			break;
	}

	ADC_StartConversion();
	while(!ADC_IsConversionDone());

	switch ( adc_ST ) {
		case TmLFO:    //LFO���g��
			fout = ( (ADC_GetConversionResult()>>2) * LFO_STEP_TIME) + LFO_STEP_TIME;
			tuningWord = 0x01000000 * fout / DDS_CLOCK;
            adc_ST	=	DeLFO;
			break;
		case DeLFO:    //LFO�f�B���C�^�C��
            LFODEtm = ADC_GetConversionResult()>>2;     //LFO�f�B���C�^�C�� 0ms:0-1.25s:256
         	adc_ST	= RndSe;   
            break;
		case RndSe:    //�����_���V�[�h
            LFORndSeed = ADC_GetConversionResult();     //�����_���V�[�h 0-1023
         	adc_ST	= TmLFO;   
            break;
		default:
			break;
	}
}

int main(void)
{
    SYSTEM_Initialize();
    
    onTMR1 = false;
    TMR1_OverflowCallbackRegister(MyTMR1_ISR);
    TMR1_Start();

    Gate_SetInterruptHandler(onEdgeGate_ISR);

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    unsigned int onLFORate = ADC_CONVERT_TIME;
    ADC_SelectChannel(Rate); //ADC_CHANNEL_ANA0
    ADC_StartConversion();

    __uint24 accmulator = 0;
    __uint24 count;
    __uint24 updateRandum = 0;
	unsigned int dacval;
    
    while(1)
    {
        // 2000Hz=0.5ms �^�C�}�[������
        if (onTMR1){
            
            //�T�C���g�e�[�u������擾
            count = accmulator >> 16;
            dacval = sineTbl[count];

            //�T�C���g
            if ( 0 == LFODelayCount){
                PWM3_LoadDutyValue(dacval);
            } else if ( 0 != LFODelayCount){
                PWM3_LoadDutyValue(511);
                LFODelayCount--;
            }
            
            //�O�p�g
             if (count<=0x3F){
                dacval = 0x1FF + ( ( 0x00003F & count) <<3);
            } else if (count<=0x7F){
                dacval = 0x3FF - ( ( 0x00003F & count) <<3);
            } else if (count<=0xBF){
                dacval = 0x1FF - ( ( 0x00003F & count) <<3);
            } else if (count<=0xFF){
                dacval = ( ( 0x00003F & count) <<3);
            }
            PWM4_LoadDutyValue(dacval);

            //���`�g
             if  (count<=0x7F){
                Square_SetHigh();
             } else {
                Square_SetLow();
             }

            //�����_��
             updateRandum = updateRandum + count;
             if ( updateRandum > 0xFF ){
                 updateRandum = updateRandum - 0xFF;

                srand(LFORndSeed);
                dacval=(rand() % 1022) + 1;
                PWM5_LoadDutyValue(dacval);
             }
            
            //���Z�ݐϊ�։��Z
            accmulator += tuningWord;
   
            onLFORate--;            
            onTMR1 = false;
        }
        
        //ADC�R���o�[�^�ˊe�ϐ����X�V
        if (0 == onLFORate){
           cnvADC();
           onLFORate=ADC_CONVERT_TIME;
        }
    }    
}