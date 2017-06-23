// EditListCtrl.cpp : 实现文件
#include "stdafx.h"
// #include "AltairNetworkLockTools.h"
#include "EditListCtrl.h"

// CEditListCtrl
IMPLEMENT_DYNAMIC(CEditListCtrl, CListCtrl)
CEditListCtrl::CEditListCtrl()
{
	m_edit = NULL;//编辑框的指针，初始为NULL，表示无编辑框
	m_isedit = NULL;//标志哪些列可编辑的标志维数组，初始为NULL
	m_item = -1;//当前编辑的行号，初值为-1
	m_subitem = -1;//当前编辑的列号，初值为-1
}

CEditListCtrl::~CEditListCtrl()
{

}

BEGIN_MESSAGE_MAP(CEditListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CEditListCtrl::OnNMClick)
	ON_NOTIFY_REFLECT(NM_SETFOCUS, &CEditListCtrl::OnNMSetfocus)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CEditListCtrl 消息处理程序
void CEditListCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{	
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if(!m_isedit) return;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(!m_edit)
	{
		m_subitem=pNMListView->iSubItem;
		if(pNMListView->iItem!=m_item)
		{
			m_item=pNMListView->iItem;//标志被单击的项目
			return;
		}
	}
	if(!m_isedit[m_subitem])//若当前列不允许直接编辑,则返回 
		return;
	RECT m_itemrect,m_r;
	GetItemRect(m_item ,&m_itemrect,2);
	//m_itemrect.right+=30;
	GetItemRect(0 ,&m_r,2);
	//m_r.right+=30;
	int m_height=m_itemrect.bottom -m_itemrect.top ;
	int x=m_r.left ,y=m_r.top,cx=0,cy=m_height;//(x,y,cx,cy)为编辑框显示的位置
	if (m_item==0)
	{
		cy+=20;
	}
	for(int i=0;i< m_item;i++)
	{
		y+=m_height;
	    cy=y+m_height;
	}
	for(int t=0;t<m_subitem;t++)
	{
		x+=GetColumnWidth(t);
	    cx=x+GetColumnWidth(t);
	}
	if(m_edit)//若编辑框已存在
	{
		CString s1;
		s1.Format ("%d %d %d %d",x,y,cx,cy);
		m_edit->MoveWindow(x,y,cx-x,cy-y);//移动到当前子项目的位置
		Invalidate();//刷新屏幕。
		return;
	}
	//若编辑框不存在,则创建编辑框,并在当前子项目处显示编辑框。
	CRect rect(x,y,cx,cy);
	m_edit=new CEdit();
	m_edit->Create (WS_CHILD|WS_VISIBLE|WS_BORDER,rect,this,107);
	CString str=GetItemText (pNMListView->iItem,pNMListView->iSubItem);
	m_edit->UpdateData(0);
	m_edit->SetWindowText(str); 
	DWORD dwSel = m_edit->GetSel();   
	m_edit->SetSel(HIWORD(dwSel), -1);
	//显示编辑框
	m_edit->ShowWindow(SW_SHOW);
	m_edit->SetFocus();

	*pResult = 0;
}

void CEditListCtrl::OnNMSetfocus(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_edit)
	{//将编辑框中的数据写回对应的子项目中
		UpdateData( );
		CString str;
		m_edit->GetWindowText(str);
		SetItemText(m_item,m_subitem,str);
		delete m_edit;
		m_edit=NULL;
	}
	*pResult = 0;
}

void CEditListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LRESULT* pResult=new LRESULT;
	if(m_edit)
	{
		OnNMClick((NMHDR*)this,pResult) ;
	}
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CEditListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//垂直滚动时,移动已显示的编辑框
	LRESULT* pResult=new LRESULT;
	if(m_edit)
	{
		RECT m_itemrect,m_headrect;
		GetItemRect(m_item ,&m_itemrect,2);
		GetHeaderCtrl()->GetWindowRect(&m_headrect);
		if(m_itemrect.top<m_headrect.bottom-m_headrect.top) 
		{
			RECT m_rect;
			m_edit->GetWindowRect(&m_rect);
			m_edit->MoveWindow(m_rect.left,-(m_rect.bottom-m_rect.top),m_rect.right,0);
		}
		else 
		{
			OnNMClick((NMHDR*)this,pResult) ;
		}
	}
	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CEditListCtrl::SetEditColomn(int col,BOOL edit)
{
	//设置允许直接进行编辑的列
	if(!m_isedit)
	{
		int len=GetHeaderCtrl()->GetItemCount();
		m_isedit=new BOOL[len];
		for(int i=0;i<len;i++)//初始化m_isedit
			m_isedit[i]=FALSE;
	}
	m_isedit[col]=edit;
}

void CEditListCtrl::OnDestroy()
{
	CListCtrl::OnDestroy();
	delete [] m_isedit;
	// TODO: 在此处添加消息处理程序代码
}
