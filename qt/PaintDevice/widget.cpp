#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    // Pixmap绘图设备，专门为平台做了显示的优化
//    QPixmap pix(300, 300);
//    pix.fill(Qt::white);  // 填充颜色

//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    pix.save("D:\\Downloads\\Pix.png");

//    // QImage绘图设备，可以对像素进行访问
//    QImage img(300, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    img.save("D:\\Downloads\\Img.png");

    // QPicture绘图设备，可以记录和重现绘图的指令
    QPicture pic;
    QPainter painter;

    painter.begin(&pic);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();

    pic.save("D:\\Downloads\\Pic.any");  // 保存到磁盘
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

//    // 利用QImage对像素进行修改
//    QImage img;
//    img.load(":/image/demo.bmp");

//    // 修改像素点
//    for (int i = 0; i < 20; i++)
//    {
//        for (int j = 0; j < 20; j++)
//        {
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }

//    painter.drawImage(0, 0, img);

    // 重现QPicture的绘图指令
    QPicture pic;
    pic.load("D:\\Downloads\\Pic.any");

    painter.drawPicture(0, 0, pic);
}

Widget::~Widget()
{
    delete ui;
}
