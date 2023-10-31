/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Motor.c                                                      *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for Motor driver                                 *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "std_types.h"
#include "PWM.h"
#include "Motor.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define UNLOCK 0x4C4F434B
#define PORTD_RCGC 3
#define PD6 6   /*motor 1 +ve*/
#define PD7 7   /*motor 1 -ve*/
#define PD2 2   /*motor 2 +ve*/
#define PD3 3   /*motor 2 -ve*/
#define LEFT_MOTORS     1<<(PD6|PD2)
#define RIGHT_MOTORS    1<<(PD7|PD3)
#define PINS 1<<PD6|1<<PD7|1<<PD2|1<<PD3

/*******************************************************************************
 *                                Variables                                  *
 *******************************************************************************/
dir direction;

/*
 * Description:
 * This function initializes the motors, configuring GPIO pins and PWM for motor control.
 * It sets the motor duty cycle to 70%.
 * Parameters: None
 * Returns: None
 */
void
Motors_Init(void)
{
    /*Dio Init*/
 DIO_Init();
   

    PWM_INIT();

  	PWM_set_DC(70);

}

/*
 * Description:
 * This function sets the direction of the motors based on the provided enum value.
 * It configures GPIO pins to control motor direction.
 * Parameters:
 * - d: The direction to set (STOP, FORWARD, BACKWARD, LEFTT, RIGHTT, SPIN).
 * Returns: None
 */
void
Motors_set_direction(dir d)
{
    switch (d)
    {
    case STOP:
        DIO_WritePin(DIO_PortD, PD2,  LOW);
        DIO_WritePin(DIO_PortD, PD3,  LOW);
        DIO_WritePin(DIO_PortD, PD6,  LOW);
        DIO_WritePin(DIO_PortD, PD7,  LOW);   
        direction = STOP;
        break;

    case FORWARD:
        DIO_WritePin(DIO_PortD, PD2,  LOW);
        DIO_WritePin(DIO_PortD, PD3,  HIGH);
        DIO_WritePin(DIO_PortD, PD6,  LOW);
        DIO_WritePin(DIO_PortD, PD7,  HIGH);
        direction = FORWARD;

        break;

    case BACKWARD:
             DIO_WritePin(DIO_PortD, PD2,  HIGH);
        DIO_WritePin(DIO_PortD, PD3,  LOW);
        DIO_WritePin(DIO_PortD, PD6,  HIGH);
        DIO_WritePin(DIO_PortD, PD7,  LOW);
        direction = BACKWARD;
        break;

    case LEFTT:
           DIO_WritePin(DIO_PortD, PD2,  LOW);
        DIO_WritePin(DIO_PortD, PD3,  LOW);
        DIO_WritePin(DIO_PortD, PD6,  LOW);
        DIO_WritePin(DIO_PortD, PD7,  HIGH);
        direction = LEFTT;
        break;

    case RIGHTT:
       DIO_WritePin(DIO_PortD, PD3,  HIGH);
        DIO_WritePin(DIO_PortD, PD2,  LOW);
        DIO_WritePin(DIO_PortD, PD6,  LOW);
        DIO_WritePin(DIO_PortD, PD7,  LOW);
        direction = RIGHTT;
        break;

    case SPIN:
          DIO_WritePin(DIO_PortD, PD2,  LOW);
        DIO_WritePin(DIO_PortD, PD3,  HIGH);
        DIO_WritePin(DIO_PortD, PD6,  HIGH);
        DIO_WritePin(DIO_PortD, PD7,  LOW);
        direction = SPIN;
        break;

    default:
        break;
    }

}


dir
Motors_get_direction()
{
    return direction;
}
