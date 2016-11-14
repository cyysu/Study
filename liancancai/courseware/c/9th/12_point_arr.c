#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show(char *s)
{
	printf("show s = %s\n", s);
}
int main(void)
{
	char s[] = "hello";
	char *p = "hello";

	/*s = "world";*/ //数组不可以整体赋值
	strcpy(s, "world");
	/*p = "world";//表示p重新指向一个world常量*/
	strcpy(p, "world");

	/*p = s;*/

	s[0] = 'A';
	/*p[0] = 'A';*///表示p指向常量区修改常量区内容

	printf("s[0] = %c\n", s[0]);
	printf("p[0] = %c\n", p[0]);

	printf("s = %s\n", s);
	printf("p = %s\n", p);

    /*
	 *show(s);
	 *show("world123");
     */
	return 0;
}
