/*******************************************************************************
 * Project: Driver Development
 * Module: PortLLDriver.h
 * SW-Version: 1.0.0
 * Purpose: This file contain macros, Port hardware APIs Prototype
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

#ifndef PORTLLDRIVER_H
#define PORTLLDRIVER_H

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"
#include "Port.h"

/********************************************************************************
 *                                  Global Data Type
********************************************************************************/

/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/

/********************************************************************************
 *                                  Function Prototypes
*********************************************************************************/

/* Function for PORT init GPIO group API */
extern FUNC(void) Port_HwInitGroup(GPIO_RegType *GPIOx, Port_PinConfigType *pinConfigPtr, Port_NumberPinType NumberPins);

/* Function for PORT set pin mode API */
extern FUNC(void) Port_HwSetPinMode(GPIO_RegType *GPIOx, Port_PinType PinId, Port_PinModeType PinMode);

/* Function for PORT set alternate functionality API */
extern FUNC(void) Port_HwSetToAlternateMode(GPIO_RegType *GPIOx, Port_PinType PinId, Port_PinAlternateType AltMode);

/* Function for PORT set interrupt config port pin API */
extern FUNC(void) Port_InterruptConfig(Port_IQRNumberType IQRNumber, Port_IQRPriorityType IQRPriority, Port_IQREnableOrDisable EnbOrDib);

/* Function for PORT clear the corresponding bit in EXTI Pending register API */
extern FUNC(void) Port_InterruptHandling(Port_PinType PinId);

#endif /* PORTLLDRIVER_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/
