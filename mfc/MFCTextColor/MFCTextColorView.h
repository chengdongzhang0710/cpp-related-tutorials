
// MFCTextColorView.h : interface of the CMFCTextColorView class
//

#pragma once


class CMFCTextColorView : public CView
{
protected: // create from serialization only
	CMFCTextColorView() noexcept;
	DECLARE_DYNCREATE(CMFCTextColorView)

// Attributes
public:
	CMFCTextColorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCTextColorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in MFCTextColorView.cpp
inline CMFCTextColorDoc* CMFCTextColorView::GetDocument() const
   { return reinterpret_cast<CMFCTextColorDoc*>(m_pDocument); }
#endif

