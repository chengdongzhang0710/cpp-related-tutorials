
// MFCFilePaintsDoc.h : interface of the CMFCFilePaintsDoc class
//


#pragma once


class CMFCFilePaintsDoc : public CDocument
{
protected: // create from serialization only
	CMFCFilePaintsDoc() noexcept;
	DECLARE_DYNCREATE(CMFCFilePaintsDoc)

// Attributes
public:
	CPoint m_pt[200];
	int m_num;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCFilePaintsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
