// leave_school.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "leave_school.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char susername1[] = "root";         //username
const char spswd1[] = "***";         //password
const char shost1[] = "localhost";    //or"127.0.0.1"
const char sdatabase1[] = "domitory_manage";        //database
unsigned int sport1 = 3306;           //server port 
MYSQL smyCont1;
MYSQL_RES *sresult1;
MYSQL_ROW srow1;
int srow_num1;

// leave_school dialog

IMPLEMENT_DYNAMIC(leave_school, CDialogEx)

leave_school::leave_school(CWnd* pParent /*=NULL*/)
	: CDialogEx(leave_school::IDD, pParent)
	, ls_student_num(_T(""))
	, ls_student_name(_T(""))
	, ls_lt(_T(""))
	, ls_ct(_T(""))
{

}

leave_school::~leave_school()
{
}

void leave_school::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ls_student_num);
	DDX_Text(pDX, IDC_EDIT2, ls_student_name);
	DDX_Text(pDX, IDC_EDIT3, ls_lt);
	DDX_Text(pDX, IDC_EDIT4, ls_ct);
}


BEGIN_MESSAGE_MAP(leave_school, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &leave_school::OnBnClickedButton1)
END_MESSAGE_MAP()


// leave_school message handlers


void leave_school::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = ls_student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, ls_student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ls_student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = ls_student_name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, ls_student_name, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ls_student_name, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = ls_lt.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, ls_lt, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ls_lt, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = ls_ct.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, ls_ct, length, NULL, 0, NULL, NULL);
	char* l_r = new char[nBytes + 1];
	memset(l_r, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ls_ct, length, l_r, nBytes, NULL, NULL);
	l_r[nBytes] = 0;

	mysql_init(&smyCont1);
	if (mysql_real_connect(&smyCont1, shost1, susername1, spswd1, sdatabase1, sport1, NULL, 0)){
		mysql_query(&smyCont1, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into leave_school(student_num,student_name,leave_date,come_date) values('");
		sprintf(ch, "%s", s_n);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");

		sprintf(ch, "%s", nam);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");

		sprintf(ch, "%s", in_t);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");

		sprintf(ch, "%s", l_r);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ")");
		strcat(sql, ";");
		//test = sql;
		mysql_query(&smyCont1, sql);
	}
	if (sresult1 != NULL){
		mysql_free_result(sresult1);
	}
	ls_student_num = "";
	ls_student_name = "";
	ls_lt = "";
	ls_ct = "";
	UpdateData(FALSE);
}
