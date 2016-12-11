#include <iostream>
#include <cstring>

using namespace std;

class A{
	private:
		string str[10];
	public:
		A(void);
};

A::A(void)
{
	memset(str, 0, sizeof(str));
}

int main(void)
{
	//A a;
	
	

	string str[10];

	//memset(str, 0, sizeof(str));

	str[1] = "hello";

	printf("hello!\n");

	return 0;
}
