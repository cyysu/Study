#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GETP(ptr, type, member) (type *)(((void *)ptr) - ((unsigned long)&(((type*)0)->member)))

struct node_t{
	struct node_t *next;
	struct node_t *prev;
};

struct tea_t{
	char name[20];
	int code;
	int age;
	double money;
	struct node_t sel;
};

struct cls_t{
	struct node_t sel;
	char name[20];
	int age;
	int id;
};

struct cur_t{
	char name[20];
	struct node_t sel;
	double grads;
};

void add(struct node_t *new, struct node_t *head)
{
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

void test(struct node_t *head)
{
	struct cls_t *ap = NULL;
	struct tea_t *bp = NULL;
	struct cur_t *cp = NULL;

	// ap = (struct cls_t *)(((void *)head->next) - ((unsigned long)&(((struct cls_t *)0)->sel)));
	ap = GETP(head->next, struct cls_t , sel);
	printf("name = %s, id = %d, age = %d\n", ap->name, ap->id, ap->age);

	bp = GETP(head->next->next, struct tea_t, sel);
	printf("name = %s, age = %d, code = %d, money = %g\n", bp->name, bp->age, bp->code, bp->money);

	cp = GETP(head->next->next->next, struct cur_t, sel);
	printf("name = %s, grads = %g\n", cp->name, cp->grads);
}

int main(void)
{
	struct cls_t cls = {.name = "XiaoMing", .age = 20, .id = 201311};
	struct tea_t tea = {.name = "Mr_Wang", .age = 33, .code = 1, .money = 6500.0};
	struct cur_t cur = {.name = "Yu_Wen", .grads = 90.5};
	struct node_t head = {&head, &head};

	add(&cls.sel, &head);
	add(&tea.sel, &head);
	add(&cur.sel, &head);

	test(&head);
	return 0;
}