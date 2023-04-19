
// MFCChangeIcon.h : main header file for the MFCChangeIcon application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCChangeIconApp:
// See MFCChangeIcon.cpp for the implementation of this class
//

class CMFCChangeIconApp : public CWinApp
{
public:
	CMFCChangeIconApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCChangeIconApp theApp;
