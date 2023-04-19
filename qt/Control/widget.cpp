#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 单选按钮
    ui->rBtnMale->setChecked(true);  // 设置默认选中

    connect(ui->rBtnFemale, &QRadioButton::clicked, [=](){
        qDebug() << "Female is choosed!";
    });


    // 多选按钮
    // 0 - 未选中，2 - 选中，1 - 半选
    connect(ui->cBtnPrice, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
    });

    // ListWidget
//    QListWidgetItem *item = new QListWidgetItem("Hello World");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);  // 设置水平居中

    QStringList list;
    list << "London Bridge is falling down," << "Falling down, falling down," << "London Bridge is falling down," << "My fair Lady.";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
