#ifndef _GPIO_H_
#define _GPIO_H_

#include "hw_kl46z.h"
#include "type.h"

/*** mode_option[2:0]  ***/
#define gpio_mode				(0x01u << 0)			
#define alt2_mode				(0x02u << 0)			
#define alt3_mode				(0x03u << 0)			
#define alt4_mode				(0x04u << 0)			
#define alt5_mode				(0x05u << 0)			
#define alt6_mode				(0x06u << 0)			
#define alt7_mode				(0x07u << 0)		
/*** mode_option[3]  ***/
#define gpio_input				(0x00u << 3)	
#define gpio_output				(0x01u << 3)	
/*** mode_option[5:4]  ***/
#define pull_up					(0x03u << 4)
#define pull_down				(0x02u << 4)
/*** mode_option[9:6]  ***/
#define DMA_rising_req			(0x01u << 6)
#define DMA_falling_req			(0x02u << 6)
#define DMA_either_req			(0x03u << 6)
#define Int_logic_0				(0x08u << 6)
#define Int_rising_edge			(0x09u << 6)
#define Int_falling_edge		(0x0Au << 6)
#define Int_either_edge			(0x0Bu << 6)
#define Int_logic_1				(0x0Cu << 6)
/*** mode_option[10]  ***/
#define SRE_enable				(0x01u << 10)
/*** mode_option[11] ***/
#define PFE_enable				(0x01u << 11)
/* mode_option[12] */
#define DSE_enable				(0x01u << 12)


/*************** Define button and Led on board  *********************************************/

#define SW1_pin					3					/* SW1 Port C pin 3  */
#define SW1_port				PORTC				/* W1 Port C pin 3  */

#define SW2_pin					12					/* SW2 Port C pin 12 */
#define SW2_port				PORTC				/* SW2 Port C pin 12 */

#define Green_led_pin			5					/* Port D pin 5  */
#define Green_led_port			PORTD				/* Port D pin 5  */

#define Red_led_pin				29					/* Port E pin 29 */
#define Red_led_port			PORTE				/* Port E pin 29 */

#define uart2_Tx_port			PORTE				/* Port E pin 22 */
#define uart2_Tx_pin			22	

#define uart2_Rx_port			PORTE				/* Port E pin 23 */
#define uart2_Rx_pin			23	


/**************************** global function *************************************************/

/* setting mode for pin */
extern void Set_Mode_pin(uint8_t port, uint8_t pin, uint32_t mode_option);
/* initialize pins */
extern void Init_pin(pin_t *list_pin, uint64_t number_pins);
/* set value for pin */
extern void Write_pin(pin_t pin, uint8_t value);
/* read value of pin */
extern uint8_t Read_pin(pin_t pin);
/* toggle value of pin */
extern void toggle_pin(pin_t pin);

#endif	// _GPIO_H_