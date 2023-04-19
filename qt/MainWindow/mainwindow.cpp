#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口大小
    resize(600, 400);


    // 菜单栏创建
    // 菜单栏只能最多有一个！
    QMenuBar *bar = menuBar();
    setMenuBar(bar);  // 将菜单栏放入到窗口中

    // 创建菜单
    QMenu *fileMenu = bar->addMenu("File");
    QMenu *editMenu = bar->addMenu("Edit");

    // 创建菜单项
    QAction *newAction = fileMenu->addAction("New");
    fileMenu->addSeparator();  // 添加分割线
    QAction *openAction = fileMenu->addAction("Open");


    // 工具栏创建
    // 工具栏可以有多个！
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);  // 后期设置工具栏只允许左右停靠
    toolBar->setFloatable(false);  // 设置浮动
    toolBar->setMovable(true);  // 设置移动(总开关)

    // 工具栏中可以设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();  // 添加分割线
    toolBar->addAction(openAction);

    // 工具栏中添加控件
    QPushButton *btn = new QPushButton("Button", this);
    toolBar->addWidget(btn);


    // 状态栏创建
    // 状态栏只能最多有一个！
    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);  // 设置到窗口中

    // 放置标签控件
    QLabel *label = new QLabel("Left Message", this);
    stBar->addWidget(label);

    QLabel *label2 = new QLabel("Right Message", this);
    stBar->addPermanentWidget(label2);


    // 铆接部件(浮动窗口)创建
    // 铆接部件可以有多个！
    QDockWidget *dockWidget = new QDockWidget("Float Window", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);  // 设置后期停靠区域只允许上下


    // 中心部件创建
    // 中心部件只能最多有一个！
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}
