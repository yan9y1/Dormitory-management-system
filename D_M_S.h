
// D_M_S.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CD_M_SApp:
// See D_M_S.cpp for the implementation of this class
//

class CD_M_SApp : public CWinApp
{
public:
	CD_M_SApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CD_M_SApp theApp;