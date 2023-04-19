#include "student.h"
#include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{

}

void Student::treat()
{
    qDebug() << "Treat Teacher!";
}

void Student::treat(QString foodName)
{
    // QString -> QByteArray(.toUtf8()) -> char*(.data())
    qDebug() << "Treat Teacher! Teacher Wants To Eat " << foodName.toUtf8().data();
}
