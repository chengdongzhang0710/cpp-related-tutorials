#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 栈控件使用
    // 设置默认定位ScrollArea
    ui->stackedWidget->setCurrentIndex(0);

    // ScrollArea按钮
    connect(ui->btn_ScrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    // ToolBox按钮
    connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    // TabWidget按钮
    connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });


    // 下拉框
    ui->comboBox->addItem("Benz");
    ui->comboBox->addItem("BMW");
    ui->comboBox->addItem("Volkswagen");

    // 点击按钮选中特定项
    connect(ui->btn_Select, &QPushButton::clicked, [=](){
//        ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("BMW");
    });

    // 利用QLabel显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/image/demo.bmp"));

    // 利用QLabel显示gif动态图片
    QMovie *movie = new QMovie(":/image/mua.gif");
    ui->lbl_Movie->setMovie(movie);
    movie->start();  // 播放动图
}

Widget::~Widget()
{
    delete ui;
}
