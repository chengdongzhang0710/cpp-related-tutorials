
// MFCFileOperations.h : main header file for the MFCFileOperations application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCFileOperationsApp:
// See MFCFileOperations.cpp for the implementation of this class
//

class CMFCFileOperationsApp : public CWinApp
{
public:
	CMFCFileOperationsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCFileOperationsApp theApp;
