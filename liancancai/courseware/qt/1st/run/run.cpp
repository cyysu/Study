#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>



int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QLabel *cmdLabel;

	//定义一个提示信息
	cmdLabel = new QLabel;
	cmdLabel->setText("please input cmd line");

	//定义打开标签
	QLabel openLabel;
	openLabel.setText("open : ");

	//定义行编辑
	QLineEdit cmdLineEdit;
	cmdLineEdit.clear();//清空

	//定义命令水平布局
	QHBoxLayout cmdLayout;//定义水平布局
	cmdLayout.addWidget(&openLabel);//添加到布局中
	cmdLayout.addWidget(&cmdLineEdit);

	//定义三个按钮
	QPushButton submitButton;
	QPushButton cancelButton;
	QPushButton browserButton;
	
	submitButton.setText("submit");
	cancelButton.setText("cancel");
	browserButton.setText("browser");

	//定义按钮水平布局
	QHBoxLayout buttonLayout;
	buttonLayout.addWidget(&submitButton);
	buttonLayout.addWidget(&cancelButton);
	buttonLayout.addWidget(&browserButton);

	//定义垂直布局
	QVBoxLayout mainLayout;
	mainLayout.addWidget(cmdLabel);//添加部件
	mainLayout.addLayout(&cmdLayout);//添加布局
	mainLayout.addLayout(&buttonLayout);

	//定义主窗口
	QWidget widget;
	widget.setLayout(&mainLayout);
	widget.show();//显示


	app.exec();
	delete cmdLabel;
	return 0;
}
