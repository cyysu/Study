#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define container_of(ptr, type, number)  \
		(type *)(((char *)ptr) - (unsigned long)(&(((type *)0)->number)))
//核心在此之上。。
struct node{
	struct node *prev;
	struct node *next;

};

struct class{
	char buf[128];
	struct node sel;
	struct node s_head;
};

struct student{
	char buf[128];
	int age;
	int sex;
	struct node sel;
	struct node c_head;
};

struct item{
	struct class *c;
	struct student *s;
	struct node s_sel;
	struct node c_sel;
};

void add_node(struct node *head, struct node *new)
{
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

void add_stu(struct node *student, struct node *class)
{
	struct student *old = NULL;
	struct item *item = NULL;
	
	char buf[128];

	struct node *tail = NULL;

	struct class *tmp = NULL;

	while(1)//输入end结束
	{
		printf("plese enter student :\t");//获取学生姓名
		fgets(buf, sizeof(buf) - 1, stdin);
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';

		if(!strncasecmp(buf, "end", 3))
		{
			break;
		}

		old = (struct student *)malloc(sizeof(struct student));

		strcpy(old->buf, buf);//
AA:		old->age = rand() % 20;//年龄必须大于15岁
		if(old->age < 15)
			goto AA;
		old->sex = rand() % 2;

		old->c_head.next = &old->c_head;//前后都指向自己
		old->c_head.prev = &old->c_head;

		add_node(student, &old->sel);//将学生的链表连接起来

		for(tail = class->next; tail != class; tail = tail->next)
		{
			tmp = container_of(tail, struct class, sel);
		
			printf("%s \t class :[Y / N] \t:", tmp->buf);//课程名
			char ch;

			scanf("%c", &ch);

			while(getchar() != '\n')
				;
		
			if(ch == 'Y' || ch == 'y')
			{
				item = (struct item *)malloc(sizeof(struct item));

				item->s = old;
				item->c = tmp;

				add_node(&old->c_head, &item->c_sel);//学生链接到sel

				add_node(&tmp->s_head, &item->s_sel);//课程也链接到sel
			}
		}
	}
}
     
void travel(struct node *head_c)
{
	struct node *tail = NULL;
	struct node *last = NULL;

	struct class *new = NULL;
	struct item *old = NULL;

	for(tail = head_c->next; tail != head_c; tail = tail->next)
	{
		new = container_of(tail, struct class, sel);//获取class 结构体的首地址

		printf("\nclass : %s\t ", new->buf);

		//通过内核链表找到了student的地址
		for(last = new->s_head.next; last != &new->s_head; last = last->next)
		{
			old = container_of(last, struct item, s_sel);//获取item中student的首地址

			printf("[%s]", old->s->buf);
			printf("-[%d]-[%d]\t", old->s->age, old->s->sex);
		}
		putchar('\n');
	}
}

void add_cls(struct node *head, struct node *s_head)
{
	struct class *new = NULL;
	struct node *tail = NULL;
	
	struct item *item = NULL;
	struct student *student = NULL;
	
	char buf[128];

	new = (struct class *)malloc(sizeof(struct class));
	
	printf("please enter add class :\t");

	fgets(buf, sizeof(buf) - 1, stdin);
	if(buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) -1 ] = '\0';
	
	strcpy(new->buf, buf);

	new->s_head.next = &new->s_head;
	new->s_head.prev = &new->s_head;

	add_node(head, &new->sel);

	printf("%s class -> is_add student :[Y / N]\t", new->buf);

	char ch;

	ch = getchar();

	while(getchar() != '\n')
		;

	if(ch == 'y' || ch == 'Y')
	{

		for(tail = s_head->next; tail != s_head; tail = tail->next)
		{
			student = container_of(tail, struct student, sel);
	
			printf("IS_ADD [%s] student \t", student->buf);

			ch = getchar();

			while(getchar() != '\n')
				;

			if(ch == 'N' || ch == 'n')
				continue;

			item = (struct item *)malloc(sizeof(struct item));
	
			item->s_sel.next = &new->s_head;
			item->s_sel.prev = new->s_head.prev;
	
			new->s_head.prev->next = &item->s_sel;
			new->s_head.prev = &item->s_sel;
	
			item->c_sel.next = &student->c_head;
			item->c_sel.prev = student->c_head.prev;

			student->c_head.prev->next = &item->c_sel;
			student->c_head.prev = &item->c_sel;

			item->s = student;
			item->c = new;
		}
	}
}

void find_cls(struct node *head)
{
	struct node *tail = NULL;
	struct node *last = NULL;

	struct class *class = NULL;
	struct student *student = NULL;
	
	struct item *item = NULL;
	char buf[128];
	
	printf("please enter want find class :\t");

	fgets(buf, sizeof(buf) - 1, stdin);
	if(buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	
	for(tail = head->next; tail != head; tail = tail->next)
	{
		class = container_of(tail, struct class, sel);

		if(!strcmp(class->buf, buf))
		{
			// printf("class: %s student number:\t");

			for(last = class->s_head.next; last != &class->s_head; last = last->next)
			{
				item = container_of(last, struct item, s_sel);

				printf("%s\t", item->s->buf);
			}
		}
	}
}

void find_student(struct node *s_head)
{
	struct node *tail = NULL;
	struct student *student = NULL;

	struct class *class = NULL;
	struct item *item = NULL;

	struct node *last = NULL;
	char buf[128];

	printf("please enter student :\t");

	fgets(buf, sizeof(buf) - 1, stdin);
	if(buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';


	for(tail = s_head->next; tail != s_head; tail = tail->next)
	{
		
		student = container_of(tail, struct student, sel);
				
		if(!strcmp(buf, student->buf))
		{
			for(last = student->c_head.next; last != &student->c_head; last = last->next)
			{
				item = container_of(last, struct item, c_sel);
					printf("[%s]", item->c->buf);
			}
			return;
		}

	}
}

void show_class(struct node *c_head)
{
	struct node *tail = NULL;
	struct class *class = NULL;

	struct class *student = NULL;

	printf("all class list :\t");

	for(tail = c_head->next; tail != c_head; tail = tail->next)
	{
		class = container_of(tail, struct class, sel);

		printf("[%s] ", class->buf);
	}
}

void show_student(struct node *s_head)
{
	struct node *tail = NULL;
	struct student *student = NULL;

	printf("all student list :\t");

	for(tail = s_head->next; tail != s_head; tail = tail->next)
	{
		student = container_of(tail, struct student, sel);

		printf("[%s] ", student->buf);
	}
}

void delete_class(struct node *c_head, struct node *s_head)
{
	struct node *new = NULL;

	struct node *tail = NULL;
	struct node *last = NULL;

	struct class *class = NULL;
	struct student *student = NULL;
	
	struct item *item = NULL;
	char buf[128];

	printf("you want to delete class : ");
	
	fgets(buf, sizeof(buf) - 1,  stdin);
	if(buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	
	for(tail = c_head->next; tail != c_head; tail = tail->next)
	{
		class = container_of(tail, struct class, sel);

		if(!strcmp(buf, class->buf))
		{

			for(last = class->s_head.next; last != &class->s_head; last = last->next)
			{

				item = container_of(last, struct item, s_sel);

				item->s_sel.prev->next = item->s_sel.next;
				item->s_sel.next->prev = item->s_sel.prev;
	
				item->c_sel.prev->next = item->c_sel.next;
				item->c_sel.next->prev = item->c_sel.prev;
		
				item->s = NULL;
				item->c = NULL;
				
				free(item);
				item = NULL;
			}

			tail->prev->next = tail->next;
			tail->next->prev = tail->prev;

			free(class);
			class = NULL;

			return;
		}

	}
}

void delete_student(struct node *c_head, struct node *s_head)
{
	struct node *tail = NULL;
	struct node *last = NULL;

	struct class *class = NULL;
	struct student *student = NULL;

	struct item *item = NULL;
	char buf[128];

	printf("please enter want to student :\t");

	fgets(buf, sizeof(buf) - 1, stdin);
	if(buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	
	for(tail = s_head->next; tail != s_head; tail = tail->next)
	{
		student = container_of(tail, struct student, sel);

		if(!strcmp(buf, student->buf))
		{
			for(last = student->c_head.next; last != &student->c_head; last = last->next)
			{
				item = container_of(last, struct item, c_sel);

				item->s = NULL;
				item->c = NULL;

				item->s_sel.prev->next = item->s_sel.next;
				item->s_sel.next->prev = item->s_sel.prev;

				item->c_sel.prev->next = item->c_sel.next;
				item->c_sel.next->prev = item->c_sel.prev;

				free(item);
				item = NULL;
			}

			student->sel.next->prev = student->sel.prev;
			student->sel.prev->next = student->sel.next;

			free(student);

			student = NULL;

			return;
		
		}
	}

}

static void destroy_s(struct node *head)
{
	struct node *tail = NULL;
	struct student *student = NULL;

	for(tail = head->next; tail != head; tail = tail->next)
	{
		student = container_of(tail, struct student, sel);

		student->sel.next->prev = student->sel.prev;
		student->sel.prev->next = student->sel.next;

		free(student);
		student = NULL;
	}
}

static void destroy_c(struct node *c_head, struct node *s_head)
{
	struct node *tail = NULL;
	struct class *class  = NULL;

	struct student *student = NULL;
	struct item *item = NULL;
	
	struct node *last = NULL;

	for(tail = c_head->next; tail != c_head; tail = tail->next)
	{
		class = container_of(tail, struct class, sel);

		for(last = class->s_head.next; last != &class->s_head; last = last->next)
		{
			item = container_of(last, struct item, s_sel);

			item->c_sel.next->prev = item->c_sel.prev;
			item->c_sel.prev->next = item->c_sel.next;

			item->s_sel.next->prev = item->s_sel.prev;
			item->s_sel.prev->next = item->s_sel.next;

			item->s = NULL;
			item->c = NULL;

			free(item);
			item = NULL;
		}

		class->sel.next->prev = class->sel.prev;
		class->sel.prev->next = class->sel.next;

		free(class);
		class = NULL;
	}
}

void destroy(struct node *c_head, struct node *s_head)
{
	destroy_c(c_head, s_head);

	destroy_s(s_head);
}

int main(void)
{
	struct node head_s = {.next = &head_s, .prev = &head_s};
	struct node head_c = {.next = &head_c, .prev = &head_c};
	
	struct class *new = NULL;
	int quit = 0;

	char buf[128];

	

	while(1)
	{
		printf("please enter class :\t");
	
		fgets(buf, sizeof(buf) - 1, stdin);
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';

	

		if(!strncasecmp(buf, "END", 3))
		{
			break;
		}

		new = (struct class *)malloc(sizeof(struct class));

		strcpy(new->buf, buf);
		new->s_head.next = &new->s_head;
		
		new->s_head.prev = &new->s_head;
		add_node(&head_c, &new->sel);
	}

	while(!quit)
	{
		printf("==== 1  -> add student    ===\n");
		printf("==== 2  -> add class      ===\n");
		printf("==== 3  -> find class     ===\n");
		printf("==== 4  -> find student   ===\n");
		printf("==== 5  -> tarvel all     ===\n");
		printf("==== 6  -> show class     ===\n");
		printf("==== 7  -> show sudent    ===\n");
		printf("==== 8  -> delete class   ===\n");
		printf("==== 9  -> delete student ===\n");
		printf("==== 10 -> destroy        ===\n");

		printf("input your want number: \t");

		int num = 0;

		scanf("%d", &num);

		while(getchar() != '\n')
			;
		switch(num)
		{
			case 1:
			add_stu(&head_s, &head_c);
			putchar('\n');
			break;

			case 2:
			add_cls(&head_c, &head_s);
			putchar('\n');
			break;
			
			case 3:
			find_cls(&head_c);
			putchar('\n');
			break;

			case 4:
			find_student(&head_s);
			putchar('\n');
			break;

			case 5:
			travel(&head_c);
			putchar('\n');
			break;
		
			case 6:
			show_class(&head_c);
			putchar('\n');
			break;
		
			case 7:
			show_student(&head_s);
			putchar('\n');
			break;

			case 8:
			delete_class(&head_c, &head_s);
			putchar('\n');
			break;

			case 9:
			delete_student(&head_c, &head_s);
			putchar('\n');
			break;

			case 10:
			quit = !quit;
			break;

			default:
			break;
		}
	}

	destroy(&head_c, &head_s);

	return 0;
}