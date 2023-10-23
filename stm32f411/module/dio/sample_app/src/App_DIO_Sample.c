/*******************************************************************************
 * Project: Driver Development
 * Module: App_DIO_Sample.c
 * SW-Version: 1.0.0
 * Purpose: This file implement source application for DIO module
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "App_DIO_Sample.h"
// #include "stm32f411.h"
#include "Dio.h"
// #include "DioLLDriver.h"

boolean GHighLevelCheck = 0;
boolean GHLowLevelCheck = 0;

Dio_LevelType GTest[3];

void Mcu_Init();
void Clock_Init();
void Port_Init();

/********************************************************************************
 *                                  Main Function
********************************************************************************/
int main() {
    /* Enable clock for GPIO */
    Mcu_Init();
    /* Configure type for pin of GPIO */
    Port_Init();

    /* Create a variable to check pin */
    Dio_LevelType LPinCheckLevel = 0;

    /* Checkpoint 1: Check for Dio_ReadPin and Dio_WritePin */
    Dio_WritePin(PORTD_Group, PORTx_Pin0, SET_PIN);
    LPinCheckLevel = Dio_ReadPin(PORTD_Group, PORTx_Pin0);

    if (LPinCheckLevel == SET_PIN) {
        GHighLevelCheck = TRUE;
    } else {
        GHighLevelCheck = FALSE;
    }

    Dio_WritePin(PORTD_Group, PORTx_Pin0, RESET_PIN);
    LPinCheckLevel = Dio_ReadPin(PORTD_Group, PORTx_Pin0);

    if (LPinCheckLevel == RESET_PIN) {
        GHLowLevelCheck = TRUE;
    } else {
        GHLowLevelCheck = FALSE;
    }

    GTest[0] = GHighLevelCheck & GHLowLevelCheck;

    /* End Checkpoint 1 */

    /* Create a variable to check group */
    Dio_GroupLevelType LGroupCheckLevel = 0;

    /* Checkpoint 2: Check for Dio_ReadGroup and Dio_WriteGroup */
    LGroupCheckLevel = 0;
    Dio_WriteGroup(PORTD_Group, SET_GROUP);
    LGroupCheckLevel = Dio_ReadGroup(PORTD_Group);

    if (LGroupCheckLevel == SET_GROUP) {
        GHighLevelCheck = TRUE;
    } else {
        GHighLevelCheck = FALSE;
    }

    Dio_WriteGroup(PORTD_Group, RESET_GROUP);
    LGroupCheckLevel = Dio_ReadGroup(PORTD_Group);

    if (LGroupCheckLevel == RESET_GROUP) {
        GHLowLevelCheck = TRUE;
    } else {
        GHLowLevelCheck = FALSE;
    }

    GTest[1] = GHighLevelCheck & GHLowLevelCheck;

    /* End Checkpoint 2 */

    /* Checkpoint 3: Check for Dio_FlipPin */
    LPinCheckLevel = Dio_ReadPin(PORTD_Group, PORTx_Pin0);

    Dio_LevelType LPinCheckFlip = 0;
    LPinCheckFlip = Dio_FlipPin(PORTD_Group, PORTx_Pin0);
    
    if (LPinCheckLevel != LPinCheckFlip) {
        GHighLevelCheck = TRUE;
    } else {
        GHighLevelCheck = FALSE;
    }

    LPinCheckLevel = Dio_ReadPin(PORTD_Group, PORTx_Pin0);
    LPinCheckFlip = Dio_FlipPin(PORTD_Group, PORTx_Pin0);
    
    if (LPinCheckLevel != LPinCheckFlip) {
        GHLowLevelCheck = TRUE;
    } else {
        GHLowLevelCheck = FALSE;
    }

    GTest[2] = GHighLevelCheck & GHLowLevelCheck;

    /* End checkpoint 3 */
}

void Mcu_Init() {
    Clock_Init();
}

void Clock_Init() {
    /* Enable clock for all GPIOx Groups */
    RCC->AHB1ENR = 0x0000009F;
}

void Port_Init() {
    /* Set all pins of all group is ouput type */
    GPIOD->MODER = 0x55555555;
}

/********************************************************************************
 *                                  End of file
*********************************************************************************/
