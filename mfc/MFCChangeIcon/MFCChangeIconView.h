
// MFCChangeIconView.h : interface of the CMFCChangeIconView class
//

#pragma once


class CMFCChangeIconView : public CView
{
protected: // create from serialization only
	CMFCChangeIconView() noexcept;
	DECLARE_DYNCREATE(CMFCChangeIconView)

// Attributes
public:
	CMFCChangeIconDoc* GetDocument() const;

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
	virtual ~CMFCChangeIconView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCChangeIconView.cpp
inline CMFCChangeIconDoc* CMFCChangeIconView::GetDocument() const
   { return reinterpret_cast<CMFCChangeIconDoc*>(m_pDocument); }
#endif

