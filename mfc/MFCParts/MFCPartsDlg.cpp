
// MFCPartsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCParts.h"
#include "MFCPartsDlg.h"
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


// CMFCPartsDlg dialog



CMFCPartsDlg::CMFCPartsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPARTS_DIALOG, pParent)
	, m_str(_T(""))
	, m_pos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPartsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
	DDX_Text(pDX, IDC_EDIT2, m_pos);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scrollBar);
}

BEGIN_MESSAGE_MAP(CMFCPartsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCPartsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCPartsDlg::OnBnClickedButton2)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMFCPartsDlg message handlers

BOOL CMFCPartsDlg::OnInitDialog()
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

	m_str = TEXT("123");
	UpdateData(FALSE);


	m_comboBox.SetCurSel(2);  // 设置默认显示项
	
	CString str;
	m_comboBox.GetLBText(0, str);
	//MessageBox(str);

	m_comboBox.AddString(TEXT("Test"));


	m_pos = 50;
	UpdateData(FALSE);

	m_scrollBar.SetScrollRange(0, 100);
	m_scrollBar.SetScrollPos(m_pos);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCPartsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCPartsDlg::OnPaint()
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
HCURSOR CMFCPartsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPartsDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	MessageBox(TEXT("Test"));
}


void CMFCPartsDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	MessageBox(m_str);
}


void CMFCPartsDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	int tmpPos;
	if (pScrollBar == &m_scrollBar)
	{
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:  // 滑块位置
		{
			m_scrollBar.SetScrollPos(nPos);
			m_pos = nPos;
			UpdateData(FALSE);
			break;
		}
		case SB_LINELEFT:  // 向左的箭头
		{
			tmpPos = m_scrollBar.GetScrollPos() - 10;
			if (tmpPos < 0)
			{
				tmpPos = 0;
			}

			m_scrollBar.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_LINERIGHT:  // 向右的箭头
		{
			tmpPos = m_scrollBar.GetScrollPos() + 10;
			if (tmpPos > 100)
			{
				tmpPos = 100;
			}

			m_scrollBar.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_PAGELEFT:  // 箭头和滑块之间左边
		{
			tmpPos = m_scrollBar.GetScrollPos() - 5;
			if (tmpPos < 0)
			{
				tmpPos = 0;
			}

			m_scrollBar.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_PAGERIGHT:  // 箭头和滑块之间右边
		{
			tmpPos = m_scrollBar.GetScrollPos() + 5;
			if (tmpPos > 100)
			{
				tmpPos = 100;
			}

			m_scrollBar.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		default:
			break;
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
