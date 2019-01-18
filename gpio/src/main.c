#include "hw_kl46z.h"
#include "gpio.h"


void delay(unsigned int timeout)
{
    unsigned int t1;
    for (t1 = 0; t1 < timeout; t1++)
    {
          asm("nop");
    }
}
/********************************************************************************/
int main()
{
	/* enable clock gate PORTE and PORTD */
	unsigned int temp_reg;
	temp_reg = read_reg(SIM_SCGC5,~(0x3u << 12));
	temp_reg |= (0x3u <<12 );
	write_reg(SIM_SCGC5, temp_reg);
	
	/* set gpio output mode */
	init_GPIO_OUTPUT(Red_led_PORT,Red_led);
	init_GPIO_OUTPUT(Green_led_PORT,Green_led);
	
	while(1)
	{

	  led_on(Red_led_PORT,Red_led);	
	  delay(500);
	  led_off(Red_led_PORT,Red_led);	
	  delay(500);

  
	}
  
  
  return 0;
}
