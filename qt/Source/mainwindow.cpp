#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionNew->setIcon(QIcon(":/image/demo.bmp"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
