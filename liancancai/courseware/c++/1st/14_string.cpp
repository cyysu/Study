#include <iostream>

using namespace std;

int main(void)
{
	int i;	
	string str1 = "make";
	string str2 = "mask";

	for (i = 0; i < str1.size(); i++)
	{
		cout << str1[i];
	}
	cout << endl;
	str1[0] = 'A';

	str1 = "hello";
	cout << "str1 = " << str1 << endl;
	// make < mask => 1
	
	//strcmp
	// str1[0] - str2[0]

	
	cout << "str1 > str2 = " << (str1 > str2) << endl; 
	cout << "str1 > str2 = " << (str1 >= str2) << endl; 
	cout << "str1 > str2 = " << (str1 < str2) << endl; 
	cout << "str1 > str2 = " << (str1 <= str2) << endl; 
	cout << "str1 > str2 = " << (str1 == str2) << endl; 
	cout << "str1 > str2 = " << (str1 !=  str2) << endl; 

	return 0;
}
