#pragma once


// CMyListCtrl

class CMyListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl)

public:
	CMyListCtrl();
	virtual ~CMyListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


