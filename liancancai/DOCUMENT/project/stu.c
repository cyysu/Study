#include "stu.h"


//比较学生帐号
int cmp_acount(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct stu_t *)d2)->acount);
}

//比较学生id
int cmp_stu_id(void *d1, void *d2)
{
	return *((int *)d1) - ((struct stu_t *)d2)->id;
}

//比较学生姓名
int cmp_stu_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct stu_t *)d2)->name);
}

//比较学生年龄
int cmp_stu_age(void *d1, void *d2)
{
	return *((int *)d1) - ((struct stu_t *)d2)->age;
}

//比较学生性别
int cmp_stu_sex(void *d1, void *d2)
{
	return *((char *)d1) - ((struct stu_t *)d2)->sex;
}

//比较老师帐号
int cmp_teach_acount(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct teach_t *)d2)->acount);
}


//比较课程名
int cmp_course_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct course_t *)d2)->name);
}

//比较课程id
int cmp_course_id(void *d1, void *d2)
{
	return *((int *)d1) - ((struct course_t *)d2)->id;
}

//隐藏密码函数
void passwd(char *buf, int size)
{
	int i, ret;
	char s[8];
	system("stty -echo");
	system("stty -icanon");

	fflush(NULL);

	for(i = 0; i < size; i++)
	{
		ret = read(0, s, sizeof(s));
		if(s[0] == 127)
		{
			if(i <= 0)
			{
				i = -1;
				continue;
			}
			else
			{
				i -= 2;
				move_left(1);
				printf(" ");
				move_left(1);
			}
		}
		else
		{
			buf[i] = s[0];
			if(buf[i] == '\n')
			{
				buf[i] = '\0';
				break;
			}
			printf("*");
		}
		fflush(NULL);
		memset(s, 0, sizeof(s));
	}
	system("stty echo");
	system("stty icanon");
	printf("\n");
	
}

//管理员登录判断及帐号密码初始化
int root_login(char *acount, char *passwd)
{
	struct root_t root = {"000000", "000000"};
	if(strcmp(acount, root.acount) == 0 && strcmp(passwd, root.passwd) == 0)
		return 1;
	return 0;
}

//注册帐号
int stu_create(LLIST *handle)
{
	system("stty echo icanon");
	char buf1[40], buf2[40];
	struct stu_t stu;
	int i, total;

	
	GETLINES("请输入帐号 :", stu.acount);
	if(llist_ind(stu.acount, cmp_acount, handle) != NULL)
	{
		printf("帐号已存在 !\n");
		system("stty -echo -icanon");
		return 0;
	}

	printf("请输入你的密码 :");
	passwd(buf1, sizeof(buf1));
	
	printf("请再次输入你的密码 :");
	passwd(buf2, sizeof(buf2));

	if(strcmp(buf1, buf2) == 0)
		strcpy(stu.passwd, buf1);
	else
	{
		printf("两次输入不一致 !\n");
		system("stty -echo -icanon");
		return 0;
	}

	GETLINES("请输入你的姓名 :", stu.name);

	printf("请输入你的年龄 :");
	scanf("%d", &stu.age);
	getchar();

	printf("请输入你的性别(M/F) :");
	scanf("%c", &stu.sex);

	getchar();

	stu.id = 10001 + handle->num;

	stu.en = -1;
	stu.cn = -1;

	stu.flag = 0;

	memset(stu.course, -1, sizeof(stu.course));
	for(i = 0; i < sizeof(stu.grade) / sizeof(double); i++)
	{
		stu.grade[i] = -1;
	}
	
	llist_append(&stu, handle);

	system("stty -echo -icanon");
	return 1;
}

//登录帐号 成功返回 1 失败返回 0
int stu_login(char *acount, char *passwd, LLIST *handle)
{
	if(llist_ind(acount, cmp_acount, handle) != NULL && strcmp(((struct stu_t *)llist_ind(acount, cmp_acount, handle))->passwd , passwd) == 0)
		return 1;
	else
		return 0;

}

//添加课程
void course_add(LLIST *handle)
{
	system("stty echo icanon");
	struct course_t course;

	GETLINES("请输入课程名 :", course.name);
	if(llist_ind(course.name, cmp_course_name, handle) != NULL)
	{
		printf("课程已存在 !\n");
		system("stty -echo -icanon");
		return ;
	}
	course.id = 1 + handle->num;

	llist_append(&course, handle);
	system("stty -echo -icanon");
}

//打印课程
void course_ls(void *data)
{
	struct course_t *course = (struct course_t *)data;
	printf("id = %-4d课程名 = %s\n", course->id, course->name);
}

//打印全部课程
void course_ls_all(LLIST *handle)
{
	llist_travel(handle, course_ls, 0);
}

//选择课程
int choose_course(char *acount, LLIST *stu_handle, LLIST *course_handle)
{
	system("stty echo icanon");
	int id;
	printf("请输入课程id :");
	scanf("%d", &id);
	getchar();
	
	if(llist_ind(&id, cmp_course_id, course_handle) != NULL)
	{
		((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->course[id] = id;
		((struct course_t *)llist_ind(&id, cmp_course_id, course_handle))->people++;
		system("stty -echo -icanon");
		return 1;
	}
	else
	{
		printf("id 不存在\n");
		system("stty -echo -icanon");
		return 0;
	}
}

//打印必修课程及成绩
void stu_cls(char *acount, LLIST *stu_handle)
{
	int i;
	struct stu_t *stu = (struct stu_t *)llist_ind(acount, cmp_acount, stu_handle);
	printf("语文成绩 :%.2lf\n", stu->cn);
	printf("英语成绩 :%.2lf\n", stu->en);
    /*
	 *for(i = 0; i < sizeof(((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->course) / sizeof(int); i++)
	 *{
	 *    if(((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->course[i] != -1)
	 *    {
	 *        printf("%s成绩 :%.2lf\n", ((struct course_t *)llist_ind(&i, cmp_course_id, course_handle))->name, ((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->grade[i]);
	 *    }
	 *}
	 *printf("\n");
     */
}

//打印选修课的成绩
void stu_ls_course(char *acount, LLIST *stu_handle, LLIST *course_handle)
{
	int i;
	for(i = 0; i < sizeof(((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->course) / sizeof(int); i++)
	{
		if(((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->course[i] != -1)
		{
			printf("%s成绩 :%.2lf\n", ((struct course_t *)llist_ind(&i, cmp_course_id, course_handle))->name, ((struct stu_t *)llist_ind(acount, cmp_acount, stu_handle))->grade[i]);
		}
	}
}

//打印个人信息
void stu_pls(char *acount, LLIST *handle)
{
	struct stu_t *stu = (struct stu_t *)llist_ind(acount, cmp_acount, handle);
	printf("姓名 :%s\n", stu->name);
	printf("学号 :%d\n", stu->id);
	printf("年龄 :%d\n", stu->age);
	printf("性别 :%c\n", stu->sex);
}

//修改个人信息 flag 1.姓名 2.年龄 3.性别 4.密码 成功返回 1 失败打印密码错误并返回 0
int stu_mod(char *acount, int flag, LLIST *handle)
{
	system("stty echo icanon");
	char name[128], prev[40], new[40];
	int age;
	char sex;

	if(llist_ind(acount, cmp_acount, handle) == NULL)
	{
		printf("帐号不存在 !\n");
		system("stty -echo -icanon");
		return 0;
	}

	else
	{
		if(flag == 1)
		{
			GETLINES("请输入修改姓名 :", name);
			strcpy(((struct stu_t *)llist_ind(acount, cmp_acount, handle))->name, name);
			printf("修改成功\n");
		}

		if(flag == 2)
		{
			printf("请输入修改年龄 :");
			scanf("%d", &age);
			((struct stu_t *)llist_ind(acount, cmp_acount, handle))->age = age;
			printf("修改成功\n");
		}

		if(flag == 3)
		{
			printf("请输入修改性别 :");
			scanf("%c", &sex);
			((struct stu_t *)llist_ind(acount, cmp_acount, handle))->sex = sex;
			printf("修改成功\n");
		}

		if(flag == 4)
		{
			printf("请输入你的密码 :");
			passwd(prev, sizeof(prev));
			if(strcmp(((struct stu_t *)llist_ind(acount, cmp_acount, handle))->passwd, prev) != 0)
			{
				printf("密码错误 !\n");
				system("stty -echo -icanon");
				return 0;
			}
			else
			{
				printf("请输入你的新密码 :");
				passwd(new, sizeof(new));
		
				strcpy(((struct stu_t *)llist_ind(acount, cmp_acount, handle))->passwd, new);
				printf("修改成功\n");
			}

		}
		if(flag == 5)
		{
			printf("请输入你的新密码 :");
			passwd(new, sizeof(new));
	
			strcpy(((struct stu_t *)llist_ind(acount, cmp_acount, handle))->passwd, new);
			printf("修改成功\n");
		}
	}
	system("stty -echo -icanon");
	return 1;	
}

//储存学生表
void stu_store(LLIST *handle)
{
	llist_store("stu.db", handle);
}

//加载学生表
LLIST *stu_load(void)
{
	return llist_load("stu.db");
}

//储存课程表
void course_store(LLIST *handle)
{
	llist_store("course.db", handle);
}

//加载课程表
LLIST *course_load(void)
{
	return llist_load("course.db");
}

/*
 *void init(void)
 *{
 *    LLIST *stu_handle = NULL;
 *    LLIST *course_handle = NULL;
 *
 *    course_handle = llist_create(sizeof(struct course_t));
 *
 *    stu_handle = llist_create(sizeof(struct stu_t));
 *}
 */
/*
 *
 *int main(void)
 *{
 *    char buf[40];
 *    LLIST *stu_handle = NULL;
 *    LLIST *course_handle = NULL;
 *    
 *    course_handle = llist_create(sizeof(struct course_t));
 *
 *    stu_handle = llist_create(sizeof(struct stu_t));
 *
 *    while(1)
 *    {
 *        course_add(course_handle);
 *        course_ls_all(course_handle);
 *    }
 *    stu_create(stu_handle);
 *    
 *    stu_cls("123", stu_handle, course_handle);
 *    stu_pls("123", stu_handle);
 *    
 *    stu_mod("123", 4, stu_handle);
 *
 *}
 */

//创建老师帐号和密码
int teach_add(LLIST *handle)
{
	system("stty echo icanon");
	struct teach_t teach = {};
	GETLINES("请输入帐号 :", teach.acount);
	if(llist_ind(teach.acount, cmp_teach_acount, handle) != NULL)
	{
		printf("帐号已存在 !\n");
		system("stty -echo -icanon");
		return 0;
	}
	strcpy(teach.passwd, "000000");
	

	llist_append(&teach, handle);	

	system("stty -echo -icanon");
	return 1;
}

//老师登录判断
int teach_login(char *acount, char *passwd, LLIST *handle)
{
	if(llist_ind(acount, cmp_teach_acount, handle) != NULL && strcmp(((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->passwd , passwd) == 0)
		return 1;
	else
		return 0;
}

//老师查看个人信息
void teach_pls(char *acount, LLIST *handle)
{
	struct teach_t *teach = (struct teach_t *)llist_ind(acount, cmp_teach_acount, handle);
	printf("姓名 :%s\n", teach->name);
	printf("性别 :%c\n", teach->sex);
}

//打印老师结构体函数
void ls_teach(void *data)
{
	struct teach_t *teach = (struct teach_t *)data;
	printf("帐号 :%-8s姓名 :%-8ssex :%-3c\n", teach->acount, teach->name, teach->sex);
}

//查看所有老师信息
void ls_all_teach(LLIST *handle)
{
	/*printf("%s\n", "ksjafk");*/
	llist_travel(handle, ls_teach, 0);	
}

//老师修改个人信息
int teach_mod(char *acount, int flag, LLIST *handle)
{
	system("stty echo icanon");
	char name[128], prev[40], new[40];
	int age;
	char sex;

	if(llist_ind(acount, cmp_teach_acount, handle) == NULL)
	{
		printf("帐号不存在 !\n");
		system("stty -echo -icanon");
		return 0;
	}

	else
	{
		if(flag == 1)
		{
			GETLINES("请输入修改姓名 :", name);
			strcpy(((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->name, name);
			printf("修改成功\n");
		}

	/*
	 *    if(flag == 2)
	 *    {
	 *        printf("请输入修改年龄 :");
	 *        scanf("%d", &age);
	 *        ((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->age = age;
	 *        printf("修改成功\n");
	 *    }
	 *
	 */
		if(flag == 3)
		{
			printf("请输入修改性别(M/F) :");
			scanf("%c", &sex);
			((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->sex = sex;
			printf("修改成功\n");
		}

		if(flag == 4)
		{
			printf("请输入你的密码 :");
			passwd(prev, sizeof(prev));
			if(strcmp(((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->passwd, prev) != 0)
			{
				printf("密码错误 !\n");
				system("stty -echo -icanon");
				return 0;
			}
			else
			{
				printf("请输入你的新密码 :");
				passwd(new, sizeof(new));
		
				strcpy(((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->passwd, new);
				printf("修改成功\n");
			}

		}
		if(flag == 5)
		{
			printf("请输入你的新密码 :");
			passwd(new, sizeof(new));
	
			strcpy(((struct teach_t *)llist_ind(acount, cmp_teach_acount, handle))->passwd, new);
			printf("修改成功\n");
		}
	}
	system("stty -echo -icanon");
	return 1;	
}

//打印单个学生所有信息
void ls_stu(void *data)
{
	struct stu_t *stu = (struct stu_t *)data;
	if(stu->flag == 0)
		printf("姓名 :%-8sid :%-7dage :%-5dsex :%-3c\n", stu->name, stu->id, stu->age, stu->sex);
}

void ls_stu1(void *data)
{
	struct stu_t *stu = (struct stu_t *)data;
	printf("姓名 :%-8sid :%-7dage :%-5dsex :%-3c\n", stu->name, stu->id, stu->age, stu->sex);
}

//查看所有学生信息(不能看到移除学生)
void ls_all_stu(LLIST *handle)
{
	/*printf("%s\n", "ksjafk");*/
	llist_travel(handle, ls_stu, 0);	
}

//查看所有学生信息(能看到移除学生)
void ls_all_stu1(LLIST *handle)
{
	/*printf("%s\n", "ksjafk");*/
	llist_travel(handle, ls_stu1, 0);	
}

//老师修改学生信息
int mod_stu(LLIST *handle, int flag)
{
	system("stty echo icanon");

	int id;
	char name[128];
	int age;
	char sex;

	printf("请输入学生的id :");
	scanf("%d", &id);
	getchar();
	if(llist_ind(&id, cmp_stu_id, handle) == NULL || ((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->flag != 0)
	{
		printf("id不存在\n");
		system("stty -echo -icanon");
		return 0;
	}
	else
	{
		ls_stu(llist_ind(&id, cmp_stu_id, handle));	
		if(flag == 1)
		{
			GETLINES("请输入修改姓名 :", name);
			strcpy(((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->name, name);
		}

		if(flag == 2)
		{
			printf("请输入修改年龄 :");
			scanf("%d", &age);
			((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->age = age;
		}

		if(flag == 3)
		{
			printf("请输入修改性别 :");
			scanf("%c", &sex);
			((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->sex = sex;
		}
	}
	system("stty -echo -icanon");
	return 1;
}

//查找学生 1.id 2.name 3.age 4.sex
void find_stu(LLIST *handle, int flag)
{
	system("stty echo icanon");
	int id, age;
	char name[128], sex;	

	if(flag == 1)
	{
		printf("请输入id :");
		scanf("%d", &id);
		getchar();
		ls_all_stu(llist_find(&id, cmp_stu_id, handle));
	}
	if(flag == 2)
	{
		GETLINES("请输入学生姓名 :", name);
		ls_all_stu(llist_find(name, cmp_stu_name, handle));
	}
	if(flag == 3)
	{
		printf("请输入age :");
		scanf("%d", &age);
		getchar();
		ls_all_stu(llist_find(&age, cmp_stu_age, handle));
	}
	if(flag == 4)
	{
		printf("请输入sex :");
		scanf("%c", &sex);
		getchar();
		ls_all_stu(llist_find(&sex, cmp_stu_sex, handle));
	}
	system("stty -echo -icanon");
}

//移除学生信息
int move_stu(LLIST *handle)
{
	system("stty echo icanon");

	int id;

	printf("请输入学生的id :");
	scanf("%d", &id);
	getchar();
	if(llist_ind(&id, cmp_stu_id, handle) == NULL ||  ((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->flag != 0)
	{
		system("stty -echo -icanon");
		return 0;
	}
	else
	{
		((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->flag = 1;
	}

	system("stty -echo -icanon");
	return 1;
}

//储存老师表
void teach_store(LLIST *handle)
{
	llist_store("teach.db", handle);
}

//加载老师表
LLIST *teach_load(void)
{
	return llist_load("teach.db");
}

//删除老师帐号
void del_teach(LLIST *handle)
{
	system("stty echo icanon");
	char acount[40];
	GETLINES("请输入老师帐号 :", acount);
	if(llist_ind(acount, cmp_teach_acount, handle) == NULL)
	{
		printf("帐号不存在 !\n");
		system("stty -echo -icanon");
		return ;
	}
	else
	{
		llist_del(acount, cmp_teach_acount, handle);
		printf("删除成功\n");
	}
	system("stty -echo -icanon");
}

//删除学生帐号
void del_stu(LLIST *handle)
{
	system("stty echo icanon");
	int id;
	printf("请输入学生的id :");
	scanf("%d", &id);
	getchar();
	if(llist_ind(&id, cmp_stu_id, handle) == NULL)
	{
		printf("id不存在 !\n");
		system("stty -echo -icanon");
		return ;
	}
	else
	{
		llist_del(&id, cmp_stu_id, handle);
		printf("删除成功\n");
	}
	system("stty -echo -icanon");
}

//修改必修成绩
void mod_comp(LLIST *handle)
{
	system("stty echo icanon");
	int id;
	double cn, en;

	printf("请输入学生的id :");
	scanf("%d", &id);
	getchar();
	if(llist_ind(&id, cmp_stu_id, handle) == NULL || ((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->flag != 0)
	{
		printf("id不存在\n");
		system("stty -echo -icanon");
		return ;
	}
	else
	{
		printf("语文成绩 :");
		scanf("%lf", &cn);
		getchar();
		((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->cn = cn;
		printf("修改成功\n");

		printf("英语成绩 :");
		scanf("%lf", &en);
		getchar();
		((struct stu_t *)llist_ind(&id, cmp_stu_id, handle))->en = en;
		printf("修改成功\n");
	}
	system("stty -echo -icanon");
}

void mod_elec(LLIST *course_handle, LLIST *stu_handle)
{
	system("stty echo icanon");
	int id, i, total = 0;

	printf("请输入学生的id :");
	scanf("%d", &id);
	getchar();
	if(llist_ind(&id, cmp_stu_id, stu_handle) == NULL || ((struct stu_t *)llist_ind(&id, cmp_stu_id, stu_handle))->flag != 0)
	{
		printf("id不存在\n");
		system("stty -echo -icanon");
		return ;
	}
	else
	{
		for(i = 0; i < sizeof(((struct stu_t *)llist_ind(&id, cmp_acount, stu_handle))->course) / sizeof(int); i++)
		{
			if(((struct stu_t *)llist_ind(&id, cmp_stu_id, stu_handle))->course[i] != -1)
			{
				printf("%s成绩 :", ((struct course_t *)llist_ind(&i, cmp_course_id, course_handle))->name);
				scanf("%lf", &((struct stu_t *)llist_ind(&id, cmp_stu_id, stu_handle))->grade[i]);
				getchar();
				printf("修改成功\n");
				total++;
			}
		}
		if(total == 0)
		{
			printf("没有选课\n");
			total = 0;
		}
	}
	system("stty -echo -icanon");
}

//打印学生的信息和所有课程成绩
void grad_ls(LLIST *stu_handle, LLIST *course_handle)
{
	int i;
	struct node_t *tail = NULL;
	struct stu_t *stu = NULL;

	for(tail = stu_handle->head.next; tail != &stu_handle->head; tail = tail->next)
	{
		stu = (struct stu_t *)tail->data;
		if(stu->flag == 0)
		{
			printf("id :%-7d姓名 :%-7sage :%-5dsex :%-3c语文成绩 :%-6.2lf英语成绩 :%-6.2lf", stu->id, stu->name, stu->age, stu->sex, stu->cn, stu->en);

			 for(i = 0; i < sizeof(stu->course) / sizeof(int); i++)
			 {
				 if(stu->course[i] != -1)
				 {
					 printf("%s成绩 :%-6.2lf", ((struct course_t *)llist_ind(&i, cmp_course_id, course_handle))->name, stu->grade[i]);
				 }
			 }
			 printf("\n");
		}
	}
}

//打印学生的信息和必修课程成绩
void grad_comp_ls(LLIST *stu_handle)
{
	struct node_t *tail = NULL;
	struct stu_t *stu = NULL;

	for(tail = stu_handle->head.next; tail != &stu_handle->head; tail = tail->next)
	{
		stu = (struct stu_t *)tail->data;
		if(stu->flag == 0)
		{
			printf("id :%-7d姓名 :%-7sage :%-5dsex :%-3c语文成绩 :%-6.2lf英语成绩 :%-6.2lf", stu->id, stu->name, stu->age, stu->sex, stu->cn, stu->en);
			 printf("\n");
		}
	}
}

//打印学生的信息和选修课程成绩
void grad_elec_ls(LLIST *stu_handle, LLIST *course_handle)
{
	int i, total = 0;
	struct node_t *tail = NULL;
	struct stu_t *stu = NULL;

	for(tail = stu_handle->head.next; tail != &stu_handle->head; tail = tail->next)
	{
		stu = (struct stu_t *)tail->data;
		if(stu->flag == 0)
		{
			for(i = 0; i < sizeof(stu->course) / sizeof(int); i++)
			{
				if(stu->course[i] != -1)
				{
					total++;
				}
			}
			if(total != 0)
			{
				printf("id :%-7d姓名 :%-7sage :%-5dsex :%-3c", stu->id, stu->name, stu->age, stu->sex);
				total = 0;
				for(i = 0; i < sizeof(stu->course) / sizeof(int); i++)
				{
					if(stu->course[i] != -1)
					{
						printf("%s成绩 :%-6.2lf", ((struct course_t *)llist_ind(&i, cmp_course_id, course_handle))->name, stu->grade[i]);
					}
				}
				printf("\n");
			}
		}
	}
}

