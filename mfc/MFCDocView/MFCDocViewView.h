
// MFCDocViewView.h : interface of the CMFCDocViewView class
//

#pragma once


class CMFCDocViewView : public CFormView
{
protected: // create from serialization only
	CMFCDocViewView() noexcept;
	DECLARE_DYNCREATE(CMFCDocViewView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCDOCVIEW_FORM };
#endif

// Attributes
public:
	CMFCDocViewDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCDocViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
private:
	CButton m_buttonPrev;
	CButton m_buttonNext;
	int m_uiID;
	CString m_uiName;
	int m_uiAge;
	int m_uiScore;
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
private:
	CButton m_buttonAdd;
};

#ifndef _DEBUG  // debug version in MFCDocViewView.cpp
inline CMFCDocViewDoc* CMFCDocViewView::GetDocument() const
   { return reinterpret_cast<CMFCDocViewDoc*>(m_pDocument); }
#endif

