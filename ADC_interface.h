/*
 * ADC_interface.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Mariam
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADMUX	(*((volatile u8*)(0x27)))
#define ADCSRA	(*((volatile u8*)(0x26)))
#define ADCH	(*((volatile u8*)(0x25)))
#define ADCL	(*((volatile u8*)(0x24)))

void ADC_vidIntitalization(void);
u8 ADC_GetAdcBlocking(u8 Copy_Channel_Num, u8* Copy_Data );

#define STD_u8_ERROR_OK (u8)1
#define STD_u8_ERROR_NOK (u8)0
#endif /* ADC_INTERFACE_H_ */
