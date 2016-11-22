#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	ofstream fout;

	//fout.open(argv[1], ios_base::out | ios_base::app);
	fout.open(argv[1], ios_base::out);

	if (!fout.is_open())
	{
		cout << "open failed!\n";
		return -1;
	}

	fout << "hello";

	return 0;
}
