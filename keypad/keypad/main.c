
#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
#include "utility.h"


int main(void)
{
	unsigned char butn;
	unsigned char malik[4][4] = 
	{
		{0x06, 0x5B, 0x4F, 0x77},
		{0x66, 0x6D, 0x7D, 0x7C},
		{0x07, 0x7F, 0x6F, 0x39},
		{0x1B, 0x3F, 0x76, 0x5E},
	};
	
	for (int i=4; i<8;i++) //output
	{
		DDRC |= (1 << i);
		PORTC &= ~(1 << i);
	}
	for (int j=0; j<4;j++) //input
	{
		DDRC &= ~(1 << j);
		PORTC |= (1 << j);
	}
    DDRA = 0xFF;
	
	 
	
    while (1) 
    {
		
		
	if(gpio_read_pin(PORTC_ID, 0) == 1 && gpio_read_pin(PORTC_ID, 1) ==1 && gpio_read_pin(PORTC_ID, 2) == 1 && gpio_read_pin(PORTC_ID, 3) == 1){
		PORTA = 0x00;
	}
	else 
	{
		for (int j=0; j<4;j++) // read status of colums pins
	{
		
	if ((PINC & (1 << j ))==0)
	           {
		butn = j;
	           }	
	}	 
	PORTC &= ~(1 << 4);
	PORTC |= (1 << 5);
	PORTC |= (1 << 6);
	PORTC |= (1 << 7);
	if ((gpio_read_pin(PORTC_ID,butn))==1)
	{
		PORTC |= (1 << 4);
		PORTC &= ~(1 << 5);
		PORTC |= (1 << 6);
		PORTC |= (1 << 7);
		if ((gpio_read_pin(PORTC_ID,butn))==1)
		{
			PORTC |= (1 << 4);
			PORTC |= (1 << 5);
			PORTC &= ~(1 << 6);
			PORTC |= (1 << 7);
			if ((gpio_read_pin(PORTC_ID,butn))==1)
			{
				PORTC |= (1 << 4);
				PORTC |= (1 << 5);
				PORTC |= (1 << 6);
				PORTC &= ~(1 << 7);
				if ((gpio_read_pin(PORTC_ID,butn))==1)
				{
					PORTA = 0x00;
				}
				else {
					PORTA = malik[0][butn];
					_delay_ms(10);
					for (int i =4; i<8;i++)
					{
						PORTC &= ~(1 << i);
					}
					
				}
				
			}
			else {
				PORTA = malik[1][butn];
				_delay_ms(10);
				for (int i =4; i<8;i++)
				{
					PORTC &= ~(1 << i);
				}
				
			}
		}
		else {
			PORTA = malik[2][butn];
			_delay_ms(10);
		for (int i =4; i<8;i++)
		{
			PORTC &= ~(1 << i);
		}
			
		}
	}
	else {
		PORTA = malik[3][butn];
		_delay_ms(10);
	for (int i =4; i<8;i++)
	{
		PORTC &= ~(1 << i);
	}
		
	}
			   }
		
    }
}

