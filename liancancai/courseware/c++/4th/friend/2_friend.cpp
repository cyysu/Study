#include <iostream>

using namespace std;

class Time{
	private:
		int hours;
		int minutes;
	public:
		Time(void);
		Time(int h, int m);
		void reset(int h = 0, int m = 0){hours = h;minutes = m;};
		void addhours(int h);
		void addminutes(int m);
		Time sum(Time & t1, Time & t2);
		Time operator+(const Time t);//重载加法运算符
		Time operator-(const Time & t);
		Time operator*(const double mul);
		Time operator*(Time & t1);//友元
		friend Time operator*(double mul, Time & t);//友元
		//friend Time operator*(Time & t1, Time & t2);//友元
		friend void test(void);//友元函数
		void display(void);
		void show(void) const;
		~Time(void);
};

Time operator*(double mul, Time & t)
{
	Time temp;
	double m;
	
	cout << "world" << endl;
	m = (t.hours * 60 + t.minutes) * mul;

	temp.hours = (int) m / 60;
	temp.minutes = (int) m % 60;
	
	return temp;
	
}
/*
 *Time operator*(Time & t1, Time & t2)
 *{
 *    Time temp;
 *
 *    cout << "test" << endl;
 *    
 *    return temp;
 *    
 *}
 */
//外部函数
void test(void)
{
	Time t;

	cout << "test" << endl;
	cout << "hours :" << t.hours << endl;
}

//类的方法
void Time::display(void)
{
	Time t;

	cout << "siaplay" << endl;
	cout << "hours :" << t.hours << endl;

}

int main(void)
{
	Time a;
	Time t1(3, 50), t2(4, 20);

	//time * num => hello
	//num * time => world
	//time * time => test
	a = t1 * t2 * t1 * 12 * 2 * t1;//友元
	//a = t1 * 1.5;//方法
	a.show();

	return 0;
}


Time Time::operator*(Time & t)
{
	
	Time temp;
	cout << "*******" << endl;
	
	return temp;
}
Time Time::operator*(const double mul)
{
	Time temp;
	double m;
	
	cout << "hello" << endl;
	m = (this->hours * 60 + this->minutes) * mul;

	temp.hours = (int) m / 60;
	temp.minutes = (int) m % 60;
	
	return temp;
}
Time Time::operator-(const Time & t)
{
	Time temp;
	int h1, h2;

	h1 = this->hours * 60 + this->minutes;
	h2 = t.hours * 60 + t.minutes;

	temp.hours = (h1 - h2) / 60;
	temp.minutes = (h1 - h2) % 60;

	return temp;
}

Time Time::operator+(const Time  t)
{
	Time temp;//局部变量，可以返回变量值

	cout << "this->hours : " << this->hours << endl;
	cout << "t.hours : " << t.hours << endl;
	printf("========\n");
	int min;
	min = this->minutes + t.minutes;
	
	temp.hours = this->hours + t.hours + min / 60;
	temp.minutes = min % 60;

	return temp;
	
}

//实现加法运算
Time Time::sum(Time & t1, Time & t2)
{
	Time temp;//局部变量，可以返回变量值

	int min;
	min = t1.minutes + t2.minutes;
	
	temp.hours = t1.hours + t2.hours + min / 60;
	temp.minutes = min % 60;

	return temp;

}
Time::Time(void)
{
	hours = 0;
	minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::addhours(int h)
{
	this->hours += h;
}
void Time::addminutes(int m)
{
	int t;
	t = this->minutes + m;

	this->hours += t / 60;
	this->minutes = t % 60;
}

void Time::show(void) const
{
	cout << "hours : " << hours << "  mintes : " << minutes << endl;
}
Time::~Time(void)
{
	hours = 0;
	minutes = 0;
}
