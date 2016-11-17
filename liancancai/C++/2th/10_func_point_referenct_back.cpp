#include <iostream>

using namespace std;

struct cls_t{
	char name[128];
	int age;
	char sex;

	void (*fun1) (void);
	struct cls_t & (*fun2)(struct cls_t & stu);
};

void fun1(void)
{
	cout << "fun1" << endl;
}

struct cls_t & fun2(struct cls_t & stu)
{
	cout << stu.name << endl;

	return stu;
}

int main(void)
{
	struct cls_t stu = {"xiao ming", 21, 'M', fun1, fun2};

	stu.fun1();
	stu.fun2(stu).fun2(stu).fun2(stu).fun2(stu).fun1();

	return 0;
}
