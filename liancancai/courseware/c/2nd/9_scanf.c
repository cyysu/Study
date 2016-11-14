#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 123, b;
	char ch = 'A';
	float f = 2.34;

	putchar(ch);
	putchar('\n');
	putchar(10);

	printf("a = %i\n", a);
	printf("f = %g\n", f);
	printf("please input two number : ");
	scanf("%d:%d", &a, &b);

	/*scanf("%c", &ch);*/
	getchar();//表示接受一个字符
	printf("please input char : ");
	/*scanf("%c", &ch);*/
	ch = getchar();




    /*
	 *printf("please input number : ");
	 *scanf("%d", &b);
     */

	printf("a = %d b = %d\n", a, b);
	printf("ch = %c %d\n", ch, ch);
	return 0;
}
