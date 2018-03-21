
// D_M_SDlg.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "D_M_SDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CD_M_SDlg dialog



CD_M_SDlg::CD_M_SDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CD_M_SDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CD_M_SDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CD_M_SDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CD_M_SDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CD_M_SDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CD_M_SDlg message handlers

BOOL CD_M_SDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CD_M_SDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CD_M_SDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CD_M_SDlg::OnBnClickedButton1()
{
	if (students_p == NULL)
	{
		students_p = new students_in();
		students_p->Create(IDD_DIALOG1, this);
	}

	if (students_p == NULL) return (void)MessageBox(_T("子窗口的句柄为空！"));
	students_p->ShowWindow(SW_SHOWNORMAL);
	// TODO: Add your control notification handler code here
}


void CD_M_SDlg::OnBnClickedButton2()
{
	if (managers_p == NULL)
	{
		managers_p = new managers_in();
		managers_p->Create(IDD_DIALOG2, this);
	}

	if (managers_p == NULL) return (void)MessageBox(_T("子窗口的句柄为空！"));
	managers_p->ShowWindow(SW_SHOWNORMAL);
	// TODO: Add your control notification handler code here
}
