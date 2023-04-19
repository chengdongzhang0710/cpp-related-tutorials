
// MFCTabControlDlg.h : header file
//

#pragma once

#include "TabSheet.h"
#include "MyDlg1.h"
#include "MyDlg2.h"


// CMFCTabControlDlg dialog
class CMFCTabControlDlg : public CDialogEx
{
// Construction
public:
	CMFCTabControlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTABCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CTabSheet m_tabCtrl;
	MyDlg1 m_dlg1;
	MyDlg2 m_dlg2;
};
