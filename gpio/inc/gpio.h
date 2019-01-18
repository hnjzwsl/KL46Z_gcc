#ifndef _GPIO_H_
#define _GPIO_H_

#include "hw_kl46z.h"


extern void init_GPIO_OUTPUT(unsigned char port, unsigned char pin);
extern void led_on(unsigned char port_led,unsigned char pin_led);
extern void led_off(unsigned char port_led,unsigned char pin_led);




#define Red_led_PORT	PORTE
#define Red_led			29

#define Green_led_PORT	PORTD
#define Green_led		5


#endif	//_GPIO_H_