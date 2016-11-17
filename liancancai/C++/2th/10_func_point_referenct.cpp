#include <iostream>

using namespace std;

struct cls_t {
	char name[128];
	int age;
	char sex;
	double grade;

	void (*fun1)(void);
	struct cls_t &(*fun2)(struct cls_t & stu);
};

void hello(void)
{
	cout << "hello" << endl;
}

struct cls_t & student(struct cls_t & stu)
{
	cout << "stu.name = " << stu.name << endl;

	return stu;
}

int main(void)
{
	struct cls_t stu = {"xiaoming", 21, 'M', 88.5, hello, student};

	stu.fun1();
	stu.fun2(stu).fun1();
	return 0;
}