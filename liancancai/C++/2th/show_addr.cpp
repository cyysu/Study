#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int a = 10;
	
	printf("&a = %p\n", &a);
	cout << "&a = " << static_cast<void *> (&a) << endl;

	cout << "&a = " << static_cast<void *> (&a) << endl;
	
	return 0;
}
