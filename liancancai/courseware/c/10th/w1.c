#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;

	return tmp;
}
char *my_strncpy(char *dest, const char *src, int size)
{
	char *tmp = dest;

	while(*src != '\0' && size--)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return tmp;
}

char *my_strstr(const char *haystack, const char *needle)
{
	while(*haystack != '\0')
	{
		if (*haystack == *needle && strncmp(haystack, needle, strlen(needle)) == 0)
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}
int main(void)
{
	char dest[128];
	char *p = NULL;
	
	/*p = strcpy(dest, "hello");*/
	p = my_strncpy(dest, "hello", 3);
	printf("p = %s : %p\n", p, p);
	printf("dest = %s : %p\n", dest, dest);

	/*printf("my_strstr = %s\n", my_strstr("hello", ""));*/
	printf("my_strstr = %s\n", strstr("hello", ""));

	return 0;
}
