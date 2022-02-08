/*
 * Timer_interface.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Mariam
 */

#ifndef TIMER_REGS_H_
#define TIMER_REGS_H_

#define Timer_TCNT0  *((volatile u8*)(0x52))
#define Timer_TCCR0  *((volatile u8*)(0x53))
#define Timer_OCR0   *((volatile u8*)(0x5C))
#define Timer_TIMSK  *((volatile u8*)(0x59))
#define SREG_Register   *((volatile u8*)(0x5F))
#endif /* TIMER_REGS_H_ */
