
// MFCFilePaintsView.h : interface of the CMFCFilePaintsView class
//

#pragma once


class CMFCFilePaintsView : public CView
{
protected: // create from serialization only
	CMFCFilePaintsView() noexcept;
	DECLARE_DYNCREATE(CMFCFilePaintsView)

// Attributes
public:
	CMFCFilePaintsDoc* GetDocument() const;

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
	virtual ~CMFCFilePaintsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCFilePaintsView.cpp
inline CMFCFilePaintsDoc* CMFCFilePaintsView::GetDocument() const
   { return reinterpret_cast<CMFCFilePaintsDoc*>(m_pDocument); }
#endif

