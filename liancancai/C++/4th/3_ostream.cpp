/**
 * @Author:      lcc
 * @DateTime:    2016-11-22 08:39:10
 * @Description: 重定向 << >> 运算符
 */

#include <iostream>

using namespace std;

//定义 复数 类
class Complex{
private:
	double real;
	double imag;
public:
	Complex(double real = 0.0, double imag = 0.0);
	// ~Complex(void) { cout << "~Complex" << endl;}
	friend ostream & operator << (ostream & output, Complex & c);//重载  <<
	friend istream & operator >> (istream & input, Complex & c);//重载 >>
	Complex operator + (const Complex c);//复数相加
};

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

ostream & operator << (ostream & output, Complex & c)
{
	cout << "(" << c.real << "," << c.imag << "i" << ")";
	return output;
}  

istream & operator >> (istream & input, Complex & c)
{
	cout << "please input real and image part:";
	input >> c.real >> c.imag;

	return input;
}

Complex Complex::operator + (const Complex c)
{
	Complex tmp;

	tmp.real = this->real + c.real;
	tmp.imag = this->imag + c.imag;

	return tmp;
}
//重载流插入运算符　<< 
//重载流提取运算符 >>
int main(void)
{
	Complex c1(1, 2), c2(2, 3);
	Complex tmp;

	cout << "测试<<" << endl;
	tmp = c1 + c2;

	cout << c1 << "+" << c2 << "=" << tmp << endl;


	cout <<"测试>>" << endl;


	//cin >> tmp 等价于 operator>>(cin, tmp);
	cin >> tmp;

	//cout << tmp 等价于 operator<<(cout, tmp)
	cout << tmp;
	// cout << tmp;
	return 0;
}
