
// MFCDocViewView.cpp : implementation of the CMFCDocViewView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDocView.h"
#endif

#include "MFCDocViewDoc.h"
#include "MFCDocViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDocViewView

IMPLEMENT_DYNCREATE(CMFCDocViewView, CFormView)

BEGIN_MESSAGE_MAP(CMFCDocViewView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCDocViewView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCDocViewView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDocViewView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDocViewView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCDocViewView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFCDocViewView construction/destruction

CMFCDocViewView::CMFCDocViewView() noexcept
	: CFormView(IDD_MFCDOCVIEW_FORM)
	, m_uiID(0)
	, m_uiName(TEXT(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: add construction code here

}

CMFCDocViewView::~CMFCDocViewView()
{
}

void CMFCDocViewView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_buttonPrev);
	DDX_Control(pDX, IDC_BUTTON3, m_buttonNext);
	DDX_Text(pDX, IDC_EDIT1, m_uiID);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
	DDX_Control(pDX, IDC_BUTTON1, m_buttonAdd);
}

BOOL CMFCDocViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCDocViewView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	OnBnClickedRadio1();
}


// CMFCDocViewView printing

BOOL CMFCDocViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDocViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDocViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCDocViewView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMFCDocViewView diagnostics

#ifdef _DEBUG
void CMFCDocViewView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCDocViewView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCDocViewDoc* CMFCDocViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDocViewDoc)));
	return (CMFCDocViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDocViewView message handlers


void CMFCDocViewView::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here

	m_buttonPrev.EnableWindow(FALSE);
	m_buttonNext.EnableWindow(FALSE);
	m_buttonAdd.EnableWindow(TRUE);
}


void CMFCDocViewView::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here

	m_buttonPrev.EnableWindow(TRUE);
	m_buttonNext.EnableWindow(TRUE);
	m_buttonAdd.EnableWindow(FALSE);
}


void CMFCDocViewView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	Student* stu = new Student(m_uiID, m_uiName, m_uiAge, m_uiScore);

	CMFCDocViewDoc* pDoc = GetDocument();

	pDoc->m_stuList.AddTail(stu);
	pDoc->m_pos = pDoc->m_stuList.GetTailPosition();
}


void CMFCDocViewView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CMFCDocViewDoc* pDoc = GetDocument();

	pDoc->m_stuList.GetPrev(pDoc->m_pos);  // 获取上一个元素后，pDoc->m_pos会自动往上移动
	if (pDoc->m_pos == NULL)
	{
		pDoc->m_pos = pDoc->m_stuList.GetTailPosition();
	}

	Student* ps = pDoc->m_stuList.GetAt(pDoc->m_pos);
	m_uiID = ps->m_id;
	m_uiName = ps->m_name;
	m_uiAge = ps->m_age;
	m_uiScore = ps->m_score;

	UpdateData(FALSE);
}


void CMFCDocViewView::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here

	CMFCDocViewDoc* pDoc = GetDocument();

	pDoc->m_stuList.GetNext(pDoc->m_pos);
	if (pDoc->m_pos == NULL)
	{
		pDoc->m_pos = pDoc->m_stuList.GetHeadPosition();
	}

	Student* ps = pDoc->m_stuList.GetAt(pDoc->m_pos);
	m_uiID = ps->m_id;
	m_uiName = ps->m_name;
	m_uiAge = ps->m_age;
	m_uiScore = ps->m_score;

	UpdateData(FALSE);
}
