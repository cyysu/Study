#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class student{
	private:
		char *name;
		int age;
	public:
		student(void);
		student(const char *m_name, int m_age);
		void show(void);
		void set_name(const char *m_name);
		void set_age(int m_age);
		int get_size(void);
		~student(void);
};


int main(void)
{
	student stu("tom", 20);
	student *p = NULL;
	student cls[10];
	int i ;
	char buf [128];
	int age;

	p = new student;
	if (p == NULL)
	{
		return -1;
	}

	//p("jim", 20);

	p->set_name("刘德华");
	p->show();

	delete p;

	for (i = 0; i < 10; i ++)
	{
		memset(buf, 0, sizeof(buf));

		snprintf(buf, sizeof(buf), "Stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls[i].set_name(buf);
		
		age = rand() % 5 + 18;
		cls[i].set_age(age);
	}
	for (i = 0; i < 10; i++)
	{
		cls[i].show();
	}
    /*
	 *cout << "len = " << stu.get_size() << endl;
	 *stu.set_name("zhangsan");
	 *cout << "len = " << stu.get_size() << endl;
	 *stu.show();
     */
	return 0;
}

student::student(void)
{
	name = new char [7];
	strcpy(name, "noname");
	//memset(name, 0, sizeof(name));
	age = -1;
}
student::student(const char *m_name, int m_age)
{
	int len = strlen(m_name);
	name = new char [len + 1];
	if (name == NULL)
	{
		printf("new failed!\n");
		return;
	}
	strcpy(name, m_name);
	age = m_age;
}

student::~student(void)
{
	delete [] name;
	age = -1;
	name = NULL;
}

void student::show(void)
{
	cout << "name : " << name << "  age : " << age << endl;
}

void student::set_name(const char *m_name)
{
	delete [] name;
	int len = strlen(m_name);

	name = new char [len + 1];
	strcpy(name, m_name);

}

void student::set_age(int m_age)
{
	age = m_age;
}

int student::get_size(void)
{
	int len = strlen(name);

	return len;
}
