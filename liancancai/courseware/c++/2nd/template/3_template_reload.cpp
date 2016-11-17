
#include <iostream>

using namespace std;


//声明模板
template <typename T>
void Swap(T & a, T & b);

//新的模板
template <typename T>
void Swap(T *a, T *b, int n);

void show(int *arr)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{

	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {5,4,3,2,1};
	
	show(arr1);
	show(arr2);
	Swap(arr1, arr2, 5);
	show(arr1);
	show(arr2);


	return 0;
}

//实现旧模板
template <typename T>
void Swap(T & a, T & b)
{
	T temp;

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

