/*******************************************************************************
 * Project: Driver Development
 * Module: Port.c
 * SW-Version: 1.0.0
 * Purpose: This file to implement API of PORT
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"
#include "PortLLDriver.h"
#include "Port.h"

/********************************************************************************
 *                                  Global Data
********************************************************************************/

/********************************************************************************
 *                                  Function Implementation
*********************************************************************************/

/**
 * Function name        : Port_Init
 * 
 * Description          : This function to initialize for PORT module
 * 
 * Input parameters     : ConfigPtr, NumberGroups
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
FUNC(void) Port_Init(Port_ConfigType *ConfigPtr, Port_NumberGroupType NumberGroups) {
    Port_ConfigType *LpConfig;
    LpConfig = ConfigPtr;
    /* Loop all GPIO groups and init */
    uint8 LIndex;
    for (LIndex = 0; LIndex < NumberGroups; LIndex++) {
        GPIO_RegType *LpGPIOx;
        LpGPIOx = PORT_GROUP_TO_GPIO(LpConfig->GroupId);
        /* Init hardware */
        Port_HwInitGroup(LpGPIOx, LpConfig->PinConfig, LpConfig->NumberPins);
        LpConfig++;
    }
    return;
}


/**
 * Function name        : Port_SetPinMode
 * 
 * Description          : This function to set the mode for Pin
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : PinId (Refer @param PORTx_Pin)
 *                      : PinMode
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
FUNC(void) Port_SetPinMode(Port_GroupType GroupId, Port_PinType PinId, Port_PinModeType PinMode) {
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Set pin mode hardware */
    Port_HwSetPinMode(LpGPIOx, PinId, PinMode);
    return;
}


/**
 * Function name        : Port_SetToAlternateMode
 * 
 * Description          : This function to set the mode for alternate functionality
 * 
 * Input parameters     : GroupId (Refer @param PORTx_Group)
 *                      : PinId (Refer @param PORTx_Pin)
 *                      : AltMode
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
FUNC(void) Port_SetToAlternateMode(Port_GroupType GroupId, Port_PinType PinId, Port_PinAlternateType AltMode) {
    GPIO_RegType *LpGPIOx;
    LpGPIOx = PORT_GROUP_TO_GPIO(GroupId);
    /* Set alternate functionality hardware */
    Port_HwSetToAlternateMode(LpGPIOx, PinId, AltMode);
    return;
}

/********************************************************************************
 *                                  End of file
*********************************************************************************/
