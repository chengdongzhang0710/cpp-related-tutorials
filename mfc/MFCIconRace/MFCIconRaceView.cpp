
// MFCIconRaceView.cpp : implementation of the CMFCIconRaceView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCIconRace.h"
#endif

#include "MFCIconRaceDoc.h"
#include "MFCIconRaceView.h"

#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCIconRaceView

IMPLEMENT_DYNCREATE(CMFCIconRaceView, CView)

BEGIN_MESSAGE_MAP(CMFCIconRaceView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_SETTINGS_RESTART, &CMFCIconRaceView::OnSettingsRestart)
END_MESSAGE_MAP()

// CMFCIconRaceView construction/destruction

CMFCIconRaceView::CMFCIconRaceView() noexcept
{
	// TODO: add construction code here

	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);

	x1 = x2 = x3 = x4 = 30;
	y = 30;
}

CMFCIconRaceView::~CMFCIconRaceView()
{
}

BOOL CMFCIconRaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCIconRaceView drawing

void CMFCIconRaceView::OnDraw(CDC* pDC)
{
	CMFCIconRaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	pDC->DrawIcon(x1, y, icon[0]);
	pDC->DrawIcon(x2, y + 200, icon[1]);
	pDC->DrawIcon(x3, y + 400, icon[2]);
	pDC->DrawIcon(x4, y + 600, icon[3]);
}


// CMFCIconRaceView printing

BOOL CMFCIconRaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCIconRaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCIconRaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCIconRaceView diagnostics

#ifdef _DEBUG
void CMFCIconRaceView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCIconRaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCIconRaceDoc* CMFCIconRaceView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCIconRaceDoc)));
	return (CMFCIconRaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCIconRaceView message handlers


int CMFCIconRaceView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	SetTimer(1, 500, NULL);

	return 0;
}


void CMFCIconRaceView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (nIDEvent == 1)
	{
		x1 += 50;
		x2 += 100;
		x3 += 150;
		x4 += 200;

		// 越界判断
		// 获取客户区范围
		CRect rect;
		GetClientRect(&rect);

		if (x1 > rect.Width())
		{
			x1 = 30;
		}
		if (x2 > rect.Width())
		{
			x2 = 30;
		}
		if (x3 > rect.Width())
		{
			x3 = 30;
		}
		if (x4 > rect.Width())
		{
			x4 = 30;
		}

		Invalidate();  // 间接调用OnDraw()
	}

	CView::OnTimer(nIDEvent);
}


void CMFCIconRaceView::OnSettingsRestart()
{
	// TODO: Add your command handler code here

	x1 = x2 = x3 = x4 = 30;
	Invalidate();
}
