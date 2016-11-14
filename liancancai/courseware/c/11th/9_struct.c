#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct b_t{
	int a;
	int b;
};

struct a_t{
	char name[128];
	struct b_t *a;	
	/*struct a_t *b;*/
};

int main(void)
{
	struct b_t b = {11, 22};
	struct a_t a = {"tom", &b};
	struct a_t *p = NULL;

	//

	p = &a;

	strcpy(p->name, "hello");

	printf("p->name = %s\n", p->name);
	printf("p->a->a = %d\n", p->a->a);
	
	printf("a.name = %s\n", a.name);
	printf("a.a.a = %d\n", a.a->a);
	printf("a.a.b = %d\n", a.a->b);
	return 0;
}
