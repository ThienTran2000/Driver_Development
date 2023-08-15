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
 * Function name        : Port_SelectGPIOx
 * 
 * Description          : This function return register structure pointer
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return register structure pointer
 * 
 * Registers used       : None
 * 
*/
FUNC(GPIO_RegType *) Port_SelectGPIOx(Port_GroupType GroupId) {
    /* Create a return value*/
    GPIO_RegType *LpGPIOx;
    LpGPIOx = NULL;
    if (GroupId == 0) {
        LpGPIOx = GPIOA;
    }
    else if (GroupId == 1) {
        LpGPIOx = GPIOB;
    } 
    else if (GroupId == 2) {
        LpGPIOx = GPIOC;
    } 
    else if (GroupId == 3) {
        LpGPIOx = GPIOD;
    } 
    else if (GroupId == 4) {
        LpGPIOx = GPIOE;
    } 
    else if (GroupId == 5) {
        LpGPIOx =GPIOH;
    }
    else {
        /* Do nothing */
    }
    return LpGPIOx;
}


/**
 * Function name        : Port_HwInit
 * 
 * Description          : This function to access hardware and init Port module
 * 
 * Input parameters     : GPIOx
 *                      : pinConfigPtr
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_AFRL, GPIOx_AFRH
 * 
*/
FUNC(void) Port_HwInitGroup(GPIO_RegType *GPIOx, Port_PinConfigType *pinConfigPtr, Port_NumberPinType NumberPins) {
    Port_PinConfigType *LpConfig;
    LpConfig = pinConfigPtr;
    /* Loop all pins and init */
    uint8 LIndex;
    for (LIndex = 0; LIndex < NumberPins; LIndex++) {
        /* Config pin mode for Input, Output, Alternate and Analog mode */
        if (LpConfig->PinMode <= 3) {
            /* Clean the correspond bits field first */
            GPIOx->MODER &= ~(0x11 << 2*(LpConfig->PinId));
            /* Set the correspond bits field */
            GPIOx->MODER |= (LpConfig->PinMode) << 2*(LpConfig->PinId);
        }
        /* Config pin mode for interrupt rasing, falling and both */
        else {
            /* TBD */
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
 * Description          : TThis function access hardware to set the mode for Pin
 * 
 * Input parameters     : GPIOx
 *                      : pinConfigPtr
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_MODER
 * 
*/
FUNC(void) Port_HwSetPinMode(GPIO_RegType *GPIOx, Port_PinType PinId, Port_PinModeType PinMode) {
    /* Config pin mode for Input, Output, Alternate and Analog mode */
    if (PinMode <= 3) {
        /* Clean the correspond bits field first */
        GPIOx->MODER &= ~(0x11 << 2*(PinId));
        /* Set the correspond bits field */
        GPIOx->MODER |= (PinMode) << 2*(PinId);
    }
    /* Config pin mode for interrupt rasing, falling and both */
    else {
        /* TBD */
    }
    return;
}

/*
 * Function name        : Port_HwSetToAlternateMode
 * 
 * Description          : TThis function access hardware to set alternate functionality for Pin
 * 
 * Input parameters     : GPIOx
 *                      : pinConfigPtr
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

/********************************************************************************
 *                                  End of file
*********************************************************************************/
