#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;

    /*
	 *i = 1;
	 *I:
	 *printf("%d ", i);
	 *i++;
	 *if (i < 10)
	 *    goto I;
     */

	/*printf("\n");*/

	i = 0;
	I:
		j = 0;
		J:
		printf("* ");
		j++;
		if (j <= i)
			goto J;
	printf("\n");
	i++;
	if (i < 5)
		goto I;
	return 0;
}
