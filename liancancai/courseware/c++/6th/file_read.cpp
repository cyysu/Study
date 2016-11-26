#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	char ch;

	ifstream fin;

	fin.open("./test");

	//fin.seekg(5);

	fin >> ch;
	fin.seekp(5, ios_base::cur);
	fin >> ch;

	cout << "ch = " << ch << endl;
	return 0;
}
