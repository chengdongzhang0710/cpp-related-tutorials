
// MFCFilePaintsView.cpp : implementation of the CMFCFilePaintsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFilePaints.h"
#endif

#include "MFCFilePaintsDoc.h"
#include "MFCFilePaintsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFilePaintsView

IMPLEMENT_DYNCREATE(CMFCFilePaintsView, CView)

BEGIN_MESSAGE_MAP(CMFCFilePaintsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCFilePaintsView construction/destruction

CMFCFilePaintsView::CMFCFilePaintsView() noexcept
{
	// TODO: add construction code here

}

CMFCFilePaintsView::~CMFCFilePaintsView()
{
}

BOOL CMFCFilePaintsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCFilePaintsView drawing

void CMFCFilePaintsView::OnDraw(CDC* pDC)
{
	CMFCFilePaintsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	for (int i = 0; i < pDoc->m_num; i++)
	{
		pDC->Ellipse(pDoc->m_pt[i].x - 5, pDoc->m_pt[i].y - 5, pDoc->m_pt[i].x + 5, pDoc->m_pt[i].y + 5);
	}
}


// CMFCFilePaintsView printing

BOOL CMFCFilePaintsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCFilePaintsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCFilePaintsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCFilePaintsView diagnostics

#ifdef _DEBUG
void CMFCFilePaintsView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCFilePaintsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCFilePaintsDoc* CMFCFilePaintsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFilePaintsDoc)));
	return (CMFCFilePaintsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFilePaintsView message handlers


void CMFCFilePaintsView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CMFCFilePaintsDoc* pDoc = GetDocument();

	if (pDoc->m_num > 200)
	{
		pDoc->m_num = 200;
		return;
	}

	pDoc->m_pt[pDoc->m_num] = point;
	pDoc->m_num++;

	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
