#include <iostream>

using namespace std;

int main(void)
{
	char ch;
	char buf[128];

	cout << "please input char : ";
	//cin >> ch;
    /*
	 *cin.get(ch);//接受一个字符
	 *cin.get();
     */
	cin.get(ch).get();

	cout << "ch = " << ch << endl;

	cout << "please input string : ";
	//cin >> ch;
	//cin.get(buf, sizeof(buf)).get();//接受一个字符
	//cin.getline(buf, sizeof(buf));
	cin.getline(buf, sizeof(buf), '#');

	cout << "buf = " << buf << endl;
	while(1)
	{
		//cout << "hello" << endl;;//行缓冲
		//cerr << "hello";//无缓冲
		cout << "hello";
		sleep(1);
		fflush(NULL);
	}
	return 0;
}
