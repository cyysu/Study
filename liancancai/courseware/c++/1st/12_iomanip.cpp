#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	double num = 10;
	int i;
	
	cout << setw(6) <<"base_num";
	cout << setw(10) <<"sqrt ";
	cout << setw(10) << "fourth" << endl;;
	for (i = 10; i <= 100; i += 10)
	{
		num = sqrt(i);
		cout << setw(6) << setfill('*') <<i;
		cout << setfill(' ') << setw(10) << setprecision(3) << num;
		cout << setfill(' ') << setw(10) << setprecision(4) << sqrt(num) << endl;
	}
	return 0;
}

