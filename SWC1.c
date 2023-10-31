/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC1.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for The first software component                 *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "SWC1.h"
#include "SWCsIncludes.h"
#include "Sensor.h"
#include "ultrasonic.h"
#include "PushBuuton.h"
#include "LCD.h"
#include "Motor.h"

/* External reference to the TaskHandle for TempSensor Task */
extern TaskHandle_t TSHandle;

/*
 * Description:
 * ModulesInit task initializes various hardware modules, including the PushButton,
 * LCD, Motors, Temperature Sensor, Left LDR, Right LDR, and Ultrasonic Sensor.
 * Once initialization is complete, it suspends itself.
 */
void ModulesInit(void * pvParameters){
    /* Initialize the PushButton module */
    PushButton_INIT();

    /* Initialize the LCD module */
    LCD_Init();

    /* Initialize the Motor module */
    Motors_Init();

    /* Initialize the temperature sensor */
    TS_Init();

    /* Initialize the left LDR */
    LdrLeft_Init();

    /* Initialize the right LDR */
    LdrRight_Init();

    /* Initialize the ultrasonic sensor */
    ultarsonic_init();

    /* At the end the task suspends itself */
    vTaskSuspend( NULL );
}

/*
 * Description:
 * The SwitchCheck task monitors the Start Button and displays status on an LCD screen.
 * If the Start Button is pressed, it clears the LCD screen, resets the counter, and waits for a specified interval.
 * If the Start Button is not pressed, it displays "I am OFF" on the LCD, stops motors, and increments the counter.
 */
void SwitchCheck(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 60000/ portTICK_PERIOD_MS;

    uint8_t counter = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        /* Check if the Start Button is pressed */
        if(GET_Start_Button() == 1){
            /* Clear the LCD screen */
            LCD_Clear();

            LCD_GoToString(1,0, "DISTANCE=");
            LCD_GoToString(2,0, "DIR=");

            /* Reset the counter */
            counter = 0;

            /* Delay until the specified time interval (xFrequency) has passed */
            vTaskDelayUntil(&xLastWakeTime, xFrequency);
        }else{

            if(counter == 0)
            {
                /* Clear the LCD screen */
                LCD_Clear();

                /* Display "I am OFF" on the LCD */
                LCD_SendString("I am OFF");

                /* stop the motors */
                Motors_set_direction(STOP);

                /* Increment the counter */
                counter++;
            }
        }
    }
}