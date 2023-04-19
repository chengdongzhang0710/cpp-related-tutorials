#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "Open", "D:\\Downloads");

        // 将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        // 格式编码类
//        QTextCodec *codec = QTextCodec::codecForName("gbk");

        // 读取内容放入到textEdit中
        // QFile默认支持的格式是UTF-8
        QFile file(path);  // 参数就是读取文件的路径

        // 设置打开方式
        file.open(QIODevice::ReadOnly);

//        QByteArray arr = file.readAll();

        QByteArray arr;
        while (!file.atEnd())
        {
            arr += file.readLine();
        }

        // 将读取到的数据放入textEdit中
        ui->textEdit->setText(arr);
//        ui->textEdit->setText(codec->toUnicode(arr));

        // 对文件对象进行关闭
        file.close();

        // 进行写文件
//        file.open(QIODevice::Append);  // 用追加方式进行写
//        file.write("\nEND");
//        file.close();

        // QFileInfo文件信息类
        QFileInfo info(path);
        qDebug() << "Size:" << info.size();
        qDebug() << "Suffix:" << info.suffix();
        qDebug() << "Name:" << info.fileName();
        qDebug() << "Path:" << info.filePath();
        qDebug() << "Created At:" << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "Modified At:" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}
