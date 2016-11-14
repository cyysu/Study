#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char buf[5];
	int a = 1;

	float f = 212.34345;

	printf("hello;ldslksajlfdlksahf	\
	dkashfjgfjsadhfjdfhj\n");
	printf("kldsfhahfhdkslfhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhjdshfkjsahfkdsjfhf\n");
	printf("test"
	"hello\n");
    /*
	 *printf("f = %#-10.2f#\n", f);
	 *printf("==========\n");
	 *printf("%*s\n", 15, "hello");
	 *printf("%*s\n", 15, "helloworld");
	 *printf("==========\n");
	 *printf("%s\n", "hello");
	 *printf("%s\n", "helloworld");
     */
	printf("==============\n");
	printf("#%*d#\n", -15, 1);
	printf("#%-10d#\n", 12);
	printf("#%-10d#\n", 123);
	printf("#%-10d#\n", 1234);
	printf("#%-10d#\n", 12345);
	printf("==============\n");

	/*fclose(stdout);//关闭标准输出*/
	/*fclose(stderr);*/
	printf("hello!\n");//默认标准输出
	fprintf(stdout, "world!\n");//指定输出到标准输出
	fprintf(stderr, "error!\n");//指定输出到错误输出
	printf("buf = %s\n", buf);
	/*sprintf(buf, "helloworld!!");*/
	snprintf(buf,sizeof(buf), "helloworld!!!!");
	printf("buf = %s\n", buf);

	return 0;
}
