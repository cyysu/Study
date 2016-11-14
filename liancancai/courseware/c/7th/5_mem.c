#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int a[10];
	int b[10] = {1,2,3,4,5,6};
	char s1[128];
	char s2[128] = "hello";

	memset(a, 1, sizeof(a));
	memset(s1, 0, sizeof(s1));

	/*memcpy(s1, s2, strlen(s2) + 1);*/
	// s2 -> hello
	// s2 + 3 -> hel lo
	// s2 + 2 -> he llo
	// helllo
	memmove(s2 + 3, s2 + 2, strlen(s2) + 1);
	/*printf("s1 = %s\n", s1);*/
	printf("s2 = %s\n", s2);





	printf("sizeof(b + 4) = %d\n", sizeof(b + 4));

	memcpy(a + 2, b + 4, sizeof(int) * 2);

	for (i = 0; i < 10; i++)
	{
		printf("%#x ", a[i]);
	}
	printf("\n");
	
	return 0;
}
