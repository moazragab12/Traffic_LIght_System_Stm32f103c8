#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***********<Mcal********/
#include "RCC_interface.h"
#include "GPIO_Interface.h"
#include "STK_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_Interface.h"
#include "EXTI_private.h"
/***********<HAL*********/
#include "LED.h"

#define Button_Pin GPIO_PIN4

#define Red_Ped_Led GPIO_PIN1
#define Green_Cars_Led GPIO_PIN1
#define Yellow_Ped_Led GPIO_PIN2
#define Yellow_Cars_Led GPIO_PIN2
#define Green_Ped_Led GPIO_PIN3
#define Red_Cars_Led GPIO_PIN3
u8 x=0,flag=1,yellow=1;
void interrupt(void);
int main(void)
{MCAL_RCC_InitSysClock();
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_AFIOEN);
	/********<Set pin modes PORT A*******/
	MCAL_GPIO_SetPinMode(GPIO_PORTA,Red_Ped_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	MCAL_GPIO_SetPinMode(GPIO_PORTA,Yellow_Ped_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
		MCAL_GPIO_SetPinMode(GPIO_PORTA,Green_Ped_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		/********<Set pin modes PORT B*******/
	MCAL_GPIO_SetPinMode(GPIO_PORTB,Green_Cars_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,Yellow_Cars_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,Red_Cars_Led,GPIO_OUTPUT_PUSH_PULL_2MHZ);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,Button_Pin,GPIO_INPUT_PULL_DOWN_MOD);
	 void (*function_ptr)(void);
	function_ptr=interrupt;
	EXTI_Callback(function_ptr);
	MCAL_NVIC_EnableIRQ(NVIC_EXTI4_IRQn);
	EXTI_vInit();
	while(1)
	{ u8 i=5;
		
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,Red_Cars_Led,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Green_Ped_Led,GPIO_HIGH);
					MCAL_STK_SetDelay_ms(5000);
				 MCAL_GPIO_SetPinValue(GPIO_PORTA,Green_Ped_Led,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Red_Cars_Led,GPIO_LOW);
		yellow=1;
		  
		if(yellow){
			yellow=2;
			i=10;
while(i--)
{	
			MCAL_GPIO_SetPinValue(GPIO_PORTA,Yellow_Cars_Led,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Yellow_Ped_Led,GPIO_HIGH);
					MCAL_STK_SetDelay_ms(500);
				 MCAL_GPIO_SetPinValue(GPIO_PORTA,Yellow_Cars_Led,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Yellow_Ped_Led,GPIO_LOW);
	if(yellow==0)
	{flag=0;
	break;}
}		
		}

					x=1;
				u32 j=0;
				while( (x && j<20) && yellow)
				{ yellow=1;
					 MCAL_GPIO_SetPinValue(GPIO_PORTA,Red_Ped_Led,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Green_Cars_Led,GPIO_HIGH);
					MCAL_STK_SetDelay_ms(250);
				 MCAL_GPIO_SetPinValue(GPIO_PORTA,Red_Ped_Led,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Green_Cars_Led,GPIO_LOW);
					j=j+1;
				}
	x=0;
				yellow=1;
				if(flag==0 && yellow)
				{	i=50;
			
				while(i--)
				{ 
					HAL_LED_BlinkOnce(LED_PORTA,LED_PIN2,100);
					HAL_LED_BlinkOnce(LED_PORTB,LED_PIN2,100);
				
				}
				flag=1;
			}
				else if(flag==1 && yellow)
				{
						 MCAL_GPIO_SetPinValue(GPIO_PORTA,Yellow_Ped_Led,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Yellow_Cars_Led,GPIO_HIGH);
					MCAL_STK_SetDelay_ms(5000);
				 MCAL_GPIO_SetPinValue(GPIO_PORTA,Yellow_Ped_Led,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,Yellow_Cars_Led,GPIO_LOW);
				}
		
}
}



void interrupt(void)
 { if(yellow==2)
	 {yellow=0;
	 return;}
	 if(x==0)
	 return;
	 flag=0;
	 u8 z;
	 u8 *ptr=&z;
	 
	 for(u32 i=0;i<5000;i++)
	 {MCAL_GPIO_GetPinValue(GPIO_PORTB,Button_Pin,ptr);
	 if(*ptr==0)
		 break;
	 }
	 if(*ptr==1)	 
	 { flag=1;
		 x=1;	 return;
	 }
	 else 
		 {
	 x=0; return ;}

	 return;
 }
 
