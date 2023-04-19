
// MFCChangeIconView.cpp : implementation of the CMFCChangeIconView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCChangeIcon.h"
#endif

#include "MFCChangeIconDoc.h"
#include "MFCChangeIconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCChangeIconView

IMPLEMENT_DYNCREATE(CMFCChangeIconView, CView)

BEGIN_MESSAGE_MAP(CMFCChangeIconView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCChangeIconView construction/destruction

CMFCChangeIconView::CMFCChangeIconView() noexcept
{
	// TODO: add construction code here

}

CMFCChangeIconView::~CMFCChangeIconView()
{
}

BOOL CMFCChangeIconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCChangeIconView drawing

void CMFCChangeIconView::OnDraw(CDC* /*pDC*/)
{
	CMFCChangeIconDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCChangeIconView printing

BOOL CMFCChangeIconView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCChangeIconView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCChangeIconView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCChangeIconView diagnostics

#ifdef _DEBUG
void CMFCChangeIconView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCChangeIconView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCChangeIconDoc* CMFCChangeIconView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCChangeIconDoc)));
	return (CMFCChangeIconDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCChangeIconView message handlers
