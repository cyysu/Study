#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	QApplication app(argc, argv);//初始化QT图形界面
    五笔还是拼音
	cout << "hello" << endl;
	return app.exec();//作为一个进程循环运行起来
}
