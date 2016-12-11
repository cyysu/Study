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
		Time operator*(const Time & t);
		void show(void) const;
		~Time(void);
};

int main(void)
{
	Time t1(0, 21);
	Time t2(0, 20);

	Time temp;

	t1.show();
	t2.show();

	// temp = t1 - t2;
	// temp.show();

	temp = t1 * t2;
	temp.show();
	// Time time(5, 40);
	// Time t1(3,49),t2(5,31);
	// Time temp;

	// //temp = t1 + t2;//运算符重载
	// temp = t1.operator+(t2);//t1叫调用者 t2叫给传的参数
	// temp = t2.operator+(t1);
	// temp = t1 + t2 + time;// t1.operator+(t2 + time)
	// 					  // t1.operator+(t2.operator+(time));
	// temp.show();

	// t1 = t1.sum(t1, t2);

	// t1.show();



	// time.addhours(2);
	// time.addminutes(50);

	// //time.reset(10,10);

	// time.show();

	return 0;
}
Time Time::operator+(const Time  t)
{
	Time temp;//局部变量，可以返回变量值

	int min;
	min = this->minutes + t.minutes;
	
	temp.hours = this->hours + t.hours + min / 60;
	temp.minutes = min % 60;

	return temp;
	
}

Time Time::operator-(const Time & t)
{
	Time temp;

	int min;

	min = this->minutes - t.minutes;

	if(min < 0)
	{
		temp.hours = this->hours - t.hours - ((-min) / 60) - 1;
	}
	else
	{
		temp.hours = this->hours - t.hours - (min / 60);
	}

	if(min < 0)
	{
		temp.minutes = min % 60 + 60;
	}
	else
	{
		temp.minutes = min % 60;
	}

	return temp;
}

Time Time::operator*(const Time & t)
{
	Time temp;
	int min;

	min = this->minutes * t.minutes;

	temp.hours = this->hours * t.hours + min / 60;
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
