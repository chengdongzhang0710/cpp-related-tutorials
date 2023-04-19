
// MFCTextEditorView.cpp : implementation of the CMFCTextEditorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTextEditor.h"
#endif

#include "MFCTextEditorDoc.h"
#include "MFCTextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTextEditorView

IMPLEMENT_DYNCREATE(CMFCTextEditorView, CView)

BEGIN_MESSAGE_MAP(CMFCTextEditorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCTextEditorView construction/destruction

CMFCTextEditorView::CMFCTextEditorView() noexcept
{
	// TODO: add construction code here

	this->m_point = 0;
	this->m_str = TEXT("");
}

CMFCTextEditorView::~CMFCTextEditorView()
{
}

BOOL CMFCTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTextEditorView drawing

void CMFCTextEditorView::OnDraw(CDC* /*pDC*/)
{
	CMFCTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCTextEditorView printing

BOOL CMFCTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTextEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTextEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCTextEditorView diagnostics

#ifdef _DEBUG
void CMFCTextEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTextEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTextEditorDoc* CMFCTextEditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextEditorDoc)));
	return (CMFCTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTextEditorView message handlers


// 视图创建后自动调用
int CMFCTextEditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);
	ShowCaret();

	return 0;
}


void CMFCTextEditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	SetCaretPos(point);
	m_point = point;

	m_str.Empty();

	CView::OnLButtonDown(nFlags, point);
}


void CMFCTextEditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);

	if (nChar == VK_RETURN)
	{
		m_str.Empty();
		
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		m_point.y += tm.tmHeight;
	}
	else if (nChar == VK_BACK)
	{
		COLORREF color = dc.GetBkColor();
		COLORREF oldColor = dc.SetTextColor(color);

		dc.TextOutW(m_point.x, m_point.y, m_str);

		m_str = m_str.Left(m_str.GetLength() - 1);
		dc.SetTextColor(oldColor);
		dc.TextOutW(m_point.x, m_point.y, m_str);
	}
	else
	{
		m_str += (TCHAR)nChar;
	}

	CSize size = dc.GetTextExtent(m_str);
	int x = m_point.x + size.cx;
	int y = m_point.y;
	SetCaretPos(CPoint(x, y));

	dc.TextOutW(m_point.x, m_point.y, m_str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
