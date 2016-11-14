#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	double cn;
	double en;
};

//int -> user -> save -> malloc count -> printf -> free
int main(void)
{
	int i;
	int count = 0;
	struct cls_t cls;//临时接受用户输入
	struct cls_t *new = NULL;//用来存储用户数据所有数据
	struct cls_t *prev = NULL;//用来保存原来数据

	//表示接受用户数据
	while(1)
	{
		printf("please input %d name : ", count + 1);
		fgets(cls.name, sizeof(cls.name), stdin);
		if (cls.name[strlen(cls.name) - 1] == '\n')
			cls.name[strlen(cls.name) - 1] = '\0';

		//退出条件
		if (strcmp(cls.name, "exit") == 0)
		{
			break;
		}

		printf("please input %d id : ", count + 1);
		scanf("%d", &cls.id);
		if (cls.id == -1)
		{
			break;
		}
		printf("please input %d age : ", count + 1);
		scanf("%d", &cls.age);
		getchar();
		printf("please input %d sex : ", count + 1);
		scanf("%c", &cls.sex);
		printf("please input %d cn : ", count + 1);
		scanf("%lf", &cls.cn);
		printf("please input %d en : ", count + 1);
		scanf("%lf", &cls.en);
		getchar();

		new = insert(cls, new, &count);

		//申请数据空间
/*
 *        new = (struct cls_t *)malloc(sizeof(struct cls_t) * (count + 1));
 *        if (NULL == new)
 *        {
 *            printf("malloc failed!\n");
 *            return -1;
 *        }
 *
 *        //添加数据到空间地址中
 *        memcpy(new, prev, sizeof(struct cls_t) * count);
 *        free(prev);
 *        new[count] = cls;
 *        prev = new;
 *
 *        count++;
 */
	}

	for (i = 0; i < count; i++)
	{
		printf("name : %s | id : %d | age : %d | sex : %c | cn : %.2f | en : %.2f\n", new[i].name, new[i].id, new[i].age, new[i].sex, new[i].cn, new[i].en);
	}

	free(new);
	return 0;
}
