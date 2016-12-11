#include <iostream>

using namespace std;

class student{
private:
	char *name;
	int age;
	char sex;
	static int num;
protected:
public:
	student(void);
	student(const char *_name , int _age = -1, char _sex = 'N');
	void set_name(const char *_name);
	void set_age(int _age);
	void set_sex(char _sex);
	void set_all(const char *_name, int _age, char _sex);
	void show(void) const;
	student & test(student & stu);
	~student(void);
};

int student::num = 0;

int my_strlen(const char *s)
{
	int i = 0;

	while(s[i] != '\0')
	{
		i++;
	}	
	
	return i;
}

void my_strcpy(char *des, const char *src, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		des[i] = src[i];
	}
	des[i] = '\0';	

}

//这个函数不完整 没考虑 NULl的情况
int my_strcmp(const char *s1, const char *s2)
{
	int i;
	int n1 = 0;
	int n2 = 0;

	while(s1[n1] != '\0')
	{
		n1++;
	}

	while(s2[n2] != '\0')
	{
		n2++;
	}

	if(n1 != n2)
	{
		return -1;
	}

	for (i = 0; i < n1; i++)
	{
		if(s1[i] != s2[i])
		{
			return -1;
		}
	}

	return 0;
}


int main(int argc, char *argv[])
{
	student stu1("xiao ming", 21, 'M');

	stu1.show();

	student stu2;
	stu2.show();

	// stu1.show();
	// stu2.show();

	// cout << "===========" << endl;

	// stu1 = stu1.test(stu1);
	// stu2 = stu2.test(stu2);
	// stu1.show();
	// stu2.show();
	// stu2.set_all("xiao hong", 19, 'F');
	// stu2.show();

	// stu1.set_name("zhang san");
	// stu1.set_age(33);
	// stu1.set_sex('F');
	// stu1.show();
	// if (0 == my_strcmp(argv[1], argv[2]))
	// {
	// 	cout << "same as" << endl;
	// }
	// else
	// {
	// 	cout << "different" << endl;
	// }


	return 0;
}

student::student(void)
{
	name = new char [8];
	
	my_strcpy(name, "no name", 8);

	age = -1;
	sex = 'N';
	num ++;
}

student::student(const char *_name, int _age, char _sex)
{
	int len = my_strlen(_name);

	name = new char [len + 1];

	my_strcpy(name, _name, len);
	age = _age;
	sex = _sex;
	num++;
}

void student::show(void) const
{
	cout << "name = " << name << endl;
	cout << "age = " << age << endl;
	cout << "sex = " << sex << endl;
	cout << "num = " << num << endl;
}

student::~student(void)
{
	delete [] name;
	cout << "~student" << endl;
}

void student::set_name(const char *_name)
{
	int len;

	len = my_strlen(_name) + 1;

	delete [] name;
	name = new char [len];

	my_strcpy(name, _name, len);
}

void student::set_age(int _age)
{
	age = _age;
}

void student::set_sex(char _sex)
{
	sex = _sex;
}


void student::set_all(const char *_name, int _age, char _sex)
{
	int len;
	
	delete [] name;

	name = new char [len + 1];

	len = my_strlen(_name);

	my_strcpy(name, _name, len);
	age = _age;
	sex = _sex;
}

student & student::test(student & stu)
{
	if(0 == my_strcmp(name, "no name") && -1 == age && 'N' == sex)
	{
		cout << "return this " << endl;
		return *this;
	}
	else
	{
		cout << "return stu" << endl;
		return stu;
	}
}
