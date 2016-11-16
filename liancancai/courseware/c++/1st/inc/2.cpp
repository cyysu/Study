#include <iostream>

extern "C"
{
	void test(void)
	{
		std::cout << "c++ : test!" << std::endl;
	}
}
