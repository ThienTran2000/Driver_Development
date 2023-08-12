/*******************************************************************************
 * Project: Driver Development
 * Module: Dio.h
 * SW-Version: 1.0.0
 * Purpose: This file contain macros, Dio APIs definition, Dio data type
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

#ifndef DIO_H
#define DIO_H

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"

/********************************************************************************
 *                                  Global Data Type
********************************************************************************/
typedef uint8               Dio_LevelType;
typedef uint8               Dio_PinType;
typedef uint8               Dio_GroupType;
typedef uint16              Dio_GroupLevelType;


/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/
/**
 * @brief: This parameter is used for Dio_GroupType
 * @param: GPIOx_Group 
 */
#define GPIOA_Group         0
#define GPIOB_Group         1
#define GPIOC_Group         2
#define GPIOD_Group         3
#define GPIOE_Group         4
#define GPIOH_Group         5

/**
 * @brief: This parameter is used for Dio_PinType
 * @param: GPIOx_Pin
 */
#define GPIOx_Pin1          1
#define GPIOx_Pin2          2
#define GPIOx_Pin3          3
#define GPIOx_Pin4          4
#define GPIOx_Pin5          5
#define GPIOx_Pin6          6
#define GPIOx_Pin7          7
#define GPIOx_Pin8          8
#define GPIOx_Pin9          9
#define GPIOx_Pin10         10
#define GPIOx_Pin11         11
#define GPIOx_Pin12         12
#define GPIOx_Pin13         13
#define GPIOx_Pin14         14
#define GPIOx_Pin15         15

/********************************************************************************
 *                                  Function Prototypes
*********************************************************************************/
/* Function for DIO read pin API */
extern FUNC(Dio_LevelType) Dio_ReadPin(Dio_GroupType GroupId, Dio_PinType PinId);

/* Function for DIO write pin API */
extern FUNC(void) Dio_WritePin(Dio_GroupType GroupId, Dio_PinType PinId);

/* Function for DIO read group API */
extern FUNC(Dio_GroupLevelType) Dio_ReadGroup(Dio_GroupType GroupId);

/* Function for DIO write group API */
extern FUNC(Dio_GroupLevelType) Dio_WriteGroup(Dio_GroupType GroupId);

/* Function for DIO write group API */
extern FUNC(Dio_GroupLevelType) Dio_WriteGroup(Dio_GroupType GroupId);

/* Function for DIO flip pin API */
extern FUNC(Dio_LevelType) Dio_FlipPin(Dio_GroupType GroupId, Dio_PinType PinId);

#endif /* DIO_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/