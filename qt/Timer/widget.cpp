#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    id = startTimer(1000);  // 参数1 - 时间间隔(单位毫秒)

    id2 = startTimer(2000);

    // 定时器的第二种方式
    QTimer *timer = new QTimer(this);

    timer->start(500);  // 启动定时器

    connect(timer, &QTimer::timeout, [=](){
        // label_3每隔0.5秒+1
        static int num3 = 1;
        ui->label_3->setText(QString::number(num3++));
    });

    // 点击暂停按钮实现停止定时器
    connect(ui->btn, &QPushButton::clicked, [=](){
        timer->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id)
    {
        // label每隔1秒+1
        static int num = 1;
        ui->label->setText(QString::number(num++));
    }

    if (event->timerId() == id2)
    {
        // label_2每隔2秒+1
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }
}
