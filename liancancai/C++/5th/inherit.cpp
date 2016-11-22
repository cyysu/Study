#include <iostream>

using namespace std;

class A{
private:
	int pri;
protected:
	int pro;
public:
	int pub;
};

class B: public A{

};

class C: protected A{

};

int main(void)
{
	B b;
	C c;

	// b.pri = 1;
	// b.pro = 1;
	// b.pub = 1;	
	c.pri = 1;
	c.pro = 1;
	c.pub = 1;

	return 0;
}
