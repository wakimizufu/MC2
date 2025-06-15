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
//変数
_Bool onTMR1; 

//ADSR カーブテーブル 最大70%Ver
# define EXP_CURVE_LENGTH 256
# define EXP_CURVE_MAX_VALUE 1023
const unsigned int curveTbl[EXP_CURVE_LENGTH] = {
0,13,27,40,53,66,79,91,103,115,127,138,149,161,171,182,
192,202,212,222,231,241,250,259,268,277,285,294,302,310,317,325,
333,340,347,354,361,368,375,382,389,395,401,407,413,419,424,430,
436,441,447,452,457,462,467,472,476,481,485,490,494,499,503,507,
511,515,519,523,527,530,534,537,541,544,548,550,554,557,560,563,
566,569,572,575,577,580,583,585,588,590,592,595,597,599,602,604,
606,609,611,613,615,616,618,620,622,624,625,627,629,631,632,634,
636,637,639,640,641,643,644,646,647,648,650,651,653,653,655,656,
657,658,660,660,662,662,664,665,665,667,667,668,669,670,671,672,
673,674,674,675,676,676,677,679,679,680,681,681,681,682,683,683,
684,685,686,686,686,687,688,688,689,689,690,690,690,691,692,692,
693,693,693,694,695,695,695,695,696,696,697,697,697,697,698,698,
699,699,700,700,700,700,700,701,701,702,702,702,702,702,702,703,
703,704,704,704,704,704,704,704,705,705,705,706,706,706,706,707,
707,707,707,707,707,707,707,707,708,708,708,708,708,709,709,709,
709,709,709,709,709,709,709,709,710,710,710,710,710,710,710,711};


//エンベロープ ステータス
enum ENV_ST {
    EMP,    //未出力
    ATK,    //アタック
    DCY,    //ディケイ
    SUS,    //サスティン
    REL     //リリース
};


//ADC変換タイミング(単位:2msec)
#define ADC_CONVERT_TIME 100 

//エンベロープ関連

//アクセントON時:DAC最大増加%
#define ENV_ACC_MAX 0.43 

_Bool envGate = false;
enum ENV_ST env1_ST = EMP;  //現在のエンベロープ ステータス
uint16_t envCount = 0;  //エンベロープカウンタ
uint16_t envDAC   = 0;  //エンベロープ用DAC
uint16_t Atm = 50;     //アタック 2ms:4-1.5s:300
uint16_t Dtm = 700;    //ディケイ 2ms:4-5s:1000
uint16_t Slv = 300;     //サスティン レベル(0-1023)
uint16_t Rtm = 40;    //リリース 2ms:4-5s:1000
uint16_t Acclv = 0;     //アクセント レベル(0-1023)
uint16_t Rpoint = 0;

//ADC ステータス
enum ADC_ST {
    TmATK,    //アタックタイム
    TmDCY,    //ディケイタイム
    LvSUS,    //サスティンレベル
    TmREL,     //リリースタイム
    LvACC     //アクセントレベル
};
enum ADC_ST adc_ST = TmATK;  //現在のADCステータス

//ADC変換タイミング(単位:2msec)
#define ADC_CONVERT_TIME 100 

// 関数プロトタイプ
void MyTMR1_ISR(void);
void onEdgeGate_ISR(void);
uint16_t getExpIndex(uint16_t value , uint16_t max);
void setEnvelope(void);
void cnvADC(void);
uint16_t cnvEnvAccDAC ( uint16_t value );

// 2000Hz=0.5ms タイマー割込み
void MyTMR1_ISR(void){
    onTMR1 = true;
}

// GATE 入力割込み
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

//カーブテーブル値取得関数
uint16_t getExpIndex(uint16_t value , uint16_t max) {
    double temp = (double)value / (double)max;
    temp = temp * (EXP_CURVE_LENGTH - 1);
    if (temp > (EXP_CURVE_LENGTH - 1) )temp = (EXP_CURVE_LENGTH - 1);
    return (uint16_t)temp;
}


//エンベロープジェネレータ実行
void setEnvelope (){

	double dTemp;
    uint16_t tmpDAC;
	
	switch ( env1_ST ) {
		case EMP:    //未出力
			envDAC	=	0;
			break;

		case ATK:    //アタック
			if ( envCount < Atm ) {
                Rpoint = getExpIndex(envCount, Atm);
				Rpoint = curveTbl[Rpoint];
       			envDAC	= Rpoint;
			} else if ( envCount >= Atm ) {
				env1_ST = DCY;
				envCount = 0;
			}
			break;

		case DCY:    //ディケイ
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

		case SUS:    //サスティン
			envDAC	=	Slv;
            Rpoint = Slv;
            envCount = 0;
			break;

		case REL:    //リリース
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

    
    //EnvToVCA
    tmpDAC = envDAC;
    if ( HIGH == ampWave_GetValue()){   //VCA出力波形=GATEの場合

        //Gateの状態をそのまま反映
        if (envGate){
          	PWM1_LoadDutyValue(1023);
        } else if (!envGate){
          	PWM1_LoadDutyValue(0);
        }

    } else {   //VCA出力波形=ENVの場合
        
        //AccentAmp⇒LレベルならアクセントON/HレベルならアクセントOFF
        if (LOW == accAmp_GetValue()){
            tmpDAC = cnvEnvAccDAC(tmpDAC);
        }
    	PWM1_LoadDutyValue(tmpDAC);
    }

    //EnvToVCF
    tmpDAC = envDAC;
    //AccentAmp⇒LレベルならアクセントON/HレベルならアクセントOFF
    if (LOW == accFlt_GetValue()){
        tmpDAC = cnvEnvAccDAC(tmpDAC);
    }
  	PWM2_LoadDutyValue(tmpDAC); 
    
}


//ADCコンバータ⇒各変数を更新
void cnvADC(){

	switch ( adc_ST ) {
		case TmATK:    //アタックタイム
			ADC_ChannelSelect(ATTACK); //ADC_CHANNEL_ANB7
			break;
		case TmDCY:    //ディケイタイム
			ADC_ChannelSelect(DECAY); //ADC_CHANNEL_ANC3
			break;
		case LvSUS:    //サスティンレベル
			ADC_ChannelSelect(SUSTAIN); //ADC_CHANNEL_ANC6
			break;
		case TmREL:     //リリースタイム
			ADC_ChannelSelect(RELEASE); //ADC_CHANNEL_ANC7
			break;
		case LvACC:     //アクセントレベル
			ADC_ChannelSelect(ACCLEV); //ADC_CHANNEL_ANC7
			break;
		default:
			break;
	}

	ADC_ConversionStart();
	while(!ADC_IsConversionDone());

	switch ( adc_ST ) {
		case TmATK:   //アタックタイム
			Atm = (ADC_ConversionResultGet()>>1) | 0x004;     //2ms:4 - 2.5s:512
			adc_ST	=	TmDCY;
			break;
		case TmDCY:    //ディケイタイム
			Dtm = ADC_ConversionResultGet() | 0x004;	//2ms:4 - 5s:1023
			adc_ST	=	LvSUS;
			break;

		case LvSUS:    //サスティンレベル
			Slv = ADC_ConversionResultGet();	//0 - 1023
			adc_ST	=	TmREL;
			break;

		case TmREL:    //リリースタイム
			Rtm = ADC_ConversionResultGet() | 0x004;	//2ms:4 - 5s:1023
			adc_ST	=	LvACC;
			break;

		case LvACC:    //アクセントレベル
			Acclv = ADC_ConversionResultGet();	//0 - 1023
			adc_ST	=	TmATK;
			break;
 		default:
			break;
	}
}

uint16_t cnvEnvAccDAC ( uint16_t value ) {

	uint16_t result;
	double accAttenate;

	accAttenate	= ( Acclv/0x3FF ) * ENV_ACC_MAX;
	accAttenate = accAttenate + 1;
	result = value * accAttenate;

	if ( result >= EXP_CURVE_MAX_VALUE ) {
		result = EXP_CURVE_MAX_VALUE;
  }

	return result;
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
    ADC_ChannelSelect(ATTACK); //ADC_CHANNEL_ANA2
    ADC_ConversionStart();

    while(1)
    {
         // 2000Hz=0.5ms タイマー割込み
        if (onTMR1){
           //エンベロープジェネレータ実行
           setEnvelope();
           onLFORate--;            
           onTMR1 = false;
        }
        
        //ADCコンバータ⇒各変数を更新
        if (0 == onLFORate){
           cnvADC();
           onLFORate=ADC_CONVERT_TIME;
        }
    }    
}