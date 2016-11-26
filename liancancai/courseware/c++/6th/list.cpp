#include <iostream>
#include <list>
#include <iterator>//迭代器头文件
#include <algorithm> //算法头文件

using namespace std;

int main(void)
{
	int i;
	//定义链表
	list<int> one;
	list<int>::iterator t;
	int num = 100;
	int count = 0;
	int a[6] = {6, 6, 6, 4, 7, 6};
	list<int> two;
	two.insert(two.begin(), a, a + 6);

	for (t = two.begin(); t != two.end(); t++)
	{
		//cout << one[i] << " ";
		cout << *t << " ";
	}
	cout << endl;
	two.unique();//删除相邻重复数据
	for (t = two.begin(); t != two.end(); t++)
	{
		//cout << one[i] << " ";
		cout << *t << " ";
	}
	cout << endl;


	for (i = 0; i < 10; i++)
	{
		one.push_back(rand() % 10);
	}

	//one.clear(); //表示清空所有数据
	for (t = one.begin(); t != one.end(); t++)
	{
		//cout << one[i] << " ";
		cout << *t << " ";
	}
	cout << endl;
	t = one.begin();

	//one.erase(one.begin());//删除第二个数据

/*
 *    one.insert(one.begin(), num);
 *    one.insert(one.end(), 200);
 *    one.insert(one.begin(), 3, 9);
 *
 */
	for (t = one.begin(), count = 0; t != one.end(); t++, count++)
	{
		//cout << one[i] << " ";
        /*
		 *if (count == 5)
		 *    one.insert(t, 300);
         */
		//cout << *t << " ";
	}
	cout << endl;

	one.unique();

	for (t = one.begin(); t != one.end(); t++)
	{
		//cout << one[i] << " ";
		cout << *t << " ";
	}
	cout << endl;

	cout << one.back() << endl;//表示返回最后一个数据
	return 0;
}
