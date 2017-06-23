// EditListCtrl.cpp : ʵ���ļ�
#include "stdafx.h"
// #include "AltairNetworkLockTools.h"
#include "EditListCtrl.h"

// CEditListCtrl
IMPLEMENT_DYNAMIC(CEditListCtrl, CListCtrl)
CEditListCtrl::CEditListCtrl()
{
	m_edit = NULL;//�༭���ָ�룬��ʼΪNULL����ʾ�ޱ༭��
	m_isedit = NULL;//��־��Щ�пɱ༭�ı�־ά���飬��ʼΪNULL
	m_item = -1;//��ǰ�༭���кţ���ֵΪ-1
	m_subitem = -1;//��ǰ�༭���кţ���ֵΪ-1
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

// CEditListCtrl ��Ϣ�������
void CEditListCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{	
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!m_isedit) return;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(!m_edit)
	{
		m_subitem=pNMListView->iSubItem;
		if(pNMListView->iItem!=m_item)
		{
			m_item=pNMListView->iItem;//��־����������Ŀ
			return;
		}
	}
	if(!m_isedit[m_subitem])//����ǰ�в�����ֱ�ӱ༭,�򷵻� 
		return;
	RECT m_itemrect,m_r;
	GetItemRect(m_item ,&m_itemrect,2);
	//m_itemrect.right+=30;
	GetItemRect(0 ,&m_r,2);
	//m_r.right+=30;
	int m_height=m_itemrect.bottom -m_itemrect.top ;
	int x=m_r.left ,y=m_r.top,cx=0,cy=m_height;//(x,y,cx,cy)Ϊ�༭����ʾ��λ��
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
	if(m_edit)//���༭���Ѵ���
	{
		CString s1;
		s1.Format ("%d %d %d %d",x,y,cx,cy);
		m_edit->MoveWindow(x,y,cx-x,cy-y);//�ƶ�����ǰ����Ŀ��λ��
		Invalidate();//ˢ����Ļ��
		return;
	}
	//���༭�򲻴���,�򴴽��༭��,���ڵ�ǰ����Ŀ����ʾ�༭��
	CRect rect(x,y,cx,cy);
	m_edit=new CEdit();
	m_edit->Create (WS_CHILD|WS_VISIBLE|WS_BORDER,rect,this,107);
	CString str=GetItemText (pNMListView->iItem,pNMListView->iSubItem);
	m_edit->UpdateData(0);
	m_edit->SetWindowText(str); 
	DWORD dwSel = m_edit->GetSel();   
	m_edit->SetSel(HIWORD(dwSel), -1);
	//��ʾ�༭��
	m_edit->ShowWindow(SW_SHOW);
	m_edit->SetFocus();

	*pResult = 0;
}

void CEditListCtrl::OnNMSetfocus(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_edit)
	{//���༭���е�����д�ض�Ӧ������Ŀ��
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LRESULT* pResult=new LRESULT;
	if(m_edit)
	{
		OnNMClick((NMHDR*)this,pResult) ;
	}
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CEditListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ֱ����ʱ,�ƶ�����ʾ�ı༭��
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
	//��������ֱ�ӽ��б༭����
	if(!m_isedit)
	{
		int len=GetHeaderCtrl()->GetItemCount();
		m_isedit=new BOOL[len];
		for(int i=0;i<len;i++)//��ʼ��m_isedit
			m_isedit[i]=FALSE;
	}
	m_isedit[col]=edit;
}

void CEditListCtrl::OnDestroy()
{
	CListCtrl::OnDestroy();
	delete [] m_isedit;
	// TODO: �ڴ˴������Ϣ����������
}
