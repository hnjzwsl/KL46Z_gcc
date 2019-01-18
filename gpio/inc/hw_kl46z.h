#ifndef _HW_KL46Z_H_
#define _HW_KL46Z_H

#include "type.h"

#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

#define BASE_ADDRESS_PORT(port)	(0x40049000u + 0x1000*(port))
#define BASE_ADDRESS_GPIO(port)	(0x400FF000u + 0x40*(port))
#define BASE_ADDRESS_SIM		 0x40047000u


#define PORTA	0u
#define PORTB	1u
#define PORTC	2u
#define PORTD	3u
#define PORTE	4u

/* SIM */
#define SIM_SOPT1				(BASE_ADDRESS_SIM + 0x0u   )
#define SIM_SOPT1CFG			(BASE_ADDRESS_SIM + 0x04u  )
#define SIM_SOPT2				(BASE_ADDRESS_SIM + 0x1004u)
#define SIM_SOPT4				(BASE_ADDRESS_SIM + 0x100Cu)
#define SIM_SOPT5				(BASE_ADDRESS_SIM + 0x1010u)
#define SIM_SOPT7				(BASE_ADDRESS_SIM + 0x1024u)
#define SIM_SCGC4				(BASE_ADDRESS_SIM + 0x1034u)
#define SIM_SCGC5				(BASE_ADDRESS_SIM + 0x1038u)
#define SIM_SCGC6				(BASE_ADDRESS_SIM + 0x103Cu)
#define SIM_SCGC7				(BASE_ADDRESS_SIM + 0x1040u)
#define SIM_CLKDIV1				(BASE_ADDRESS_SIM + 0x1044u)
#define SIM_FCFG1				(BASE_ADDRESS_SIM + 0x104Cu)
#define SIM_FCFG2				(BASE_ADDRESS_SIM + 0x1050u)
#define SIM_UIDMH				(BASE_ADDRESS_SIM + 0x1058u)
#define SIM_UIDML				(BASE_ADDRESS_SIM + 0x105Cu)
#define SIM_UIDL				(BASE_ADDRESS_SIM + 0x1060u)
#define SIM_COPC				(BASE_ADDRESS_SIM + 0x1100u)
#define SIM_SRVCOP				(BASE_ADDRESS_SIM + 0x1104u)


/* PORT */
#define PORT_PCR(port, pin)   	(BASE_ADDRESS_PORT(port) + 4*(pin))
#define PORT_GPCLR(port, pin)   (BASE_ADDRESS_PORT(port) + 0x80*(pin))
#define PORT_GPCHR(port, pin)   (BASE_ADDRESS_PORT(port) + 0x84*(pin))
#define PORT_ISFR(port)   		(BASE_ADDRESS_PORT(port) + 0xA0)

/* GPIO */
#define GPIO_PDOR(port)       	(BASE_ADDRESS_GPIO(port) + 0x00u)
#define GPIO_PSOR(port)       	(BASE_ADDRESS_GPIO(port) + 0x04u)
#define GPIO_PCOR(port)       	(BASE_ADDRESS_GPIO(port) + 0x08u)
#define GPIO_PTOR(port)       	(BASE_ADDRESS_GPIO(port) + 0x0Cu)
#define GPIO_PDDR(port)       	(BASE_ADDRESS_GPIO(port) + 0x14u)


/* NVIC */
#define	 	NVIC_ISER				0xE000E100u
#define 	NVIC_ICER				0xE000E180u
#define 	NVIC_ISPR				0xE000E200u
#define 	NVIC_ICPR				0xE000E280u
#define 	NVIC_IPR(n)				(0xE000E400u + (4*n))


/* SYSTICK */
#define		SYST_CSR				0xE000E010u
#define 	SYST_RVR				0xE000E014u
#define 	SYST_CVR				0xE000E018u
#define 	SYST_CALIB				0xE000E01Cu


/* PIT */
#define BASE_ADDRESS_PIT		0x40037000u
#define PIT_MCR					(BASE_ADDRESS_PIT + 0x00u)
#define PIT_LTMR64H				(BASE_ADDRESS_PIT + 0xE0u)
#define PIT_LTMR64L				(BASE_ADDRESS_PIT + 0xE4u)
#define PIT_LDVAL(n)			(BASE_ADDRESS_PIT + 0x100u + ((n) * 0x10u))
#define PIT_TCTRL(n)			(BASE_ADDRESS_PIT + 0x108u + ((n) * 0x10u))
#define PIT_TFLG(n)				(BASE_ADDRESS_PIT + 0x10Cu + ((n) * 0x10u))


/* MCG */
#define MCG_BASE_ADDRESS		0x40064000u
#define MCG_C1					(MCG_BASE_ADDRESS + 0x00u)
#define MCG_C2					(MCG_BASE_ADDRESS + 0x01u)
#define MCG_C3					(MCG_BASE_ADDRESS + 0x02u)
#define MCG_C4					(MCG_BASE_ADDRESS + 0x03u)
#define MCG_C5					(MCG_BASE_ADDRESS + 0x04u)
#define MCG_C6					(MCG_BASE_ADDRESS + 0x05u)
#define MCG_S					(MCG_BASE_ADDRESS + 0x06u)
#define MCG_SC					(MCG_BASE_ADDRESS + 0x08u)
#define MCG_ATCVH				(MCG_BASE_ADDRESS + 0x0Au)
#define MCG_ATCVL				(MCG_BASE_ADDRESS + 0x0Bu)
#define MCG_C7					(MCG_BASE_ADDRESS + 0x0Cu)
#define MCG_C8					(MCG_BASE_ADDRESS + 0x0Du)
#define MCG_C9					(MCG_BASE_ADDRESS + 0x0Eu)
#define MCG_C10					(MCG_BASE_ADDRESS + 0x0Fu)
				

#endif   //_HW_KL46Z_H