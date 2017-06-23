// MyDocument.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "MyDocument.h"


// CMyDocument

IMPLEMENT_DYNCREATE(CMyDocument, CDocument)

CMyDocument::CMyDocument()
{
}

BOOL CMyDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CMyDocument::~CMyDocument()
{
}


BEGIN_MESSAGE_MAP(CMyDocument, CDocument)
END_MESSAGE_MAP()


// CMyDocument 诊断

#ifdef _DEBUG
void CMyDocument::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyDocument 序列化

void CMyDocument::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMyDocument 命令
