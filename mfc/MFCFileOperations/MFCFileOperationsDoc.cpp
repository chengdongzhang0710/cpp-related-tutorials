
// MFCFileOperationsDoc.cpp : implementation of the CMFCFileOperationsDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCFileOperations.h"
#endif

#include "MFCFileOperationsDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCFileOperationsDoc

IMPLEMENT_DYNCREATE(CMFCFileOperationsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCFileOperationsDoc, CDocument)
END_MESSAGE_MAP()


// CMFCFileOperationsDoc construction/destruction

CMFCFileOperationsDoc::CMFCFileOperationsDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCFileOperationsDoc::~CMFCFileOperationsDoc()
{
}

BOOL CMFCFileOperationsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCFileOperationsDoc serialization

void CMFCFileOperationsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here

		// 按保存调用此处
		CString str = TEXT("ABC");
		int a = 100;

		ar << str << a;
	}
	else
	{
		// TODO: add loading code here

		// 打开文件
		CString str;
		int a;

		ar >> str >> a;

		CString buf;
		buf.Format(TEXT("%s, %d"), str, a);
		AfxMessageBox(buf);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCFileOperationsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFCFileOperationsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCFileOperationsDoc::SetSearchContent(const CString& value)
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

// CMFCFileOperationsDoc diagnostics

#ifdef _DEBUG
void CMFCFileOperationsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCFileOperationsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCFileOperationsDoc commands
