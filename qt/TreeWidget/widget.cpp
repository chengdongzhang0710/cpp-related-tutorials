#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // TreeWidget树控件使用
    // 设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "Name" << "Introduction");

    QTreeWidgetItem *rItem = new QTreeWidgetItem(QStringList() << "Romance");
    QTreeWidgetItem *sItem = new QTreeWidgetItem(QStringList() << "Sci-Fi Movie");

    // 加载顶层的节点
    ui->treeWidget->addTopLevelItem(rItem);
    ui->treeWidget->addTopLevelItem(sItem);

    // 追加子节点
    QTreeWidgetItem *r1 = new QTreeWidgetItem(QStringList() << "Titanic" << "A seventeen-year-old aristocrat falls in love with a kind but poor artist aboard the luxurious, ill-fated R.M.S. Titanic.");
    rItem->addChild(r1);

    QTreeWidgetItem *r2 = new QTreeWidgetItem(QStringList() << "Love Story" << "A boy and a girl from different backgrounds fall in love regardless of their upbringing - and then tragedy strikes.");
    rItem->addChild(r2);
}

Widget::~Widget()
{
    delete ui;
}
