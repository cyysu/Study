#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char s1[128] = "hello";
	char s2[8] = "world ";

	//"make" "mask" 'a'-> 97  'b' -> 98
	
	printf("strcmp(make, mask) = %d\n", strcmp("make", "mask"));
	printf("strcmp(mask, make) = %d\n", strcmp("mask", "make"));
	printf("strcmp(mask, mask) = %d\n", strcmp("mask", "mask"));
	printf("strcmp(mask, maskaa) = %d\n", strcmp("mask", "maskaa"));
	printf("strncmp(mask, make, 2) = %d\n", strncmp("mask", "make", 2));

	//"hello" 'l'

	printf("strchr(hello, l) = %s\n", strchr("hello", 'l'));
	printf("strchr(hello, L) = %s\n", strchr("hello", 'L'));
	printf("strrchr(hello, l) = %s\n", strrchr("hello", 'l'));

	printf("strstr(hello, ll) = %s\n", strstr("hello", "ll"));
	printf("strstr(hello, lol) = %s\n", strstr("hello", "lol"));
	printf("strcasestr(hello, lL) = %s\n", strcasestr("hello", "lL"));

    /*
	 *printf("s2 = %s\n", s2);
	 *strncat(s2, s1, 3);
	 *printf("s2 = %s\n", s2);
     */

	return 0;
}
