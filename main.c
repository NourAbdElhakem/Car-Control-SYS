#define F_CPU 8000000
#include "util/delay.h"
#include "STDTYPS.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC.h"
#include "timer.h"
#include "UART.h"
#include "Sensors.h"
#include "Ultrasonic.h"
#include "Car_control_sys.h"


int main(void)
{
    sei();
	DIO_INITPIN();
	LCD_INIT();
	LCD_Clear();
	ADC_Init(VREF_VCC,ADC_SCALER_64);
Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
UART_init();
ULTRASONIC_INIT();

Car_Control_init();

LCD_writeString("Car Control System");

	while(1)
	{
		
		_delay_ms(100);
		Car_Control_Runnable();
		
		
		
	}
	
	
}


