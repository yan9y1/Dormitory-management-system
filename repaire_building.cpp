// repaire_building.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "repaire_building.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char susername4[] = "root";         //username
const char spswd4[] = "*******";         //password
const char shost4[] = "localhost";    //or"127.0.0.1"
const char sdatabase4[] = "domitory_manage";        //database
unsigned int sport4 = 3306;           //server port 
MYSQL smyCont4;
MYSQL_RES *sresult4;
MYSQL_ROW srow4;
int srow_num4;

// repaire_building dialog

IMPLEMENT_DYNAMIC(repaire_building, CDialogEx)

repaire_building::repaire_building(CWnd* pParent /*=NULL*/)
	: CDialogEx(repaire_building::IDD, pParent)
	, rb_student_num(_T(""))
	, rb_student_name(_T(""))
	, rb_building_num(_T(""))
	, rb_floor_num(_T(""))
	, rb_situation(_T(""))
{

}

repaire_building::~repaire_building()
{
}

void repaire_building::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rb_student_num);
	DDX_Text(pDX, IDC_EDIT2, rb_student_name);
	DDX_Text(pDX, IDC_EDIT7, rb_building_num);
	DDX_Text(pDX, IDC_EDIT3, rb_floor_num);
	DDX_Text(pDX, IDC_EDIT4, rb_situation);
}


BEGIN_MESSAGE_MAP(repaire_building, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &repaire_building::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &repaire_building::OnEnChangeEdit4)
END_MESSAGE_MAP()


// repaire_building message handlers


void repaire_building::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = rb_student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, rb_student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rb_student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = rb_student_name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rb_student_name, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rb_student_name, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = rb_building_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rb_building_num, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rb_building_num, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = rb_floor_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rb_floor_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rb_floor_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;

	length = rb_situation.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, rb_situation, length, NULL, 0, NULL, NULL);
	char* l_r = new char[nBytes + 1];
	memset(l_r, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, rb_situation, length, l_r, nBytes, NULL, NULL);
	l_r[nBytes] = 0;

	mysql_init(&smyCont4);
	if (mysql_real_connect(&smyCont4, shost4, susername4, spswd4, sdatabase4, sport4, NULL, 0)){
		mysql_query(&smyCont4, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into repair_building values('");
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
		mysql_query(&smyCont4, sql);
	}
	if (sresult4 != NULL){
		mysql_free_result(sresult4);
	}
	rb_student_name = "";
	rb_student_num = "";
	rb_building_num = "";
	rb_floor_num = "";
	rb_situation = "";
	//rr_rn = "";
	UpdateData(FALSE);

}


void repaire_building::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
