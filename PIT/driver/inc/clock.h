#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "hw_kl46z.h"

typedef struct
{
	uint8_t 	mode;
	uint32_t	MCGIRCLK;
	uint32_t	core_platform_system_clock;
	uint32_t	bus_flash_clock;
	uint32_t	MCGPLL_FLL_CLK;
	uint32_t	OSCERCLK;
	uint32_t	ERCLK32;
	uint32_t	LPO;
	uint32_t	RTC_CLKOUT;
}clock_t;


extern void init_systemClock(void);
extern void init_FEI(void);
extern void init_FEE(void);
extern void init_FBI(void);
extern void init_FBE(void);
extern void init_BLPI(void);
extern void init_BLPE(void);
extern void init_PBE(void);
extern void init_PEE(void);



#endif	// _CLOCK_H_