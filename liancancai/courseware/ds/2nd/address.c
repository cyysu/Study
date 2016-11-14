#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	struct node_t head = {0, NULL};
	struct node_t a = {11, NULL};
	struct node_t b = {22, NULL};

	head.next = &a;
	/*head.next = &a.data;*/
	a.next = &b;

	printf("head.next = %p\n", head.next);
	printf("head.next + 1 = %p\n", head.next + 1);
	printf("&a = %p\n", &a);
	printf("&a.data = %p\n", &a.data);
	printf("");
	return 0;
}
