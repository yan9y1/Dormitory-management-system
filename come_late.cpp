// come_late.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "come_late.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char susername[] = "root";         //username
const char spswd[] = "****";         //password
const char shost[] = "localhost";    //or"127.0.0.1"
const char sdatabase[] = "domitory_manage";        //database
unsigned int sport = 3306;           //server port 
MYSQL smyCont;
MYSQL_RES *sresult;
MYSQL_ROW srow;
int srow_num;

// come_late dialog

IMPLEMENT_DYNAMIC(come_late, CDialogEx)

come_late::come_late(CWnd* pParent /*=NULL*/)
	: CDialogEx(come_late::IDD, pParent)
	, lr_student_name(_T(""))
	, lr_building_num(_T(""))
	, lr_room_num(_T(""))
	, lr_time(_T(""))
	, lr_reason(_T(""))
	, lre_student_num(_T(""))
{

}

come_late::~come_late()
{
}

void come_late::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, lr_student_num);
	DDX_Text(pDX, IDC_EDIT2, lr_student_name);
	DDX_Text(pDX, IDC_EDIT3, lr_building_num);
	DDX_Text(pDX, IDC_EDIT4, lr_room_num);
	DDX_Text(pDX, IDC_EDIT5, lr_time);
	DDX_Text(pDX, IDC_EDIT6, lr_reason);
	DDX_Text(pDX, IDC_EDIT1, lre_student_num);
}


BEGIN_MESSAGE_MAP(come_late, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &come_late::OnBnClickedButton1)
END_MESSAGE_MAP()


// come_late message handlers


void come_late::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = lre_student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, lre_student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lre_student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = lr_student_name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, lr_student_name, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lr_student_name, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = lr_building_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, lr_building_num, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lr_building_num, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = lr_room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, lr_room_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lr_room_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;
		
	length = lr_time.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, lr_time, length, NULL, 0, NULL, NULL);
	char* l_t = new char[nBytes + 1];
	memset(l_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lr_time, length, l_t, nBytes, NULL, NULL);
	l_t[nBytes] = 0;
	
	length = lr_reason.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, lr_reason, length, NULL, 0, NULL, NULL);
	char* l_r = new char[nBytes + 1];
	memset(l_r, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, lr_reason, length, l_r, nBytes, NULL, NULL);
	l_r[nBytes] = 0;

	mysql_init(&smyCont);
	if (mysql_real_connect(&smyCont, shost, susername, spswd, sdatabase, sport, NULL, 0)){
		mysql_query(&smyCont, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into come_late values('");
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

		sprintf(ch, "%s", r_n);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");

		sprintf(ch, "%s", l_t);
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
		//lr_reason = sql;
		mysql_query(&smyCont, sql);
	}
	if (sresult != NULL){
		mysql_free_result(sresult);
	}
	lr_student_name = "";
	lre_student_num = "";
	lr_building_num = "";
	lr_room_num = "";
	lr_time = "";
	lr_reason = "";
	UpdateData(FALSE);
}
