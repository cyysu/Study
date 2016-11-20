#include <iostream>

using namespace std;

class student{
private:
	char name[128];
	int age;
	char sex;
protected:
public:
	student(void);
	student(const char *_name, int _age = -1, char _sex = 'N');
	void set_all(const char *_name, int _age, char _sex);
	void show(void);
	~student(void);
};

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

int main(void)
{
	student stu1("xiao ming", 21, 'M');
	student stu2;
	
	//stu1.show();
	
	return 0;
}

student::student(void)
{
	cout << "default" << endl;
}

student::student(const char *_name, int _age, char _sex)
{
	my_strcpy(name, _name, my_strlen(_name));
	age = _age;
	sex = _sex;

	cout << "student three" << endl;
}

void student::show(void)
{
	cout << "name = " << name << endl;
	cout << "age = " << age << endl;
	cout << "sex = " << sex << endl;
}

student::~student(void)
{
	cout << "~student" << endl;
}

void student::set_all(const char *_name, int _age, char _sex)
{
	my_strcpy(name, _name, my_strlen(_name));
	age = _age;
	sex = _sex;
}

