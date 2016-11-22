#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ofstream fout;
	char buf [128];

	fout.open(argv[1]);

	if(!fout)
	{
		cout << "open fialed" << endl;
	}

	cout << "please input a string :" << endl;

	cin.getline(buf, sizeof(buf));

	fout << buf;

	fout.close();

	return 0;
}
