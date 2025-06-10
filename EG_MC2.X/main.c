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
#include <stdbool.h>
#include <math.h>

/*
    Main application
*/

//�ϐ�
_Bool onTMR1; 

//ADSR �J�[�u�e�[�u��
# define EXP_CURVE_LENGTH 256
# define EXP_CURVE_MAX_VALUE 1023
const unsigned int curveTbl[EXP_CURVE_LENGTH] = {
0,19,39,58,77,95,113,131,148,165,182,198,214,230,245,260,275,
289,304,318,331,345,358,371,383,396,408,420,432,443,454,465,476,487,
497,507,517,527,537,546,556,565,574,582,591,599,607,615,623,631,639,
646,653,661,668,675,681,688,694,701,707,713,719,725,731,737,742,748,
753,758,763,768,773,778,783,787,792,796,801,805,809,814,818,822,825,
829,833,837,840,844,847,851,854,857,861,864,867,870,873,876,879,881,
884,887,889,892,894,897,899,902,904,906,909,911,913,915,917,919,921,
923,925,927,929,931,933,934,936,938,939,941,943,944,946,947,949,950,
951,953,954,955,957,958,959,961,962,963,964,965,966,967,968,970,971,
972,973,974,974,975,976,977,978,979,980,981,981,982,983,984,985,985,
986,987,987,988,989,989,990,991,991,992,993,993,994,994,995,995,996,
996,997,997,998,998,999,999,1000,1000,1001,1001,1001,1002,1002,1003,1003,1003,
1004,1004,1004,1005,1005,1006,1006,1006,1006,1007,1007,1007,1008,1008,1008,1009,1009,
1009,1009,1010,1010,1010,1010,1011,1011,1011,1011,1011,1012,1012,1012,1012,1012,1013,
1013,1013,1013,1013,1014,1014,1014,1014,1014,1014,1015,1015,1015,1015,1015,1015,1015,1016};


//�G���x���[�v �X�e�[�^�X
enum ENV_ST {
    EMP,    //���o��
    ATK,    //�A�^�b�N
    DCY,    //�f�B�P�C
    SUS,    //�T�X�e�B��
    REL     //�����[�X
};


//ADC�ϊ��^�C�~���O(�P��:2msec)
#define ADC_CONVERT_TIME 100 

//ADC 8bit�ɑ΂���LFO�X�e�b�v���g��(�P��:Hz))
#define LFO_STEP_TIME 0.117 




//�G���x���[�v�֘A

//�A�N�Z���gOFF��:DAC�����䗦
#define ENV_ACC_ATT 0.7 

_Bool envGate = false;
enum ENV_ST env1_ST = EMP;  //���݂̃G���x���[�v �X�e�[�^�X
uint16_t envCount = 0;  //�G���x���[�v�J�E���^
uint16_t envDAC   = 0;  //�G���x���[�v�pDAC
uint16_t Atm = 50;     //�A�^�b�N 2ms:4-1.5s:300
uint16_t Dtm = 700;    //�f�B�P�C 2ms:4-5s:1000
uint16_t Slv = 300;     //�T�X�e�B�� ���x��(0-1023)
uint16_t Rtm = 40;    //�����[�X 2ms:4-5s:1000
uint16_t Rpoint = 0;

//ADC �X�e�[�^�X
enum ADC_ST {
    TmATK,    //�A�^�b�N�^�C��
    TmDCY,    //�f�B�P�C�^�C��
    LvSUS,    //�T�X�e�B�����x��
    TmREL     //�����[�X�^�C��
};
enum ADC_ST adc_ST = TmATK;  //���݂�ADC�X�e�[�^�X

//ADC�ϊ��^�C�~���O(�P��:2msec)
#define ADC_CONVERT_TIME 100 

// �֐��v���g�^�C�v
void MyTMR1_ISR(void);
void onEdgeGate_ISR(void);
uint16_t getExpIndex(uint16_t value , uint16_t max);
void setEnvelope(void);
void cnvADC(void);

// 2000Hz=0.5ms �^�C�}�[������
void MyTMR1_ISR(void){
    onTMR1 = true;
}

// GATE ���͊�����
void onEdgeGate_ISR(void){
    envGate = Gate_GetValue();
    
    if ( envGate ){
        env1_ST = ATK;
        envCount = 0;
    } else if (!envGate) {
        env1_ST = REL;
        envCount = 0;
    }
}

//�J�[�u�e�[�u���l�擾�֐�
uint16_t getExpIndex(uint16_t value , uint16_t max) {
    double temp = (double)value / (double)max;
    temp = temp * (EXP_CURVE_LENGTH - 1);
    if (temp > (EXP_CURVE_LENGTH - 1) )temp = (EXP_CURVE_LENGTH - 1);
    return (uint16_t)temp;
}


//�G���x���[�v�W�F�l���[�^���s
void setEnvelope (){

	double dTemp;
	
	switch ( env1_ST ) {
		case EMP:    //���o��
			envDAC	=	0;
			break;

		case ATK:    //�A�^�b�N
			if ( envCount < Atm ) {
                Rpoint = getExpIndex(envCount, Atm);
				Rpoint = curveTbl[Rpoint];
       			envDAC	= Rpoint;
			} else if ( envCount >= Atm ) {
				env1_ST = DCY;
				envCount = 0;
			}
			break;

		case DCY:    //�f�B�P�C
			if ( envCount < Dtm ) {
                dTemp = (double)EXP_CURVE_MAX_VALUE - curveTbl[getExpIndex(envCount, Dtm)];
                dTemp = Slv + ((EXP_CURVE_MAX_VALUE - Slv) * (dTemp/EXP_CURVE_MAX_VALUE));
                Rpoint = (uint16_t)dTemp;
       			envDAC	= Rpoint;
			} else if ( envCount >= Dtm ) {
				env1_ST = SUS;
				envCount = 0;
			}
			break;

		case SUS:    //�T�X�e�B��
			envDAC	=	Slv;
            Rpoint = Slv;
            envCount = 0;
			break;

		case REL:    //�����[�X
			if ( envCount < Rtm ) {
                dTemp = (double)EXP_CURVE_MAX_VALUE - curveTbl[getExpIndex(envCount, Rtm)];
                dTemp = dTemp / (double)EXP_CURVE_MAX_VALUE;
                dTemp =  Rpoint * dTemp;
       			envDAC	= (uint16_t)dTemp;
			}  else if ( envCount >= Rtm ) {
                env1_ST = EMP;
                envDAC	=	0;
			}

			break;

		default:
			break;
	}

	envCount++;

    
    //Accent��L���x���Ȃ�A�N�Z���gON/H���x���Ȃ�A�N�Z���gOFF
    if (HIGH == Accent_GetValue()){
        envDAC = envDAC * ENV_ACC_ATT;
    }

    //EnvToVCA
    if ( HIGH == AmpWave_GetValue()){   //VCA�o�͔g�`=GATE�̏ꍇ

        //Gate�̏�Ԃ����̂܂ܔ��f
        if (envGate){
          	PWM3_LoadDutyValue(1023);
        } else if (!envGate){
          	PWM3_LoadDutyValue(0);
        }

    } else {   //VCA�o�͔g�`=ENV�̏ꍇ
    	PWM3_LoadDutyValue(envDAC);
    }

    //EnvToVCF
  	PWM4_LoadDutyValue(envDAC); 
}


//ADC�R���o�[�^�ˊe�ϐ����X�V
void cnvADC(){

	switch ( adc_ST ) {
		case TmATK:    //�A�^�b�N�^�C��
			ADC_SelectChannel(Attack); //ADC_CHANNEL_ANB7
			break;
		case TmDCY:    //�f�B�P�C�^�C��
			ADC_SelectChannel(Decay); //ADC_CHANNEL_ANC3
			break;
		case LvSUS:    //�T�X�e�B�����x��
			ADC_SelectChannel(Sustain); //ADC_CHANNEL_ANC6
			break;
		case TmREL:     //�����[�X�^�C��
			ADC_SelectChannel(Release); //ADC_CHANNEL_ANC7
			break;
		default:
			break;
	}

	ADC_StartConversion();
	while(!ADC_IsConversionDone());

	switch ( adc_ST ) {
		case TmATK:   //�A�^�b�N�^�C��
			Atm = (ADC_GetConversionResult()>>1) | 0x004;     //2ms:4 - 2.5s:512
			adc_ST	=	TmDCY;
			break;
		case TmDCY:    //�f�B�P�C�^�C��
			Dtm = ADC_GetConversionResult() | 0x004;	//2ms:4 - 5s:1023
			adc_ST	=	LvSUS;
			break;

		case LvSUS:    //�T�X�e�B�����x��
			Slv = ADC_GetConversionResult();	//0 - 1023
			adc_ST	=	TmREL;
			break;

		case TmREL:    //�����[�X�^�C��
			Rtm = ADC_GetConversionResult() | 0x004;	//2ms:4 - 5s:1023
			adc_ST	=	TmATK;
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

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 
 
    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    unsigned int onLFORate = ADC_CONVERT_TIME;
    ADC_SelectChannel(Attack); //ADC_CHANNEL_ANA2
    ADC_StartConversion();
    
    while(1)
    {
         // 2000Hz=0.5ms �^�C�}�[������
        if (onTMR1){
           //�G���x���[�v�W�F�l���[�^���s
           setEnvelope();
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