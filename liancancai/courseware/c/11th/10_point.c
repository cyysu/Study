#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GETLINES(string, buf) do{							\
						printf(string);						\
						fgets(buf, sizeof(buf), stdin);		\
						if (buf[strlen(buf) - 1] == '\n')	\
							buf[strlen(buf) - 1] = '\0';	\
					}while(0) 



struct a_t{
	char name[128];
	int age;
	char sex;
};

int main(void)
{
	struct a_t *p = NULL;
	//"zhang san " 20 'M'
	p = (struct a_t *)malloc(sizeof(struct a_t));
	if (NULL == p)
	{
		return -1;
	}

	GETLINES("please input name : ", p->name);
	printf("please input age : ");
	scanf("%d", &p->age);
	getchar();
	printf("please input sex : ");
	scanf("%c", &p->sex);


	printf("name : %s | age : %d | sex : %c\n", p->name, p->age, p->sex);
	printf("&p = %p\n", &p);
	printf("p = %p\n", p);
	printf("name : %p | age : %p | sex : %p\n", p->name, &p->age, &p->sex);
	return 0;
}
