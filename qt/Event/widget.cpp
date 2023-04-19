#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 给label安装事件过滤器
    ui->label->installEventFilter(this);
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->label)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            QString str = QString("In Event Filter Mouse Pressed! x = %1, y = %2").arg(e->x()).arg(e->y());
            qDebug() << str;
            return true;
        }
    }

    return QWidget::eventFilter(object, event);
}

Widget::~Widget()
{
    delete ui;
}
