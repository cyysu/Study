#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现加法bc

//表示将字符转换成数据
int char_to_int(char ch)
{
	return ch - 48;
}
//将数据转换成字符
char int_to_char(int ch)
{
	return ch + 48;
}
void rever(char s[])
{
	int i;
	int len = strlen(s);

	for (i = 0; i < strlen(s) / 2; i++)
	{
		s[i] ^= s[len - i - 1];
		s[len - i - 1] ^= s[i];
		s[i] ^= s[len - i - 1];
	}
}
int main(void)
{
	int i;
	char s1[1024], s2[1024], s3[1024] = {};
	int len_s1, len_s2, max, min;

	//获取字符串
	printf("please input string1 : ");
	fgets(s1, sizeof(s1), stdin);
	if (s1[strlen(s1) - 1] == '\n')
		s1[strlen(s1) - 1] = '\0';

	printf("please input string2 : ");
	fgets(s2, sizeof(s2), stdin);
	if (s2[strlen(s2) - 1] == '\n')
		s2[strlen(s2) - 1] = '\0';
	
	//求字符串长度,为了循环
	max = strlen(s1) > strlen(s2) ? strlen(s1) : strlen(s2);
	min = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

	//打印相加两个数
	printf("%*s\n", max + 1, s1);
	printf("%*s\n", max + 1, s2);

	//反转
	rever(s1);
	rever(s2);

	//首先按最短长度累加
	for (i = 0; i < min; i++)
	{
		/*s3[i] = int_to_char((char_to_int(s1[i]) + char_to_int(s2[i])) % 10)*/
		s3[i] = ((s1[i] - 48) + (s2[i] - 48) + s3[i]) % 10 + 48;
		s3[i + 1] = ((s1[i] - 48) + (s2[i] - 48)) / 10;
	}

	// char - 48 = int
	//然后累加剩余数据长度
	for (; i < max; i++)
	{
		/*printf("s3 = %d\n", s3[i]);*/
		/*getchar();*/
		//为了保持s3[i]不会发生变量，所以先求进位。
		s3[i + 1] = strlen(s1) > strlen(s2) ? (((s1[i] - 48) + s3[i]) / 10) : (((s2[i] - 48) + s3[i]) / 10);
		s3[i] = strlen(s1) > strlen(s2) ? (((s1[i] - 48) + s3[i]) % 10 + 48) : (((s2[i] - 48) + s3[i]) % 10 + 48);
		
	}
	//判断最后一位数据类型(int)
	if (s3[i] == 1)
	{
		s3[i] = '1';
	}

	rever(s3);
	
	printf("%*s\n", max + 1, s3);
	return 0;
}
