#pragma once
// #include "MyListCtrl.h"
#include "EditListCtrl.h"


// CMyFormView ������ͼ

class CMyFormView : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView)

protected:
	CMyFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyFormView();

public:
	enum { IDD = IDD_MYFORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
// 	CMyListCtrl lCtrl;
	CEditListCtrl m_list;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


