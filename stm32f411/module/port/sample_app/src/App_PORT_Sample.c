/*******************************************************************************
 * Project: Driver Development
 * Module: App_PORT_Sample.c
 * SW-Version: 1.0.0
 * Purpose: This file implement source application for PORT module
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

/********************************************************************************
 *                                  Include Section
********************************************************************************/
#include "Dio.h"
#include "Port.h"
#include "stm32f411.h"
#include "PortLLDriver.h"

void Mcu_Init();
void Clock_Init();

/********************************************************************************
 *                                  Global Data
********************************************************************************/
Port_PinConfigType GPinConfigSet1[2] = {
    {
        PORTx_Pin0,
        PIN_IT_BOTH,
        PIN_PUSH_PULL,
        PIN_HIGH_SPEED,
        PIN_PD,
        PIN_ALT0,
    },
    {
        PORTx_Pin0,
        PIN_IN_MODE,
        PIN_PUSH_PULL,
        PIN_HIGH_SPEED,
        PIN_PD,
        0
    }
};

Port_PinConfigType GPinConfigSet2[] = {
    {
        PORTx_Pin0,
        PIN_IN_MODE,
        0,
        PIN_HIGH_SPEED,
        PIN_PD,
        0
    },
    {
        PORTx_Pin12,
        PIN_OUT_MODE,
        PIN_PUSH_PULL,
        PIN_HIGH_SPEED,
        PIN_PD,
        0
    }
};

Port_ConfigType GConfigSetPtr[] = {
    /* GPIOA Group */
    {
        PORTA_Group,
        2,
        &GPinConfigSet1[0]
    },
    /* GPIOB Group */
    {
        PORTD_Group,
        2,
        &GPinConfigSet2[0]
    }
};

/********************************************************************************
 *                                  Main Function
********************************************************************************/
int main() {
    /* Enable clock for GPIO */
    Mcu_Init();
    /* Configure type for pin of GPIO */
    Port_Init(GConfigSetPtr, sizeof(GConfigSetPtr)/sizeof(GConfigSetPtr[0]));

    /* Try to write pin after init */
    Dio_WritePin(PORTD_Group, PORTx_Pin12, SET_PIN);
    Dio_LevelType LddLevel = 0;
    LddLevel = Dio_ReadPin(PORTD_Group, PORTx_Pin12);

    /* Set mode for pin */
    Port_SetPinMode(PORTB_Group, PORTx_Pin0, PIN_ALT_MODE);
    Port_SetToAlternateMode(PORTB_Group, PORTx_Pin0, PIN_ALT1);

    /* Testing for external interrupt */
    Port_InterruptConfig(6, 5, ENABLE);
    (void)LddLevel;
    while(1);
}

/* Mcu init */
void Mcu_Init() {
    Clock_Init();
}

/* Clock init */
void Clock_Init() {
    /* Enable clock for all GPIOx Groups */
    RCC->AHB1ENR = 0x0000009F;
    /* Enable clock for all SYSCFG */
    RCC->APB2ENR = 0x00004000;
}

/* Interrupt handling */
void EXTI0_IRQHandler() {
    Port_InterruptHandling(0);
    int i = 0;
    i ++;
}