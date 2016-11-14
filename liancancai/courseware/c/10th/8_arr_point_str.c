#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char name[10][10] = {"tom", "jim", "mary"};
	char (*s)[10] = NULL;//数组指针
	char *p[10] = {"tom", "jim", "mary"};//指针数组

	//zhang san 
	//li si
	//wang ma zi 

	s = name;
	/*p = name;*/

	strcpy(s[0], "hello");
	strcpy(p[0], "hello");
	/*p[0] = "hello";*/

	for (i = 0; i < 3; i++)
	{
		printf("%s ", s[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%s ", p[i]);
	}
	printf("\n");
	return 0;
}
