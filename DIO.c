/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   DIO.h                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for DIO driver                                   *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "DIO.h"
#include "DIO_Types.h"

/*******************************************************************************
 *                               Configurations                                *
 *******************************************************************************/
const DIO_PinCFG pinCFG[]={
                           /*A*/
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           /*B*/
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           /*C*/
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Input,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           /*D*/
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           /*E*/
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           /*F*/
                           {Input,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Input,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH}
};


/************************************************************************************
* API Name: DIO_Init
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Init DIO due to initialization
************************************************************************************/
void DIO_Init(void){
    uint32_t channelpos;
    uint32_t portx;
    uint8_t count = 0;
    for(count = DIO_ChannelA0; count<PinCount ;count++){
        channelpos = (count % 8);
        portx = (count/8);
        SET_BIT(SYSCTL_RCGCGPIO_R,portx);
        while((GET_BIT(SYSCTL_PRGPIO_R,portx)) == 0x00);

        switch(portx){
        case DIO_PortA:
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTA_CR_R, channelpos);
                SET_BIT(GPIO_PORTA_DIR_R, channelpos);
                SET_BIT(GPIO_PORTA_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTA_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTA_DIR_R, channelpos);
                SET_BIT(GPIO_PORTA_DEN_R, channelpos);
                SET_BIT(PORTA_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortB:
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTB_CR_R, channelpos);
                SET_BIT(GPIO_PORTB_DIR_R, channelpos);
                SET_BIT(GPIO_PORTB_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTB_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTB_DIR_R, channelpos);
                SET_BIT(GPIO_PORTB_DEN_R, channelpos);
                SET_BIT(PORTB_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortC:
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTC_CR_R, channelpos);
                SET_BIT(GPIO_PORTC_DIR_R, channelpos);
                SET_BIT(GPIO_PORTC_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTC_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTC_DIR_R, channelpos);
                SET_BIT(GPIO_PORTC_DEN_R, channelpos);
                SET_BIT(PORTC_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortD:
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTD_CR_R, channelpos);
                SET_BIT(GPIO_PORTD_DIR_R, channelpos);
                SET_BIT(GPIO_PORTD_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTD_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTD_DIR_R, channelpos);
                SET_BIT(GPIO_PORTD_DEN_R, channelpos);
                SET_BIT(PORTD_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortE:
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTE_CR_R, channelpos);
                SET_BIT(GPIO_PORTE_DIR_R, channelpos);
                SET_BIT(GPIO_PORTE_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTE_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTE_DIR_R, channelpos);
                SET_BIT(GPIO_PORTE_DEN_R, channelpos);
                SET_BIT(PORTE_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortF:
						GPIO_PORTF_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                SET_BIT(GPIO_PORTF_CR_R, channelpos);
                SET_BIT(GPIO_PORTF_DIR_R, channelpos);
                SET_BIT(GPIO_PORTF_DEN_R, channelpos);
            }else{
                SET_BIT(GPIO_PORTF_CR_R, channelpos);
                CLEAR_BIT(GPIO_PORTF_DIR_R, channelpos);
                SET_BIT(GPIO_PORTF_DEN_R, channelpos);
                SET_BIT(PORTF_INPUT_PULL_RESIST, channelpos);
            }

            break;
        }
    }
}


/************************************************************************************
* API Name: DIO_WritePort
* Parameters (in): portx, data
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Write data on specific port
************************************************************************************/
void DIO_WritePort(DIO_PortTypes portx , uint32_t data){
    switch(portx){
    case DIO_PortA:
        GPIO_PORTA_DATA_R = data;
        break;
    case DIO_PortB:
        GPIO_PORTB_DATA_R = data;
        break;
    case DIO_PortC:
        GPIO_PORTC_DATA_R = data;
        break;
    case DIO_PortD:
        GPIO_PORTD_DATA_R = data;
        break;
    case DIO_PortE:
        GPIO_PORTE_DATA_R = data;
        break;
    case DIO_PortF:
        GPIO_PORTF_DATA_R = data;
        break;
    }
}

/************************************************************************************
* API Name: DIO_WritePin
* Parameters (in): portx, binNumber, level
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Write to specific pin HIGH or LOW
************************************************************************************/
void DIO_WritePin(DIO_PortTypes portx, uint8_t binNumber, STD_Level level){
    switch(portx){
    case DIO_PortA:
        if(level == HIGH){
            SET_BIT(GPIO_PORTA_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTA_DATA_R, binNumber);
        }
        break;
    case DIO_PortB:
        if(level == HIGH){
            SET_BIT(GPIO_PORTB_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTB_DATA_R, binNumber);
        }
        break;
    case DIO_PortC:
        if(level == HIGH){
            SET_BIT(GPIO_PORTC_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTC_DATA_R, binNumber);
        }
        break;
    case DIO_PortD:
        if(level == HIGH){
            SET_BIT(GPIO_PORTD_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTD_DATA_R, binNumber);
        }
        break;
    case DIO_PortE:
        if(level == HIGH){
            SET_BIT(GPIO_PORTE_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTE_DATA_R, binNumber);
        }
        break;
    case DIO_PortF:
        if(level == HIGH){
            SET_BIT(GPIO_PORTF_DATA_R, binNumber);
        }
        else{
            CLEAR_BIT(GPIO_PORTF_DATA_R, binNumber);
        }
        break;
    }
}

/************************************************************************************
* API Name: DIO_ReadPin
* Parameters (in): portx, binNumber
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: read certain pin
************************************************************************************/
uint8_t DIO_ReadPin(DIO_PortTypes portx, uint8_t binNumber){
    uint8_t value = 0;
		binNumber = binNumber % 8;
    switch(portx){
    case DIO_PortA:
        value = GET_BIT(GPIO_PORTA_DATA_R, binNumber);
        break;
    case DIO_PortB:
        value = GET_BIT(GPIO_PORTB_DATA_R, binNumber);
        break;
    case DIO_PortC:
        value = GET_BIT(GPIO_PORTC_DATA_R, binNumber);
        break;
    case DIO_PortD:
        value = GET_BIT(GPIO_PORTD_DATA_R, binNumber);
        break;
    case DIO_PortE:
        value = GET_BIT(GPIO_PORTE_DATA_R, binNumber);
        break;
    case DIO_PortF:
        value = GET_BIT(GPIO_PORTF_DATA_R, binNumber);
        break;
    }
    return value;
}

/************************************************************************************
* API Name: DIO_ReadPort
* Parameters (in): portx
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: read specific port
************************************************************************************/
uint8_t DIO_ReadPort(DIO_PortTypes portx){
    uint8_t data = 0;
    switch(portx){
    case DIO_PortA:
        data = GPIO_PORTA_DATA_R;
        break;
    case DIO_PortB:
        data = GPIO_PORTB_DATA_R;
        break;
    case DIO_PortC:
        data = GPIO_PORTC_DATA_R;
        break;
    case DIO_PortD:
        data = GPIO_PORTD_DATA_R;
        break;
    case DIO_PortE:
        data = GPIO_PORTE_DATA_R;
        break;
    case DIO_PortF:
        data = GPIO_PORTF_DATA_R;
        break;
    }
    return data;
}


/************************************************************************************
* API Name: DIO_WritePinBitBanding
* Parameters (in): portx, binNumber, level
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: 
************************************************************************************/
void DIO_WritePinBitBanding(DIO_PortTypes portx, uint8_t binNumber, STD_Level level){
    switch(portx){
    case DIO_PortA:
        GPIO_PORTA_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortB:
        GPIO_PORTB_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortC:
        GPIO_PORTC_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortD:
        GPIO_PORTD_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortE:
        GPIO_PORTE_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortF:
        GPIO_PORTF_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    }
}

/************************************************************************************
* API Name: DIO_ReadPinBitBanding
* Parameters (in): portx, binNumber,
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: 
************************************************************************************/
uint8_t DIO_ReadPinBitBanding(DIO_PortTypes portx, uint8_t binNumber){
    uint8_t data = 0;
    switch(portx){
    case DIO_PortA:
        data = GET_BIT(GPIO_PORTA_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortB:
        data = GET_BIT(GPIO_PORTB_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortC:
        data = GET_BIT(GPIO_PORTC_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortD:
        data = GET_BIT(GPIO_PORTD_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortE:
        data = GET_BIT(GPIO_PORTE_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortF:
        data = GET_BIT(GPIO_PORTF_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    }
    return data;
}

/************************************************************************************
* API Name: DIO_ChangePinDir
* Parameters (in): portx, binNumber, dir
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: 
************************************************************************************/
void DIO_ChangePinDir(DIO_PortTypes portx, uint8_t binNumber, DIO_DIR dir){
    switch(portx){
    case DIO_PortA:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTA_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTA_DIR_R, binNumber);
        }
        break;
    case DIO_PortB:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTB_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTB_DIR_R, binNumber);
        }
        break;
    case DIO_PortC:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTC_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTC_DIR_R, binNumber);
        }
        break;
    case DIO_PortD:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTD_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTD_DIR_R, binNumber);
        }
        break;
    case DIO_PortE:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTE_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTE_DIR_R, binNumber);
        }
        break;
    case DIO_PortF:
        if(dir == Input){
            CLEAR_BIT(GPIO_PORTF_DIR_R, binNumber);
        }else{
            SET_BIT(GPIO_PORTF_DIR_R, binNumber);
        }
        break;
    }
}


