// MFC.h : MFC 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 主符号


// CMFCApp:
// 有关此类的实现，请参阅 MFC.cpp
//

class CMFCApp : public CWinApp
{
public:
	CMFCApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApp theApp;
