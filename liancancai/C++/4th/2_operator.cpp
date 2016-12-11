#include <iostream>

using namespace std;

class Time{
private:
	int hours;
	int minutes;
public:
	Time(void);
	Time (int hours, int minutes);
	~Time(void);
	void set_time(int hours, int minutes);
	void show(void) const;
	Time operator*(const Time & time);
	Time operator*(double mul);
	friend Time operator*(double mul, const Time & time);
};

Time::Time(void)
{
	hours = 0;
	minutes = 0;
}

Time::Time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

Time::~Time(void)
{
	hours = 0;
	minutes = 0;
}

void Time::set_time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

void Time::show(void) const
{
	cout << "hours = " << hours << endl;
	cout << "minutes = " << minutes << endl;
}

Time Time::operator*(const Time & time)
{
	Time tmp;

	tmp.hours = this->hours * time.hours;
	tmp.minutes = this->minutes * time.minutes;

	return tmp;
}

Time Time::operator*(double mul)
{
	Time tmp;
	
	tmp.hours = this->hours * mul;
	tmp.minutes = this->minutes * mul;

	return tmp;
}

Time operator*(double mul, const Time & time)
{
	Time tmp;

	tmp.hours = time.hours * mul;
	tmp.minutes = time.minutes * mul;

	return tmp;
}

int main(void)
{
	Time time1(1, 2);
	Time time2(2, 2);
	Time tmp;

	cout << "测试类相乘" << endl;
	tmp.show();
	tmp = time1 * time2 * time2;
	tmp.show();

	cout << "类与小数相乘" << endl;
	tmp = time1 * 3.0;
	tmp.show();

	cout << "测试小数与类相乘" << endl;
	tmp = 4.0 * time1;
	tmp.show();

	cout << "测试连续相乘" << endl;
	tmp = 1.0 * time1 * time2 * 1.0 * 1.0;
	tmp.show();

	return 0;
}
