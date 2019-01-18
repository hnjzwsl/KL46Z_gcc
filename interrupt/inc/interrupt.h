#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "hw_kl46z.h"

void Reserved_IRQHandler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

void PORTC_PORTD_IRQHandler();

void init_IT_SW1();
void init_IT_SW2();


#endif