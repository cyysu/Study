
#include <iostream>

using namespace std;

struct cls_t{
	string name;
	int age;
	char sex;
	double result;
};

//声明一个普通函数
//void Swap(cls_t & , cls_t &);

//声明模板
template <typename T>
void Swap(T & a, T & b);

//新的模板
template <typename T>
void Swap(T *a, T *b, int n);

//显示具体化
template <> void Swap<cls_t>(cls_t &, cls_t &);

void show(int *arr)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void show(cls_t cls)
{
	cout << "name : " << cls.name << " age : " << cls.age
		<< " sex : " << cls.sex << " result : " << cls.result
		<< endl;
}
int main(void)
{
	cls_t cls1 = {"jim", 20, 'M', 77.5};
	cls_t cls2 = {"mary", 18, 'F', 88.6};


	show(cls1);
	show(cls2);
	Swap(cls1, cls2);
	show(cls1);
	show(cls2);

	return 0;
}

//普通函数
void Swap(cls_t & a, cls_t & b)
{

	cout << "func!" << endl;
	cls_t temp;

	temp = a;
	a = b;
	b = temp;
	
}

//实现旧模板
template <typename T>
void Swap(T & a, T & b)
{
	T temp;

	cout << "template" << endl;
	temp = a;
	a = b;
	b = temp;
}

//实现新的模板
template <typename T>
void Swap(T *a, T *b, int n)
{

	int i;
	T temp;
	for (i = 0; i < n; i++)
	{
		Swap(a[i], b[i]);
        /*
		 *temp = a[i];
		 *a[i] = b[i];
		 *b[i] = temp;
         */
	}
}

//显示实现：
//template <> void Swap<cls_t>(cls_t & d1, cls_t & d2)
template <> void Swap(cls_t & d1, cls_t & d2)
{
	double temp;

	cout << "explicit" << endl;
	temp = d1.result;
	d1.result = d2.result;
	d2.result = temp;

}
