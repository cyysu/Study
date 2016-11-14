#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//水仙花数

void daffofil_one(void)
{
	int g, shi, bai, x;
	for(x = 100; x <= 999; x ++)
	{
		g = x %  10, shi = x / 10 % 10, bai = x / 100;
		// printf("%d %d %d %d\n", x, bai, shi, g);
		if(g * g * g + shi * shi * shi + bai * bai * bai == x);
			// printf("%d\n", x);
	}
}

void daffofil_two(void)
{
	int g, shi ,bai;
	for(g = 0; g < 9; g++)
	{
		for(shi = 0; shi < 9; shi++)
		{
			for(bai = 1; bai < 9; bai++)
			{
				if(g * g * g + shi * shi * shi + bai * bai * bai == bai * 100 + shi *10 + g);
				// printf("%d%d%d\n", bai, shi, g);
			}
		}
	}
}

int main(void)
{
	// daffofil_one();
	daffofil_two();
	return 0;
}

