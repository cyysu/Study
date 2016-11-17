#include <iostream>

//内联函数
inline void hello(void)
{
	std::cout << "hello" << std::endl;
}

void world(void)
{
	hello();
}
