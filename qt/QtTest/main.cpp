#include "widget.h"

#include <QApplication>

// 命名规范
// 类名 - 首字母大写，单词和单词之间首字母大写
// 函数名&变量名称 - 首字母小写，单词和单词之间首字母大写

// 快捷键
// 注释 - ctrl + /
// 运行 - ctrl + r
// 编译 - ctrl + b
// 字体缩放 - ctrl + 鼠标滚轮
// 查找 - ctrl + f
// 整行移动 - ctrl + shift + 上下方向键
// 帮助文档 - F1
// 自动对齐 - ctrl + i
// 同名之间的.h和.cpp切换 - F4

// argc - 命令行变量的数量，argv - 命令行变量的数组
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // 在Qt中应用程序对象有且仅有一个
    Widget w;  // 窗口对象Widget，父类QWidget
    w.show();  // 窗口对象默认不会显示，必须要调用show方法显示窗口
    return a.exec();  // 让应用程序对象进入消息循环，让代码阻塞
}
