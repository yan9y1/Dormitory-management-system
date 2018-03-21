// managers_in.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "managers_in.h"
#include "afxdialogex.h"


// managers_in dialog

IMPLEMENT_DYNAMIC(managers_in, CDialogEx)

managers_in::managers_in(CWnd* pParent /*=NULL*/)
	: CDialogEx(managers_in::IDD, pParent)
{

}

managers_in::~managers_in()
{
}

void managers_in::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MANAGERS, managers_tab);
}


BEGIN_MESSAGE_MAP(managers_in, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_MANAGERS, &managers_in::OnTcnSelchangeManagers)
END_MESSAGE_MAP()


// managers_in message handlers


BOOL managers_in::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	managers_tab.InsertItem(0, L"添加学生");
	managers_tab.InsertItem(1, L"添加宿舍");
	managers_tab.InsertItem(2, L"添加宿舍财产");
	managers_tab.InsertItem(3, L"查看晚归");
	managers_tab.InsertItem(4, L"查看离校");
	managers_tab.InsertItem(5, L"查看宿舍财产报修");
	managers_tab.InsertItem(6, L"查看宿舍楼财产报修");
	// TODO:  Add extra initialization here

	as_page.Create(IDD_DIALOG8, &managers_tab);
	ad_page.Create(IDD_DIALOG9, &managers_tab);
	ap_page.Create(IDD_DIALOG10, &managers_tab);
	vl_page.Create(IDD_DIALOG11, &managers_tab);
	vle_page.Create(IDD_DIALOG12, &managers_tab);
	vd_page.Create(IDD_DIALOG13, &managers_tab);
	vb_page.Create(IDD_DIALOG14, &managers_tab);

	CRect rs;
	managers_tab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置 
	rs.top += 40;
	rs.bottom -= 8;
	rs.left += 8;
	rs.right -= 8;
	//设置子对话框尺寸并移动到指定位置 
	as_page.MoveWindow(&rs);
	ad_page.MoveWindow(&rs);
	ap_page.MoveWindow(&rs);
	vl_page.MoveWindow(&rs);
	vle_page.MoveWindow(&rs);
	vd_page.MoveWindow(&rs);
	vb_page.MoveWindow(&rs);
	
	//分别设置隐藏和显示 
	as_page.ShowWindow(SW_SHOW);
	ad_page.ShowWindow(SW_HIDE);
	ap_page.ShowWindow(SW_HIDE);
	vl_page.ShowWindow(SW_HIDE);
	vle_page.ShowWindow(SW_HIDE);
	vd_page.ShowWindow(SW_HIDE);
	vb_page.ShowWindow(SW_HIDE);
	
	//设置默认的选项卡 
	managers_tab.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void managers_in::OnTcnSelchangeManagers(NMHDR *pNMHDR, LRESULT *pResult)
{

	CRect r;
	managers_tab.GetClientRect(&r);
	int CurSel = managers_tab.GetCurSel();

	switch (CurSel)
	{
	case 0:
		//m_page1.ShowWindow(true);
		//m_page2.ShowWindow(false);
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 1:
		//m_page1.ShowWindow(false);
		//m_page2.ShowWindow(true);
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 2:
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 3:
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 4:
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 5:
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		break;
	case 6:
		as_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ad_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		ap_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vl_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vle_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vd_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);
		vb_page.SetWindowPos(NULL, 30, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);
		break;
	}
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
