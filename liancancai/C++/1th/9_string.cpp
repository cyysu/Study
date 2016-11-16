#include <iostream>

using namespace std;

int main(void)
{
	string one = "hello word";
	string two(20, 'A');
	string three(one, 6);
	string four("four");

	cout << one << endl;
	cout << "one size = ";
	cout << one.size() << endl; 

	cout << two << endl;
	cout << "two size = ";
	cout << two.size() << endl;

	cout << three << endl;
	cout << four << endl;

	return 0;
}