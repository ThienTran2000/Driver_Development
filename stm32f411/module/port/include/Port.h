/*******************************************************************************
 * Project: Driver Development
 * Module: Dio.h
 * SW-Version: 1.0.0
 * Purpose: This file contain macros, function prototype for source application for PORT module
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

#ifndef PORT_H
#define PORT_H

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "stm32f411.h"

/********************************************************************************
 *                                  Global Data Type
********************************************************************************/
typedef uint8       Port_PinType;
typedef uint8       Port_GroupType;

/* This is enum type for Pin output mode */
typedef enum E_Port_PinOutputType {
    PIN_PUSH_PULL,
    PIN_OPEN_DRAIN
} Port_PinOutputType;

/* This is eum type for Pin mode*/
typedef enum E_Port_PinModeType {
    PIN_IN_MODE,
    PIN_OUT_MODE,
    PIN_ALT_MODE,
    PIN_ANALOG_MODE,
    PIN_IT_FALLING,
    PIN_IT_RASING,
    PIN_IT_BOTH
} Port_PinModeType;

/* This is enum type for Pin speed*/
typedef enum E_Port_PinSpeedType {
    PIN_LOW_SPEED,
    PIN_MEDIUM_SPEED,
    PIN_FAST_SPEED,
    PIN_HIGH_SPEED
} Port_PinSpeedType;

/* This is enum type for Alternate mode */
typedef enum E_Port_PinAlternateType {
    PIN_ALT0,
    PIN_ALT1,
    PIN_ALT2,
    PIN_ALT3,
    PIN_ALT4,
    PIN_ALT5,
    PIN_ALT6,
    PIN_ALT7,
    PIN_ALT8,
    PIN_ALT9,
    PIN_ALT10,
    PIN_ALT11,
    PIN_ALT12,
    PIN_ALT13,
    PIN_ALT14,
    PIN_ALT15,
} Port_PinAlternateType;

/* This is enum type for Pin pull-up, pull-down */
typedef enum E_Port_PinPUPDType {
    PIN_NO_PUPD,
    PIN_PU,
    PIN_PD
} Port_PinPUPDType;

/* This is a config for PORT module to initialize a Pin*/
typedef struct St_PortPinConfigType {
    Port_PinType PinId;
    Port_PinModeType PinMode;
    Port_PinOutputType PinOutMode;
    Port_PinSpeedType PinSpeed;
    Port_PinPUPDType PinPUPD;
    Port_PinAlternateType AlternativeMode;
} Port_PinConfigType;

/* This is a config for PORT module to initialize */
typedef struct St_PortConfigType {
    Port_GroupType GroupId;
    Port_PinConfigType PinConfig[];
} Port_ConfigType;

/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/

/********************************************************************************
 *                                  Function Prototypes
*********************************************************************************/
/* Function for Port initialize API */
extern FUNC(void) Port_Init(Port_ConfigType *ConfigPtr);

/* Function for Port set pin mode API */
extern FUNC(void) Port_SetPinMode(Port_GroupType GroupId, Port_PinType PinId, Port_PinModeType PinMode);

/* Function for Port to set alternate function API */
extern FUNC(void) Port_SetToAlternateMode(Port_GroupType GroupId, Port_PinType PinId, Port_PinAlternateType AltMode);

#endif /* PORT_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/
