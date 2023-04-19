#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->tch = new Teacher(this);
    this->stu = new Student(this);

//    connect(tch, &Teacher::hungry, stu, &Student::treat);

    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;

    connect(tch, teacherSignal, stu, studentSlot);

//    classIsOver();

    QPushButton* btn = new QPushButton("Class Is Over", this);
    resize(600, 400);
//    connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void(Student::*studentSlot2)(void) = &Student::treat;
    connect(tch, teacherSignal2, stu, studentSlot2);

    // 拓展
    // 1. 信号是可以连接信号
    // 2. 一个信号可以连接多个槽函数
    // 3. 多个信号可以连接同一个槽函数
    // 4. 信号和槽函数的参数必须必须类型一一对应
    // 5. 信号的参数个数可以多于槽函数的参数个数

    connect(btn, &QPushButton::clicked, tch, teacherSignal2);  // 信号连接信号

    disconnect(tch, teacherSignal2, stu, studentSlot2);  // 断开信号

    // Qt4版本以前的信号和槽连接方式
    // 利用Qt4信号槽连接无参版本
    // 底层：SIGNAl("hungry") SLOT("treat")
    // 优点：参数直观；缺点：类型不做检测
//    connect(tch, SIGNAL(hungry()), stu, SIGNAL(treat()));

    // Lambda表达式
    // = - 值传递(推荐)；& - 引用传递
//    [=](){
//        btn->setText("Modified");
//    }();

//    int res = []()->int{return 100;}();
//    qDebug() << "res = " << res;

    // 利用Lambda表达式实现点击按钮关闭窗口
    QPushButton* btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->setText("Close");
    btn2->move(100, 0);

    connect(btn2, &QPushButton::clicked, [=](){
        this->close();
        emit tch->hungry("Beef");
        btn2->setText("Modified");
    });
}

void Widget::classIsOver()
{
//    emit tch->hungry();
    emit tch->hungry("Chicken");
}

Widget::~Widget()
{
    delete ui;
}
