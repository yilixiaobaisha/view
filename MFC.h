// MFC.h : MFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ������


// CMFCApp:
// �йش����ʵ�֣������ MFC.cpp
//

class CMFCApp : public CWinApp
{
public:
	CMFCApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApp theApp;
