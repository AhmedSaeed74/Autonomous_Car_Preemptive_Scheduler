/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   ADC.c                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for ADC driver                                   *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "ADC.h"


static void ADC_sequencer_EN(ADC_Base BASE, ADC_sequencer sequencer, ADC_CH_TYPE ch);

/* ADC_sequencer_EN Function */
/**
 * @brief Enables the ADC sequencer for a specific channel in the Analog-to-Digital Converter (ADC) module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param sequencer The ADC sequencer to enable. (ADC_sequencer)
 * @param ch        The ADC channel to associate with the sequencer. (ADC_CH_TYPE)
 *
 * @return None.
 *
 * @note This function enables the specified ADC sequencer for the given channel.
 *       It configures the ADC module registers to associate the sequencer with the channel
 *       and enables the sequencer for subsequent conversions.
 */

void ADC_sequencer_EN(ADC_Base BASE, ADC_sequencer sequencer, ADC_CH_TYPE ch)
{
    switch (BASE)
    {
        case ADC_Base_0:
            switch (sequencer)
            {
                case ADC_sequencer_0:
                    CLEAR_BIT(ADC0_ACTSS_R, 0);             /* Disable ADC sequencer 0 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    SET_BIT(ADC0_SSCTL0_R, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    SET_BIT(ADC0_SSCTL0_R, 2);
                    SET_BIT(ADC0_ACTSS_R, 0);             /* Enable ADC sequencer 0 */
                    break;
                case ADC_sequencer_1:
                    CLEAR_BIT(ADC0_ACTSS_R, 1);             /* Disable ADC sequencer 1 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    SET_BIT(ADC0_SSCTL1_R, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    SET_BIT(ADC0_SSCTL1_R, 2);
                    SET_BIT(ADC0_ACTSS_R, 1);             /* Enable ADC sequencer 1 */
                    break;
                case ADC_sequencer_2:
                    CLEAR_BIT(ADC0_ACTSS_R, 2);             /* Disable ADC sequencer 2 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    SET_BIT(ADC0_SSCTL2_R, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    SET_BIT(ADC0_SSCTL2_R, 2);
                    SET_BIT(ADC0_ACTSS_R, 2);             /* Enable ADC sequencer 2 */
                    break;
                case ADC_sequencer_3:
                    CLEAR_BIT(ADC0_ACTSS_R, 3);             /* Disable ADC sequencer 3 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    SET_BIT(ADC0_SSCTL3_R, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    SET_BIT(ADC0_SSCTL3_R, 2);
                    SET_BIT(ADC0_ACTSS_R, 3);             /* Enable ADC sequencer 3 */
                    break;
                default:
                    /* Handle invalid sequencer */
                    break;
            }
            break;
        case ADC_Base_1:
            /* Handle ADC Base 1 if applicable */
            break;
        default:
            /* Handle invalid ADC Base */
            break;
    }
}

/* ADC_Read Function */
/**
 * @brief Reads the converted value from the Analog-to-Digital Converter (ADC) module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param ch        The ADC channel to read the converted value from. (ADC_CH_TYPE)
 * @param sequencer The ADC sequencer to read the converted value from. (ADC_sequencer)
 *
 * @return The converted value read from the ADC.
 *
 * @note This function reads the converted value from the ADC module for a specific channel and sequencer.
 *       It waits for the conversion to complete, retrieves the converted value,
 *       and returns it to the caller.
 */

uint16_t ADC_Read(ADC_Base BASE, ADC_CH_TYPE ch, ADC_sequencer sequencer)
{
    uint16_t value;

    switch (sequencer)
    {
        case ADC_sequencer_0:
            ADC0_SSMUX0_R = (ADC0_SSMUX0_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            SET_BIT(ADC0_PSSI_R, 0);                          /* Initiate the ADC conversion for Sample Sequencer 0 */
            while (!GET_BIT(ADC0_RIS_R, 0U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO0_R;                                 /* Read the converted value */
            SET_BIT(ADC0_ISC_R, 0);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_1:
            ADC0_SSMUX1_R = (ADC0_SSMUX1_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            SET_BIT(ADC0_PSSI_R, 1);                          /* Initiate the ADC conversion for Sample Sequencer 1 */
            while (!GET_BIT(ADC0_RIS_R, 1U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO1_R;                                 /* Read the converted value */
            SET_BIT(ADC0_ISC_R, 1);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_2:
            ADC0_SSMUX2_R = (ADC0_SSMUX2_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            SET_BIT(ADC0_PSSI_R, 2);                          /* Initiate the ADC conversion for Sample Sequencer 2 */
            while (!GET_BIT(ADC0_RIS_R, 2U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO2_R;                                 /* Read the converted value */
            SET_BIT(ADC0_ISC_R, 2);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_3:
            ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            SET_BIT(ADC0_PSSI_R, 3);                          /* Initiate the ADC conversion for Sample Sequencer 3 */
            while (!GET_BIT(ADC0_RIS_R, 3U))                     /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO3_R;                                 /* Read the converted value */
            SET_BIT(ADC0_ISC_R, 3);                           /* Clear the conversion completion flag */
            break;
        default:
            /* Handle invalid sequencer */
            break;
    }

    return value;
}


/* ADC_Init Function */
/**
 * @brief Initializes the Analog-to-Digital Converter (ADC) module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param module    The ADC module to enable. (ADC_Module)
 * @param ch        The ADC channel to configure. (ADC_CH_TYPE)
 * @param sequencer The ADC sequencer to enable for the specified channel. (ADC_sequencer)
 *
 * @return None.
 *
 * @note This function initializes the ADC module for a specific channel and sequencer.
 *       It enables the necessary GPIO pins, configures the corresponding registers,
 *       and enables the specified ADC sequencer.
 */

void ADC_Init(ADC_Base BASE, ADC_Module module, ADC_CH_TYPE ch, ADC_sequencer sequencer)
{
    switch (module)
    {
        case ADC_Module_0:
            SET_BIT(SYSCTL_RCGCADC_R, 0);   /* Enable ADC Module 0 */
            break;
        case ADC_Module_1:
            SET_BIT(SYSCTL_RCGCADC_R, 1);   /* Enable ADC Module 1 */
            break;
        default:
            /* Handle invalid ADC Module */
            break;
    }
		DIO_Init(); 

    switch (ch)
    {
        case CH_0:
            SET_BIT(GPIO_PORTE_AFSEL_R, 3); /* Enable alternate function for PE3 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 3);   /* Disable digital function for PE3 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 3); /* Enable analog mode for PE3 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_0 */
            break;
        case CH_1:
            SET_BIT(GPIO_PORTE_AFSEL_R, 2); /* Enable alternate function for PE2 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 2);   /* Disable digital function for PE2 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 2); /* Enable analog mode for PE2 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_1 */
            break;
        case CH_2:
            SET_BIT(GPIO_PORTE_AFSEL_R, 1); /* Enable alternate function for PE1 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 1);   /* Disable digital function for PE1 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 1); /* Enable analog mode for PE1 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_2 */
            break;
        case CH_3:
            SET_BIT(GPIO_PORTE_AFSEL_R, 0); /* Enable alternate function for PE0 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 0);   /* Disable digital function for PE0 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 0); /* Enable analog mode for PE0 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_3 */
            break;
        case CH_4:
            SET_BIT(GPIO_PORTE_AFSEL_R, 3); /* Enable alternate function for PD3 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 3);   /* Disable digital function for PD3 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 3); /* Enable analog mode for PD3 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_4 */
            break;
        case CH_5:
            SET_BIT(GPIO_PORTE_AFSEL_R, 2); /* Enable alternate function for PD2 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 2);   /* Disable digital function for PD2 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 2); /* Enable analog mode for PD2 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_5 */
            break;
        case CH_6:
            SET_BIT(GPIO_PORTE_AFSEL_R, 1); /* Enable alternate function for PD1 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 1);   /* Disable digital function for PD1 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 1); /* Enable analog mode for PD1 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_6 */
            break;
        case CH_7:
            SET_BIT(GPIO_PORTE_AFSEL_R, 0); /* Enable alternate function forPD0 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 0);   /* Disable digital function for PD0 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 0); /* Enable analog mode for PD0 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_7 */
            break;
        case CH_8:
            SET_BIT(GPIO_PORTE_AFSEL_R, 5); /* Enable alternate function for PE5 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 5);   /* Disable digital function for PE5 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 5); /* Enable analog mode for PE5 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_8 */
            break;
        case CH_9:
            SET_BIT(GPIO_PORTE_AFSEL_R, 4); /* Enable alternate function for PE4 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 4);   /* Disable digital function for PE4 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 4); /* Enable analog mode for PE4 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_9 */
            break;
        case CH_10:
            SET_BIT(GPIO_PORTE_AFSEL_R, 4); /* Enable alternate function for PB4 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 4);   /* Disable digital function for PB4 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 4); /* Enable analog mode for PB4 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_10 */
            break;
        case CH_11:
            SET_BIT(GPIO_PORTE_AFSEL_R, 5); /* Enable alternate function for PB5 */
            CLEAR_BIT(GPIO_PORTE_DEN_R, 5);   /* Disable digital function for PB5 */
            SET_BIT(GPIO_PORTE_AMSEL_R, 5); /* Enable analog mode for PB5 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_11 */
            break;
        default:
            /* Handle invalid Channel */
            break;
    }
}

/**
 * @brief Initializes the ADC module for the temperature sensor on the specified channel.
 *
 * @param ADC_Type The ADC type to initialize.
 * @param Channel  The ADC channel to use for temperature sensing.
 */

void ADC_Init_TS(uint8_t ADC_Type, uint8_t Channel)
{
    /* Enable the clock for the specified ADC module (ADC_Type) */
    SYSCTL_RCGCADC_R |= (1U << ADC_Type);

    /* Enable the clock for GPIO Port E */
    SYSCTL_RCGCGPIO_R |= (1U << 4);

    /* Configure GPIO pins in Port E (PE3) for alternative function (ADC) */
    GPIO_PORTE_AFSEL_R |= 0x08;

    /* Disable the digital functionality of GPIO pins in Port E (PE3) */
    GPIO_PORTE_DEN_R &= ~(0x08);

    /* Enable the analog functionality of GPIO pins in Port E (PE3) */
    GPIO_PORTE_AMSEL_R |= 0x08;

    /* Disable Sample Sequencer 3 before making changes */
    ADC0_ACTSS_R &= ~(1U << 3);

    /* Select start conversion trigger method (using software trigger) */
    ADC0_EMUX_R = 0U;

    /* Configure Sample Sequence Control for single-ended, one-conversion, and raw interrupt */
    ADC0_SSCTL3_R = (1U << 1) | (1U << 2) | (1U << 3);

    /* Enable Sample Sequencer 3 */
    ADC0_ACTSS_R |= (1U << 3);
}
/**
 * @brief Reads the temperature value from the specified channel.
 *
 * @param Channel The ADC channel to read from.
 *
 * @return The temperature value read from the ADC.
 */

uint16_t ADC_Read_TS(uint8_t Channel)
{
    /* Select ADC input channel */
    ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0) | Channel;

    /* Initiate the ADC conversion for Sample Sequencer 3 */
    ADC0_PSSI_R |= (1U << 3);

    /* Wait for conversion to complete */
    while ((ADC0_RIS_R & (1U << 3)) == 0) {}

    /* Read conversion result */
    uint16_t result = ADC0_SSFIFO3_R;

    /* Clear completion flag */
    ADC0_ISC_R = (1U << 3);

    /* Conversion formula to calculate temperature */
    result = (147.5 - (((float)75 * VREFF * (float)result) / 4096));

    return result;
}



