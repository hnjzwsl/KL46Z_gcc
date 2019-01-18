#include "hw_kl46z.h"
#include "gpio.h"
#include "interrupt.h"
#include "type.h"

#define number_pins		4

pin_t list_pins[number_pins] = {
	
	/* button 1 on board */
	{
		SW1_port,
		SW1_pin,
		gpio_mode | gpio_input | pull_up | Int_logic_0,
	},
	/* button 2 on board */
	{
		SW2_port,
		SW2_pin,
		gpio_mode | gpio_input | pull_up | Int_logic_0,
	},
	/* red led on board */
	{
		Red_led_port,
		Red_led_pin,
		gpio_mode | gpio_output,
	},
	/* green led on board */
	{
		Green_led_port,
		Green_led_pin,
		gpio_mode | gpio_output,
	},
};

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}


void main()
{
	/* enable clock gate PORTE and PORTD */
	unsigned int temp_reg;
	temp_reg = read_reg(SIM_SCGC5,~(0x1Fu << 9));
	temp_reg |= (0x1Fu << 9 );
	write_reg(SIM_SCGC5, temp_reg);
	
	/* pin gpio */
	Init_pin(list_pins,number_pins);

	while(1)
	{	
		toggle_pin(list_pins[3]);
		delay(0xff);
	}
}