// MyDocument.cpp : ʵ���ļ�
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


// CMyDocument ���

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


// CMyDocument ���л�

void CMyDocument::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMyDocument ����
