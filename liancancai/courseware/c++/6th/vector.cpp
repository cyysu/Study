#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int i;

	vector<int> a;//定义容器
	//定义一个迭代器
	vector<int>::iterator t;

	for (i = 0; i < 10; i++)
	{
		a.push_back(rand() % 100);
	}
	for (i = 0; i < 10; i++)
	{
		//cout << a[i] << " " << &a[i] << endl;;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << a.size() << endl;

	a.erase(a.begin(), a.begin() + 2);

	//排序
	sort(a.begin(), a.end());
	for (t = a.begin(); t != a.end(); t++)
	{
		//cout << *t << " " << &*t << endl;
		cout << *t << " ";
	}
	cout << endl;
	cout << a.size() << endl;

	return 0;
}
