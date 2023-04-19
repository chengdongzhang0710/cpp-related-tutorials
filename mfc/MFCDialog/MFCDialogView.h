
// MFCDialogView.h : interface of the CMFCDialogView class
//

#pragma once


class CMFCDialogView : public CView
{
protected: // create from serialization only
	CMFCDialogView() noexcept;
	DECLARE_DYNCREATE(CMFCDialogView)

// Attributes
public:
	CMFCDialogDoc* GetDocument() const;

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
	virtual ~CMFCDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCDialogView.cpp
inline CMFCDialogDoc* CMFCDialogView::GetDocument() const
   { return reinterpret_cast<CMFCDialogDoc*>(m_pDocument); }
#endif

