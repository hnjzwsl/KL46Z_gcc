#include "gpio.h"

void led_on(unsigned char port_led, unsigned char pin_led)
{
	unsigned int temp_reg;
	temp_reg = read_reg(GPIO_PDOR(port_led),~(0x1u << pin_led));
	temp_reg |= (0x0u << pin_led);
	write_reg(GPIO_PDOR(port_led), temp_reg);
}

void led_off(unsigned char port_led, unsigned char pin_led)
{
	unsigned int temp_reg;
	temp_reg = read_reg(GPIO_PDOR(port_led),~(0x1u << pin_led));
	temp_reg |= (0x1u << pin_led);
	write_reg(GPIO_PDOR(port_led), temp_reg);
}

void init_GPIO_OUTPUT(unsigned char port, unsigned char pin)
{
	/* set mode gpio */
	unsigned int temp_reg;
	temp_reg = read_reg(PORT_PCR(port,pin),~(0x7u << 8));
	temp_reg |= (0x1u << 8 );
	write_reg(PORT_PCR(port,pin), temp_reg);
	
	/* set gpio output mode */
	temp_reg = read_reg(GPIO_PDDR(port),~(1u << pin));
	temp_reg |= (1u << pin);
	write_reg(GPIO_PDDR(port), temp_reg);
	
	/* Default Led off*/
	led_off(port,pin);
	
}