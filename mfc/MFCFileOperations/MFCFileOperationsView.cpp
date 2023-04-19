
// MFCFileOperationsView.cpp : implementation of the CMFCFileOperationsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFileOperations.h"
#endif

#include "MFCFileOperationsDoc.h"
#include "MFCFileOperationsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFileOperationsView

IMPLEMENT_DYNCREATE(CMFCFileOperationsView, CView)

BEGIN_MESSAGE_MAP(CMFCFileOperationsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCFileOperationsView construction/destruction

CMFCFileOperationsView::CMFCFileOperationsView() noexcept
{
	// TODO: add construction code here

}

CMFCFileOperationsView::~CMFCFileOperationsView()
{
}

BOOL CMFCFileOperationsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCFileOperationsView drawing

void CMFCFileOperationsView::OnDraw(CDC* /*pDC*/)
{
	CMFCFileOperationsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCFileOperationsView printing

BOOL CMFCFileOperationsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCFileOperationsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCFileOperationsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCFileOperationsView diagnostics

#ifdef _DEBUG
void CMFCFileOperationsView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCFileOperationsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCFileOperationsDoc* CMFCFileOperationsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFileOperationsDoc)));
	return (CMFCFileOperationsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFileOperationsView message handlers
