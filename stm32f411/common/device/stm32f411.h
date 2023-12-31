/*******************************************************************************
 * Project: Driver Development
 * Module: stm32f411.h
 * SW-Version: 1.0.0
 * Purpose: This file to define data type, register structure, base address for peripherals
 * Environment:
 *              Device: stm32f411xce
 * Author: Thien Tran
********************************************************************************/

#ifndef STM32F411_H
#define STM32F411_H

/********************************************************************************
 *                                  Include Section
********************************************************************************/

/********************************************************************************
 *                                  Global Data Type
********************************************************************************/
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef signed long long    sint64;
typedef unsigned long long  uint64;
typedef unsigned char       boolean;
typedef float               float32;
typedef double              float64;

/* Define a registers structure for RCC module */
typedef struct St_RCC_RegType
{
    uint32   CR;                      /* Address offset 0x00 -> CR */
    uint32   PLLCFGR;                 /* Address offset 0x04 -> PLLCFGR */
    uint32   CFGR;                    /* Address offset 0x08 -> CFGR */
    uint32   CIR;                     /* Address offset 0x0C -> CIR */
    uint32   AHB1RSTR;                /* Address offset 0x10 -> AHB1RSTR */
    uint32   AHB2RSTR;                /* Address offset 0x14 -> AHB2RSTR */
    uint32   reserved1[2];            /* Address offset 0x18, 0x1C -> Reserved */
    uint32   APB1RSTR;                /* Address offset 0x20 -> APB1RSTR */
    uint32   APB2RSTR;                /* Address offset 0x24 -> APB2RSTR */
    uint32   reserved2[2];            /* Address offset 0x28, 0x2C -> Reserved */
    uint32   AHB1ENR;                 /* Address offset 0x30 -> AHB1ENR */
    uint32   AHB2ENR;                 /* Address offset 0x34 -> AHB2ENR */
    uint32   reserved3[2];            /* Address offset 0x38, 0x3C -> Reserved */
    uint32   APB1ENR;                 /* Address offset 0x40 -> APB1ENR */
    uint32   APB2ENR;                 /* Address offset 0x44 -> APB2ENR */
    uint32   reserved4[2];            /* Address offset 0x48, 0x4C -> Reserved */
    uint32   AHB1LPENR;               /* Address offset 0x50 -> AHB1LPENR */
    uint32   AHB2LPENR;               /* Address offset 0x54 -> AHB2LPENR */
    uint32   reserved5[2];            /* Address offset 0x58, 0x5C -> Reserved */
    uint32   APB1LPENR;               /* Address offset 0x60 -> APB1LPENR */
    uint32   APB2LPENR;               /* Address offset 0x64 -> APB2LPENR */
    uint32   reserved6[2];            /* Address offset 0x68, 0x6C -> Reserved */
    uint32   BDCR;                    /* Address offset 0x70 -> BDCR */
    uint32   CSR;                     /* Address offset 0x74 -> CSR */
    uint32   reserved7[2];            /* Address offset 0x78, 0x7C -> Reserved */
    uint32   SSCGR;                   /* Address offset 0x80 -> SSCGR */
    uint32   PLLI2SCFGR;              /* Address offset 0x84 -> PLLI2SCFGR */
} RCC_RegType;

/* Define a registers structure for GPIO module */
typedef struct St_GPIO_RegType {
    uint32   MODER;                   /* Address offset 0x00 -> MODER */
    uint32   OTYPER;                  /* Address offset 0x04 -> OTYPER */
    uint32   OSPEEDR;                 /* Address offset 0x08 -> OSPEEDR */
    uint32   PUPDR;                   /* Address offset 0x0C -> PUPDR */
    uint32   IDR;                     /* Address offset 0x10 -> IDR */
    uint32   ODR;                     /* Address offset 0x14 -> ODR */
    uint32   BSRR;                    /* Address offset 0x18 -> BSRR */
    uint32   LCKR;                    /* Address offset 0x1C -> LCKR */
    uint32   AFRL;                    /* Address offset 0x20 -> AFRL */
    uint32   AFRH;                    /* Address offset 0x24 -> AFRH */
} GPIO_RegType;

/* Define a registers structure for SYSCFG module */
typedef struct  St_SYSCFG_RegType {
    uint32   MEMRMP;                  /* Address offset 0x00 -> MEMRMP */
    uint32   PMC;                     /* Address offset 0x04 -> PMC */
    uint32   EXTICR[4];               /* Address offset 0x08, 0x0C, 0x10, 0x14 -> EXTICR[4] */
    uint32   reserved[2];             /* Address offset 0x18, 0x1C -> reserved[2] */
    uint32   CMPCR;                   /* Address offset 0x20 -> CMPCR */
} SYSCFG_RegType;

/* Define a registers structure for EXTI module */
typedef struct  St_EXTI_RegType {
    uint32   IMR;                     /* Address offset 0x00 -> IMR */
    uint32   EMR;                     /* Address offset 0x04 -> EMR */
    uint32   RTSR;                    /* Address offset 0x08 -> RTSR */
    uint32   FTSR;                    /* Address offset 0x0C -> FTSR */
    uint32   SWIER;                   /* Address offset 0x10 -> SWIER */
    uint32   PR;                      /* Address offset 0x14 -> PR */
} EXTI_RegType;

/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/
#define SRAM1_BASEADDR                  (0x20000000UL)
#define FLASH_BASEADDR                  (0x08000000UL)
#define SRAM                            SRAM1_BASEADDR

#define FUNC(rettype)                   rettype
#define NULL                            (void *)0x00000000UL

/* Define base address for GPIO */
#define GPIOA_BASE_ADDR                 (0x40020000UL)
#define GPIOB_BASE_ADDR                 (0x40020400UL)
#define GPIOC_BASE_ADDR                 (0x40020800UL)
#define GPIOD_BASE_ADDR                 (0x40020C00UL)
#define GPIOE_BASE_ADDR                 (0x40021000UL)
#define GPIOH_BASE_ADDR                 (0x40021C00UL)

/* Define base address for RCC */
#define RCC_BASE_ADDR                   (0x40023800UL)

/* Define base address for SYSCFG */
#define SYSCFG_BASE_ADDR                (0x40013800UL)

/* Define base address for EXTI */
#define EXTI_BASE_ADDR                  (0x40013C00UL)

/* Define base address for NVIC */
#define NVIC_BASE_ADDR                  (0xE000E000UL)

/**
 * @brief: This parameter is used for Dio_GroupType
 * @param: PORTx_Group 
 */
#define PORTA_Group         0
#define PORTB_Group         1
#define PORTC_Group         2
#define PORTD_Group         3
#define PORTE_Group         4
#define PORTH_Group         5

/**s
 * @brief: This parameter is used for Dio_PinType
 * @param: PORTx_Pin
 */
#define PORTx_Pin0          0
#define PORTx_Pin1          1
#define PORTx_Pin2          2
#define PORTx_Pin3          3
#define PORTx_Pin4          4
#define PORTx_Pin5          5
#define PORTx_Pin6          6
#define PORTx_Pin7          7
#define PORTx_Pin8          8
#define PORTx_Pin9          9
#define PORTx_Pin10         10
#define PORTx_Pin11         11
#define PORTx_Pin12         12
#define PORTx_Pin13         13
#define PORTx_Pin14         14
#define PORTx_Pin15         15

/* Define TRUE/FALSE for boolean value */
#define TRUE                            1
#define FALSE                           0

/* RCC register structure handler */
/**
 * @brief: This parameter is used for RCC_RegType *
 * @param: RCC
 */
#define RCC                             ((RCC_RegType *)RCC_BASE_ADDR)

/* GPIOx register structure handler */
/**
 * @brief: This parameter is used for GPIO_RegType *
 * @param: GPIOx
 */
#define GPIOA                           ((GPIO_RegType *)GPIOA_BASE_ADDR)
#define GPIOB                           ((GPIO_RegType *)GPIOB_BASE_ADDR)
#define GPIOC                           ((GPIO_RegType *)GPIOC_BASE_ADDR)
#define GPIOD                           ((GPIO_RegType *)GPIOD_BASE_ADDR)
#define GPIOE                           ((GPIO_RegType *)GPIOE_BASE_ADDR)
#define GPIOH                           ((GPIO_RegType *)GPIOH_BASE_ADDR)

/* SYSCFG register structure handler */
/**
 * @brief: This parameter is used for SYSCFG_RegType *
 * @param: SYSCFG
 */
#define SYSCFG                          ((SYSCFG_RegType *)SYSCFG_BASE_ADDR)

/* EXTI register structure handler */
/**
 * @brief: This parameter is used for EXTI_RegType *
 * @param: EXTI
 */
#define EXTI                            ((EXTI_RegType *)EXTI_BASE_ADDR)

/* Define NVIC_ISERx register */
#define NVIC_ISER(x)                    ((uint32 *)(0xE000E100UL + x * 0x04))

/* Define NVIC_IPRx register */
#define NVIC_IPR(x)                    ((uint32 *)(0xE000E400UL + x * 0x04))

/* Define the macro to convert port group ID to GPIOx */
#define PORT_GROUP_TO_GPIO(x)           (x == 0 ? GPIOA : \
                                        (x == 1 ? GPIOB : \
                                        (x == 2 ? GPIOC : \
                                        (x == 3 ? GPIOD : \
                                        (x == 4 ? GPIOE : \
                                        (x == 5 ? GPIOH : GPIOA))))))

/* Define the macro to convert GPIOx to port group ID */
#define GPIO_TO_PORT_GROUP(x)           (x == GPIOA ? 0 : \
                                        (x == GPIOB ? 1 : \
                                        (x == GPIOC ? 2 : \
                                        (x == GPIOD ? 3 : \
                                        (x == GPIOE ? 4 : \
                                        (x == GPIOH ? 7 : 0))))))

#endif /* STM32F411_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/