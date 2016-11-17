#include <iostream>

using namespace std;

struct cls{
	string name;
	int age;
	void (*func1)(void);
	struct cls & (*func2)(struct cls & stu);
};

void hello(void)
{
	cout << "hello" << endl;
}


struct cls & test(struct cls & stu)
{
	cout << "test" << endl;

	return stu;
}

int main(void)
{
	struct cls student = {"tom", 20, hello, test};

	student.func1();

	student.func2(student).func1();
	cout << "=============\n";
	student.func2(student).func2(student).func2(student);
	cout << "name = " <<student.func2(student).func2(student).func2(student).name << endl;
	return 0;
}
