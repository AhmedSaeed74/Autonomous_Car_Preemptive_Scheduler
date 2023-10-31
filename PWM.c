/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   PWM.c                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for PWM driver                                   *
 *                                                                             *
 *******************************************************************************/


/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "std_types.h"
#include "PWM.h"
#include "DIO.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PWM0_RCGC 20
#define PWM_RCC 20
#define PWM_configs 0x00
#define PCTL_VALUE 0x00440000
#define PE4 4
#define PE5 5

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/
uint32_t Load_Value =  3200;
uint32_t Duty_Cycle = 60;



/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*PWM initialization function*/
/*INPUTS: NONE*/
/*OUTPUTS: NONE*/
/*Description: Initializes the PWM0 module of the TIVA-C on PINS PE4 and PE5*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/

void PWM_INIT(void)
{

    DIO_Init();
    /*Clock the PWM*/
    SET_BIT(SYSCTL_RCGC0_R, PWM0_RCGC);
    /*wait for the PWM to be ready*/
   
		//while(!GET_BIT(SYSCTL_RCGC0_R, PWM0_RCGC));
		for(int l=0; l<10000u; l++)
	{
	}
	
	
    /*use the system clock as is (16MHZ)*/
    CLEAR_BIT(SYSCTL_RCC_R, PWM_RCC);


    /*select alternative function*/
    SET_BIT(GPIO_PORTE_AFSEL_R, PE4);
    SET_BIT(GPIO_PORTE_AFSEL_R, PE5);

    /*select PWM function*/
    GPIO_PORTE_PCTL_R |= PCTL_VALUE;

    /*Enable Output on the pins*/
    SET_BIT(GPIO_PORTE_DEN_R, PE4);
    SET_BIT(GPIO_PORTE_DEN_R, PE5);

    /*For Pin PE4 PWM signal comes from PWM module 0 generator 2 (pwm2A)*/
    /*For Pin PE5 PWM signal comes from PWM module 0 generator 2 (pwm2B)*/
    /*Disable PWM0 Generator 2 selecting Count down Mode and for changes to be updated automatically*/
    PWM0_2_CTL_R = PWM_configs;

    /*OUTPUT HIGH when the counter reaches the LOAD A value, OUPUT LOW when the counter reaches Comparator A value*/
    /*OUTPUT HIGH when the counter reaches the LOAD A value*/
    SET_BIT(PWM0_2_GENA_R, 2);
    SET_BIT(PWM0_2_GENA_R, 3);
    /*OUPUT LOW when the counter reaches Comparator A value*/
    CLEAR_BIT(PWM0_2_GENA_R, 6);
    SET_BIT(PWM0_2_GENA_R, 7);

    /*OUTPUT HIGH when the counter reaches the LOAD B value, OUPUT LOW when the counter reaches Comparator B value*/
    /*OUTPUT HIGH when the counter reaches the LOAD B value*/
    SET_BIT(PWM0_2_GENB_R, 2);
    SET_BIT(PWM0_2_GENB_R, 3);
    /*OUPUT LOW when the counter reaches Comparator B value*/
    CLEAR_BIT(PWM0_2_GENB_R, 6);
    SET_BIT(PWM0_2_GENB_R, 11);

    /*For a 10KHz Frequency Load value =  ((1/10*10^3)/(1/16*10^6))-1 = 1599*/
    PWM0_2_LOAD_R = Load_Value;
    /*Duty Cycle is calculated inversely so for a 25% duty cycle cmpa = 1599*0.75 ~= 1200*/
    PWM0_2_CMPB_R = Duty_Cycle;
    PWM0_2_CMPA_R = Duty_Cycle;
    /*Start PWM0 generator 2*/
    SET_BIT(PWM0_2_CTL_R, 0);
    /*Enable M1PWM5 & M1PWM6 output*/
    SET_BIT(PWM0_ENABLE_R,4);
    SET_BIT(PWM0_ENABLE_R,5);
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*PWM set Duty Cycle Function*/
/*INPUTS: unsigned char 0-100 represents the percentage of the cycle*/
/*OUTPUTS: NONE*/
/*Description: Changes the Duty Cycle of the PWM For PINS PE4 and PE5*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/

void
PWM_set_DC(uint8_t value)
{

    Duty_Cycle = (Load_Value - (Load_Value*value/100));
    Duty_Cycle =  (Load_Value - (Load_Value*value/100));
    PWM0_2_CMPB_R = Duty_Cycle;
    PWM0_2_CMPA_R = Duty_Cycle;
}



/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*PWM get Duty Cycle Function*/
/*INPUTS: NONE*/
/*OUTPUTS: unsigned char 0-100 represents the percentage of the current Duty Cycle*/
/*Description: Returns the current duty cycle of the PWM*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/

uint8_t
PWM_get_DC()
{
    return (99-((100*PWM0_2_CMPA_R)/Load_Value));
}

