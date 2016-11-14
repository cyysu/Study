#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0, count = 0;
	char buf[128];
	char *name[10] = {};//指针数组


	while(1)
	{
		printf("please input name : ");
		fgets(buf, sizeof(buf), stdin);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';

		if (strcmp("exit", buf) == 0)
		{
			break;
		}

		name[count] = (char *)malloc(strlen(buf) + 1);
		if (name[count] == NULL)
		{
			while(--count)
				free(name[count]);
			return -1;
		}

		strcpy(name[count], buf);
		count++;
	}

	for (i = 0; i < count; i++)
	{
		printf("%s\n", name[i]);
	}

	for (i = 0; i < count; i++)
	{
		free(name[i]);
	}
	return 0;
}
