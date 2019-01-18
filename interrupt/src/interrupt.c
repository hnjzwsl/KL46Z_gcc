#include "interrupt.h"
#include "gpio.h"


/******************************************* IRQ Handler ****************************************/
void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}



void PORTC_PORTD_IRQHandler()
{
    uint32_t temp_reg;
	temp_reg = read_reg(PORT_PCR(SW1_port,SW1_pin), (0x01u << 24));
	
	if( temp_reg != 0)
	{		
		/* Red_led off */
		temp_reg = read_reg(GPIO_PDOR(Red_led_port),~(0x01 << Red_led_pin));
		temp_reg |= (0x00u << Red_led_pin);
		write_reg(GPIO_PDOR(Red_led_port),temp_reg);
		
		/* clear interrupt flag of pin */
		temp_reg = read_reg(PORT_PCR(SW1_port,SW1_pin), ~(0x01u << 24));
		temp_reg |= (0x01u << 24);
		write_reg(PORT_PCR(SW1_port,SW1_pin),temp_reg);
	}
	else if(0 != (temp_reg = read_reg(PORT_PCR(SW2_port,SW2_pin), (0x01u << 24))))
	{
		/* Red_led on */
		temp_reg = read_reg(GPIO_PDOR(Red_led_port),~(0x01 << Red_led_pin));
		temp_reg |= (0x01u << Red_led_pin);
		write_reg(GPIO_PDOR(Red_led_port),temp_reg);
		
		/* clear interrupt flag of pin */
		temp_reg = read_reg(PORT_PCR(SW2_port,SW2_pin), ~(0x01u << 24));
		temp_reg |= (0x01u << 24);
		write_reg(PORT_PCR(SW2_port,SW2_pin),temp_reg);
	
	}
}

/**************************** Init ******************************/

