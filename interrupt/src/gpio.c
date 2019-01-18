#include "gpio.h"

/* setting mode for pin */
extern void Set_Mode_pin(uint8_t port, uint8_t pin, uint32_t mode_option)
{
	uint8_t temp = 0;
	uint32_t temp_reg = 0;
	
	/* mode_option[2:0] = MUX field int PORTx_PCR register */
	temp = (uint8_t)(mode_option & (0x07u << 0));
	temp_reg = read_reg(PORT_PCR(port,pin),~(0x07u << 8));
	temp_reg |= (temp << 8);
	write_reg(PORT_PCR(port,pin),temp_reg);
	
	if(temp == gpio_mode)
	{
		/* mode_option[3] = GPIOx_PDDR[pin] */
		temp = (uint8_t) ((mode_option & (0x01u << 3)) >> 3);
		temp_reg = read_reg(GPIO_PDDR(port),~(0x01u << pin));
		temp_reg |= (temp << pin);
		write_reg(GPIO_PDDR(port),temp_reg);
		/* Setting input mode */
		if((temp<<3) == gpio_input)
		{
			/* mode_option[5:4] =  Pull_up / Pull_down */
			temp = ((mode_option & (0x03u << 4)) >> 4);
			temp_reg = read_reg(PORT_PCR(port,pin),~(0x03 << 0));
			temp_reg |= (temp << 0);
			write_reg(PORT_PCR(port,pin),temp_reg);
			
			/* mode_option[9:6] = PORTx_PCR[IRQC] : whether interrupt mode with this input pin or DMA mode */
			temp = ((mode_option & (0x0Fu << 6)) >> 6);
			temp_reg = read_reg(PORT_PCR(port,pin),~(0x0F << 16));
			temp_reg |= (temp << 16);
			write_reg(PORT_PCR(port,pin),temp_reg);
			/* init GPIO interrupt if desired */
			if( (temp<<6) == Int_logic_0 		|| 	\
				(temp<<6) == Int_logic_1 		|| 	\
				(temp<<6) == Int_rising_edge 	|| 	\
				(temp<<6) == Int_falling_edge 	|| 	\
				(temp<<6) == Int_either_edge 	)
			{
				
				/* Clear flag bit */
				temp_reg = read_reg(PORT_PCR(port,pin), ~(0x01u << 24));
				temp_reg |= (0x01u << 24);
				write_reg(PORT_PCR(port,pin),temp_reg);
				
				if(port == PORTC || port == PORTD)
				{
					/* enable interrupt in NVIC */
					temp_reg = read_reg(NVIC_ISER,~(0x01 << 31));
					temp_reg |= 0x01u << 31;
					write_reg(NVIC_ISER,temp_reg);
					
				}
				else if (port == PORTA)
				{
					/* enable interrupt in NVIC */
					temp_reg = read_reg(NVIC_ISER,~(0x01 << 30));
					temp_reg |= 0x01u << 30;
					write_reg(NVIC_ISER,temp_reg);
					
				}else  /* else port not equal PORTA | PORTC | PORTD */
				{
					/* setting gpio interrupt correspond */
				}
				/* Enable global interrupt */
				asm("cpsie i");
			}
			else /* If not desired interrupt */
			{
				/* Do something */
				/* if DMA or others mode */
			}
			
		}
		else
		{
			
		}
	}
	else  /* If mode isn't selected gpio mode - If Alternate mode is selected */
	{
		
	}
	
}
/* initialize pins */
extern void Init_pin(pin_t *list_pin, uint64_t number_pins)
{
	uint64_t i = 0;
	for(i=0; i<number_pins; i++)
	{
		if(list_pin[i].mode & (0x07u <<0) != 0)
		{
			Set_Mode_pin(list_pin[i].port, list_pin[i].pin, list_pin[i].mode);		
		}else{
			break;
		}
	}
}
/* set value for pin */
extern void Write_pin(pin_t pin, uint8_t value)
{
	uint32_t temp_reg = read_reg(GPIO_PDOR(pin.port),~(0x01 << pin.pin));
	temp_reg |= (value << pin.pin);
	write_reg(GPIO_PDOR(pin.port),temp_reg);
	
}
/* read value of pin */
extern uint8_t Read_pin(pin_t pin)
{
	uint32_t temp_reg = read_reg(GPIO_PDIR(pin.port),(0x01 << pin.pin));
	temp_reg >>= pin.pin;
	return (uint8_t)temp_reg;
}

/* toggle value of pin */
extern void toggle_pin(pin_t pin)
{
	uint32_t temp_reg = read_reg(GPIO_PTOR(pin.port),~(0x01 << pin.pin));
	temp_reg |= (0x01u << pin.pin);
	write_reg(GPIO_PTOR(pin.port),temp_reg);
}