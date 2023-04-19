# Qt从入门到实战

视频教程地址：[Qt从入门到实战](https://www.bilibili.com/video/BV1g4411H78N)





## 简介

#### 创建Qt程序

- 点击创建项目后，选择项目路径以及给项目起名称
- 名称 - 不能有中文，不能有空格
- 路径 - 不能有中文路径
- 创建默认窗口类myWidget，基类有三种选择：QWidget，QMainWindow，QDialog
- main函数
  - QApplication a - 应用程序对象，有且仅有一个
  - myWidget w - 实例化窗口对象
  - w.show() - 调用show函数显示窗口
  - return a.exec() - 让应用程序对象进入消息循环机制中，代码阻塞到当前行



#### 按钮控件常用API

- 创建 - QPushButton* btn = new QPushButton;
- 设置父亲 - setParent(this);
- 设置文本 - setText("TEXT");
- 设置位置 - move(WIDTH, HEIGHT);
- 重新指定窗口大小 - resize()
- 设置窗口标题 - setWindowTitle()
- 设置窗口固定大小 - setFixedSize()



#### 对象树

- 当创建的对象在堆区时，如果指定的父亲是QObject派生下的类或者QObject子类派生下的类，可以不用管理释放的操作，会将对象放入到对象树中
- 在一定程度上简化了内存回收机制



#### 坐标系

- 左上角为(0, 0)点
- x以右为正方向，y以下为正方向





## 信号和槽

#### 信号和槽

- 连接函数 - connect
- 参数
  - 参数1 - 信号的发送者
  - 参数2 - 发送的信号(函数地址)
  - 参数3 - 信号的接收者
  - 参数4 - 处理的槽函数(函数地址)
- 松散耦合
- 实现点击按钮关闭窗口的案例
  - connect(btn, &QPushButton::click, this, &QWidget::close);



#### 自定义信号

- 写到signals下
- 返回void
- 需要声明，不需要实现
- 可以有参数，可以重载



#### 自定义槽函数

- 写到public slot下或者public下或者全局函数
- 返回void
- 需要声明，也需要实现
- 可以有参数，可以重载



#### 触发自定义的信号

- emit 自定义信号



#### 自定义的信号和槽发生重载的解决

- 需要利用函数指针明确指向函数的地址
  - void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
  - void(Student::*studentSlot)(QString) = &Student::treat;



#### QString转成char*

- .toUtf8()转为QByteArray
- .data()转为char*



#### 拓展

- 信号可以连接信号
- 一个信号可以连接多个槽函数
- 多个信号可以连接同一个槽函数
- 信号和槽函数的参数必须必须类型一一对应
- 信号的参数个数可以多于槽函数的参数个数
- 信号槽可以断开连接 - disconnect



#### Qt4版本写法

- connect(信号发送者, 发送的信号SIGNAL(信号), 信号接受者, 槽函数SLOT(槽函数))
- 优点：参数直观；缺点：编译器不会检测参数类型



#### Lambda表达式

- [] - 标识符，匿名函数
  - = - 值传递
  - & - 引用传递
- () - 参数
- {} - 实现体
- mutable - 修饰值传递变量，可以修改拷贝出的数据，改变不了本体
- 返回值 - \[\]()->int{}





## QMainWindow

#### 菜单栏

菜单栏最多有一个

- QMenuBar *bar = MenuBar();
- setMenuBar(bar);
- QMenu *fileMenu = bar->addMenu("File"); - 创建菜单
- QAction *newAction = fileMenu->addAction("New"); - 创建菜单项
- fileMenu->addSeparator(); - 添加分割线



#### 工具栏

工具栏可以有多个

- QToolBar *toolBar = new QToolBar(this);
- addToolBar(默认停靠区域/Qt::LeftToolBarArea, toolBar);
- 设置后期停靠区域，设置浮动，设置移动
- 添加菜单项或者添加小控件



#### 状态栏

状态栏最多有一个

- QStatusBar *stBar = statusBar();
- setStatusBar(stBar); - 设置到窗口中
- stBar->addWidget(label); - 放置左侧信息
- stBar->addPermanentWidget(label2); - 放置右侧信息



#### 铆接部件(浮动窗口)

铆接部件可以有多个

- QDockWidget *dockWidget = new QDockWidget("Float Window", this);
- addDockWidget(默认停靠区域, 浮动窗口指针);
- 设置后期停靠区域



#### 核心部件

核心部件只能有一个

- setCentralWidget(edit);



#### 资源文件

- 将图片文件拷贝到项目位置下
- 右键项目 => 添加新文件 => Qt => Qt Resource File => 给资源文件起名
- resource生成resource.qrc
- open in editor编辑资源
- 添加前缀 => 添加文件
- 使用": + 前缀名 + 文件名"





## 对话框

#### 模态对话框

不可以对其他窗口进行操作(阻塞)

- QDialog dlg(this);
- dlg.exec();



#### 非模态对话框

可以对其他窗口进行操作

- QDialog *dlg = new QDialog(this); - 防止对话框一闪而过创建到堆区
- dlg->show();
- dlg->setAttribute(Qt::WA_DeleteOnClose);



#### 消息对话框

- QMessageBox - 静态成员函数创建对话框
- 错误，信息，提问，警告
- 参数1 - 父亲，参数2 - 标题，参数3 - 显示内容，参数4 - 按键类型，参数5 - 默认关联回车按键
- 返回值是StandardButton类型，利用返回值判断用户的输入



#### 其他标准对话框

- 颜色对话框 - QColorDialog::getColor();
- 文件对话框 - QFileDialog::getOpenFileName(父亲, 标题, 默认路径, 过滤文件);
- 字体对话框 - QFontDialog::getFont();





## 界面布局

#### 实现登录窗口

- 利用布局方式给窗口进行美化
- 选取Widget进行布局，水平布局、垂直布局、栅格布局
- 给用户名、密码、登录、退出按钮进行布局
- 默认窗口和控件之间有9间隙，可以调整layoutLeftMargin/layoutRightMargin/layoutTopMargin/layoutButtonMargin
- 利用弹簧进行布局





## 控件

#### 按钮组

- QPushButton - 常用按钮
- QToolButton - 工具按钮，用于显示图片
  - 如果想显示文字，修改风格 - toolButtonStyle
  - 凸起风格 - autoRaise
- QRadioButton - 单选按钮
  - 设置默认 - setChecked(true);
- QCheckBox - 多选按钮
  - 监听状态，2 - 选中，1 - 半选，0 - 未选中



#### QListWidget(列表容器)

- QListWidgetItem *item - 一行内容
- ui->listWidget->addItem(item);
- item->setTextAlignment(Qt::AlignHCenter); - 设置居中方式
- 可以利用addItems一次性添加多行内容



#### QTreeWidget(树控件)

- 设置头 - ui->treeWidget->setHeaderLabels();
- 创建根节点 - QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << "Content");
- 添加根节点到树控件上 - ui->treeWidget->addTopLevelItem(item);
- 添加子节点 - item->addChild();



#### QTableWidget(表格控件)

- 设置列数 - ui->tableWidget->setColumnCount(3);
- 设置水平表头 - ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Gender" << "Age");
- 设置行数 - ui->tableWidget->setRowCount(5);
- 设置正文 - ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Arthur"));



#### 其他控件

- StackWidget(栈控件)
  - ui->stackedWidget->setCurrentIndex(0);
- 下拉框
  - ui->comboBox->addItem("Benz");
- QLabel显示图片
  - ui->lbl_Image->setPixmap(QPixmap(":/image/demo.bmp"));
- QLabel显示动图(gif图片)
  - ui->lbl_Movie->setMovie(movie);
  - movie->start();



#### 自定义控件封装

- 添加新文件：Qt - 设计师界面类(.h/.cpp/.ui)
- .ui中设计QSpinBox和QSlider两个控件
- Widget中使用自定义控件，拖拽一个Widget，点击提升为，点击添加，点击提升
- 实现功能：改变数字，滑动条跟着移动，信号槽监听
- 提供getNumber()和setNumber()对外接口
- 测试接口





## 事件

#### 鼠标事件

- 鼠标进入事件 - enterEvent()
- 鼠标离开事件 - leaveEvent()
- 鼠标按下事件 - mousePressEvent()
- 鼠标释放事件 - mouseReleaseEvent()
- 鼠标移动事件 - mouseMoveEvent()
- event->x() - x坐标，event->y() - y坐标
- event->button() - 可以判断所有按键(Qt::LeftButton，Qt::RightButton，Qt::MidButton)
- event->buttons() - 可以判断组合按键，判断鼠标移动时候的左右键，结合&操作符
- 格式化字符串 - QString("%1 %2").arg().arg();



#### 定时器

- 利用事件void timerEvent(QTimerEvent *event)
  - 启动定时器 - startTimer(毫秒);
  - timerEvent的返回值是定时器的唯一标识符，可以和event->timerId()作比较
- 利用定时器类QTimer
  - 创建定时器对象 - QTimer *timer = new QTimer(this);
  - 启动定时器 - timer->start(毫秒);
  - 每隔一定毫秒发送信号QTimer::timeout进行监听
  - 暂停 - timer->stop();



#### event事件

- 用途：用于事件分发，也可以做拦截操作，但是不建议
- bool event(QEvent* event);
  - 返回值如果是true，代表用户处理这个事件，不用向下分发
- event->type() == 鼠标按下…… - 用于判断事件类型



#### 事件过滤器

- 在程序将事件分发到事件分发器之前，可以利用过滤器做拦截
- 步骤：
  - 给控件安装事件过滤器
  - 重写eventFilter函数





## QPainter绘图

#### 绘图事件

- 绘图事件 - void paintEvent();
- 声明一个画家对象 - QPainter painter(this);  // this指定绘图设备
- 画线、画圆、画矩形、画文字
- 设置画笔QPen：设置画笔宽度、风格
- 设置画刷QBrush：设置画刷风格



#### QPainter绘图高级设置

- 抗锯齿(效率低) - painter.setRenderHint(QPainter::Antialiasing);
- 对画家进行移动 - painter.translate(100, 0);
- 保存画家状态 - painter.save();
- 还原画家状态 - painter.restore();



#### 手动调用绘图事件

- 如果想手动调用绘图事件，利用update()
- 利用画家绘制图片 - painter.drawPixmap(x, y, QPixmap(name));



#### QPaintDevice绘图设备

QPixmap, QIamge, QBitmap(黑白色), QPicture, QWidget

- QPixmap：对不同平台做了显示优化
  - QPixmap pix(300, 300);
  - pix.fil(填充颜色);
  - 利用画家往pix上画画 - QPainter painter(&pix);
  - 保存 - pix.save("路径");
- QImage：可以对像素进行访问
  - 使用和QPixmap差不多 - QImage img(300, 300, **QImage::Format_RGB32**);
  - 其他流程和QPixmap一样
  - 可以对像素进行修改 - img.setPixel(i, j, value);
- QPicture：记录和重现绘图指令
  - QPicture pic;
  - painter.begin(&pic);
  - painter.end();
  - 保存 - pic.save(任意后缀名);
  - 利用画家可以重现 - painter.drawPicture(0, 0, pic);





## 文件操作

#### QFile进行文件读写操作

- QFile file(path);
- 读文件
  - file.open(QIODevice::ReadOnly);
  - 全部读取 - file.readAll();
  - 按行读取 - file.readLine();
  - 判断是否读到文件尾 - file.atEnd();
  - 默认支持编码格式UTF-8
  - 利用编码格式类指定格式 - QTextCodec
    - QTextCodec *codec = QTextCodec::codecForName("gbk");
    - ui->textEdit->setText(codec->toUnicode(arr));
  - 文件对象关闭 - file.close();
- 写文件
  - file.open(QIODevice::WriteOnly / QIODevice::Append);
  - file.write(内容);
  - file.close();



#### QFileInfo读取文件信息

- QFileInfo info(path);
- 大小 - file.size();
- 后缀名 - file.suffix();
- 文件名称 - file.fileName();
- 文件路径 - file.filePath();
- 创建日期 - file.create().toString("yyyy/MM/dd hh:mm:ss");
- 最后修改日期 - file.lastModified().toString("yyyy/MM/dd hh:mm:ss");
