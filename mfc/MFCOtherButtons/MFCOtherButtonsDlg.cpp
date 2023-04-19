
// MFCOtherButtonsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCOtherButtons.h"
#include "MFCOtherButtonsDlg.h"
#include "afxdialogex.h"

#include "resource.h"

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


// CMFCOtherButtonsDlg dialog



CMFCOtherButtonsDlg::CMFCOtherButtonsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCOTHERBUTTONS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCOtherButtonsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
}

BEGIN_MESSAGE_MAP(CMFCOtherButtonsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCOtherButtonsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCOtherButtonsDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCOtherButtonsDlg message handlers

BOOL CMFCOtherButtonsDlg::OnInitDialog()
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

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);

	m_check1.SetCheck(1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCOtherButtonsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCOtherButtonsDlg::OnPaint()
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
HCURSOR CMFCOtherButtonsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCOtherButtonsDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString str;

	if (IsDlgButtonChecked(IDC_RADIO1))
	{
		str = TEXT("Male");
	}

	if (IsDlgButtonChecked(IDC_RADIO2))
	{
		str = TEXT("Female");
	}

	MessageBox(str);
}


void CMFCOtherButtonsDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CString str;

	if (IsDlgButtonChecked(IDC_CHECK1))
	{
		str += TEXT("Music\r\n");
	}

	if (IsDlgButtonChecked(IDC_CHECK2))
	{
		str += TEXT("Sport\r\n");
	}

	if (IsDlgButtonChecked(IDC_CHECK3))
	{
		str += TEXT("Game\r\n");
	}

	MessageBox(str);
}
