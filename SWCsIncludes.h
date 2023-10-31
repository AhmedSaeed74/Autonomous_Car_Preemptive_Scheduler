/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWCsIncludes.h                                               *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for software components includes                 *
 *                                                                             *
 *******************************************************************************/
#ifndef SWCSINCLUDES_H__
#define SWCSINCLUDES_H__

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/* Description:
 * This structure is used to store values from left and right LDRs.
 */
 typedef struct{
	uint16_t LEFT;
	uint16_t RIGHT;
}ldr_val;
 
/*
 * Description :
 * Enum for defining directions (RIGHT, LEFT, CENTER).
 */
typedef enum{
	RIGHT,
	LEFT,
	CENTER
}dir_t;


#endif
