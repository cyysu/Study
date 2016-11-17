#include <iostream>

using namespace std;

struct cls_t{
	char name[128];
	int age;
	char sex;
	double result;
};

//声明模板
template <typename T>
void Swap(T & a, T & b);


int main(void)
{
	cls_t cls1 = {"tom", 18, 'M', 99.5};
	cls_t cls2 = {"mary", 19, 'F', 88.5};

	int a = 1, b = 2;
	double d1 = 3.44, d2 = 4.55;
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {5,4,3,2,1};
	
	
	Swap(arr1, arr2);

	cout << "name : " << cls1.name << " age : " << cls1.age
			<< "sex : " << cls1.sex << "result : " 
			<< cls1.result << endl;
	cout << "name : " << cls2.name << " age : " << cls2.age
			<< "sex : " << cls2.sex << "result : " 
			<< cls2.result << endl;
	Swap(cls1, cls2);
	cout << "name : " << cls1.name << " age : " << cls1.age
			<< "sex : " << cls1.sex << "result : " 
			<< cls1.result << endl;
	cout << "name : " << cls2.name << " age : " << cls2.age
			<< "sex : " << cls2.sex << "result : " 
			<< cls2.result << endl;


/*
 *    cout << "a = " << a << " b = " << b << endl;
 *    Swap(a, b);
 *    cout << "a = " << a << " b = " << b << endl;
 *
 *    cout << "d1 = " << d1 << " d2 = " << d2 << endl;
 *    Swap(d1, d2);
 *    cout << "d1 = " << d1 << " d2 = " << d2 << endl;
 */

	return 0;
}

template <typename T>
void Swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}
