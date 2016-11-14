#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_MAX 128
#define TEMP_MAX 10
int main(void)
{
	char buf[BUF_MAX];
	char temp[TEMP_MAX];

	scanf("%s", buf);
	// fgets (buf, sizeof(buf), stdin);

	printf ("strlen(buf) = %ld\n", strlen(buf));

	// if (buf[strlen(buf) - 1] == '\n')
	// {
	// 	buf[strlen(buf) - 1] = '\0';
	// }

	printf ("buf = %s\n", buf);

	// strcpy (temp, buf); 
	strncpy (temp, buf, strlen(buf) + 1);

	printf ("strlen(temp) = %ld\n", strlen(temp));

	printf ("temp = %s\n", temp);

	printf ("strlen(temp) = %ld\n", strlen(temp));

	return 0;
}
