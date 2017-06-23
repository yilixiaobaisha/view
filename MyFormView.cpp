// MyFormView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC.h"
#include "MyFormView.h"


// CMyFormView

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

CMyFormView::CMyFormView()
	: CFormView(CMyFormView::IDD)
	, m_list()
{
}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMyFormView ���

#ifdef _DEBUG
void CMyFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CMyFormView ��Ϣ�������

int CMyFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect re(0,0,200,200);
	GetParent()->GetClientRect(&re);
	MoveWindow(re);
	//SetWindowPos(&wndTop,0,0,re.Width(),re.Height(),SWP_SHOWWINDOW);	
	m_list.Create(WS_VISIBLE|WS_CHILD|LVS_REPORT,re,this,NULL);
	DWORD   dwStyle =  m_list.GetExtendedStyle();     
	dwStyle  |= LVS_REPORT|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT| LVS_SHOWSELALWAYS | LVS_EX_HEADERDRAGDROP |LVS_EX_CHECKBOXES;
	m_list.InsertColumn (0,"ѧ��", LVCFMT_LEFT,50);  
	m_list.InsertColumn (1,"����", LVCFMT_LEFT,90);  
	m_list.InsertColumn (2,"����", LVCFMT_LEFT,50);  
	m_list.InsertItem (0,"1");  
	m_list.SetItemText (0,1,"����");  
	m_list.SetItemText (0,2,"23");  
	m_list.InsertItem (1,"2");  
	m_list.SetItemText (1,1,"�Կ�");  
	m_list.SetItemText (1,2,"20");  
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);  
	m_list.SetEditColomn (0,TRUE);//�����0�п�ֱ�ӱ༭  
	m_list.SetEditColomn (1,TRUE); //�����1�п�ֱ�ӱ༭  
	m_list.SetEditColomn (2,TRUE); //�����2�п�ֱ�ӱ༭  
	m_list.ShowWindow(SW_SHOWMAXIMIZED);
	return 0;
}

BOOL CMyFormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	
	return CFormView::PreCreateWindow(cs);
}

void CMyFormView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	// TODO: �ڴ������Ϣ����������

	if (m_list)    //m_ListCtrl��listctrl��ʵ������
	{
		CRect rect(0,0,cx,cy);
		m_list.MoveWindow(rect);
	}
}
