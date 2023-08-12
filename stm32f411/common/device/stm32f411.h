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
    uint32   ulCR;                      /* Address offset 0x00 -> CR */
    uint32   ulPLLCFGR;                 /* Address offset 0x04 -> PLLCFGR */
    uint32   ulCFGR;                    /* Address offset 0x08 -> CFGR */
    uint32   ulCIR;                     /* Address offset 0x0C -> CIR */
    uint32   ulAHB1RSTR;                /* Address offset 0x10 -> AHB1RSTR */
    uint32   ulAHB2RSTR;                /* Address offset 0x14 -> AHB2RSTR */
    uint32   reserved1[2];              /* Address offset 0x18, 0x1C -> Reserved */
    uint32   ulAPB1RSTR;                /* Address offset 0x20 -> APB1RSTR */
    uint32   ulAPB2RSTR;                /* Address offset 0x24 -> APB2RSTR */
    uint32   reserved2[2];              /* Address offset 0x28, 0x2C -> Reserved */
    uint32   ulAHB1ENR;                 /* Address offset 0x30 -> AHB1ENR */
    uint32   ulAHB2ENR;                 /* Address offset 0x34 -> AHB2ENR */
    uint32   reserved3[2];              /* Address offset 0x38, 0x3C -> Reserved */
    uint32   ulAPB1ENR;                 /* Address offset 0x40 -> APB1ENR */
    uint32   ulAPB2ENR;                 /* Address offset 0x44 -> APB2ENR */
    uint32   reserved4[2];              /* Address offset 0x48, 0x4C -> Reserved */
    uint32   ulAHB1LPENR;               /* Address offset 0x50 -> AHB1LPENR */
    uint32   ulAHB2LPENR;               /* Address offset 0x54 -> AHB2LPENR */
    uint32   reserved5[2];              /* Address offset 0x58, 0x5C -> Reserved */
    uint32   ulAPB1LPENR;               /* Address offset 0x60 -> APB1LPENR */
    uint32   ulAPB2LPENR;               /* Address offset 0x64 -> APB2LPENR */
    uint32   reserved6[2];              /* Address offset 0x68, 0x6C -> Reserved */
    uint32   ulBDCR;                    /* Address offset 0x70 -> BDCR */
    uint32   ulCSR;                     /* Address offset 0x74 -> CSR */
    uint32   reserved7[2];              /* Address offset 0x78, 0x7C -> Reserved */
    uint32   ulSSCGR;                   /* Address offset 0x80 -> SSCGR */
    uint32   ulPLLI2SCFGR;              /* Address offset 0x84 -> PLLI2SCFGR */
} RCC_RegType;

/* Define a registers structure for GPIO module */
typedef struct St_GPIO_RegType {
    uint32   MODER;                     /* Address offset 0x00 -> MODER */
    uint32   OTYPER;                    /* Address offset 0x04 -> OTYPER */
    uint32   OSPEEDR;                   /* Address offset 0x08 -> OSPEEDR */
    uint32   PUPDR;                     /* Address offset 0x0C -> PUPDR */
    uint32   IDR;                       /* Address offset 0x10 -> IDR */
    uint32   ODR;                       /* Address offset 0x14 -> ODR */
    uint32   BSRR;                      /* Address offset 0x18 -> BSRR */
    uint32   LCKR;                      /* Address offset 0x1C -> LCKR */
    uint32   AFRL;                      /* Address offset 0x20 -> AFRL */
    uint32   AFRH;                      /* Address offset 0x24 -> AFRH */
} GPIO_RegType;

/********************************************************************************
 *                                  Macro Definition
*********************************************************************************/
#define SRAM1_BASEADDR                  (0x20000000UL)
#define FLASH_BASEADDR                  (0x08000000UL)
#define SRAM                            SRAM1_BASEADDR

#define FUNC(rettype)                   rettype

/* Define base address for GPIO */
#define GPIOA_BASE_ADDR                 (0x40020000UL)
#define GPIOB_BASE_ADDR                 (0x40020400UL)
#define GPIOC_BASE_ADDR                 (0x40020800UL)
#define GPIOD_BASE_ADDR                 (0x40020C00UL)
#define GPIOE_BASE_ADDR                 (0x40021000UL)
#define GPIOH_BASE_ADDR                 (0x40021C00UL)

/* Define base address for RCC */
#define RCC_BASE_ADDR                   (0x40023800UL)

/* RCC register structure handler */
#define RCC                             ((RCC_RegType *)RCC_BASE_ADDR)

/* GPIOx register structure handler */
#define GPIOA                           ((GPIO_RegType *)GPIOA_BASE_ADDR)
#define GPIOB                           ((GPIO_RegType *)GPIOB_BASE_ADDR)
#define GPIOC                           ((GPIO_RegType *)GPIOC_BASE_ADDR)
#define GPIOD                           ((GPIO_RegType *)GPIOD_BASE_ADDR)
#define GPIOE                           ((GPIO_RegType *)GPIOE_BASE_ADDR)
#define GPIOH                           ((GPIO_RegType *)GPIOH_BASE_ADDR)


#endif /* STM32F411_H */

/********************************************************************************
 *                                  End of file
*********************************************************************************/