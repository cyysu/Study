#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	float cn;
	float en;
};

int main(void)
{
	int  i = 0;
	struct cls_t cls[10] = {{"tom", 17}, {"jim", 18}, {"mary", 15}};

	for (i = 0; i < 10; i++)
	{
		snprintf(cls[i].name, 128, "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls[i].id = rand() % 100 + 10000;
		cls[i].age = rand() % 3 + 18;
		cls[i].sex = "MF"[rand() % 2];
		cls[i].cn = rand() % 20 + 80;
		cls[i].en = rand() % 30 + 70;
	}
	for (i = 0; i < 10; i++)
	{
		printf("name : %s | id : %d | age : %d | sex : %c | cn : %g\n", cls[i].name, cls[i].id, cls[i].age, cls[i].sex, cls[i].cn);
	}
	return 0;
}
