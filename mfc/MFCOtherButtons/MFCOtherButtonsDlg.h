
// MFCOtherButtonsDlg.h : header file
//

#pragma once


// CMFCOtherButtonsDlg dialog
class CMFCOtherButtonsDlg : public CDialogEx
{
// Construction
public:
	CMFCOtherButtonsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCOTHERBUTTONS_DIALOG };
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
public:
	afx_msg void OnBnClickedButton1();
private:
	CButton m_check1;
public:
	afx_msg void OnBnClickedButton2();
};
