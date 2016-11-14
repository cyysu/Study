#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现时间排序

int cut_word(char *s, char *t[10], char ch)
{
	int count = 0;

	t[count++] = s;

	while(*s != '\0')
	{
		if (*s == ch)
		{
			t[count++] = s + 1;
			*s = '\0';
		}
		s++;
	}

	return count;
}
int main(void)
{
	int i, count = 0, j;
	char buf[] = "12:31,4:41,19:57,12:08,23:56,7:18,11:12,4:08";
	char *time[10];
	char *t = buf;

	printf("%s\n", buf);
	count = cut_word(buf, time, ',');
    /*
	 *while ((time[count++] = strsep(&t, ",")) != NULL)
	 *    ;
     */

	for (i = 0; i < count; i++)
	{
		printf("%s ", time[i]);
	}
	printf("\n");

	/*printf(" => %d\n", atoi("12:13"));*/
	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (atoi(time[i]) > atoi(time[j]))
			{
				t = time[i];
				time[i] = time[j];
				time[j] = t;
			}
			else if ( atoi(time[i]) == atoi(time[j]) && atoi(strchr(time[i], ':') + 1) > atoi(strchr(time[j], ':') + 1))
			{
				t = time[i];
				time[i] = time[j];
				time[j] = t;
			
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		printf("%s ", time[i]);
	}
	printf("\n");
	return 0;
}
