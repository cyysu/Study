#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;

    /*
	 *0  1  2  3  4  5  6  7  8
	 *####****
	 *9  10 11 12 13 14 15 16 17
	 *####****
	 *18 19 20 21 
	 *####****
	 *####****
     */
	for (i = 0; i < 36; i++)
	{
		if (i % 9 < 4)
		{
			putchar('#');
		}
		else if (i % 9 == 8)
		{
			putchar(10);
		}
		else
		{
			putchar('*');
		}
	}
	return 0;
}
