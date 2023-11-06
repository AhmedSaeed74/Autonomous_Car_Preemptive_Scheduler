/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   std_types.h                                                  *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for the standard types                           *
 *                                                                             *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

#include "stdint.h"

#endif /* STD_TYPE_H_ */
