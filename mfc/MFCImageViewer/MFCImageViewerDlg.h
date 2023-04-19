
// MFCImageViewerDlg.h : header file
//

#pragma once


// CMFCImageViewerDlg dialog
class CMFCImageViewerDlg : public CDialogEx
{
// Construction
public:
	CMFCImageViewerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCIMAGEVIEWER_DIALOG };
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
	CStatic* m_pBmp;
	CButton m_buttonPrev;
	CButton m_buttonAuto;
	CButton m_buttonNext;
	int m_width;
	int m_height;
	int m_index;
	bool m_isAuto;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
