
#include	"extern.h"

void	FPPA0 (void)
{
	.ADJUST_IC	SYSCLK=IHRC/4		//	SYSCLK=IHRC/4 = 4Mhz

	// Setup PA4 as output low for blinky
	pa &= ~(1 << 4);
	pac |= (1 << 4);

	// Disable digital input wakeup on PA
	byte padier_val = 0b11_0_11_11_1;
	padier = padier_val;

	// Setup T16: SYSCLK/64 (= 62.5kHz), interrupt on bit 11
	t16m = 0b001_11_011;
	inten.t16 = 1;

	// Setup for TM2: ILRC, overflow at 256
	tm2c = 0b0100_00_0_0;
	tm2b = 0xFF;
	tm2s = 0b0_00_00000;
	inten.tm2 = 0;

	engint;
	int i = 0;

	while (1)
	{

//		...
//		wdreset;
	}
}


void	Interrupt (void)
{
	pushaf;

	if (Intrq.T16 && inten.t16)
	{	//	T16 Trig
		//	User can add code
		Intrq.T16	=	0;

		// Blink the light
		if (pa & (1 << 4)) pa &= ~(1 << 4);
		else pa |= (1 << 4);
	}

	if (intrq.tm2 && inten.tm2)
	{
		intrq.tm2 = 0;
		// processing and such goes down here
	}

	popaf;
}

