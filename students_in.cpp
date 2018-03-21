// students_in.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "students_in.h"
#include "afxdialogex.h"


// students_in dialog

IMPLEMENT_DYNAMIC(students_in, CDialogEx)

students_in::students_in(CWnd* pParent /*=NULL*/)
	: CDialogEx(students_in::IDD, pParent)
{

}

students_in::~students_in()
{
}

void students_in::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENTS, students_tab);
}


BEGIN_MESSAGE_MAP(students_in, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_STUDENTS, &students_in::OnTcnSelchangeStudents)
END_MESSAGE_MAP()


// students_in message handlers


BOOL students_in::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	students_tab.InsertItem(0, L"晚归登记");
	students_tab.InsertItem(1, L"离校登记");
	students_tab.InsertItem(2, L"返校登记");
	students_tab.InsertItem(3, L"宿舍财产报修");
	students_tab.InsertItem(4, L"宿舍楼财产报修");
	// TODO:  Add extra initialization here

	cl_page.Create(IDD_DIALOG3, &students_tab);
	ls_page.Create(IDD_DIALOG4, &students_tab);
	cs_page.Create(IDD_DIALOG5, &students_tab);
	rr_page.Create(IDD_DIALOG6, &students_tab);
	rb_page.Create(IDD_DIALOG7, &students_tab);

	CRect rs;
	students_tab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置 
	rs.top += 40;
	rs.bottom -= 8;
	rs.left += 8;
	rs.right -= 8;
	//设置子对话框尺寸并移动到指定位置 
	cl_page.MoveWindow(&rs);
	ls_page.MoveWindow(&rs);
	cs_page.MoveWindow(&rs);
	rr_page.MoveWindow(&rs);
	rb_page.MoveWindow(&rs);
	//分别设置隐藏和显示 
	cl_page.ShowWindow(SW_SHOW);
	ls_page.ShowWindow(SW_HIDE);
	cs_page.ShowWindow(SW_HIDE);
	rr_page.ShowWindow(SW_HIDE);
	rb_page.ShowWindow(SW_HIDE);
	//设置默认的选项卡 
	students_tab.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void students_in::OnTcnSelchangeStudents(NMHDR *pNMHDR, LRESULT *pResult)
{
	CRect r;
	students_tab.GetClientRect(&r);
	int CurSel = students_tab.GetCurSel();

	switch (CurSel)
	{
	case 0:
		//m_page1.ShowWindow(true);
		//m_page2.ShowWindow(false);
		cl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		ls_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		cs_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rr_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 1:
		//m_page1.ShowWindow(false);
		//m_page2.ShowWindow(true);
		cl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ls_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		cs_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rr_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 2:
		cl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ls_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		cs_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		rr_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 3:
		cl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ls_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		cs_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rr_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		rb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 4:
		cl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ls_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		cs_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rr_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		rb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		break;
	}
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
