#include <iostream>

using namespace std;

class Time{
	private:
		int hours;
		int minutes;
	public:
		Time(void);
		Time(int h, int m);
		#if 0
		friend void operator<<(ostream & os, Time & t);
		#else
		friend ostream & operator<<(ostream & os, Time & t);
		#endif
		void show(void) const;
		~Time(void);
};

//iostream
//ostream cout
//istream cin

#if 0
void operator<<(ostream & os, Time & t)
{
	os << "hours : " << t.hours << "  minutes : " << t.minutes << endl;
}
#else
ostream & operator<<(ostream & os, Time & t)
{
	os << "hours : " << t.hours << "  minutes : " << t.minutes;
	return os;
}
#endif
int main(void)
{
	int num = 12;
	string str = "hello";

	Time t(12, 15);

    /*
	 *cout << "num = " <<num << endl;
	 *cout << str << endl;
     */
	printf("=============\n");
	cout << "time = " << t << " hello" << endl;
	//operator<<(cout, t);
	printf("=============\n");
	t.show();
	return 0;
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

void Time::show(void) const
{
	cout << "hours : " << hours << "  mintes : " << minutes << endl;
}
Time::~Time(void)
{
	hours = 0;
	minutes = 0;
}
