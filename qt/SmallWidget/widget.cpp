#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击获取控件当前的值
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getNumber();
    });

    // 设置一半值
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget->setNumber(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
