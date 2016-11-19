#include <iostream>

#define MAX 10

using namespace std;
typedef int INT;

class arr_t{
	private:
		INT arr[MAX];//数据
		int size;//类型
		int num;//大小
	public:
		void init_arr(void);
		void show_arr(void);
		int arr_max(void);
		int arr_min(void);
		void arr_sort(void);
		INT arr_find(INT key);
};

int main(void)
{
	arr_t arr;

	arr.init_arr();
	arr.show_arr();

	return 0;
}

void arr_t::init_arr(void)
{
	size = sizeof(INT);
	num = MAX;

	int i;

	for (i = 0; i < MAX; i++)
	{
		arr[i] = i + 1;
	}	
}
 
void arr_t::show_arr(void)
{
	int i;

	for (i = 0; i < num ; i++)
	{
		cout << "arr [";
		cout << i;
		cout << "]";
		cout << " = ";
		cout << arr[i] << endl;
	}
	
}

int arr_t::arr_max(void)
{
	int i;
	int temp;
	
	temp = arr[0];
		
	for (i = 1; i < num; i ++)
	{
		if (temp < arr[i])
		{
			temp = arr[i];	
		}
	}
}





