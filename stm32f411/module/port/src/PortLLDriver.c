/*******************************************************************************
 * Project: Driver Development
 * Module: PortLLDriver.c
 * SW-Version: 1.0.0
 * Purpose: This file to implement Hardware API of PORT
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"
#include "Port.h"

/********************************************************************************
 *                                  Global Data
********************************************************************************/

/********************************************************************************
 *                                  Function Implementation
*********************************************************************************/

/**
 * Function name        : Port_HwInit
 * 
 * Description          : This function to access hardware and init Port module
 * 
 * Input parameters     : GPIOx, pinConfigPtr, NumberPins
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_AFRL, GPIOx_AFRH
 *                        EXTI_FTSR, EXTI_RTSR, EXTI_IMR, SYSCFG_EXTICR
 * 
*/
FUNC(void) Port_HwInitGroup(GPIO_RegType *GPIOx, Port_PinConfigType *pinConfigPtr, Port_NumberPinType NumberPins) {
    Port_PinConfigType *LpConfig;
    LpConfig = pinConfigPtr;
    /* Loop all pins and init */
    uint8 LIndex;
    for (LIndex = 0; LIndex < NumberPins; LIndex++) {
        /* Config pin mode for Input, Output, Alternate and Analog mode */
        if (LpConfig->PinMode <= PIN_ANALOG_MODE) {
            /* Clean the correspond bits field first */
            GPIOx->MODER &= ~(0x11 << 2*(LpConfig->PinId));
            /* Set the correspond bits field */
            GPIOx->MODER |= (LpConfig->PinMode) << 2*(LpConfig->PinId);
        }
        /* Config pin mode for interrupt rasing, falling and both */
        else if (LpConfig->PinMode <= PIN_IT_BOTH) {
            if (LpConfig->PinMode == PIN_IT_FALLING) {
                /* Set failing selecting */
                EXTI->FTSR |= (1 << LpConfig->PinId);
                /* Clear the corresponding bits rasing selecting */
                EXTI->RTSR &= ~(1 << LpConfig->PinId);
            }
            else if (LpConfig->PinMode == PIN_IT_RASING) {
                /* Set rasing selecting */
                EXTI->RTSR |= (1 << LpConfig->PinId);
                /* Clear the corresponding bits failing selecting */
                EXTI->FTSR &= ~(1 << LpConfig->PinId);
            }
            else if (LpConfig->PinMode == PIN_IT_BOTH) {
                /* Set failing selecting */
                EXTI->FTSR |= (1 << LpConfig->PinId);
                /* Set rasing selecting */
                EXTI->RTSR |= (1 << LpConfig->PinId);
            }
            /* Set interrupt configuration */
            uint8 LregIndex;
            LregIndex = LpConfig->PinId / 4;

            uint8 LoffsetField;
            LoffsetField = LpConfig->PinId % 4 * 4;
            /* Clean the correspond bits field first */
            SYSCFG->EXTICR[LregIndex] &= ~(1111 << LoffsetField);
            /* Set external interrupt configuration */
            SYSCFG->EXTICR[LregIndex] |= (GPIO_TO_PORT_GROUP(GPIOx) << LoffsetField);

            /* Enable the exit interrupt using IMR */
            EXTI->IMR |= (1 << LpConfig->PinId);
        }
        else {
            /* Do nothing */
        }

        /* Config ouput type */
        /* Clean the correspond bit first */
        GPIOx->OTYPER &= ~(1 << LpConfig->PinId);
        /* Set the correspond bit */
        GPIOx->OTYPER |= (LpConfig->PinOutMode) << (LpConfig->PinId);

        /* Config speed */
        /* Clean the correspond bits field first */
        GPIOx->OSPEEDR &= ~(0x11 << 2*(LpConfig->PinId));
        /* Set the correspond bits field */
        GPIOx->OSPEEDR |= (LpConfig->PinSpeed) << 2*(LpConfig->PinId);

        /* Config Pull-up Pull-down */
        /* Clean the correspond bits field first */
        GPIOx->PUPDR &= ~(0x11 << 2*(LpConfig->PinId));
        /* Set the correspond bits field */
        GPIOx->PUPDR |= (LpConfig->PinPUPD) << 2*(LpConfig->PinId);

        /* Config alternate functionality */
        if (LpConfig->AlternativeMode <= 7) {
            /* Clean the correspond bits field first */
            GPIOx->AFRL &= ~(0x11 << 2*(LpConfig->PinId));
            /* Set the correspond bits field */
            GPIOx->AFRL |= (LpConfig->AlternativeMode) << 2*(LpConfig->PinId);
        }
        else if (LpConfig->AlternativeMode <= 15) {
            /* Clean the correspond bits field first */
            GPIOx->AFRH &= ~(0x11 << 2*(LpConfig->PinId));
            /* Set the correspond bits field */
            GPIOx->AFRH |= (LpConfig->AlternativeMode) << 2*(LpConfig->PinId);
        }
        else {
            /* Do nothing */
        }
        LpConfig++;
    }
    return;
}

/*
 * Function name        : Port_HwSetPinMode
 * 
 * Description          : This function access hardware to set the mode for Pin
 * 
 * Input parameters     : GPIOx, PinId, PinMode
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_MODER, EXTI_FTSR, EXTI_RTSR, EXTI_IMR, SYSCFG_EXTICR
 * 
*/
FUNC(void) Port_HwSetPinMode(GPIO_RegType *GPIOx, Port_PinType PinId, Port_PinModeType PinMode) {
    /* Config pin mode for Input, Output, Alternate and Analog mode */
    if (PinMode <= PIN_ANALOG_MODE) {
        /* Clean the correspond bits field first */
        GPIOx->MODER &= ~(0x11 << 2*(PinId));
        /* Set the correspond bits field */
        GPIOx->MODER |= (PinMode) << 2*(PinId);
    }
    /* Config pin mode for interrupt rasing, falling and both */
    else if (PinMode <= PIN_IT_BOTH) {
        if (PinMode == PIN_IT_FALLING) {
            /* Set failing selecting */
            EXTI->FTSR |= (1 << PinId);
            /* Clear the corresponding bits rasing selecting */
            EXTI->RTSR &= ~(1 << PinId);
        }
        else if (PinMode == PIN_IT_RASING) {
            /* Set rasing selecting */
            EXTI->RTSR |= (1 << PinId);
            /* Clear the corresponding bits failing selecting */
            EXTI->FTSR &= ~(1 << PinId);
        }
        else if (PinMode == PIN_IT_BOTH) {
            /* Set failing selecting */
            EXTI->FTSR |= (1 << PinId);
            /* Set rasing selecting */
            EXTI->RTSR |= (1 << PinId);
        }
        /* Set interrupt configuration */
        uint8 LregIndex;
        LregIndex = PinId / 4;

        uint8 LoffsetField;
        LoffsetField = PinId % 4 * 4;
        /* Clean the correspond bits field first */
        SYSCFG->EXTICR[LregIndex] &= ~(1111 << LoffsetField);
        /* Set external interrupt configuration */
        SYSCFG->EXTICR[LregIndex] |= (GPIO_TO_PORT_GROUP(GPIOx) << LoffsetField);

        /* Enable the EXTI interrupt using IMR */
        EXTI->IMR |= (1 << PinId);
    }
    else {
        /* Do nothing */
    }
    return;
}

/*
 * Function name        : Port_HwSetToAlternateMode
 * 
 * Description          : This function access hardware to set alternate functionality for Pin
 * 
 * Input parameters     : GPIOx, PinId, AltMode
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_AFRL, GPIOx_AFRH
 * 
*/
FUNC(void) Port_HwSetToAlternateMode(GPIO_RegType *GPIOx, Port_PinType PinId, Port_PinAlternateType AltMode) {
    /* Config alternate functionality */
    if (AltMode <= 7) {
        /* Clean the correspond bits field first */
        GPIOx->AFRL &= ~(0x11 << 2*(PinId));
        /* Set the correspond bits field */
        GPIOx->AFRL |= (AltMode) << 2*(PinId);
    }
    else if (AltMode <= 15) {
        /* Clean the correspond bits field first */
        GPIOx->AFRH &= ~(0x11 << 2*(PinId));
        /* Set the correspond bits field */
        GPIOx->AFRH |= (AltMode) << 2*(PinId);
    }
    else {
        /* Do nothing */
    }
    return;
}

/*
 * Function name        : Port_InterruptConfig
 * 
 * Description          : This function access hardware to configure the interrupt for port pin
 * 
 * Input parameters     : IQRNumber, IQRPriority, EnbOrDib
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : NVIC_ISERx, NVIC_IPRx
 * 
*/
FUNC(void) Port_InterruptConfig(Port_IQRNumberType IQRNumber, Port_IQRPriorityType IQRPriority, Port_IQREnableOrDisable EnbOrDib) {
    /* Get the register index */
    uint8 LregIndex;
    LregIndex = IQRNumber / 32;
    /* Get the offset of bit */
    uint8 LoffsetBit;
    LoffsetBit = IQRNumber % 32;
    /* Set enable or disable interrupt */
    if (EnbOrDib == ENABLE) {
        *NVIC_ISER(LregIndex) |= (1 << LoffsetBit);
    } 
    else if (EnbOrDib == DISABLE) {
        *NVIC_ISER(LregIndex) |= (0 << LoffsetBit);
    }
    else {
        /* Do nothing */
    }
        /* Get the register index */
    LregIndex = IQRNumber / 4;
    /* Get the offset of bit. Note: 4 LSB bits not implemented */ 
    LoffsetBit = IQRNumber % 4 * 8 + 4;
    /* Set interrupt priority */
    *NVIC_IPR(LregIndex) |= (IQRPriority << LoffsetBit);
    return;
}

/*
 * Function name        : Port_InterruptHandling
 * 
 * Description          : This function access hardware to clear the corresponding bit in EXTI pending register
 * 
 * Input parameters     : PinId
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : EXTI_PR
 * 
*/
FUNC(void) Port_InterruptHandling(Port_PinType PinId) {
    if ((EXTI->PR >> PinId) & 1) {
        EXTI->PR |= (1 << PinId);
    }
    return;
}

/********************************************************************************
 *                                  End of file
*********************************************************************************/
