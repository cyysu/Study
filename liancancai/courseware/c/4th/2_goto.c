#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j, sum = 0;

	i = 1;//init
	loop:
		sum += i;//body
		i++;//add
	if (i <= 100)//con
		goto loop;

	printf("1 + 2 + 3 + ... + 100 = %d\n", sum);

	i = 1;
	I:

		j = 1;
		J:
			printf("%d * %d = %2d  ", j, i, i * j);
			j++;
		if (j <= i)
			goto J;

		printf("\n");
		i++;
	if (i < 10)
		goto I;
	return 0;
}
