#include <iostream>

using namespace std;

struct cls_t{
	string name;
	int age;
	char sex;
	double result;
};

void show(cls_t cls)
{
	cout << "name : " << cls.name 
		<< "| age : " << cls.age
		<< "| sex : " << cls.sex
		<< "| result : " << cls.result << endl;
}
void show(string name)
{
	cout << "name : " << name << endl;
}

void show(string name, int age, char sex)
{
	cout << "name age sex" << endl;
}
void show(string name, char sex, int age)
{
	cout << "name sex age" << endl;
}
int main(void)
{
	cls_t cls = {"tom", 20, 'M', 88.79};

	show("jim", 18, 'F');
	show("mary", 'M', 20);
    /*
	 *show(cls);
	 *show(cls.name);
     */
	return 0;
}
