/*******************************************************************************
 * Project: Driver Development
 * Module: DioLLDriver.h
 * SW-Version: 1.0.0
 * Purpose: This file contain macros, Dio hardware APIs Prototype
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

#ifndef DIOLLDRIVER_H
#define DIOLLDRIVER_H

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"
#include "Dio.h"

/********************************************************************************
 *                                  Global Data Type
********************************************************************************/

/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/

/********************************************************************************
 *                                  Function Prototypes
*********************************************************************************/

/* Function for Dio access hardware to read level of a pin */
extern FUNC(Dio_LevelType) Dio_HwReadPin(GPIO_RegType *pGPIOx, Dio_PinType PinId);

/* Function for Dio access hardware to write a level to a pin */
extern FUNC(void) Dio_HwWritePin(GPIO_RegType *pGPIOx, Dio_PinType PinId, Dio_LevelType Level);

/* Function for Dio access hardware to read level of a Group */
extern FUNC(Dio_GroupLevelType) Dio_HwReadGroup(GPIO_RegType *pGPIOx);

/* Function for Dio access hardware to write a level to a Group */
extern FUNC(void) Dio_HwWriteGroup(GPIO_RegType *pGPIOx, Dio_GroupLevelType Level);

/* Function for Dio access hardware to flip a level of a pin */
extern FUNC(Dio_LevelType) Dio_HwFlipPin(GPIO_RegType *pGPIOx, Dio_PinType PinId);

#endif /* DIOLLDRIVER_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/