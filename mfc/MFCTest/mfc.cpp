#include "mfc.h"

// 有且只有一个全局的应用程序类对象
MyApp myApp;

BOOL MyApp::InitInstance()
{
	/*
	1. 创建框架类对象
	2. 显示窗口
	3. 更新窗口
	4. 保存框架类对象指针
	*/

	// 创建框架类对象
	MyFrame* frame = new MyFrame;

	// 显示窗口
	frame->ShowWindow(SW_SHOWNORMAL);

	// 更新窗口
	frame->UpdateWindow();

	// 保存框架类对象指针
	m_pMainWnd = frame;

	return TRUE;
}

// 定义消息映射宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)  // MyFrame - 派生类名；CFrameWnd - 基类名
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	// CWnd类的成员函数
	// CFrameWnd继承于CWnd
	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint)
{
	// CWnd::MessageBox
	MessageBox(TEXT("Mouse Left Button Down"));
}

void MyFrame::OnPaint()
{
	CPaintDC cdc(this);
	cdc.TextOutW(100, 100, TEXT("Hello MFC"));
}
