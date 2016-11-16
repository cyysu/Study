#include <iostream>

using namespace std;

int main(void)
{
	float price1 = 97.9;
	float price2 = 119.0 + 1.0/3.0;

	printf("price1 = %f\n", price1);
	printf("price2 = %f\n", price2);

	
	cout << "price1 = " << price1 << endl;
	cout << "price2 = " << price2 << endl;
	
	cout.precision(2);//表示指定精度位置
	cout << "price1 = " << price1 << endl;
	cout << "price2 = " << price2 << endl;

	cout.setf(ios_base::showpoint);//表示操作浮点数
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);//表示指定精度位置
	cout << "price1 = " << price1 << endl;
	cout << "price2 = " << price2 << endl;

	return 0;
}
