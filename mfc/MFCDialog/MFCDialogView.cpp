
// MFCDialogView.cpp : implementation of the CMFCDialogView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDialog.h"
#endif

#include "MFCDialogDoc.h"
#include "MFCDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDialogView

IMPLEMENT_DYNCREATE(CMFCDialogView, CView)

BEGIN_MESSAGE_MAP(CMFCDialogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCDialogView construction/destruction

CMFCDialogView::CMFCDialogView() noexcept
{
	// TODO: add construction code here

}

CMFCDialogView::~CMFCDialogView()
{
}

BOOL CMFCDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCDialogView drawing

void CMFCDialogView::OnDraw(CDC* /*pDC*/)
{
	CMFCDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCDialogView printing

BOOL CMFCDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCDialogView diagnostics

#ifdef _DEBUG
void CMFCDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDialogDoc* CMFCDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDialogDoc)));
	return (CMFCDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDialogView message handlers
