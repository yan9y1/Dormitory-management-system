// come_school.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "come_school.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char susername2[] = "root";         //username
const char spswd2[] = "******";         //password
const char shost2[] = "localhost";    //or"127.0.0.1"
const char sdatabase2[] = "domitory_manage";        //database
unsigned int sport2 = 3306;           //server port 
MYSQL smyCont2;
MYSQL_RES *sresult2;
MYSQL_ROW srow2;
int srow_num2;

// come_school dialog

IMPLEMENT_DYNAMIC(come_school, CDialogEx)

come_school::come_school(CWnd* pParent /*=NULL*/)
	: CDialogEx(come_school::IDD, pParent)
	, c_student_num(_T(""))
	, c_student_name(_T(""))
{

}

come_school::~come_school()
{
}

void come_school::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, c_student_num);
	DDX_Text(pDX, IDC_EDIT2, c_student_name);
}


BEGIN_MESSAGE_MAP(come_school, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &come_school::OnBnClickedButton1)
END_MESSAGE_MAP()


// come_school message handlers


void come_school::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = c_student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, c_student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, c_student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = c_student_name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, c_student_name, length, NULL, 0, NULL, NULL);
	char* l_r = new char[nBytes + 1];
	memset(l_r, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, c_student_name, length, l_r, nBytes, NULL, NULL);
	l_r[nBytes] = 0;

	mysql_init(&smyCont2);
	if (mysql_real_connect(&smyCont2, shost2, susername2, spswd2, sdatabase2, sport2, NULL, 0)){
		mysql_query(&smyCont2, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "update leave_school set come_actually = '“—πÈ«ﬁ' where student_num = '");
		//strcpy(sql, "insert into leave_school (come_actually) values ('“—πÈ«ﬁ') where student_num = '");
		sprintf(ch, "%s", s_n);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ";");
		//c_student_num = sql;
		//test = sql;
		mysql_query(&smyCont2, sql);
	}
	if (sresult2 != NULL){
		mysql_free_result(sresult2);
	}
	c_student_num = "";
	c_student_name = "";
	UpdateData(FALSE);
}
