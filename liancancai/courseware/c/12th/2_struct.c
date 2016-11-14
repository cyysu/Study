#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//重命令
typedef struct cls_t{
	char name[128];//赋值strcpy memcpy,但是不可以赋值运算符
	//初始化name，系统会分配空间，值是变量
	int age;
}CLS;

typedef struct stu_t{
	char name[128];
	int age;
}STU;

struct tea_t{
	char *name;//赋值时候不可以调用str家族函数，但可以赋值运算符。
	//初始化没有空间地址，初始化值是一个常量
	int code;
};
int main(void)
{
	CLS cls = {"tom", 20}, stu;
	STU tmp;
	CLS *p = NULL;
	struct tea_t tea = {"laozhang", 1};

	printf("tea.name = %s\n", tea.name);
	struct tea_t *q = NULL;

	q = &tea;
	
	/*strcpy(q->name, "laoliu");*/
	q->name = "laoliu";
	printf("name = %s\n", q->name);
	
	p = &cls;

	//指针指向的是栈中
	strcpy(p->name,"jim");

	printf("p->name = %s\n", p->name);
	printf("p->name = %s\n", (*p).name);
	/*stu.name = cls.name;*/

	stu = cls;
	/*tmp = cls;*/
	memcpy(&tmp, &cls, sizeof(cls));

	printf("name = %s\n", cls.name);
	printf("name = %s\n", stu.name);
	printf("name = %d\n", stu.age);
	printf("name = %s\n", tmp.name);
	return 0;
}
