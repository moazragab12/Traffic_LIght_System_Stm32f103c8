/***********************************************/
/************* Author: Moaz Ragab **************/
/************* date:  28 Aug 2023 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_RCC_Programme.c ***********/
/***********************************************/
// no header guards in .c files :D

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_RCC_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

#if RCC_SYSCLK == RCC_HSE

/**< Enable the external clock to be the source for the system clock. */
#if RCC_CLK_BYPASS == RCC_RC_CLK_
    SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
#elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
    CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
#else
#error "Wrong Choice !!"
#endif /**< RCC_CLK_BYPASS */

    /**< Enable the High-Speed External clock. */
    SET_BIT(RCC_CR, RCC_CR_HSEON);

    /**< Wait until the High-Speed External clock is stable. */
    while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
        ;

    /**< Select High-Speed External clock as the system clock source. */
    RCC_CFGR = 0x00000001;

    Local_FunctionStatus = E_OK;

#elif RCC_SYSCLK == RCC_HSI

    /**< Enable the High-Speed Internal clock. */
    SET_BIT(RCC_CR, RCC_CR_HSION);

    /**< Wait until the High-Speed Internal clock is stable. */
    while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
        ;

    /**< Select High-Speed Internal clock as the system clock source. */
    RCC_CFGR = 0x00000000;

    Local_FunctionStatus = E_OK;

#elif RCC_SYSCLK == RCC_PLL
#if RCC_CLK_PLL_INPUT == RCC_HSI
    /**< Enable the High-Speed Internal clock. */
    SET_BIT(RCC_CR, RCC_CR_HSION);
    /*<Making HSI/2 clk is the source of PLL*/
    CLR_BIT(RCC_CFGR, PLL_SRC);

#elif RCC_CLK_PLL_INPUT == RCC_HSE
/**< Enable the external clock to be the source for the system clock. */
#if RCC_CLK_BYPASS == RCC_RC_CLK_
    SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
#elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
    CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */

#else
#error "Wrong Choice !!"
#endif
    /**< Enable the High-Speed External clock. */
    SET_BIT(RCC_CR, RCC_CR_HSEON);
    /*<Making HSE clk is the source of PLL*/
    SET_BIT(RCC_CFGR, PLL_SRC);
#endif /*choosing source for PLL*/

    /* Choose the multply factor of clock system*/
    MCAL_RCC_PLL_CLK_SYS_MULTP_Factor(CLK_SYS_MULTP_FACTOR);
    /*choose the divide factor of Each prephiral*/

    // main clk Divide factor
    MCAL_RCC_PLL_Divide_Pheripheral_CLK(CLK_SYS_DIVIDE_FACTOR, RCC_CFGR_SYSCLK_NOT_DV, RCC_CFGR_AHB_PRESCALER_SHIFT);

    // PCLK1 Divide factor clock
    MCAL_RCC_PLL_Divide_Pheripheral_CLK(RCC_CFGR_PPRE1_DIVIDE_FACTOR, RCC_CFGR_PPRE1_CLR, RCC_CFGR_PPRE1_PRESCALER_SHIFT);

    // PCLK2 Divide factor clock

    MCAL_RCC_PLL_Divide_Pheripheral_CLK(RCC_CFGR_PPRE2_DIVIDE_FACTOR, RCC_CFGR_PPRE2_CLR, RCC_CFGR_PPRE2_PRESCALER_SHIFT);

    // ADC Clock Divide factor

    MCAL_RCC_PLL_Divide_Pheripheral_CLK(RCC_CFGR_ADC_DIVIDE_FACTOR, RCC_CFGR_ADC_PRESCALER_SHIFT, RCC_CFGR_ADC_PRESCALER_SHIFT);

    /**< Enable the PLL. */
    SET_BIT(RCC_CR, RCC_CR_PLLON);
    /**< Wait until the PLL clock is stable. */
    while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY))
        ;
    /**< Select PLL clock as the system clock source. */
    RCC_CFGR = 0x00000010;
    // Placeholder for PLL configuration
    Local_FunctionStatus = E_OK;

#else
#error "Wrong Choice !!"

#endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    /**< Enable the peripheral on the AHB bus. */
    case RCC_AHB:
        SET_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Enable the peripheral on the APB1 bus. */
    case RCC_APB1:
        SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Enable the peripheral on the APB2 bus. */
    case RCC_APB2:
        SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    /**< Disable the peripheral on the AHB bus. */
    case RCC_AHB:
        CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Disable the peripheral on the APB1 bus. */
    case RCC_APB1:
        CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Disable the peripheral on the APB2 bus. */
    case RCC_APB2:
        CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}
// edit the shift
Std_ReturnType MCAL_RCC_PLL_CLK_SYS_MULTP_Factor(u8 Copy_Multply_Factor, u8 Copy_Shift_Value)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    // make sure that bits of Multplying is cleared
    RCC_CFGR &= ~(RCC_CFGR_MULT_CLR << RCC_CFGR_MULT_FACTOR_SHIFT);
    // if he want  multply factor he will  go into this if
#if CLK_SYS_MULTP_FACTOR != RCC_CFGR_MULT_CLR
    // Set bits as the multply factor we need
    RCC_CFGR |= (Copy_Multply_Factor << RCC_CFGR_MULT_FACTOR_SHIFT);
#endif /*< multply factor setting*/
    return Local_FunctionStatus;
}
// edit the shift
Std_ReturnType MCAL_RCC_PLL_Divide_Pheripheral_CLK(u8 Copy_Peripheral_Divide_Factor, u8 Copy_Peripheral_Clr_Value, u8 Copy_Shift_Value)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    // clear the bits before setting any of frequencies
    RCC_CFGR &= ~(Copy_Peripheral_Clr_Value << Copy_Shift_Value);

// setting the divide value
#if Copy_Peripheral_Divide_Factor != Copy_Peripheral_Clr_Value
    // Set bits as the divide factor we need
    RCC_CFGR |= (Copy_Peripheral_Divide_Factor << Copy_Shift_Value);
#endif /*< multply factor setting*/

    return Local_FunctionStatus;
}

/*****************************< The End  *****************************/