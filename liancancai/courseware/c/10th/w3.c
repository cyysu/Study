#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_word(char *s)
{
	int count = 0;

	while(*s == ' ')
		s++;
	while(*s != '\0')
	{
		if (*s == ' ' && *(s + 1) != ' ' && *(s + 1) != '\0')
		{
			count++;
		}
		s++;
	}
	return count + 1;
}
int main(void)
{
	char buf[128];
	int count = 0;

	printf("please input string : ");
	fgets(buf, sizeof(buf), stdin);
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';

	printf("buf = %s\n", buf);

	count = count_word(buf);
	printf("count = %d\n", count);
	return 0;
}
