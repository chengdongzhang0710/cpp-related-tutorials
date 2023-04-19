
// MFCIconRaceView.h : interface of the CMFCIconRaceView class
//

#pragma once


class CMFCIconRaceView : public CView
{
protected: // create from serialization only
	CMFCIconRaceView() noexcept;
	DECLARE_DYNCREATE(CMFCIconRaceView)

// Attributes
public:
	CMFCIconRaceDoc* GetDocument() const;

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
	virtual ~CMFCIconRaceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	HICON icon[4];
	int x1, x2, x3, x4;
	int y;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSettingsRestart();
};

#ifndef _DEBUG  // debug version in MFCIconRaceView.cpp
inline CMFCIconRaceDoc* CMFCIconRaceView::GetDocument() const
   { return reinterpret_cast<CMFCIconRaceDoc*>(m_pDocument); }
#endif

