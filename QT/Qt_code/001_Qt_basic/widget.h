// Created by jackzhang on 2021/2/15.

#ifndef QT_TEST_WIDGET_H
#define QT_TEST_WIDGET_H

#include <QWidget> // 包含头文件按QWidget窗口类

class Widget : public QWidget
{
	Q_OBJECT // Q_OBJECT宏， 允许类中使用信号和槽的机制
public:
	Widget(QWidget *parent = 0); // 构造函数
	~Widget(); // 析构函数
};


#endif //QT_TEST_WIDGET_H
