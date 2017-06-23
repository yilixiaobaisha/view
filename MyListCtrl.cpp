// MyListCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "MyListCtrl.h"


// CMyListCtrl

IMPLEMENT_DYNAMIC(CMyListCtrl, CListCtrl)
CMyListCtrl::CMyListCtrl()
{

}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
//	ON_WM_SIZE()
ON_WM_CREATE()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CMyListCtrl 消息处理程序


int CMyListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	InsertColumn(0, "ID", LVCFMT_LEFT, 100);
	InsertColumn( 1, "NAME", LVCFMT_LEFT, 100 );
	int nRow = InsertItem(0, "11");
	SetItemText(nRow, 1, "jacky");
	SetItemText(nRow, 0, "jacky");
	return 0;
}

