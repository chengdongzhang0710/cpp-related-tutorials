
// MFCImageViewerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCImageViewer.h"
#include "MFCImageViewerDlg.h"
#include "afxdialogex.h"

#include "CLoginDlg.h"

#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCImageViewerDlg dialog



CMFCImageViewerDlg::CMFCImageViewerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCIMAGEVIEWER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCImageViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_buttonPrev);
	DDX_Control(pDX, IDC_BUTTON2, m_buttonAuto);
	DDX_Control(pDX, IDC_BUTTON4, m_buttonNext);
}

BEGIN_MESSAGE_MAP(CMFCImageViewerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCImageViewerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCImageViewerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCImageViewerDlg::OnBnClickedButton4)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCImageViewerDlg message handlers

BOOL CMFCImageViewerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_pBmp = (CStatic*)GetDlgItem(IDC_STATIC);

	m_pBmp->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	CRect rect;
	m_pBmp->GetWindowRect(&rect);
	m_width = rect.Width();
	m_height = rect.Height();

	m_index = 1;
	CString path;
	path.Format(TEXT("../image/%d.bmp"), m_index);
	m_pBmp->SetBitmap(HBMP(path, m_width, m_height));

	m_isAuto = true;

	CLoginDlg dlg;
	dlg.DoModal();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCImageViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCImageViewerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCImageViewerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCImageViewerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	m_index--;

	if (m_index < 1)
	{
		m_index = 24;
	}

	CString path;
	path.Format(TEXT("../image/%d.bmp"), m_index);
	m_pBmp->SetBitmap(HBMP(path, m_width, m_height));
}


void CMFCImageViewerDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	if (m_isAuto)
	{
		m_buttonPrev.EnableWindow(FALSE);
		m_buttonNext.EnableWindow(FALSE);
		m_buttonAuto.SetWindowTextW(TEXT("Stop"));

		SetTimer(1, 1000, NULL);
	}
	else
	{
		m_buttonPrev.EnableWindow(TRUE);
		m_buttonNext.EnableWindow(TRUE);
		m_buttonAuto.SetWindowTextW(TEXT("Auto"));

		KillTimer(1);
	}

	m_isAuto = !m_isAuto;
}


void CMFCImageViewerDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here

	m_index++;

	if (m_index > 24)
	{
		m_index = 1;
	}

	CString path;
	path.Format(TEXT("../image/%d.bmp"), m_index);
	m_pBmp->SetBitmap(HBMP(path, m_width, m_height));
}


void CMFCImageViewerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	OnBnClickedButton4();

	CDialogEx::OnTimer(nIDEvent);
}
