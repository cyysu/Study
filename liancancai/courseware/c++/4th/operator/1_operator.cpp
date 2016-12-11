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
		//void operator<<(std::ostream & os);
		void show(void) const;
		~Time(void);
};

int main(void)
{
	Time time(5, 10);
	Time t1(10,18),t2(9,51), t3(5, 10);
	Time temp;

	cout << "hello";
	t1.show();
	//cout << t1;
	//temp = t1 - t2;
	//temp = t1 * 1.5;
	//temp = 1.5 * t1;
	temp.show();
	//temp = t1 + t2;//this => t1
	//t1 += t2;
	//temp = t2 + t1;//this => t2
	//temp = t1 + t2 + t3;//this => 3 this => 7
	//(t1.operator+(t2)).operator+(t3);
    /*
	 *temp = t1 + (t2 + t3);
	 *t1.operator+(t2.operator+(t3));
     */

	//temp = t1 + t2;//运算符重载
	//temp = t1.operator+(t2);//t1叫调用者 t2叫给传的参数
	//temp = t2.operator+(t1);
	//temp = t1 + t2 + time;
						 
	//t1 + t2 + time <=> (t1.operator+(t2)).operator(time);
	//temp.show();

/*
 *    t1 = t1.sum(t1, t2);
 *
 *    t1.show();
 *
 *
 *
 *    time.addhours(2);
 *    time.addminutes(50);
 */

	//time.reset(10,10);

	return 0;
}
/*
 *void Time::operator<<(std::ostream & os)
 *{
 *    os << "hours : " << this->hours << "  minutes " << this->minutes << endl;
 *}
 */
Time Time::operator*(const double mul)
{
	Time temp;
	double m;
	
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
