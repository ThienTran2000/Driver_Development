/*******************************************************************************
 * Project: Driver Development
 * Module: DioLLDriver.c
 * SW-Version: 1.0.0
 * Purpose: This file to implement Hardware API of DIO
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"
#include "DioLLDriver.h"
#include "Dio.h"

/********************************************************************************
 *                                  Global Data
********************************************************************************/

/********************************************************************************
 *                                  Function Implementation
*********************************************************************************/

/**
 * Function name        : Dio_SelectGPIOx
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
FUNC(GPIO_RegType *) Dio_SelectGPIOx(Dio_GroupType GroupId) {
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
 * Function name        : Dio_HwReadPin
 * 
 * Description          : This function return the level of a specific pin
 * 
 * Input parameters     : GPIOx handler (Refer @param GPIOx)
 *                      : PinId (Refer @param PORTx_Pin)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of physical level of specific pin
 * 
 * Registers used       : GPIOx_IDR
 * 
*/
FUNC(Dio_LevelType) Dio_HwReadPin(GPIO_RegType *pGPIOx, Dio_PinType PinId) {
    Dio_LevelType Lret;
    Lret = (Dio_LevelType)((pGPIOx->IDR >> PinId) & 0x00000001);
    return Lret;
}


/**
 * Function name        : Dio_HwWritePin
 * 
 * Description          : This function write a level to a specific pin
 * 
 * Input parameters     : GPIOx handler (Refer @param GPIOx)
 *                      : PinId (Refer @param PORTx_Pin)
 *                      : Level
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_ODR
 * 
*/
FUNC(void) Dio_HwWritePin(GPIO_RegType *pGPIOx, Dio_PinType PinId, Dio_LevelType Level) {
    if (Level != 0) {
        pGPIOx->ODR |= (1 << PinId);
    } 
    else {
       pGPIOx->ODR &= ~(1 << PinId);
    }
    return;
}


/**
 * Function name        : Dio_HwReadGroup
 * 
 * Description          : This function return the level of a Group
 * 
 * Input parameters     : GPIOx handler (Refer @param GPIOx)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of physical level of a Group
 * 
 * Registers used       : GPIOx_IDR
 * 
*/
FUNC(Dio_GroupLevelType) Dio_HwReadGroup(GPIO_RegType *pGPIOx) {
    Dio_GroupLevelType Lret;
    Lret = pGPIOx->ODR;
    return Lret;
}


/**
 * Function name        : Dio_HwWriteGroup
 * 
 * Description          : This function write a level to a group
 * 
 * Input parameters     : GPIOx handler (Refer @param GPIOx)
 *                      : Level
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : GPIOx_ODR
 * 
*/
FUNC(void) Dio_HwWriteGroup(GPIO_RegType *pGPIOx, Dio_GroupLevelType Level) {
    pGPIOx->ODR = Level;
    return;
}


/**
 * Function name        : Dio_HwWriteGroup
 * 
 * Description          : This function flip a specific pin and return the value of that pin after flip
 * 
 * Input parameters     : GPIOx handler (Refer @param GPIOx)
 *                      : PinId (Refer @param PORTx_Pin)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of specific pin after flip
 * 
 * Registers used       : GPIOx_ODR
 * 
*/
FUNC(Dio_LevelType) Dio_HwFlipPin(GPIO_RegType *pGPIOx, Dio_PinType PinId) {
    Dio_LevelType Lret;
    pGPIOx->ODR ^= (1 << PinId);
    Lret = (Dio_LevelType)((pGPIOx->ODR >> PinId) & 0x00000001);
    return Lret;
}

/********************************************************************************
 *                                  End of file
*********************************************************************************/
