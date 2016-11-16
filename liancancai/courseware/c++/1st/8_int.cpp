#include <iostream>

using namespace std;

int main(void)
{
	int num = 123;

	printf("num = #%10d#\n", num);
	printf("num = #%-10d#\n", num);

	cout << "#";
	cout.width(10);
	cout.fill('-');
	//cout << right << num;//表示右对齐
	cout << left << num;//表示左对齐
	cout << "#" <<endl;

	cout << "===============" << endl;
	
	cout << "#";
	cout.width(12);
	cout.fill('.');
	cout << right << num;//表示右对齐
	cout << "#" <<endl;
	return 0;
}
