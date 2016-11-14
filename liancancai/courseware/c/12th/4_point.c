#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char name[128];
	int age;
	struct cls_t *p;
};

int main(void)
{
	struct cls_t cls = {"jim", 20, NULL};

	cls.p = &cls;

	printf("name = %s\n", cls.name);
	printf("name = %s\n", cls.p->p->p->p->p->name);

	return 0;
}
