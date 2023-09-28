/***********************************************/
/************* Author: Moaz Ragab **************/
/************* date:  28 Aug 2023 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_RCC_config.h ***********/
/***********************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK RCC_HSE

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS RCC_CRYSTAL_CLK_

#endif /**< RCC_SYSCLK */

/**
 * @brief Configure the clock type for RCC_SYSCLK when using PLL.
 * @note Choose one of the available options:
 *      RCC_HSI       - HSI oscillator clock / 2 selected as PLL input clock .
 *      RCC_HSE  - HSE selected as PLL input clock.
 */
#if RCC_SYSCLK == RCC_PLL

#define RCC_CLK_PLL_INPUT RCC_HSI

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE As input for PLL.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_CLK_PLL_INPUT == RCC_HSE

#define RCC_CLK_BYPASS RCC_CRYSTAL_CLK_

#endif /**< Source of PLL when its HSE*/

#endif /**<RCC_SYSCLK_PLL_SOURCE*/

/** @} */ // end of RCC_System_Clock_Config

/**
 * @defgroup RCC_System_Clock_Config_PLL (RCC CFGR) System Clock Configuration Macros
 * @brief Macros for configuring the RCC system  when using PLL as clock System by setting RCC_CFGR register.
 * @{
 */
/**
 * @brief Choose the macro that you want to multply the system  clock by
 *   @note Choose one of the next to set the value of  CLK_SYS_MULTP_FACTOR Macro
 *   RCC_CFGR_MULT_CLR             // make sure bits are zeros (if you dont want to multply by any factor)
 *    RCC_CFGR_SYS_CLK_MULTP_4        // multply clock system by 4
 *    RCC_CFGR_SYS_CLK_MULTP_5        // multply clock system by 5
 *    RCC_CFGR_SYS_CLK_MULTP_6        // multply clock system by 6
 *    RCC_CFGR_SYS_CLK_MULTP_7        // multply clock system by 7
 *    RCC_CFGR_SYS_CLK_MULTP_8         // multply clock system by 8
 *   RCC_CFGR_SYS_CLK_MULTP_9         // multply clock system by 9
 *    RCC_CFGR_SYS_CLK_MULTP_6_N_HALF  // multply clock system by 6.5
 */
#define CLK_SYS_MULTP_FACTOR RCC_CFGR_MULT_CLR
/**
 * @brief choose the macro you want to divide the system clock by
 * @note choose one of the next for  the CLK_SYS_DIVIDE_FACTOR Macro
 *    RCC_CFGR_SYSCLK_NOT_DV         // no Divide for the main clk system
 *   RCC_CFGR_SYSCLK_DV_BY_2        // Divide for the main clk system by 2
 *   RCC_CFGR_SYSCLK_DV_BY_4       // Divide for the main clk system by 4
 *   RCC_CFGR_SYSCLK_DV_BY_8      // Divide for the main clk system by 8
 *  RCC_CFGR_SYSCLK_DV_BY_16     // Divide for the main clk system by 16
 *  RCC_CFGR_SYSCLK_DV_BY_64    // Divide for the main clk system by 64
 *  RCC_CFGR_SYSCLK_DV_BY_128  // Divide for the main clk system by 128
 *   RCC_CFGR_SYSCLK_DV_BY_256 // Divide for the main clk system by 256
 *   RCC_CFGR_SYSCLK_DV_BY_512 // Divide for the main clk system by 512
 */
#define CLK_SYS_DIVIDE_FACTOR RCC_CFGR_SYSCLK_NOT_DV

/**
 * @brief choose the macro you want to divide the PCLK1 clock by
 * @note choose one of the next for the RCC_CFGR_PPRE1_DIVIDE_FACTOR  Macro
 *RCC_CFGR_PPRE1_CLR       // used in clearing PPRE1 bits
 * RCC_CFGR_PPRE1_DV_BY_2   // APB Low speed clock (PCLK1) frequency divided by 2
 * RCC_CFGR_PPRE1_DV_BY_4   // APB Low speed clock (PCLK1) frequency divided by 4
 * RCC_CFGR_PPRE1_DV_BY_8   // APB Low speed clock (PCLK1) frequency divided by 8
 * RCC_CFGR_PPRE1_DV_BY_16  // APB Low speed clock (PCLK1) frequency divided by 16
 *
 */
#define RCC_CFGR_PPRE1_DIVIDE_FACTOR RCC_CFGR_PPRE1_CLR

/**
 * @brief choose the macro you want to divide the PCLK2 clock by
 * @note choose one of the next for the RCC_CFGR_PPRE2_DIVIDE_FACTOR  Macro
 *RCC_CFGR_PPRE2_CLR       // used in clearing PPRE2 bits
 * RCC_CFGR_PPRE2_DV_BY_2   // APB High speed clock (PCLK2) frequency divided by 2
 * RCC_CFGR_PPRE2_DV_BY_4   // APB High speed clock (PCLK2) frequency divided by 4
 * RCC_CFGR_PPRE2_DV_BY_8   // APB High speed clock (PCLK2) frequency divided by 8
 * RCC_CFGR_PPRE2_DV_BY_16  // APB High speed clock (PCLK2) frequency divided by 16
 *
 */
#define RCC_CFGR_PPRE2_DIVIDE_FACTOR RCC_CFGR_PPRE2_CLR

/**
 * @brief choose the macro you want to divide the ADC clock by
 * @note choose one of the next for the RCC_CFGR_ADC_DIVIDE_FACTOR  Macro
 * RCC_CFGR_ADC_PRESCALER_CLR      // Make sure that the 2 bits value were 00 and there were no ones(clearing)
 * RCC_CFGR_ADC_PRESCALER_DV_BY_2  // divide ADC prepherial frequency by2
 * RCC_CFGR_ADC_PRESCALER_DV_BY_4 // divide ADC prepherial frequency by4
 * RCC_CFGR_ADC_PRESCALER_DV_BY_6  // divide ADC prepherial frequency by6
 * RCC_CFGR_ADC_PRESCALER_DV_BY_8  // divide ADC prepherial frequency by8
 *
 */
#define RCC_CFGR_ADC_DIVIDE_FACTOR RCC_CFGR_ADC_PRESCALER_CLR
/** @} */ // end of RCC_CFGR_CONFIG

#endif /**< RCC_CONFIG_H_ */