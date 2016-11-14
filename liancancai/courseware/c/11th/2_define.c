#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int e = 10;
//宏命令
#define PI 3.14
#define R 2
#define S PI * R * R
#define AREA(r) PI *r * r
#define MUL(a, b) ((a) * (b))
#define USER "admin"
#define PASSWD "123456"
#define PRI printf
#define D "%d"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define SWAP(a, b) do{				\
					typeof(a) tmp;	\
					tmp = a;		\
					a = b;			\
					b = tmp;		\
					}while(0)

#define TEST SWAP(a, b)
/*#define arr(r) */

#define GETLINES(string, buf) do{							\
						printf(string);						\
						fgets(buf, sizeof(buf), stdin);		\
						if (buf[strlen(buf) - 1] == '\n')	\
							buf[strlen(buf) - 1] = '\0';	\
					}while(0) 



void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(void)
{
	int r;
	int a = 1, b = 2;
	char buf[128];
	//求变量类型

	GETLINES("please input string : ", buf);

	printf("buf = %s\n", buf);
	//实现一个结束字符串宏
	printf("a = %d b = %d\n", a, b);
	SWAP(a, b);
	printf("a = %d b = %d\n", a, b);
	typeof(r) t;

	t = 123;

	printf("t = %d\n", t);
	
	printf("MAX = %d\n", MAX(12, 34));
	printf("MAX = %d\n", MAX(42, 34));
	printf("mul = %d\n", MUL(2 + 3, 3));
	printf("please input r : ");
	scanf("%d", &r);

	/*int a[r] = {1,2,3,4,5};*/

	/*printf("sizeof(a) = %d\n", sizeof(a));*/
	printf("AREA = %g\n", AREA(r));


	printf("a = "D"\n", 123);

	PRI("hello!\n");
	printf("user = %s\n", USER);

	/*PI = 4.14;*/
	printf("PI = %g\n", PI * R * R);
	printf("S = %g\n", S);
	return 0;
}
