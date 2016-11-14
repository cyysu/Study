#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//zhang san 
// li si
// wang ma zi
int main(void)
{
	int i = 0;
	char name[10][128] = {"tom", "jim", "mary"};
	char buf[128];

	printf("soizeof(name[0]) = %d\n", sizeof(name[0]));
	strcpy(name[0],"join");

	name[0][0] = 'A';

	for (i = 0; i < 10; i++)
	{
		printf("please input %d name : ", i + 1);
		fgets(buf, sizeof(buf), stdin);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		if (strcmp(buf, "exit") == 0)
		{
			break;
		}
		strcpy(name[i], buf);
        /*
		 *fgets(name[i], sizeof(name[i]), stdin);
		 *if (name[i][strlen(name[i]) - 1] == '\n')
		 *    name[i][strlen(name[i]) - 1] = '\0';
         */
		/*printf("%s ", name[i]);*/
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s\n", name[i]);
	}
	printf("\n");
	return 0;
}
