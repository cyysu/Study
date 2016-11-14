#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表节点信息
struct node_t{
	int data;//数据域 保存用户数据输入
	struct node_t *next;//指针域 保存下一个节点地址
};

struct node_t b = {20, NULL};

int main(void)
{
	//局部变量 -> 栈 -> 由高到底
	struct node_t a = {1, NULL};
	struct node_t d = {40, NULL};
	struct node_t c = {30, NULL};

    /*
	 *int a = 1, d = 40, b = 20, c = 30;
	 *int * = 
     */

	a.next = &b;
	b.next = &c;

	printf("a -> b = %d\n", a.next->data);
	printf("a -> c = %d\n", a.next->next->data);

	// a -> b
    /*
	 *printf("a = %d : %p\n", a, &a);
	 *printf("d = %d : %p\n", d, &d);
	 *printf("a -> b = %d\n", *(&a - 1));
	 *printf("b = %d : %p\n", b, &b);
	 *printf("c = %d : %p\n", c, &c);
     */
	return 0;
}
