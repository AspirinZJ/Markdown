#include <QApplication> // 包含一个应用程序类的头文件
#include "widget.h"

int main(int argc, char *argv[])
{
	// qtApp应用程序对象，在Qt中，应用程序对象有且只有一个
	QApplication qtApp(argc, argv);

	// 窗口对象， Widget基类->QWidget
	Widget widget;

	widget.show(); // 窗口对象不会默认显示，必须调用show方法显示窗口

	// 让应用程序对象进入消息循环机制, 让代码阻塞到这行
	return QApplication::exec();
}
