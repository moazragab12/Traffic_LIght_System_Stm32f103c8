/***********************************************/
/************* Author: Moaz Ragab **************/
/************* date:  28 Aug 2023 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_RCC_private.h ***********/
/***********************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR (*((volatile u32 *)0x40021000))

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR (*((volatile u32 *)0x40021004))

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR (*((volatile u32 *)0x40021008))

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR (*((volatile u32 *)0x4002100C))

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR (*((volatile u32 *)0x40021010))

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR (*((volatile u32 *)0x40021014))

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR (*((volatile u32 *)0x4002101C))

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR (*((volatile u32 *)0x40021018))

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR (*((volatile u32 *)0x40021020))

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR (*((volatile u32 *)0x40021024))

/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION 0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY 1  /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL 8  /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON 16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY 17 /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP 18 /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE 19 /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON 24  /**< Clock Security System Enable */
#define RCC_CR_PLLON 24  /**< PLL Enable */
#define RCC_CR_PLLRDY 25 /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_CFGR_Bit_Definitions Clock configuration register (RCC_CFGR) Bit Definitions
 * @{
 */
#define PLL_SRC 16 // choose the source of PLL HSI/2 or HSE and it should be choosen before enabling PLL
/** @} */          // end of RCC_CFGR_Bit_Definitions

/**
 * @defgroup PLL Frequences Mode  Macros
 * @{
 */
/*< bits 14,15 ADCPRE[1:0]: ADC prescaler*/
/*you have to sit or clr it manually by using mask not by SIT or CLR bits functions*/

#define RCC_CFGR_ADC_PRESCALER_SHIFT 14     // the shift value
#define RCC_CFGR_ADC_PRESCALER_CLR 0b11     // Make sure that the 2 bits value were 00 and there were no ones(clearing)
#define RCC_CFGR_ADC_PRESCALER_DV_BY_2 0b00 // divide ADC prepherial frequency by2
#define RCC_CFGR_ADC_PRESCALER_DV_BY_4 0b01 // divide ADC prepherial frequency by4
#define RCC_CFGR_ADC_PRESCALER_DV_BY_6 0b10 // divide ADC prepherial frequency by6
#define RCC_CFGR_ADC_PRESCALER_DV_BY_8 0b11 // divide ADC prepherial frequency by8

/***<Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)*/
/*you have to sit or clr it manually by using mask not by SIT or CLR bits functions*/
/**
 * @note its  frequency shouldnot exceed 72 MHZ
 * */

#define RCC_CFGR_PPRE2_PRESCALER_SHIFT 11 // the shift value
#define RCC_CFGR_PPRE2_CLR 0b111          //  used in clearing PPRE2 bits
#define RCC_CFGR_PPRE2_DV_BY_2 0b100      // APB High speed clock (PCLK2) frequency divided by 2
#define RCC_CFGR_PPRE2_DV_BY_4 0b101      // APB High speed clock (PCLK2) frequency divided by 4
#define RCC_CFGR_PPRE2_DV_BY_8 0b110      // APB High speed clock (PCLK2) frequency divided by 8
#define RCC_CFGR_PPRE2_DV_BY_16 0b111     // APB High speed clock (PCLK2)frequency divided by 16

/****<Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)*/
/*you have to sit or clr it manually by using mask not by SIT or CLR bits functions*/
/**
 * @note its  frequency shouldnot exceed 36 MHZ
 * */

#define RCC_CFGR_PPRE1_PRESCALER_SHIFT 8 // the shift value
#define RCC_CFGR_PPRE1_CLR 0b111         // used in clearing PPRE1 bits
#define RCC_CFGR_PPRE1_DV_BY_2 0b100     // APB Low speed clock (PCLK1) frequency divided by 2
#define RCC_CFGR_PPRE1_DV_BY_4 0b101     // APB Low speed clock (PCLK1) frequency divided by 4
#define RCC_CFGR_PPRE1_DV_BY_8 0b110     // APB Low speed clock (PCLK1) frequency divided by 8
#define RCC_CFGR_PPRE1_DV_BY_16 0b111    // APB Low speed clock (PCLK1) frequency divided by 16

/*******<Bits 7:4 HPRE[3:0]: AHB prescaler***/
/*you have to sit or clr it manually by using mask not by SIT or CLR bits functions*/
/**
 * @note  Caution: The PLL output frequency must not exceed 72 MHz
 */

#define RCC_CFGR_AHB_PRESCALER_SHIFT 4   // the shift value
#define RCC_CFGR_SYSCLK_NOT_DV 0b0111    // no Divide for the main clk system
#define RCC_CFGR_SYSCLK_DV_BY_2 0b1000   // Divide for the main clk system by 2
#define RCC_CFGR_SYSCLK_DV_BY_4 0b1001   // Divide for the main clk system by 4
#define RCC_CFGR_SYSCLK_DV_BY_8 0b1010   // Divide for the main clk system by 8
#define RCC_CFGR_SYSCLK_DV_BY_16 0b1011  // Divide for the main clk system by 16
#define RCC_CFGR_SYSCLK_DV_BY_64 0b1100  // Divide for the main clk system by 64
#define RCC_CFGR_SYSCLK_DV_BY_128 0b1101 // Divide for the main clk system by 128
#define RCC_CFGR_SYSCLK_DV_BY_256 0b1110 // Divide for the main clk system by 256
#define RCC_CFGR_SYSCLK_DV_BY_512 0b1111 // Divide for the main clk system by 512

/****<Bits 21:18 PLLMUL[3:0]: PLL multiplication factor*/
/**
 * @note  Caution: The PLL output frequency must not exceed 72 MHz
 */
#define RCC_CFGR_MULT_FACTOR_SHIFT 18          // the shift value
#define RCC_CFGR_MULT_CLR 0b1111               // make sure bits are zeros
#define RCC_CFGR_SYS_CLK_MULTP_4 0b0010        // multply clock system by 4
#define RCC_CFGR_SYS_CLK_MULTP_5 0b0011        // multply clock system by 5
#define RCC_CFGR_SYS_CLK_MULTP_6 0b0100        // multply clock system by 6
#define RCC_CFGR_SYS_CLK_MULTP_7 0b0101        // multply clock system by 7
#define RCC_CFGR_SYS_CLK_MULTP_8 0b0110        // multply clock system by 8
#define RCC_CFGR_SYS_CLK_MULTP_9 0b0111        // multply clock system by 9
#define RCC_CFGR_SYS_CLK_MULTP_6_N_HALF 0b1101 // multply clock system by 6.5

/** @} */ // end of PLL's Modes Macros

/**

 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI 0 /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE 1 /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL 2 /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_ 0 /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_ 1      /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type

#endif /* RCC_PRIVATE_H_ */
