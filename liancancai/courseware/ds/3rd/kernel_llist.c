#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GETP(ptr, type, member)   ((type *)((void *)(ptr)- (unsigned long)(&(((type *)0)->member))))
//内核链表节点信息
//container_of  
///usr/src/kernels/2.6.18-194.el5-i686/include/linux/kernel.h
struct node_t{
	struct node_t *next;
	struct node_t *prev;
};

struct cls_t{
	struct node_t sel;
	char name[128];
	int id;
	int age;
};

struct tea_t{
	char name[128];
	int code;
	struct node_t sel;
};

struct cur_t{
	char name[128];
	struct node_t sel;
	int result;
};


void add(struct node_t *new, struct node_t *head)
{
	//尾插

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

	/*ap = (struct cls_t *)(((void *)head->next) - ((void *)&(((struct cls_t *)0)->sel)));*/
	ap = GETP(head->next, struct cls_t, sel);
	printf("name = %s id = %d age = %d\n", ap->name, ap->id, ap->age);
	/*bp = (struct tea_t *)(((void *)head->next->next) - ((void *)&(((struct tea_t *)0)->sel)));*/
	bp = GETP(head->next->next, struct tea_t, sel);
	printf("name = %s code = %d\n", bp->name, bp->code);
	cp = (struct cur_t *)(((void *)head->next->next->next) - ((void *)&(((struct cur_t *)0)->sel)));
	printf("name = %s result = %d\n", cp->name, cp->result);
    /*
	 *bp = head->next->next;
	 *cp = head->next->next;
     */
}
int main(void)
{
	struct node_t head = {&head, &head};
	struct cls_t cls = {.id = 10001, .name = "tom", .age = 18};
	struct tea_t tea = {.name = "laozhang", .code = 3};
	struct cur_t cur = {.name = "chinese", .result = 150};

	/*printf("cls. sel = %p\n", &(((struct cls_t*)0)->sel));*/
	//后插
	add(&cls.sel, &head);
	add(&tea.sel, &head);
	add(&cur.sel, &head);

	//访问
	test(&head);


/*
 *
 *    printf("cls : name = %s id = %d age = %d\n", cls.name, cls.id, cls.age);
 *    printf("cls : cls.sel = %p\n", &cls.sel);
 *    printf("head : cls.sel = %p\n", head.next);
 *
 *    printf("address : name = %p id = %p age = %p sel = %p\n", 
 *        cls.name, &cls.id, &cls.age, &cls.sel);
 *    
 *    printf("head : name = %s\n", (char *)((void *)head.next - 136));
 *    printf("head : id = %d\n", *(int *)((void *)head.next - 8));
 *    printf("head : age = %d\n", *(int *)((void *)head.next - 4));
 *    printf("=============\n");
 *    printf("tea : tea.sel = %p\n", &tea.sel);
 *    printf("head : tea.sel = %p\n", head.next->next);
 */
	return 0;
}
