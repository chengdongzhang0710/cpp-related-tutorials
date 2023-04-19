#pragma once
#include <afxwin.h>

class MyApp : public CWinApp
{
public:
	// 基类的虚函数，派生类只是重写
	// MFC程序的入口地址
	virtual BOOL InitInstance();
};

class MyFrame : public CFrameWnd
{
public:
	MyFrame();

	// 声明消息映射宏
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();
};
