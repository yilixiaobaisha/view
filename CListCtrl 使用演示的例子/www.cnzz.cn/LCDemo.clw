; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLCDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LCDemo.h"

ClassCount=4
Class1=CLCDemoApp
Class2=CLCDemoDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_LCDEMO_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CEditDlg
Resource4=IDD_EDIT_DLG
Resource5=IDR_MENU1

[CLS:CLCDemoApp]
Type=0
HeaderFile=LCDemo.h
ImplementationFile=LCDemo.cpp
Filter=N

[CLS:CLCDemoDlg]
Type=0
HeaderFile=LCDemoDlg.h
ImplementationFile=LCDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDM_EXIT

[CLS:CAboutDlg]
Type=0
HeaderFile=LCDemoDlg.h
ImplementationFile=LCDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LCDEMO_DIALOG]
Type=1
Class=CLCDemoDlg
ControlCount=7
Control1=IDC_LIST,SysListView32,1350631437
Control2=IDC_BUTTON_UP,button,1342242816
Control3=IDC_BUTTON_DOWN,button,1342242816
Control4=IDC_EDIT,button,1342242816
Control5=IDD_ADD,button,1342242816
Control6=IDC_DEL,button,1342242816
Control7=IDC_SAVE,button,1342242816

[DLG:IDD_EDIT_DLG]
Type=1
Class=CEditDlg
ControlCount=8
Control1=IDC_EDIT_NO,edit,1350631552
Control2=IDC_EDIT_NAME,edit,1350631552
Control3=IDC_EDIT_SCORE,edit,1350631552
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CEditDlg]
Type=0
HeaderFile=EditDlg.h
ImplementationFile=EditDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_NO
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=CLCDemoDlg
Command1=IDM_EDIT
Command2=IDM_ABOUT
Command3=IDM_EXIT
CommandCount=3

