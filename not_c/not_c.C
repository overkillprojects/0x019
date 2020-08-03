
#include	"extern.h"

int array[5] = {0, 1, 4, 6, 2};
int i = 0;
int j = 0;

word p;			// NB: points to an INT, but no way of relaying this information!!!

void	FPPA0 (void)
{
	.ADJUST_IC	SYSCLK=IHRC/4		//	SYSCLK=IHRC/4

	//	Insert Initial Code
	

	while (1)
	{
		// increase values in array by 1

		//array[i++]++;

		p = array + i++;
		*p += 1;

		//i %= 5;

		//i = i % 5;

		//j = i;
		//i = j % 5;

		//j = i / 5;

		if (i > 4) i -= 5;
	}
}


void	Interrupt (void)
{
	pushaf;

	if (Intrq.T16)
	{	//	T16 Trig
		//	User can add code
		Intrq.T16	=	0;
		//...
	}

	popaf;
}

