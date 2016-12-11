#include <iostream>

using namespace std;

class test{
	private:
		char name[128];
		string str;
		int age;
	public:
	test(char *_name = "tom", string _str = "hello", int _age = 18);
	void show(void) const;
};


test::test(char *_name, string _str, int _age)
{
	cout << "constructor" << endl;
}
void test::show(void) const
{
	char buf[128] = "jim";
	cout << "show => " << " age : " << age << endl;
	strcpy(this->name, buf);
	//age = 20;
	cout << "show => " << " age : " << age << endl;
}
int main(void)
{
	test a;

	a.show();
	return 0;
}
