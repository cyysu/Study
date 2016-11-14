#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义一个结构体类型
struct op_t{
	char ch;//表示操作符
	int (*func)(int,int);//操作符对应函数指针
};

// + -> add
int add(int a, int b)
{
	return a + b;
}
// - -> sub
int sub(int a, int b)
{
	return a - b;
}
// * -> mul
int mul(int a, int b)
{
	return a * b;
}
int div_(int a, int b)
{
	return a / b;
}
int mod(int a, int b)
{
	return a % b;
}
int pol(int a, int b)
{
	int c = 1;
	while(b--)
	{
		c *= a;
	}
	return c;
}
// + -> add
// - -> sub
int main(void)
{
	int i, j;
	//定义一个结构体数组，用于保存所有的运算组合
	struct op_t op[6] = {{'+', add},
						 {'-', sub},
						 {'*', mul},
						 {'/', div_},
						 {'%', mod},
						 {'^', pol}};

	//第一层循环求5和3结果值
	for (i = 0; i < 6; i++)
	{
		/*printf("ret = %c : %d\n", op[i].ch, op[i].func(5, 3));*/
		for (j = 0; j < 6; j++)
		{
			if (op[j].func(op[i].func(5, 3), 2) == 4)
			{
				printf("5 %c 3 %c 2 = 4\n", op[i].ch, op[j].ch);
			}
		}
	}
	return 0;
}
