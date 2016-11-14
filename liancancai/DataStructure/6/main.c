#include "select_course_simple.h"


struct course_t{
	int id;       //课程编号
	char name[30]; //课程名称
	int people;     //选该门课程的人数
};

struct student_t{
	char name[30];			//学生名
	int course_id[20];		//所选课程id
	int id;					//学号
	char sex;				//性别
};

int main(void)
{

	return 0;
}
