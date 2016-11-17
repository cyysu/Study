#include <iostream>

inline void hello(void)
{
	std::cout << "hello" << std::endl;
}

void world(void)
{
	std::cout << "world :"; 
	hello();
}
