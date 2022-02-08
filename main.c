/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mariam
 */
#include"std_types.h"
#include"Bit_calc.h"
#include"DIO_interface.h"
#include"DIO_regs.h"
#include"avr/io.h"
#include"avr/delay.h"
#include<avr/interrupt.h>
#include"Timer_regs.h"
#include"Timer_interface.h"
#include "ADC_interface.h"

u8 result;


ISR(TIMER0_COMP_vect)
{
		TogBit(PORTA,PIN1);
		_delay_ms(ADC_GetAdcBlocking(0,&result));

}
void main (void)
{DIO_vidSetPinDirection(PORTA,PIN0,INPUT);
DIO_vidSetPinDirection(PORTA,PIN1,OUTPUT);

	/*disable force output bit*/
	ClrBit(Timer_TCCR0,7);
	/*choosing waveform -> CTC*/
	ClrBit(Timer_TCCR0,6);
	SetBit(Timer_TCCR0,3);
	/*disable OC pins*/
	ClrBit(Timer_TCCR0,5);
	ClrBit(Timer_TCCR0,4);
	/*prescaler (/8)*/

	ClrBit(Timer_TCCR0,2);
	SetBit(Timer_TCCR0,1);
	ClrBit(Timer_TCCR0,0);
	/***********************************/
	/*Enabling the timer interrupt*/
	SetBit(Timer_TIMSK,1);
	/*******************************/
	ADC_vidIntitalization();
	/*write 200 in the OCR0 reg*/
	Timer_OCR0=ADC_GetAdcBlocking(0,&result);
/*global interrupt enabled*/
	SetBit(SREG_Register,7);

	while(1)
	{



	}
}

