#include <iostream>

using namespace std;

extern void hello(void);
extern void world(void);

inline void test(void)
{
	cout << "test" << endl;
}

int main(void)
{
	hello();
	world();
	test();
	return 0;
}
