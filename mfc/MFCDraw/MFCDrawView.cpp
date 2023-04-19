
// MFCDrawView.cpp : implementation of the CMFCDrawView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDraw.h"
#endif

#include "MFCDrawDoc.h"
#include "MFCDrawView.h"

#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawView

IMPLEMENT_DYNCREATE(CMFCDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCDrawView construction/destruction

CMFCDrawView::CMFCDrawView() noexcept
{
	// TODO: add construction code here
	m_point = 0;
	m_isPressed = false;
}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView drawing

void CMFCDrawView::OnDraw(CDC* pDC)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // 返回设置前的状态

	pDC->MoveTo(10, 10);
	pDC->LineTo(120, 10);

	pDC->SelectObject(oldPen);

	pDC->Ellipse(20, 20, 120, 120);

	CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->Ellipse(20, 20, 120, 120);

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CBrush brush2(&bitmap);
	pDC->SelectObject(&brush2);
	pDC->Ellipse(140, 20, 240, 120);

	CFont font;
	font.CreatePointFont(500, TEXT("楷体"));
	pDC->SelectObject(&font);
	pDC->TextOutW(200, 200, TEXT("你好"));
}


// CMFCDrawView printing

BOOL CMFCDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCDrawView diagnostics

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView message handlers


void CMFCDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_point = point;
	m_isPressed = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

#if 0
	CClientDC dc(this);
	dc.MoveTo(m_point);
	dc.LineTo(point);
#endif

	m_isPressed = false;

	CView::OnLButtonUp(nFlags, point);
}


void CMFCDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_isPressed)
	{
		CClientDC dc(this);
		dc.MoveTo(m_point);
		dc.LineTo(point);

		m_point = point;
	}

	CView::OnMouseMove(nFlags, point);
}
