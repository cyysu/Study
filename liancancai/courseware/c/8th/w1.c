#include <stdio.h>
#include <string.h>

void my_strcpy(char dest[], char src[])
{
	int i = 0;

	while((dest[i] = src[i++]) != '\0')
		l;
    /*
	 *while(src[i] != '\0')
	 *{
	 *    dest[i] = src[i];
	 *    i++;
	 *}
	 *dest[i] = '\0';
     */
}

void my_strncpy(char dest[], char src[], int size)
{
	int i = 0;

	while(src[i] != '\0' && size--)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

}
void my_strcat(char dest[], char src[])
{
	int i = 0, j = 0;

	while(dest[i] != '\0')
		i++;
	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}


int my_strcmp(char s1[], char s2[])
{
	int i = 0;

	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if ((s1[i] - s2[i]) < 0)
	{
		return -1;
	}
	else if ((s1[i] - s2[i]) > 0)
	{
		return 1;
	}
	else
		return 0;
}
int my_strchr(char s[], char ch)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return i;
		}
		i++;
	}

	return -1;
}

int my_strstr(char s[], char n[])
{
	int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] == n[0] && strncmp(s + i, n, strlen(n)) == 0)
		{
			return i;
		}
		i++;
	}
	return -1;
}
int main(void)
{
	char s1[128] = "kkkkkkkkkkkkkk";



	my_strncpy(s1 + 5, "hello" + 2, 2);//kkkkkll
	my_strcat(s1, "world");

	printf("my_strcmp(make, mask) = %d\n", my_strcmp("make", "mask"));
	printf("my_strcmp(make, make) = %d\n", my_strcmp("make", "make"));
	printf("my_strcmp(make, makeee) = %d\n", my_strcmp("make", "makeee"));
	printf("my_strcmp(makeee, make) = %d\n", my_strcmp("makeee", "make"));
	printf("strcmp(make, mask) = %d\n", strcmp("make", "mask"));

	printf("my_strchr(hello, l) = %d\n", my_strchr("hello", 'l'));
	printf("my_strchr(hello, l) = %d\n", my_strchr("hello", 'L'));

	printf("my_strstr(hello, ll) = %d\n", my_strstr("hello", "lL"));
	printf("s1 = %s\n", s1);



	return 0;
}
