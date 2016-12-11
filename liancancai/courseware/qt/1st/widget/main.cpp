#include <QApplication>//QT图形界面初始化头文件
#include <QLabel> //标签头文件
#include <QString>
#include <QTextCodec>//设置字体头文件

/*
 *int add(int a, int b)
 *{
 *    return a + b;
 *}
 */
int main(int argc, char **argv)
{
	QApplication app(argc, argv);//初始化QT图形界面

	QLabel label;//定义标签对象
	//QTextCodec *codec = QTextCodec::code

	//像素为单位
	label.resize(200, 100);//窗口大小
	label.move(0,430);//设置窗口位置
	label.setText("hello Qt");

	label.show();//显示对象


	return app.exec();//运行

}
