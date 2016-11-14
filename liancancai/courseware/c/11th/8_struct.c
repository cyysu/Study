#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fan(void)
{
	printf("范冰冰!\n");
}
void xiaoyanzi(void)
{
	printf("小燕子!\n");
}
//定义一个结构体信息
struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	float cn;
	float en;
	void (*love[2])(void);
};

int main(void)
{
	struct cls_t cls = {"tom", 16010001, 18, 'M', 88.5, 96.7, {fan, xiaoyanzi}};//结构体变量名

	strcpy(cls.name,"jim");
	cls.age = 19;

	printf("name = %s\n", cls.name);
	printf("id = %d\n", cls.id);
	printf("age = %d\n", cls.age);
	printf("sex = %c\n", cls.sex);
	printf("cn = %g\n", cls.cn);
	printf("en = %g\n", cls.en);

	/*cls.love = xiaoyanzi;*/

	cls.love[0]();
	cls.love[1]();

	return 0;
}
