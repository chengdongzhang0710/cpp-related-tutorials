#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击移动按钮移动图片
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        posX += 20;

        // 如果要手动调用绘图事件，使用update更新
        update();
    });
}

void Widget::paintEvent(QPaintEvent *event)
{
//    // 实例化画家对象，this指定的是绘图设备
//    QPainter painter(this);

//    // 设置画笔
//    QPen pen(QColor(255, 0, 0));
//    pen.setWidth(3);
//    pen.setStyle(Qt::DotLine);

//    painter.setPen(pen);

//    // 设置画刷
//    QBrush brush(Qt::cyan);
//    brush.setStyle(Qt::Dense1Pattern);

//    painter.setBrush(brush);

//    // 画线
//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

//    // 画圆/椭圆
//    painter.drawEllipse(QPoint(100, 100), 50, 50);

//    // 画矩形
//    painter.drawRect(QRect(20, 20, 50, 50));

//    // 画文字
//    painter.drawText(QRect(10, 200, 200, 50), "Good Good Study, Day Day Up");


    // 高级设置
//    QPainter painter(this);

//    painter.drawEllipse(QPoint(100, 50), 50, 50);

//    // 设置抗锯齿能力，但是效率会降低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200, 50), 50, 50);

//    painter.drawRect(QRect(20, 20, 50, 50));

//    // 移动画家
//    painter.translate(100, 0);

//    // 保存画家状态
//    painter.save();
//    painter.drawRect(QRect(20, 20, 50, 50));

//    painter.translate(100, 0);

//    // 还原画家保存状态
//    painter.restore();
//    painter.drawRect(QRect(20, 20, 50, 50));

    // 利用画家绘制资源图片
    QPainter painter(this);

    // 如果超出屏幕从0开始
    if (posX > this->width())
    {
        posX = 0;
    }

    painter.drawPixmap(posX, 20, QPixmap(":/image/demo.bmp"));
}

Widget::~Widget()
{
    delete ui;
}
