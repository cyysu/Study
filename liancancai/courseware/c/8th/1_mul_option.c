#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void display(char name[][10])
{
	printf("display : name[0] = %s\n", name[0]);
	printf("display : name[1] = %s\n", name[1]);
	printf("display : name = %p name + 1 = %p\n", name, name + 1);
	printf("name[0] = %s\n", name[0]);
}
void init(char s[][3][4])
{

}

void print(char s[])
{
	printf("s = %s\n", s);
	
}
int main(void)
{
	int i;
	char s[2][3][4];
	char name[10][10] = {"tom", "jim", "mary"};

	for (i = 0; i < 3; i++)
	{
		print(name[i]);
	}
	init(s);
	printf("main : name = %p name + 1 = %p\n", name, name + 1);
	printf("main : name[1] = %s\n", name[1]);
	display(name);
	return 0;
}
