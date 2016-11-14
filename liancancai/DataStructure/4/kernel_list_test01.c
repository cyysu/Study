#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define
#define offsetof(type, member)  (unsigned long)&(((type *)((0)->member)))

#define container_of(ptr, type, member) ({				\
	typeof(((type *)0)->member) *__mptr = (ptr);		\
	(type *)( (char *)__mptr - offsetof(type, member) );})

struct node_t{
	struct node_t *next;
	struct node_t *prev;
};

struct course_t
{
	char name[30];
	struct node_t sel;
};

struct student_t{
	char name[30];
	struct node_t sel;
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
	struct student_t *stu = NULL;
	struct course_t *cou = NULL;

	stu = (struct student_t *)((void *)(head->next->next) - (unsigned long)(&(((struct student_t *)0)->sel)));

	printf("student.name = %s\n", stu->name);
}

int main(void)
{
 	struct course_t course = {.name = "yuwen"};
 	struct student_t student = {.name = "xiaoming"};
 	struct node_t head = {&head, &head};

 	add(&course.sel, &head);
 	add(&student.sel, &head);

 	test(&head);

	return 0;
}
