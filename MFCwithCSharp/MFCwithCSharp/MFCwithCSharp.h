
// MFCwithCSharp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCwithCSharpApp:
// See MFCwithCSharp.cpp for the implementation of this class
//

class CMFCwithCSharpApp : public CWinApp
{
public:
	CMFCwithCSharpApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCwithCSharpApp theApp;
