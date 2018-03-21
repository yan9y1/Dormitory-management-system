// repair_room.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "repair_room.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char susername3[] = "root";         //username
const char spswd3[] = "***********";         //password
const char shost3[] = "localhost";    //or"127.0.0.1"
const char sdatabase3[] = "domitory_manage";        //database
unsigned int sport3 = 3306;           //server port 
MYSQL smyCont3;
MYSQL_RES *sresult3;
MYSQL_ROW srow3;
int srow_num3;

// repair_room dialog

IMPLEMENT_DYNAMIC(repair_room, CDialogEx)

repair_room::repair_room(CWnd* pParent /*=NULL*/)
	: CDialogEx(repair_room::IDD, pParent)
	, rr_student_num(_T(""))
	, rr_student_name(_T(""))
	, rr_building_num(_T(""))
	, rr_room_num(_T(""))
	, rr_rn(_T(""))
{

}

repair_room::~repair_room()
{
}

void repair_room::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rr_student_num);
	DDX_Text(pDX, IDC_EDIT3, rr_student_name);
	DDX_Text(pDX, IDC_EDIT2, rr_building_num);
	DDX_Text(pDX, IDC_EDIT7, rr_room_num);
	DDX_Text(pDX, IDC_EDIT4, rr_rn);
}


BEGIN_MESSAGE_MAP(repair_room, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &repair_room::OnBnClickedButton1)
END_MESSAGE_MAP()


// repair_room message handlers


void repair_room::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = rr_student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, rr_student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rr_student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = rr_student_name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rr_student_name, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rr_student_name, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = rr_building_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rr_building_num, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rr_building_num, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = rr_room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rr_room_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rr_room_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;

	length = rr_rn.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rr_rn, length, NULL, 0, NULL, NULL);
	char* l_r = new char[nBytes + 1];
	memset(l_r, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rr_rn, length, l_r, nBytes, NULL, NULL);
	l_r[nBytes] = 0;

	mysql_init(&smyCont3);
	if (mysql_real_connect(&smyCont3, shost3, susername3, spswd3, sdatabase3, sport3, NULL, 0)){
		mysql_query(&smyCont3, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into repair_room values('");
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

		sprintf(ch, "%s", l_r);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ")");
		strcat(sql, ";");
		//test = sql;
		//rr_rn = sql;
		mysql_query(&smyCont3, sql);
	}
	if (sresult3 != NULL){
		mysql_free_result(sresult3);
	}
	rr_student_name = "";
	rr_student_num = "";
	rr_building_num = "";
	rr_room_num = "";
	rr_rn = "";
	UpdateData(FALSE);
}
