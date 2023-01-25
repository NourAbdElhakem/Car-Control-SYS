#include "STDTYPS.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC.h"
#include "UART.h"
#include "util\delay.h"
#include "Ultrasonic.h"
#include "Sensors.h"
#include "timer.h"
#include "Car_control_sys.h"
#include "Kernel.h"


 volatile u8 temp_flag=0;
 volatile u8 dist_flag=0;
 volatile u8 press_flag=0;

static u16 DIS=100;



u8 test=15;


Task_t arr_Tasks[Task_num];

void Car_Control_init()
{
	/********no thing ****/
	

}


void Car_Control_Runnable(void)
{
	static u16 pressure=0,temp=0;
	static u16  distance=100,x=0 ,flag=0;

	temp=TEMP_Read();
	pressure=MPX4115_GetPress();
	x=Ultrasonic_Gettable(&distance);
	
if(x==1)
{
	flag=1;
	
}else
{
flag=0;	
}
	if((distance<=10)&&(flag==1))
	{
		if(distance<5)
		{
			LCD_Clear();
			
			DIO_Write_PIN(PINC1,HIGH);
			LCD_writeString("System Stopped");
			LCD_GO_TO(2,0);
			LCD_writeString("SYS OUT SERVICE");
			DIO_Write_PIN(PINC2,LOW);
			_delay_ms(100);
			
			while(1)
			{
				DIO_Write_PIN(PINC3,HIGH);
				_delay_ms(600);
					DIO_Write_PIN(PINC3,LOW);
				_delay_ms(600);

			}
			
	  }
			
		
		if(dist_flag==0)
		{
		UART_Send_string("Warning you will make accident");
		UART_Send_string("     ");
	    DIO_Write_PIN(PINC2,HIGH);
		dist_flag=1;
		flag=0;
		x=0;
		}
	}
	else
	{
		dist_flag=0;
		DIO_Write_PIN(PINC2,LOW);
		
	}

	if(temp>50)
	{
		if(temp_flag==0)
		{
			
		UART_Send_string("Warning Your temprature is High");
			UART_Send_string("     ");
		temp_flag=1;
		}
	}
	else
	{
		temp_flag=0;
	}
	if(pressure>35)
	{
		if(press_flag==0)
		{
		UART_Send_string("Warning Your pressure of Car wheel is High");
			UART_Send_string("     ");
		press_flag=1;
		}
	}
	else
	{
		press_flag=0;
	}
		
	
}


