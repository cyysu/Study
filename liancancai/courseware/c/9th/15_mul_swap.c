#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 1, b = 2, t1;
	int *p1 = &a, *p2 = &b, *t2;
	int **q1 = &p1, **q2 = &p2, **t3 = NULL;

	printf("before : a = %d b = %d\n", a, b);
	printf("before : *p1 = %d *p2 = %d\n", *p1, *p2);
	printf("before : **q1 = %d **q2 = %d\n", **q1, **q2);
    /*
	 *t3 = q1;
	 *q1 = q2;
	 *q2 = t3;
     */
    /*
	 *t2 = *q1;
	 **q1 = *q2;
	 **q2 = t2;
     */
	t1 = **q1;
	**q1 = **q2;
	**q2 = t1;
	printf("after  : a = %d b = %d\n", a, b);
	printf("after  : *p1 = %d *p2 = %d\n", *p1, *p2);
	printf("after  : **q1 = %d **q2 = %d\n", **q1, **q2);
	return 0;
}
