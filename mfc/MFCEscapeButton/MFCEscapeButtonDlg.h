
// MFCEscapeButtonDlg.h : header file
//

#pragma once
#include "MyButton.h"


// CMFCEscapeButtonDlg dialog
class CMFCEscapeButtonDlg : public CDialogEx
{
// Construction
public:
	CMFCEscapeButtonDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCESCAPEBUTTON_DIALOG };
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
	MyButton m_button;
};
