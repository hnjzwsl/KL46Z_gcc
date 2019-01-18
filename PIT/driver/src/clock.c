#include "clock.h"

void init_systemClock(void)
{
	/* OSC module */
	
	/* MCG module */
	
	/* SIM module */

}
bool init_FEI(void)
{
/*** Entered FEI mode ***/
	uint32_t temp_reg = read_reg(MCG_C1,~(0x03u <<6));
	write_reg(MCG_C1,temp_reg);			/* MCG_C1[7:6] = 0x00u, output of PLL or FLL is selected for MCGCOUTCLK */
	
	temp_reg = read_reg(MCG_C1,~(0x01u << 2));
	temp_reg |= ( 0x01u << 2 );			
	write_reg(MCG_C1,temp_reg);			/* The 32,768KHz internal reference clock is selected for FLL */
	
	temp_reg = read_reg(MCG_C6,~(0x01 << 6));
	write_reg(MCG_C6,temp_reg);			/* MCG_C6[PLLS] = 0, FLL is selected */
	
	return true;
	

}

bool check_FEI(void)
{	
	if((read_reg(MCG_S,(0x03u << 2))) != 0x00u )
	/* MCG_S[3:2] != 0x00u, output of PLL or FLL isn't selected for MCGCOUTCLK */		
	{
		return false;
	}
	else if ( (read_reg(MCG_S,(0x01u << 4))) != (0x01u << 4)) 
	/* The 32,768KHz internal reference clock isn't selected for FLL */
	{
		return false;
	}
	else if((read_reg(MCG_S,(0x01u << 5))) != (0x00u << 5))
	/* FLL isn't selected as MCGOUTCLK source */
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool init_FEE(uint8_t source_mode)
{
	uint32_t temp_reg;
	if(source_mode == FEI)   /* Changes from FEI mode to FEE mode */
	{
		do{
			if(check_FEI(void) == true) /* If FEI has been configured */
			{
				/*** OSC ***/
				
				/* Selects the source for the external reference clock */
				temp_reg = read_reg(MCG_C2,~(0x01u << 2));
				temp_teg |= (0x01u << 2);    /* Oscillator is selected  */
				
				/* Enable OSCERCLK */
				temp_reg = read_reg(OSC0_CR,~(0x01u << 7));
				temp_reg |= (0x01u << 7);
				write_reg(OSC0_CR,temp_reg);
				
				/* Selects the MCG FLL external reference clock */
				temp_reg = read_reg(MCG_C7,~(0x01 << 0));
				write_reg(MCG_C7,temp_reg);				/* Select OSCCLK - using the internal oscillator circuits */
				
				/* setup */
				/*** Entered FEI mode ***/
				temp_reg = read_reg(MCG_C1,~(0x03u <<6));
				write_reg(MCG_C1,temp_reg);			/* MCG_C1[7:6] = 0x00u, output of PLL or FLL is selected for MCGCOUTCLK */
				
				temp_reg = read_reg(MCG_C1,~(0x01u << 2));	/* External reference clock is selected as clock source for FLL */		
				write_reg(MCG_C1,temp_reg);			/* The 32,768KHz internal reference clock is selected for FLL */
				
				temp_reg = read_reg(MCG_C6,~(0x01 << 6));
				write_reg(MCG_C6,temp_reg);			/* MCG_C6[PLLS] = 0, FLL is selected */
				
				return true;	/* break when change state success */
				
			}
			else
			{
				init_FEI(void);
			}
			
		}while(1);	/* break when change state success */
	}
	else if (source_mode == FBI)
	{
		do{
			if(check_FBI(void) == true) /* If FEI has been configured */
			{
				/* setup */
				/*** Entered FEI mode ***/
				uint32_t temp_reg = read_reg(MCG_C1,~(0x03u <<6));
				write_reg(MCG_C1,temp_reg);			/* MCG_C1[7:6] = 0x00u, output of PLL or FLL is selected for MCGCOUTCLK */
				
				temp_reg = read_reg(MCG_C1,~(0x01u << 2));	/* External reference clock is selected as clock source for FLL */		
				write_reg(MCG_C1,temp_reg);			/* The 32,768KHz internal reference clock is selected for FLL */
				
				temp_reg = read_reg(MCG_C6,~(0x01 << 6));
				write_reg(MCG_C6,temp_reg);			/* MCG_C6[PLLS] = 0, FLL is selected */
				
				return true;	/* break when change state success */
				
			}
			else
			{
				init_FBI(void);
			}
			
		}while(1);	/* break when change state success */
	}
	else if (source_mode == FBE)
	{
		
	}
	else
	{
		return false;
	}
}
void init_FBI(void)
{
	
}
void init_FBE(void)
{
	
}
void init_BLPI(void)
{
	
}
void init_BLPE(void)
{
	
}
void init_PBE(void)
{
	
}
void init_PEE(void)
{
	
}

