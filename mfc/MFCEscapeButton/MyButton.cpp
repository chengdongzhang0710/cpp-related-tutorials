// MyButton.cpp : implementation file
//

#include "pch.h"
#include "MFCEscapeButton.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton message handlers




void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	int x = rand() % 400;
	int y = rand() % 400;

	this->MoveWindow(x, y, 55, 64);

	CButton::OnMouseMove(nFlags, point);
}
