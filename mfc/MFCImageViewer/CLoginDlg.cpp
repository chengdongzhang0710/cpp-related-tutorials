// CLoginDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCImageViewer.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_account(_T(""))
	, m_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_account);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CLoginDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here

	exit(1);
}


void CLoginDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialogEx::OnOK();
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	if (m_account == TEXT("root") && m_password == TEXT("password"))
	{
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(TEXT("Account or password is not correct!"));
	}
}


void CLoginDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	exit(1);

	//CDialogEx::OnClose();
}
