
// MFCMenu.h : main header file for the MFCMenu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMenuApp:
// See MFCMenu.cpp for the implementation of this class
//

class CMFCMenuApp : public CWinApp
{
public:
	CMFCMenuApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMenuApp theApp;
