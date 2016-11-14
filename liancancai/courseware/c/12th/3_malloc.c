#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

struct tea_t{
	char *name;
	int code;
};

int main(void)
{
	struct tea_t *tea = NULL;

	tea = (struct tea_t *)malloc(sizeof(struct tea_t));
	ERRP(NULL == tea, "malloc tea failed!\n", goto ERR1);
	
	tea->name = (char *)malloc(128);
	ERRP(tea->name == NULL, "malloc name failed!\n", goto ERR2);

	GETLINES("please input name : ", tea->name, 128);

	printf("name = %s\n", tea->name);
	//通过外部输入用户：zhang san 110
	return 0;
ERR2:
	free(tea);
ERR1:
	return -1;
}
