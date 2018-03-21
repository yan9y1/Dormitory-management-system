// add_students.cpp : implementation file
//
#include "stdafx.h"
#include "D_M_S.h"
#include "add_students.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)
const char username[] = "root";         //username
const char pswd[] = "***********";         //password
const char host[] = "localhost";    //or"127.0.0.1"
const char database[] = "domitory_manage";        //database
unsigned int port = 3306;           //server port 
MYSQL myCont;
MYSQL_RES *result;
MYSQL_ROW row;
int row_num;
// add_students dialog

IMPLEMENT_DYNAMIC(add_students, CDialogEx)

add_students::add_students(CWnd* pParent /*=NULL*/)
	: CDialogEx(add_students::IDD, pParent)
	, student_num(_T(""))
	, name(_T(""))
	, in_time(_T(""))
	, room_num(_T(""))
	, building_num(_T(""))
	//, room_num(_T(""))
	, as_d(_T(""))
{

}

add_students::~add_students()
{
}

void add_students::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, as_list);
	DDX_Text(pDX, IDC_EDIT1, student_num);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, in_time);
	//  DDX_Text(pDX, IDC_EDIT4, room_num);
	DDX_Text(pDX, IDC_EDIT4, building_num);
	DDX_Text(pDX, IDC_EDIT5, room_num);
	DDX_Text(pDX, IDC_EDIT6, as_d);
}


BEGIN_MESSAGE_MAP(add_students, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &add_students::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &add_students::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &add_students::OnBnClickedButton2)
END_MESSAGE_MAP()


// add_students message handlers


void add_students::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


BOOL add_students::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	as_list.InsertColumn(0, L"学号", LVCFMT_CENTER, 95);
	as_list.InsertColumn(1, L"姓名", LVCFMT_CENTER, 95);
	as_list.InsertColumn(2, L"入学时间", LVCFMT_CENTER, 95);
	as_list.InsertColumn(3, L"宿舍楼号", LVCFMT_CENTER, 95);
	as_list.InsertColumn(4, L"宿舍号", LVCFMT_CENTER, 95);
	int tag;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, username, pswd, database, port, NULL, 0)){
		mysql_query(&myCont, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont, "select * from students");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result = mysql_store_result(&myCont);
			row_num = mysql_num_rows(result);
			if (result){
				int tag = 0;
				while (row = mysql_fetch_row(result)){
					char * q0 = row[0];
					char * q1 = row[1];
					char * q2 = row[2];
					char * q3 = row[3];
					char * q4 = row[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					LPWSTR Q3 = new WCHAR[q3l];
					LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					as_list.InsertItem(tag, _T("kill"));
					as_list.SetItemText(tag, 0, Q0);
					as_list.SetItemText(tag, 1, Q1);
					as_list.SetItemText(tag, 2, Q2);
					as_list.SetItemText(tag, 3, Q3);
					as_list.SetItemText(tag, 4, Q4);
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					delete[]Q3;
					delete[]Q4;
				}
			}
		}
	}
	else{
		//cout << "connect failed!" << endl;
	}
	if (result != NULL){
		mysql_free_result(result);
	}


	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void add_students::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int length = student_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, student_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, student_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = name.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, name, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, name, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = in_time.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, in_time, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, in_time, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = building_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, building_num, length, NULL, 0, NULL, NULL);
	char* b_n = new char[nBytes + 1];
	memset(b_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, building_num, length, b_n, nBytes, NULL, NULL);
	b_n[nBytes] = 0;

	length = room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, room_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, room_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, username, pswd, database, port, NULL, 0)){
		mysql_query(&myCont, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into students values('");
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

		sprintf(ch, "%s", b_n);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");

		sprintf(ch, "%s", r_n);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ")");
		strcat(sql, ";");
		mysql_query(&myCont, sql);

		int w = mysql_query(&myCont, "select * from students");
		if (w != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result = mysql_store_result(&myCont);
			if (result){
				int tag = 0;
				while (row = mysql_fetch_row(result)){
					char * q0 = row[0];
					char * q1 = row[1];
					char * q2 = row[2];
					char * q3 = row[3];
					char * q4 = row[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					LPWSTR Q3 = new WCHAR[q3l];
					LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);

					UpdateData(FALSE);
					if (tag < row_num){
						as_list.SetItemText(tag, 0, Q0);
						as_list.SetItemText(tag, 1, Q1);
						as_list.SetItemText(tag, 2, Q2);
						as_list.SetItemText(tag, 3, Q3);
						as_list.SetItemText(tag, 4, Q4);
					}
					else{
						as_list.InsertItem(tag, _T("kill"));
						as_list.SetItemText(tag, 0, Q0);
						as_list.SetItemText(tag, 1, Q1);
						as_list.SetItemText(tag, 2, Q2);
						as_list.SetItemText(tag, 3, Q3);
						as_list.SetItemText(tag, 4, Q4);
						++row_num;
					}
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					delete[]Q3;
					delete[]Q4;
				}
			}
		}
	}
	//row_num = 0;
	if (result != NULL){
		mysql_free_result(result);
	}
	student_num = "";
	name = "";
	in_time = "";
	building_num = "";
	room_num = "";
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void add_students::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = as_d.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, as_d, length, NULL, 0, NULL, NULL);
	char* s_d = new char[nBytes + 1];
	memset(s_d, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, as_d, length, s_d, nBytes, NULL, NULL);
	s_d[nBytes] = 0;

	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, username, pswd, database, port, NULL, 0)){
		mysql_query(&myCont, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "delete from students where student_num = '");
		sprintf(ch, "%s", s_d);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ";");
		mysql_query(&myCont, sql);
	}

	int w = mysql_query(&myCont, "select * from students");
	if (w != 0){
		//cout << "query failed!" << endl;
	}
	else{
		result = mysql_store_result(&myCont);
		int row_num2 =  mysql_num_rows(result);
		if (result){
			int tag = 0;
			while (row = mysql_fetch_row(result)){
				char * q0 = row[0];
				char * q1 = row[1];
				char * q2 = row[2];
				char * q3 = row[3];
				char * q4 = row[4];
				int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
				int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
				int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
				int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
				int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
				LPWSTR Q0 = new WCHAR[q0l];
				LPWSTR Q1 = new WCHAR[q1l];
				LPWSTR Q2 = new WCHAR[q2l];
				LPWSTR Q3 = new WCHAR[q3l];
				LPWSTR Q4 = new WCHAR[q4l];
				MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
				MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
				MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
				MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
				MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
				//if (tag < row_num2){
					as_list.SetItemText(tag, 0, Q0);
					as_list.SetItemText(tag, 1, Q1);
					as_list.SetItemText(tag, 2, Q2);
					as_list.SetItemText(tag, 3, Q3);
					as_list.SetItemText(tag, 4, Q4);
				//}
				tag++;
				delete[]Q0;
				delete[]Q1;
				delete[]Q2;
				delete[]Q3;
				delete[]Q4;
			}
		}
		for (int k = row_num2; k < row_num;k++){
			as_list.SetItemText(k, 0, L'');
			as_list.SetItemText(k, 1, L'');
			as_list.SetItemText(k, 2, L'');
			as_list.SetItemText(k, 3, L'');
			as_list.SetItemText(k, 4, L'');
		}

	}
	if (result != NULL){
		mysql_free_result(result);
	}

	as_d = "";
	UpdateData(FALSE);
}
