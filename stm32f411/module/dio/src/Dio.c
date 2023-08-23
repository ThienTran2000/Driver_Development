/*******************************************************************************
 * Project: Driver Development
 * Module: Dio.c
 * SW-Version: 1.0.0
 * Purpose: This file to implement API of DIO
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
 * Function name        : Dio_ReadPin
 * 
 * Description          : This function return the level of a specific pin
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : PinId (Refer @param PORTx_Pin)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of physical level of specific pin
 * 
 * Registers used       : None
 * 
*/
FUNC(Dio_LevelType) Dio_ReadPin(Dio_GroupType GroupId, Dio_PinType PinId) {
    /* Create a return value */
    Dio_LevelType LRet;
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Call Hardware function to read the value of pin */
    LRet = Dio_HwReadPin(LpGPIOx, PinId);
    return LRet;
}


/**
 * Function name        : Dio_WritePin
 * 
 * Description          : This function write a level to a specific pin
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : PinId (Refer @param PORTx_Pin)
 *                      : Level
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : None
 * 
 * Registers used       : None
 * 
*/
FUNC(void) Dio_WritePin(Dio_GroupType GroupId, Dio_PinType PinId, Dio_LevelType Level) {
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Call Hardware function to write a value to a pin */
    Dio_HwWritePin(LpGPIOx, PinId, Level);
    return;
}


/**
 * Function name        : Dio_ReadGroup
 * 
 * Description          : This function return the level of all pins of a specific Group
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of physical level of all pins of a specific Group
 * 
 * Registers used       : None
 * 
*/
FUNC(Dio_GroupLevelType) Dio_ReadGroup(Dio_GroupType GroupId) {
    /* Create a return value */
    Dio_GroupLevelType LRet;
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Call Hardware function to read the value of group */
    LRet = Dio_HwReadGroup(LpGPIOx);
    return LRet;
}


/**
 * Function name        : Dio_WriteGroup
 * 
 * Description          : This function write a level to all pins of a specific Group
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : Level
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of physical level of all pins of a specific Group
 * 
 * Registers used       : None
 * 
*/
FUNC(void) Dio_WriteGroup(Dio_GroupType GroupId, Dio_GroupLevelType Level) {
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Call Hardware function to write a value to a group */
    Dio_HwWriteGroup(LpGPIOx, Level);
    return;
}

/**
 * Function name        : Dio_WriteGroup
 * 
 * Description          : This function flip a specific pin and return the value of that pin after flip
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : PinId (Refer @param PORTx_Pin)
 * 
 * Inout parameters     : None
 * 
 * Output parameters    : None
 * 
 * Return parameter     : Return the value of specific pin after flip
 * 
 * Registers used       : None
 * 
*/
FUNC(Dio_LevelType) Dio_FlipPin(Dio_GroupType GroupId, Dio_PinType PinId) {
    /* Create a return value */
    Dio_LevelType LRet;
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Call Hardware function to read the value of group */
    LRet = Dio_HwFlipPin(LpGPIOx, PinId);
    return LRet;
}

/********************************************************************************
 *                                  End of file
*********************************************************************************/
