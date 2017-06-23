#pragma once


// CMyDocument �ĵ�

class CMyDocument : public CDocument
{
	DECLARE_DYNCREATE(CMyDocument)

public:
	CMyDocument();
	virtual ~CMyDocument();
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� i/o ��д
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
