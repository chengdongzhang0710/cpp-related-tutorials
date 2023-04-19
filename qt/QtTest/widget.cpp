#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* btn = new QPushButton;
//    btn->show();  // show() - 以顶层方式弹出窗口控件
    btn->setParent(this);  // 让btn对象依赖在widget窗口中
    btn->setText("First Button");

    QPushButton* btn2 = new QPushButton("Second Button", this);  // 按照控件的大小创建窗口
    btn2->move(100, 100);  // 移动btn2按钮
    btn2->resize(50, 50);  // 按钮重新指定大小
//    resize(600, 400);  // 重置窗口大小

    setFixedSize(600, 400);  // 设置固定窗口大小

    setWindowTitle("First Window");

    // btn - 信号的发送者
    // &QPushButton::clicked - 发送的信号(函数地址)
    // this - 信号的接收者
    // &QWidget::close - 处理的槽函数(函数地址)
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
}

Widget::~Widget()
{
}
