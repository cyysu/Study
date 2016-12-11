#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	char i;

	for (i = 0; i < atoi(argv[1]); i ++)
	{
		cout << i;
		cout << " "; 
	}
	cout << endl;


	return 0;
}
