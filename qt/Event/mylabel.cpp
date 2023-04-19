#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置鼠标追踪状态
    setMouseTracking(true);
}

void MyLabel::enterEvent(QEnterEvent *event)
{
//    qDebug() << "Mouse Entered!";
}

void MyLabel::leaveEvent(QEvent *event)
{
//    qDebug() << "Mouse Left!";
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QString str = QString("Mouse Pressed! x = %1, y = %2").arg(event->x()).arg(event->y());
        qDebug() << str;
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        qDebug() << "Mouse Released!";
    }
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
//    if (event->buttons() & Qt::LeftButton)
//    {
//        qDebug() << "Mouse Moved!";
//    }

    qDebug() << "Mouse Moved!";
}

bool MyLabel::event(QEvent *event)
{
    // 如果是鼠标按下，在event事件分发中做拦截操作
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *e = static_cast<QMouseEvent *>(event);
        QString str = QString("In Event Function Mouse Pressed! x = %1, y = %2").arg(e->x()).arg(e->y());
        qDebug() << str;
        return true;  // return true代表用户自己处理这个事件，不向下分发
    }

    // 其他事件交给父类处理，默认处理
    return QLabel::event(event);
}
