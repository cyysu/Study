#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char name[10];
	int age;
};

void test(struct cls_t *cls)
{
	printf("test : name = %s age = %d\n", cls->name, cls->age);
	strcpy(cls->name, "jim");
	printf("test : name = %s age = %d\n", cls->name, cls->age);

}

struct cls_t test1(void)
{
	struct cls_t cls = {"mary", 12};

	printf("test1 : &cls = %p\n", &cls);
	return cls;
}
struct cls_t *test2(void)
{
	struct cls_t *cls = NULL;

	
	printf("test2 : &cls = %p\n", cls);
	return cls;
	
}
int main(void)
{
	struct cls_t cls = {"tom", 18};
	struct cls_t *p = NULL;

	printf("main : &cls = %p\n", &cls);
	test(&cls);
	printf("main : name = %s age = %d\n", cls.name, cls.age);

	cls = test1();
	printf("main : &cls = %p\n", &cls);
	printf("main : name = %s age = %d\n", cls.name, cls.age);

	printf("=============\n");
	p = test2();
	printf("p = %p\n", p);
	printf("main : name = %s age = %d\n", p->name, p->age);

	return 0;
}
