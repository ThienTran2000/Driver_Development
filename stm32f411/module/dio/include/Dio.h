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

#define SET_PIN             (Dio_LevelType)0x01
#define RESET_PIN           (Dio_LevelType)0x00

/********************************************************************************
 *                                  Function Prototypes
*********************************************************************************/
/* Function for DIO read pin API */
extern FUNC(Dio_LevelType) Dio_ReadPin(Dio_GroupType GroupId, Dio_PinType PinId);

/* Function for DIO write pin API */
extern FUNC(void) Dio_WritePin(Dio_GroupType GroupId, Dio_PinType PinId, Dio_LevelType Level);

/* Function for DIO read group API */
extern FUNC(Dio_GroupLevelType) Dio_ReadGroup(Dio_GroupType GroupId);

/* Function for DIO write group API */
extern FUNC(void) Dio_WriteGroup(Dio_GroupType GroupId, Dio_GroupLevelType Level);

/* Function for DIO flip pin API */
extern FUNC(Dio_LevelType) Dio_FlipPin(Dio_GroupType GroupId, Dio_PinType PinId);

#endif /* DIO_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/