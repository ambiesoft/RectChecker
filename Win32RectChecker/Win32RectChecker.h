
// Win32RectChecker.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CWin32RectCheckerApp:
// See Win32RectChecker.cpp for the implementation of this class
//

class CWin32RectCheckerApp : public CWinApp
{
public:
	CWin32RectCheckerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWin32RectCheckerApp theApp;
