#if 0
#include <iostream>


using namespace std;

void test(int a)
{
	cout << "test1" << endl;
}
void test(int a, int b)
{
	cout << "test2!" << endl;
}
int main(void)
{
	
	test(1);
	test(1, 2);
	return 0;
}
#else

#include <stdio.h>



void test(int a)
{
	printf("test1!\n");
}
void test(int a, int b)
{
	printf("test2!\n");
}

int main(void)
{
	
	test(1);
	test(1, 2);
	return 0;
}

#endif
