#include <iostream>
#include <string.h>

using namespace std;

char buf[256];

struct cls_t {
	char name[128];
	int age;
	char sex;
	double grade;
};

int main(void)
{
	struct cls_t *stu = NULL;
	int i;

	stu = new (buf) struct cls_t;
	if (NULL == stu)
	{
		cout << "new stu failed" << endl;
		return -1;	
	}	

	strcpy(stu->name, "xiao ming");
	stu->age = 21;
	stu->sex = 'M';
	stu->grade = 85.5;

	cout << "stu->name = " << stu->name << endl;
	cout << "stu->age = " << stu->age << endl;
	cout << "stu->sex = " << stu->sex << endl;
	cout << "stu->grade = " << stu->grade << endl;

	delete stu; //这里一释放就把buf 给摧毁了，buf 不能在使用了

//	strcpy(buf, "hello world");
//	cout << "buf = " << buf << endl;
    return 0;
}
