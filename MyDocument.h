#pragma once


// CMyDocument 文档

class CMyDocument : public CDocument
{
	DECLARE_DYNCREATE(CMyDocument)

public:
	CMyDocument();
	virtual ~CMyDocument();
	virtual void Serialize(CArchive& ar);   // 为文档 i/o 重写
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
