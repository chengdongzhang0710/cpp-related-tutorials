
// MFCFilePaintsDoc.cpp : implementation of the CMFCFilePaintsDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFilePaints.h"
#endif

#include "MFCFilePaintsDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCFilePaintsDoc

IMPLEMENT_DYNCREATE(CMFCFilePaintsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCFilePaintsDoc, CDocument)
END_MESSAGE_MAP()


// CMFCFilePaintsDoc construction/destruction

CMFCFilePaintsDoc::CMFCFilePaintsDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCFilePaintsDoc::~CMFCFilePaintsDoc()
{
}

BOOL CMFCFilePaintsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCFilePaintsDoc serialization

void CMFCFilePaintsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here

		ar << m_num;
		for (int i = 0; i < m_num; i++)
		{
			ar << m_pt[i];
		}
	}
	else
	{
		// TODO: add loading code here

		ar >> m_num;
		for (int i = 0; i < m_num; i++)
		{
			ar >> m_pt[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCFilePaintsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCFilePaintsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCFilePaintsDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCFilePaintsDoc diagnostics

#ifdef _DEBUG
void CMFCFilePaintsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCFilePaintsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCFilePaintsDoc commands


void CMFCFilePaintsDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class

	memset(&m_pt, 0, sizeof(m_pt));

	m_num = 0;

	CDocument::DeleteContents();
}
