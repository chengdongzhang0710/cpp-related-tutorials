# MFC进阶教程

视频教程地址：[MFC进阶教程](https://www.bilibili.com/video/BV1jb411M78M)





## 基本概念

- **API：**应用程序接口
- **WinAPI：**Windows平台下的系统调用，需要包括头文件windows.h，调用系统提供的特殊接口，得到系统的资源
- **窗口：**父窗口和子窗口，客户区和非客户区
- **句柄：**结构体类型，窗口句柄HWND，图标句柄HICO
- **消息队列、消息、窗口过程函数**





## WinAPI窗口程序

#### 创建流程

1. 定义入口函数WinMain()
2. 创建一个窗口
   1. 设计窗口类WNDCLASS(给成员变量赋值)
   2. 注册窗口类
   3. 创建窗口类
   4. 显示和更新窗口
3. 消息循环
4. 窗口过程函数



#### 参考文档

- MSDN：WinAPI，MFC
- MFC参考文档





## MFC程序

- 应用程序类：CWinApp
- 框架类：CFrameWnd



#### MFC创建流程

1. 有且只有一个全局的应用程序类对象
2. 在程序入口函数实现功能 InitInstance()
   1. 给框架类MyFrame对象动态分配空间(自动调用它的构造函数)
      1. 框架类MyFrame对象构造函数函数里创建窗口 CWnd::Create()
   2. 框架类对象显示窗口 CWnd::ShowWindow()
   3. 框架类对象更新窗口 CWnd::UpdateWindow()
   4. 保存框架类对象指针 CWinThread::m_pMainWnd



#### 事件处理

消息映射

1. 所操作类中声明消息映射宏 DECLARE_MESSAGE_MAP()
2. 对应的.cpp文件定义宏
3. 对应类中消息处理函数的声明
4. 对应.cpp文件中消息处理函数的定义





## 根据向导创建工程

#### 文档视图结构

- 文档：它是一个类，这个类专门来存储数据
- 视图：它是一个类，这个类专门来显示和修改数据
- 框架类：它是一个容器，这个容器装了视图



#### 几个比较重要的函数

- 应用程序类 CWinApp
  - InitInstance()：程序的入口地址
- 框架类 CFrameWnd
  - PreCreateWindow()：创建窗口程序之前调用
  - OnCreate()：创建窗口后触发WM_CREATE，它是WM_CREATE消息的处理函数
- 视图类 CView
  - OnDraw()：绘图，WM_PAINT消息处理函数OnPaint()内部调用OnDraw()，OnPaint()和OnDraw()同时存在，只有OnPaint()有效



#### 事件的添加和删除

- 框架和视图的区别
  - 框架相当于容器，容器放视图
  - 视图相当于壁纸，我们点击窗口，只有视图响应，框架被视图挡住，无法响应



#### 字符集

- ANSI：多字节(单字节)，char p[] = "abc";  // 一个字符一个字节，用strlen()
- Unicode：宽字节，TCHAR* p = L"abc";  // 一个字符两个字节，用wcslen()
- MFC：
  - TCHAR：自动适应字节(条件编译)
  - TEXT()，_T()



#### 拓展

- afx_xxx：全局函数，不属于某个类特有的
- xxxEx，xxxW：拓展函数



#### MFC命名规范

- 类名和函数名：单词首字母大写
- 形参：isFlag，isPressTest……
- 成员变量：m_xxx





## 简单绘图

#### 画直线

1. 鼠标按下和抬起
2. 创建画家对象 CClientDC
3. 起点和终点
   - CDC::MoveTo()
   - CDC::LineTo()



#### 画笔、画刷的使用

1. 定义画家 CDC
2. 定义画笔(画刷)  CPen(CBrush)
   - 画刷：单色，样式，位图

3. 把画笔交给画家 CDC::SelectObject()



#### 写字

1. CFont的使用





## 文本编辑器

1. 创建插入符
   1. 创建 CWnd::CreateSolidCaret()
   2. 显示 CWnd::ShowCaret()
   3. 插入符的高度是根据字体的高度来确定，获取字体信息 CDC::GetTextMetrics()
   4. 设置插入符的位置 CWnd::SetCaretPos()
2. 在字符消息处理函数中写字
   1. 写字 CDC::TextOutW()
   2. 获取字符串的尺寸信息 CDC::GetTextExtent()
   3. 获取背景色 CDC::GetBkColor()
   4. 设定字体颜色 CDC::SetTextColor()
   5. 截取字符串(CString)左边指定长度的字符 str = str.Left(str.GetLength() - 1);





## 字体渐变

1. 定时器的使用
   1. 设置定时器 CWnd::SetTimer()
   2. 关闭定时器 CWnd::KillTimer()
   3. 定时器消息 WM_TIMER
2. 视图类中的OnDraw()中写字 CDC::TextOutW()
3. 指定区域写字 CDC::DrawText()
4. 让窗口失效，产生WM_PAINT，间接调用OnDraw()函数 CWnd::Invalidate





## 菜单的相关操作

#### 菜单的命令响应函数

- 弹式菜单，ID不可编辑，Popup属性为True，按下去，弹出一个菜单项
- 非弹式菜单，ID可编辑，Popup属性为False
- 菜单响应命令消息的路由(顺序)
  - frame => (1) view => (2) doc => view => (3) frame => (4) app
- 消息类型
  - 命令消息WM_COMMAND：菜单处理函数选中
  - 标准消息：属性 => 消息
  - 通告消息：点击按钮，处理函数
  - 注意！CWnd可以接收任何消息，CCmdTarget不能接收标准消息



#### 菜单相关静态操作

在框架类中进行相应操作，在OnCreate()中实现

- 获取菜单栏 CWnd::GetMenu()
- 获取菜单栏中的子菜单 CMenu::GetSubMenu()
  - 标志菜单 CMenu::CheckMenuItem()
    - 通过位置 MF_BYPOSITION
    - 通过ID MF_BYCOMMAND
  - 设置默认菜单 CMenu::SetDefaultItem()
    - 注意：一个菜单项只能设置一个默认菜单
  - 禁用菜单 CMenu::EnableMenuItem()
    - 注意：需要把CFrameWnd::m_bAutoMenuEnable成员变量设置为FALSE
  - 分隔线：分隔线也占一个位置，在使用MF_BYPOSITION时需要注意
- 移除菜单 CWnd::SetMenu()
  - SetMenu(NULL);
- 装载菜单
  - 创建菜单 CMenu::LoadMenu()
  - 设置菜单 CWnd::SetMenu()
  - 从CMenu对象中分离Windows菜单 CMenu::Detach()
- 菜单命令更新机制：菜单更新是内部自动更新的
- 快捷菜单，弹出菜单：由于鼠标点击的区域是在视图区域，所以需要在视图类中处理
  - 注意！一定要新建菜单，不能使用框架类的主菜单
  - 处理鼠标右击事件WM_RBUTTONDOWN
  - 获取所需的子菜单
  - 弹出菜单项 CMenu::TrackPopupMenu()
  - 客户区坐标转屏幕坐标 CWnd::ClientToScreen()



#### 菜单相关动态操作

- 创建空菜单 CMenu::CreateMenu()
- 追加弹式菜单 CMenu::AppendMenu(MF_POPUP, )
  - 每个菜单都有一个菜单句柄 CMenu::m_hMenu
  - 重画菜单条 CWnd::DrawMenuBar()
- 追加普通菜单 CMenu::AppendMenu(MF_STRING, )
- 插入菜单 CMenu::InsertMenu()
- 删除菜单 CMenu::DeleteMenu()





## 动态图标

- 定时器 CWnd::SetTimer()
  - 定时器信号 WM_TIMER
  - 设置定时器应该放在OnCreate()
- 加载自定义图标 (WinAPI) LoadIcon() / (MFC) CWinApp::LoadIcon()
  - 将资源ID转换为字符串 MAKEINTRESOURCE()
  - 获取应用程序实例 AfxGetInstanceHandle() AfxGetApp()->m_hInstance
- 设置图标(WinAPI) SetClassLong()
  - 窗口句柄 CWnd::m_hWnd





## 对话框

#### 模态对话框

1. 资源视图 => Dialog => 右击 => 插入Dialog
2. 创建对话框对象CDialog
3. 以模态方式运行CDialog::DoModal()



#### 非模态对话框

1. 资源视图 => Dialog => 右击 => 插入Dialog
2. 创建对话框对象，需要在.h的地方声明为成员变量CDialog
3. 创建对话框(在构造函数或OnCreate()，目的只创建一次) CDialog::Create()
4. 显示窗口 CWnd::ShowWindow



#### 自定义对话框类

1. 资源视图 => Dialog => 右击 => 插入Dialog
2. 点击对话框模板 => 右击 => 添加类
3. 多出来一个自定义类，.h类中有个枚举和对话框关联 enum{ IDD = IDD_DIALOG2 };





## 基于对话框(控件)编程

#### 基于对话框应用程序框架

- 应用程序类：继承于CWinApp
  - InitInstance() - 程序的入口地址
- 对话框类：继承于CDialogEx
  - OnInitDialog() - 对话框的初始化工作
  - DoDataExchange - 控件和变量的关联和交换





## 常用控件

#### 静态控件CStatic

Qt中的标签QLabel，显示一些文字信息

- Caption - 修改显示的内容
- ID - XXX_STATIC，静态ID，不响应任何消息(事件)，不能关联控件变量



#### 按钮CButton

- Caption - 修改显示的内容
- 消息处理 BN_CLICKED，用户点击按钮自动触发
  - 属性 => 控制事件 => 选择所需事件
  - 双击按钮，自动生成消息处理函数



#### 逃跑按钮

类似于Qt提升

1. 自定义按钮类，继承于CButton，选择类视图最开始的文件夹 => 右击 => 添加类 => MFC => MFC类
   1. 处理鼠标移动消息 WM_MOUSEMOVE
   2. 获取父窗口指针 CWnd::GetParent()
   3. 获取父窗口客户区域的范围 CWnd::GetClientRect()
   4. 获取按钮的范围 CWnd::GetWindowRect()
   5. 产生随机坐标 rand() % w
   6. 移动按钮的位置 CWnd::MoveWindow()
2. 关联变量，选中按钮 => 右击 => 添加变量 => 变量类型 - MyButton => 变量 - button，最终button和我们所选中的按钮关联成功，操作button，相当于操作UI上的按钮(Qt的提升)
3. 为按钮设置位图
   1. 按钮属性 Bitmap => True
   2. 在对话框类中OnInitDialog()做如下处理
      1. 创建位图模板
      2. 创建位图对象 CBitmap
      3. 加载位图资源 CBitmap::LoadBitmap()
      4. 按钮设置位图 CButton::SetBitmap()
      5. 获取位图大小 CBitmap::GetBitmap()
      6. 重新设置按钮大小(图片和按钮大小一致) CWnd::MoveWindow()



#### 编辑框CEdit

- 关联类别 - Value，Control
  - Value - 标准普通数据类型(CString str;)，关联变量和控件数据的交互更新：
    - 把编辑区的内容更新到str中 UpdateData(TRUE);
    - 把str的内容更新到编辑区中 UpdateData(FALSE);
  - Control - 控件类型，控件类型的对象即为UI上的控件
- 常用属性设置
  - Number => True 只能输入数字
  - Password => True 密码模式
  - Want Return => True 接收回车键，自动换行，只有在多行模式下才能换行
  - Multiline => True 多行模式
  - Auto VScroll => True，Vertical Scroll => True 当垂直方式字符太多，自动出现滚动条
  - Read Only => True 只读
- 复制小案例
  1. 获取编辑区内容 CWnd::GetWindowText()
  2. 设置编辑区内容 CWnd::SetWindowText()
  3. 关闭对话框窗口 CDialog::OnOK()，CDialog::OnCancel()



#### 单选框、复选框

特殊的CButton，没有单选框、复选框类型

- 单选框
  1. 属性设置：顺序排放，Ctrl + D查看
  2. 同组第一个按钮Group设置为True
  3. 初始化单选框 CWnd::CheckRadioButton()
  4. 按钮是否按下 CWnd::IsDlgButtonChecked()
- 复选框
  1. 常关联变量BOOL UpdateData(TRUE)，UpdateData(FALSE)
  2. 设置按钮选择状态 CButton::SetCheck()
  3. 获取按钮选择状态 CButton::GetCheck()



#### 列表框CListBox

- 给列表框加一个字符串 CListBox::AddString()
- 选中列表列表框某一项，自动触发事件 LBN_SELCHANGE
  - 获取当前选中项 CListBox::GetCurSel()
  - 获取指定位置的内容 CListBox::GetText()
- 删除指定位置的字符串 CListBox::DeleteString()
- 在指定位置插入字符串 CListBox::InsertString()



#### 组合框(下拉框)CComboBox

- 获取内容 CComboList::GetLBText()，其他接口和CListBox的用法几乎一样
- 属性设置
  - Data - 设置内容，不同内容间同英文的分号";"分隔
  - Type



#### 滚动条CScrollBar

- 设置给定滚动条的最小和最大位置 CScrollBar::SetScrollRange()
- 获取一个滚动框的当前位置 CScrollBar::GetScrollPos()
- 设置一个滚动框的当前位置 CScrollBar::SetScrollPos()
- 处理滚动条的事件，不是在滚动条控件本身处理，是在滚动条所属的父窗口处理(对话框类)
  - 处理信号 WM_HSCROLL
- 滚动条位置关系

```c++
switch (nSBCode)  // 判断滚动条的哪一部分
{
    case SB_THUMBPOSITION:  // 滑块位置
        break;
    case SB_LINELEFT:  // 向左的箭头
        break;
    case SB_LINERIGHT:  // 向右的箭头
        break;
    case SB_PAGELEFT:  // 箭头和滑块之间左边
        break;
    case SB_PAGERIGHT:  // 箭头和滑块之间右边
        break;
    default:
        break;
}
```



#### 微调(旋转)按钮SpinControl

- 属性设置
  - Auto Buddy => True
  - Set Buddy Integer => True
- 微调(旋转)按钮的顺序比伙伴大1(Ctrl + D查看)



#### 列表视图控件CListCtrl

- 属性设置 View => Report
- 常用接口
  - 设置列表风格 CListCtrl::SetExtendStyle()
    - LVS_EX_FULLROWSELECT 选择整行
    - LVS_EX_GRIDLINES 网格方式
    - 具体有哪些风格，可通过MSDN查看
  - 获取列表风格 CListCtrl::GetExtendStyle()
    - 具体有哪些风格，可通过MSDN查看
  - 插入某列 CListCtrl::InsertColumn()
  - 字符串格式化 CString str; str.Format(TEXT("Student%d"), i);
  - 插入新项后，才能设置子项内容
    - 插入新项(确定第几行) CListCtrl::InsertItem()
    - 设置子项内容(设置第几列) CListCtrl::SetItemText()



#### 树视图控件CTreeCtrl

- 常用属性设置
  - Has Buttons => True
  - Has Lines => True
  - Lines at Root => True
- 写代码流程
  1. 加载自定义图标
     1. 获取应用程序对象指针 AfxGetApp()
     2. 加载自定义图标 CWinApp::LoadIcon()
  2. 创建图像列表
     1. .h文件类中定义图形列表CImageList对象
     2. 创建图像列表 CImageList::Create()
     3. 图像列表追加图标 CImageList::Add()
  3. 设置图形状态列表 CTreeCtrl::SetImageList()
  4. 插入节点 CTreeCtrl::InsertItem()
  5. 设置默认选中项 CTreeCtrl::SelectItem()



#### 标签控件CTabCtrl

1. 在UI工具箱拖放Tab Control
2. 把TabSheet.h和TabSheet.cpp放在项目文件同级目录，并且添加到工程目录中
3. 给UI上TabControl关联Control类型(CTabSheet)
4. CTabSheet对象添加对话框
   1. 资源视图 => Dialog => 右击 => 插入Dialog
   2. 设置相应属性
      1. Style => Child 子窗口
      2. Border => None 无边框
   3. 自定义类：点击对话框模板 => 右击 => 添加类
   4. 主对话框类中，定义自定义类对象
   5. 主对话框类中，OnInitDialog()做初始化工作
   6. CTabSheet添加对话框 CTabSheet::AddPage()，tmp.AddPage(TEXT("系统管理"), &t1, tab1);
      - tmp - 为CTabSheet对象
      - t1 - 需要添加对话框对象
      - tab1 - 对话框ID
   7. 显示窗口 CTabSheet::Show()





## 文档视图结构

文档类CDocument：存储加载(读写)数据

视图类CView：显示和修改数据



#### 单文档

- 文档模板：把框架窗口、文档、视图关联在一起
- 文档类CDocument：
  - OnNewDocument() - 第一次新建窗口调用，后面每次按“新建”，自动调用此函数
  - DeleteContents() - 做一些释放资源的操作，每次按“新建”，新建前先调用此函数
- 框架类可以认为是视图类的容器



#### 各类相关访问

- 在视图类访问文档对象指针
  - CView::GetDocument()
  - CDocument* GetDocument() const;





## 文档序列化

二进制操作文件(CArchive)，相当于Qt QDataStream

- 序列化：以二进制方式写文件
- 反序列化：以二进制方式读文件



#### 写文件

1. 创建文件对象CFile
2. 以写方式打开文件 CFile::Open()
3. 创建序列化对象，并且和文件关联在一起
   - CArchive::store() - 把数据保存到归档文件中，允许CFile写操作
4. 往数据流写数据(相当于往文件写数据)
   - ar << a << b << c
5. 断开数据流和文件的关联 CArchive::Close()
6. 关闭文件 CFile::Close()



#### 读文件

1. 创建文件对象CFile
2. 以读方式打开文件 CFile::Open()
3. 创建序列化对象，并且和文件关联在一起
   - CArchive::load() - 从归档文件装载数据，CFile只读
4. 往数据流读数据(相当于往文件读数据)
   - ar >> a >> b >> c
5. 断开数据流和文件的关联 CArchive::Close()
6. 关闭文件 CFile::Close()





## 文档视图案例

#### 文档类自带序列化操作函数Serialize()

```c++
void CMy01_CArchiveDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO 在此添加存储代码
        // 按保存按钮时调用
    }
    else
    {
        // TODO 在此添加加载代码
        // 按打开按钮时调用
    }
}
```



#### 学生管理系统

1. 定义一个学生类Stu
2. 文档类存储数据，视图类修改和显示数据
   1. 从尾部添加元素 CList::AddTail()
   2. 获取此列表尾部元素的位置 CList::GetTailPosition()
   3. 获取上一个元素 CList::GetPrev()
   4. 获取下一个元素 CList::GetNext()
   5. 获取首元素位置 CList::GetHeadPosition()
   6. 获取最后一个元素位置 CList::GetTailPosition()
   7. 获取指定位置的元素 CList::GetAt()
   8. 移除头结点元素(并没有释放空间) CList::RemoveHead()
3. 视图的基类是CFormView
4. 重写文档类DeleteContents()，做一些释放资源的操作，每次按“新建”，新建前先调用此函数

