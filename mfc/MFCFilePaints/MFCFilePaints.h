
// MFCFilePaints.h : main header file for the MFCFilePaints application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCFilePaintsApp:
// See MFCFilePaints.cpp for the implementation of this class
//

class CMFCFilePaintsApp : public CWinApp
{
public:
	CMFCFilePaintsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCFilePaintsApp theApp;
