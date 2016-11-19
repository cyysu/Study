#include <iostream>

using namespace std;

class student{
	private:
		char *name;
		int age;
		static int num;
	public:
		student(void);
		student(char *m_name, int m_age);
		void show(void)const;
		student & test(student & cls);
		void init(char *name, int age);
		void set_name(char *m_name);
		void set_age(int m_age);
		int get_size(void);
		static void temp(void);
		static int count(void){return num;};
		~student(void);
};

int student::num = 0;


int main(void)
{
	student stu;
	student stu1;

	stu.show();

	cout << "count = " << student::count() << endl; 

	student::temp();
	return 0;
}
void student::temp(void)
{
	cout << "age : " << age << endl;
}
void student::init(char *name, int age)
{
	int len = strlen(name);
	this->name = new char [len + 1];
	if (this->name == NULL)
	{
		printf("new failed!\n");
		return;
	}
	strcpy(this->name, name);
	this->age = age;

}
student & student::test(student & cls)
{
	//cls.age = 10;
	//cout << "name : " << name << " age : " << age << endl;

	if (strcmp(cls.name, "noname") == 0 && cls.age == -1)
	{
		return *this;
	}
	else
	{
		return cls;
	}
}
student::student(void)
{
	name = new char [7];
	strcpy(name, "noname");
	//memset(name, 0, sizeof(name));
	age = -1;
	num += 1;
}
student::student(char *m_name, int m_age)
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
	num += 1;
}

student::~student(void)
{
	delete [] name;
	age = -1;
	name = NULL;
	num--;
}

void student::show(void)const
{
	//strcpy(name, "he");
	cout << "name : " << name << "  age : " << age << endl;
	cout << "num = " << num << endl;
}

void student::set_name(char *m_name)
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

