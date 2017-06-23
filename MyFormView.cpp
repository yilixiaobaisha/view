// MyFormView.cpp : 实现文件
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


// CMyFormView 诊断

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


// CMyFormView 消息处理程序

int CMyFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect re(0,0,200,200);
	GetParent()->GetClientRect(&re);
	MoveWindow(re);
	//SetWindowPos(&wndTop,0,0,re.Width(),re.Height(),SWP_SHOWWINDOW);	
	m_list.Create(WS_VISIBLE|WS_CHILD|LVS_REPORT,re,this,NULL);
	DWORD   dwStyle =  m_list.GetExtendedStyle();     
	dwStyle  |= LVS_REPORT|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT| LVS_SHOWSELALWAYS | LVS_EX_HEADERDRAGDROP |LVS_EX_CHECKBOXES;
	m_list.InsertColumn (0,"学号", LVCFMT_LEFT,50);  
	m_list.InsertColumn (1,"姓名", LVCFMT_LEFT,90);  
	m_list.InsertColumn (2,"年龄", LVCFMT_LEFT,50);  
	m_list.InsertItem (0,"1");  
	m_list.SetItemText (0,1,"王明");  
	m_list.SetItemText (0,2,"23");  
	m_list.InsertItem (1,"2");  
	m_list.SetItemText (1,1,"赵可");  
	m_list.SetItemText (1,2,"20");  
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);  
	m_list.SetEditColomn (0,TRUE);//允许第0列可直接编辑  
	m_list.SetEditColomn (1,TRUE); //允许第1列可直接编辑  
	m_list.SetEditColomn (2,TRUE); //允许第2列可直接编辑  
	m_list.ShowWindow(SW_SHOWMAXIMIZED);
	return 0;
}

BOOL CMyFormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	return CFormView::PreCreateWindow(cs);
}

void CMyFormView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	// TODO: 在此添加消息处理程序代码

	if (m_list)    //m_ListCtrl是listctrl的实例对象
	{
		CRect rect(0,0,cx,cy);
		m_list.MoveWindow(rect);
	}
}
