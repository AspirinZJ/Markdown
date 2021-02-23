// Created by jackzhang on 2021/2/15.
#include "widget.h"
#include <QPushButton> // QPushButton按钮控件的头文件

Widget::Widget(QWidget *parent) : QWidget(parent)
{
	// QPushButton *qButton = new QPushButton;
	auto *qButton = new QPushButton; // 无需使用delete删除
	// qButton->show();	// show() 以顶层方式弹出窗口控件
	// 让pPushButton对象依附在Widget窗口中
	qButton->setParent(this);
	// 显示文本
	qButton->setText("First Button");

	// 创建第二个按钮, 按照控件的大小创建窗口
	auto *qButton2 = new QPushButton("Second button", this);
	// 移动qButton2按钮
	qButton2->move(100, 100);
	// 设置按钮大小
	qButton2->resize(200, 200);

	// 重置窗口大小
	resize(1280, 720);

	// 设置窗口标题
	setWindowTitle("First Window");

	// 设置固定的窗口大小
	setFixedSize(1366, 768); // 使用了这个命令后就无法拖拽改变窗口大小
}

Widget::~Widget()
{}
