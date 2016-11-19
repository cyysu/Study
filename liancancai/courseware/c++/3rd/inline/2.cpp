#include <iostream>

//inline void hello(void)
static void hello(void)
{
	std::cout << "hello" << std::endl;
}
void world(void)
{
	hello();
	std::cout << "world" << std::endl;
}
