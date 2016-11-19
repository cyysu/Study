#ifndef __STU_H__
#define __STU_H__


#include "llist.h"
#include "vt.h"

struct stu_t{
	char name[128];
	int id;
	int age;
	char sex;
	int course[40];
	char acount[40];
	char passwd[40];
	double en;
	double cn;
	double grade[40];
	int flag;
};

struct course_t{
	char name[128];
	int id;
	int people;
};

struct teach_t{
	char name[128];
	char sex;
	char acount[40];
	char passwd[40];
};

struct root_t{
	char acount[40];
	char passwd[40];
};

//void init(void);
//隐藏密码输入
void passwd(char *buf, int size);

//管理员登录判断及帐号密码初始化
int root_login(char *acount, char *passwd);

//注册学生帐号
int stu_create(LLIST *handle);

//学生登录判断
int stu_login(char *acount, char *passwd, LLIST *handle);

//添加课程
void course_add(LLIST *handle);

//打印全部选修课程
void course_ls_all(LLIST *handle);

//选课
int choose_course(char *acount, LLIST *stu_handle, LLIST *course_handle);

//打印学生选的课程和成绩
void stu_ls_course(char *acount, LLIST *stu_handle, LLIST *course_handle);

//打印学生必修课程和成绩
void stu_cls(char *acount, LLIST *stu_handle);

//打印学生个人信息
void stu_pls(char *acount, LLIST *handle);

//储存学生表
void stu_store(LLIST *handle);

//加载学生表
LLIST *stu_load(void);

//修改学生基本信息和密码
int stu_mod(char *acount, int flag, LLIST *handle);

//储存课程表
void course_store(LLIST *handle);

//加载课程表
LLIST *course_load(void);

//添加老师帐号
int teach_add(LLIST *handle);

//老师登录帐号密码判断
int teach_login(char *acount, char *passwd, LLIST *handle);

//老师查看个人信息
void teach_pls(char *acount, LLIST *handle);

//打印所有老师信息
void ls_all_teach(LLIST *handle);

//老师修改个人信息
int teach_mod(char *acount, int flag, LLIST *handle);

//查看所有学生信息(不能看到移除学生)
void ls_all_stu(LLIST *handle);

//查看所有学生信息(能看到移除学生)
void ls_all_stu1(LLIST *handle);

//老师修改学生信息
int mod_stu(LLIST *handle, int flag);

//查找学生信息
void find_stu(LLIST *handle, int flag);

//老师移除学生信息
int move_stu(LLIST *handle);

//储存老师表
void teach_store(LLIST *handle);

//加载老师表
LLIST *teach_load(void);

//删除老师帐号
void del_teach(LLIST *handle);

//删除学生帐号
void del_stu(LLIST *handle);

//修改必修成绩
void mod_comp(LLIST *handle);

//修改选修成绩
void mod_elec(LLIST *course_handle, LLIST *stu_handle);

//打印所有学生所有课程的成绩
void grad_ls(LLIST *stu_handle, LLIST *course_handle);

//打印所有学生必修课程的成绩
void grad_comp_ls(LLIST *stu_handle);

//打印所有学生所有课程的成绩
void grad_elec_ls(LLIST *stu_handle, LLIST *course_handle);

#endif
