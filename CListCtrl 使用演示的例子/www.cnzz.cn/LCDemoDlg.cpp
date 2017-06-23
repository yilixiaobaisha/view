// LCDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LCDemo.h"
#include "LCDemoDlg.h"

#include"EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLCDemoDlg dialog

CLCDemoDlg::CLCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLCDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLCDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nIndex=-1;
}

void CLCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLCDemoDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLCDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CLCDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_UP, OnButtonUp)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, OnButtonDown)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_COMMAND(IDM_EDIT, OnEdit)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
	ON_BN_CLICKED(IDD_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLCDemoDlg message handlers


void CLCDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLCDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLCDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CLCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_imagelist.Create(16,16,TRUE,2,2);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_list.SetImageList(&m_imagelist,LVSIL_SMALL);

	m_font.CreateFont(16, 0,0,0,FW_NORMAL, 0,0,0,
		DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
	m_list.SetFont(&m_font);


/*-----------------------------------------------------------*/	
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.SetBkColor(RGB(247,247,255));
	m_list.SetTextColor(RGB(0,0,255));
	m_list.SetTextBkColor(RGB(247,247,255));
	m_list.InsertColumn(0, "ѧ��", LVCFMT_LEFT, 110);
	m_list.InsertColumn(1, "����", LVCFMT_LEFT, 130);
	m_list.InsertColumn(2, "�ɼ�", LVCFMT_LEFT, 47);

	m_list.InsertItem(0,"2002112105");
	m_list.SetItemText(0,1,"�̺���");
	m_list.SetItemText(0,2,"96");

	m_list.InsertItem(1,"2002112126");
	m_list.SetItemText(1,1,"���л�");
	m_list.SetItemText(1,2,"85");

	m_list.InsertItem(2,"2002112125");
	m_list.SetItemText(2,1,"������");
	m_list.SetItemText(2,2,"95");

	m_list.InsertItem(3,"2002112103");
	m_list.SetItemText(3,1,"Ԭ��");
	m_list.SetItemText(3,2,"92");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLCDemoDlg::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	m_nIndex = m_list.GetNextSelectedItem(pos);  // �õ���Ŀ����
	
	*pResult = 0;
}

void CLCDemoDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	m_nIndex = m_list.GetNextSelectedItem(pos);  // �õ���Ŀ����
	
	CEditDlg ed;
	ed.m_strNo=m_list.GetItemText(m_nIndex,0);
	ed.m_strName=m_list.GetItemText(m_nIndex,1);
	ed.m_strScore=m_list.GetItemText(m_nIndex,2);
	
	if(ed.DoModal()==IDOK)
	{			
		m_list.SetItemText(m_nIndex,0,ed.m_strNo);
		m_list.SetItemText(m_nIndex,1,ed.m_strName);
		m_list.SetItemText(m_nIndex,2,ed.m_strScore);
	}
	
	*pResult = 0;
}


void CLCDemoDlg::OnButtonUp() 
{
	m_list.SetFocus();
	
	if (m_nIndex == -1)	  //���û��ѡ��ͷ���
	{
		MessageBox("��ѡ��һ��������!","��ʾ",MB_ICONINFORMATION);
		return;  
	}
	
	if (m_nIndex == 0)  // �ж���ѡ���Ƿ�λ������
	{
		MessageBox("�Ѿ�λ�ڵ�һ��!","��ʾ",MB_ICONINFORMATION);
		return;
	}
	
	// ��ȡ��ѡ�б����������
	CString str1, str2, str3;
	str1 = m_list.GetItemText(m_nIndex, 0);
	str2 = m_list.GetItemText(m_nIndex, 1);
	str3 = m_list.GetItemText(m_nIndex, 2);
	
	// ɾ����ѡ�б���
	m_list.DeleteItem(m_nIndex);
	
	// ��m_nIndex-1λ�ô�����������ɾ�б���ĸ�������	
	m_list.InsertItem(m_nIndex-1, str1);
	m_list.SetItemText(m_nIndex-1, 1, str2);
	m_list.SetItemText(m_nIndex-1, 2, str3);
	m_nIndex--;
	
	// ʹ��m_nIndex-1λ�ô���Ŀ������ʾ����ý���
	UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
	m_list.SetItemState(m_nIndex, flag, flag);
}


void CLCDemoDlg::OnButtonDown() 
{
	m_list.SetFocus();	

	if (m_nIndex == -1)	  //���û��ѡ��ͷ���
	{
		MessageBox("��ѡ��һ��������!","��ʾ",MB_ICONINFORMATION);
		return;  
	}

	if (m_nIndex == m_list.GetItemCount()-1)  // �ж���ѡ���Ƿ�λ����β
	{
		MessageBox("�Ѿ�λ����ĩ��!","��ʾ",MB_ICONINFORMATION);
		return;
	}
	
	CString str1, str2, str3;
	str1 = m_list.GetItemText(m_nIndex, 0);
	str2 = m_list.GetItemText(m_nIndex, 1);
	str3 = m_list.GetItemText(m_nIndex, 2);
	
	m_list.DeleteItem(m_nIndex);
	
	// ��m_nIndex+1λ�ô�����������ɾ�б���ĸ�������
	m_list.InsertItem(m_nIndex+1, str1);
	m_list.SetItemText(m_nIndex+1, 1, str2);
	m_list.SetItemText(m_nIndex+1, 2, str3);
	m_nIndex++;
	
	// ʹ��m_nIndex+1λ�ô���Ŀ������ʾ����ý���
	UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
	m_list.SetItemState(m_nIndex, flag, flag);
}


void CLCDemoDlg::OnEdit() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	m_nIndex = m_list.GetNextSelectedItem(pos);  // �õ���Ŀ����

	if(m_nIndex==-1)
	{
		MessageBox("��ѡ��һ�����޸�!","��ʾ",MB_ICONINFORMATION);
		return;
	}
	
	
	CEditDlg ed;
	ed.m_strNo=m_list.GetItemText(m_nIndex,0);
	ed.m_strName=m_list.GetItemText(m_nIndex,1);
	ed.m_strScore=m_list.GetItemText(m_nIndex,2);
	
	if(ed.DoModal()==IDOK)
	{			
		m_list.SetItemText(m_nIndex,0,ed.m_strNo);
		m_list.SetItemText(m_nIndex,1,ed.m_strName);
		m_list.SetItemText(m_nIndex,2,ed.m_strScore);
	}
}

void CLCDemoDlg::OnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CLCDemoDlg::OnExit() 
{
	PostMessage(WM_CLOSE,0,0);	
}

void CLCDemoDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CPoint pt;
	::GetCursorPos(&pt);

	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu=menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this,NULL);

	*pResult = 0;  
}

void CLCDemoDlg::OnAdd() 
{
	CEditDlg ed;
	if(ed.DoModal()==IDOK)
	{
		int nn=m_list.InsertItem(m_list.GetItemCount(),ed.m_strNo);
		m_list.SetItemText(nn,1,ed.m_strName);
		m_list.SetItemText(nn,2,ed.m_strScore);
	}	
}

void CLCDemoDlg::OnDel() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	m_nIndex = m_list.GetNextSelectedItem(pos);  // �õ���Ŀ����
	
	if(m_nIndex==-1)
	{
		MessageBox("��ѡ��һ����ɾ��!","��ʾ",MB_ICONINFORMATION);
		return;
	}
	
	m_list.DeleteItem(m_nIndex); 
	
	UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
	m_list.SetItemState(m_nIndex-1, flag, flag);
	
}

void CLCDemoDlg::OnSave() 
{
	CStdioFile sf;
	if(sf.Open("����.txt",CFile::modeCreate | CFile::modeWrite))
	{
		CString strOut;
		strOut="\r\nѧ��\t\t����\t\t�ɼ�\r\n";
		sf.WriteString(strOut);
		
		for(int i=0;i<m_list.GetItemCount();i++)
		{
			strOut=m_list.GetItemText(i,0) + "\t"+m_list.GetItemText(i,1)+"\t         "+m_list.GetItemText(i,2) +"\r\n";
			sf.WriteString(strOut);
		}
		sf.Close();
		MessageBox("����ɹ�!","��ʾ",MB_ICONINFORMATION);
	}
	
	else
		MessageBox("����ʧ��!","��ʾ",MB_ICONINFORMATION);		
}