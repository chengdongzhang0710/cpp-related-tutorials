#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建按钮弹出一个对话框
    connect(ui->actionNew, &QAction::triggered, [=](){
        // 对话框分类
        // 模态对话框 - 不可以对其他窗口进行操作
        // 非模态对话框 - 可以对其他窗口进行操作

        // 模态对话框创建 - 阻塞的功能
//        QDialog dlg(this);
//        dlg.resize(200, 100);
//        dlg.exec();
//        qDebug() << "A modal dialog pops up!";

        // 非模态对话框创建
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200, 100);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug() << "A modeless dialog pops up!";


        // 消息对话框创建
//        QMessageBox::critical(this, "Critical", "Error!");  // 错误对话框
//        QMessageBox::information(this, "Info", "Hint!");  // 信息对话框
//        QMessageBox::warning(this, "Warning", "Caution!");  // 警告对话框
        // 提问对话框 - 父亲 标题 提示内容 按键类型 默认关联回车按键
//        if (QMessageBox::Save == QMessageBox::question(this, "Question", "Ask!", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "Choose Save!";
//        }
//        else
//        {
//            qDebug() << "Choose Cancel!";
//        }


        // 其他标准对话框
        // 颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << "r =" << color.red() << "g =" << color.green() << "b =" << color.blue();

        // 文件对话框
//        QString str = QFileDialog::getOpenFileName(this, "Open File", "D:\\Downloads", "(*.txt)");
//        qDebug() << str;

        // 字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("Arial", 36));
        qDebug() << "Font:" << font.family().toUtf8().data() << "Size:" << font.pointSize() << "Bold:" << font.bold() << "Italic:" << font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
