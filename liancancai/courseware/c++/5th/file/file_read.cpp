#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	//1 定义输入流
	ifstream fin;
	char ch;
	char buf[128];
	string str;

	//2 帮定流和文件
	fin.open(argv[1]);

	if (fin.fail())
	{
		cout << "fail" << endl;
	}
	if (!fin)
	{
		cout << "fin" << endl;
	}
	if (!fin.good())
	{
		cout << "good!" << endl;
	}

	if (!fin.is_open())
	{
		cout << "open failed!\n";
		return -1;
	}

	//fin >> buf;
	//fin.getline(buf, sizeof(buf));
	getline(fin, str);
	cout << str << endl;
	//表示从键盘中获取输入流
	//cin >> ch;
	//从文件中获取输入流

/*
 *    while(1)
 *    {
 *        fin >> ch;
 *        if (fin.eof())
 *        {
 *            break;
 *            //fin.clear();
 *        }
 *        cout << "ch = " << ch << endl;
 *
 *        sleep(1);
 *    }
 *    cout << "open success!\n";
 *
 */
	//关闭文件
	fin.close();
	return 0;
}
