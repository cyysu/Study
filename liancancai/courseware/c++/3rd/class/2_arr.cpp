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
	arr_t a;	
	return 0;
}
