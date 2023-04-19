
// MFCTextEditorView.h : interface of the CMFCTextEditorView class
//

#pragma once


class CMFCTextEditorView : public CView
{
protected: // create from serialization only
	CMFCTextEditorView() noexcept;
	DECLARE_DYNCREATE(CMFCTextEditorView)

// Attributes
public:
	CMFCTextEditorDoc* GetDocument() const;

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
	virtual ~CMFCTextEditorView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_point;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString m_str;
};

#ifndef _DEBUG  // debug version in MFCTextEditorView.cpp
inline CMFCTextEditorDoc* CMFCTextEditorView::GetDocument() const
   { return reinterpret_cast<CMFCTextEditorDoc*>(m_pDocument); }
#endif

