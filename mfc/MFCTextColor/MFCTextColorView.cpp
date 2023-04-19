
// MFCTextColorView.cpp : implementation of the CMFCTextColorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTextColor.h"
#endif

#include "MFCTextColorDoc.h"
#include "MFCTextColorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTextColorView

IMPLEMENT_DYNCREATE(CMFCTextColorView, CView)

BEGIN_MESSAGE_MAP(CMFCTextColorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCTextColorView construction/destruction

CMFCTextColorView::CMFCTextColorView() noexcept
{
	// TODO: add construction code here

}

CMFCTextColorView::~CMFCTextColorView()
{
}

BOOL CMFCTextColorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTextColorView drawing

void CMFCTextColorView::OnDraw(CDC* /*pDC*/)
{
	CMFCTextColorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCTextColorView printing

BOOL CMFCTextColorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTextColorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTextColorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCTextColorView diagnostics

#ifdef _DEBUG
void CMFCTextColorView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTextColorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTextColorDoc* CMFCTextColorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextColorDoc)));
	return (CMFCTextColorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTextColorView message handlers


int CMFCTextColorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	// 1 - 定时器ID
	// 500 - 时间间隔，以毫秒为单位
	// NULL - 使用系统默认的处理函数，每个500毫秒触发WM_TIMER
	//SetTimer(1, 500, NULL);
	SetTimer(1, 100, NULL);

	return 0;
}


void CMFCTextColorView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	if (nIDEvent == 1)
	{
		static int w = 0;
		w += 5;

		CString str = TEXT("轨道上的猫 银河里的序曲 逃离而出 从这里看到的才是更精彩的世界");
		CClientDC dc(this);
		CSize size = dc.GetTextExtent(str);

		if (w > size.cx)
		{
			w = 0;
			Invalidate();  // 重新刷新窗口
		}

		int x = 30;
		int y = 30;
		CRect rect(x, y, x + w, y + size.cy);

		dc.TextOutW(x, y, str);

		dc.SetTextColor(RGB(255, 0, 0));
		dc.DrawText(str, &rect, DT_LEFT);
	}

#if 0
	static int i = 0;
	i++;

	CString str;
	str.Format(TEXT("%d"), i);

	if (i == 5)
	{
		KillTimer(1);
	}

	MessageBox(str);
#endif

	CView::OnTimer(nIDEvent);
}
