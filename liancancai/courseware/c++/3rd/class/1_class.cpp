#include <iostream>

using namespace std;

//string  str str. -> append()
//定义cls_t的一个类
class cls_t{
	//属性
	private:
		char name[128];
	protected:
		int age;
		int id;
	public:
		char sex;
		double result;
	//方法
	public:
		//定义显示方法
		void show_name(void);
		void set_name(char *m_name);
};

int main(void)
{
	cls_t cls;//cls表示类的一个对象

	cls.sex = 'M'; 
	cls.set_name("jim");
	cls.show_name();

    /*
	 *cout << "age : " << cls.age << endl;
	 *cout << "id : " << cls.id << endl;
     */
	cout << "sex : " << cls.sex << endl;
	cout << "result : " << cls.result << endl;
	return 0;
}

//实现类方法
void cls_t::show_name(void)
{
	cout << "name : " << name << endl;

}

void cls_t::set_name(char * m_name)
{
	strcpy(name, m_name);
}
