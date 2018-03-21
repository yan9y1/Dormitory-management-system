// visit_leave.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "visit_leave.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)
const char username5[] = "root";         //username
const char pswd5[] = "";         //password
const char host5[] = "localhost";    //or"127.0.0.1"
const char database5[] = "domitory_manage";        //database
unsigned int port5 = 3306;           //server port 
MYSQL myCont5;
MYSQL_RES *result5;
MYSQL_ROW row5;
int row_num5;

// visit_leave dialog

IMPLEMENT_DYNAMIC(visit_leave, CDialogEx)

visit_leave::visit_leave(CWnd* pParent /*=NULL*/)
	: CDialogEx(visit_leave::IDD, pParent)
	, le_d(_T(""))
{

}

visit_leave::~visit_leave()
{
}

void visit_leave::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, leave_list);
	DDX_Text(pDX, IDC_EDIT1, le_d);
}


BEGIN_MESSAGE_MAP(visit_leave, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &visit_leave::OnBnClickedButton1)
END_MESSAGE_MAP()


// visit_leave message handlers


BOOL visit_leave::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	leave_list.InsertColumn(0, L"学号", LVCFMT_CENTER, 80);
	leave_list.InsertColumn(1, L"姓名", LVCFMT_CENTER, 80);
	leave_list.InsertColumn(2, L"离校时间", LVCFMT_CENTER, 80);
	leave_list.InsertColumn(3, L"返校楼号", LVCFMT_CENTER, 80);
	leave_list.InsertColumn(4, L"返校状态", LVCFMT_CENTER, 80);
	int tag;
	mysql_init(&myCont5);
	if (mysql_real_connect(&myCont5, host5, username5, pswd5, database5, port5, NULL, 0)){
		mysql_query(&myCont5, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont5, "select * from leave_school");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result5 = mysql_store_result(&myCont5);
			row_num5 = mysql_num_rows(result5);
			if (result5){
				int tag = 0;
				while (row5 = mysql_fetch_row(result5)){
					char * q0 = row5[0];
					char * q1 = row5[1];
					char * q2 = row5[2];
					char * q3 = row5[3];
					char * q4 = row5[4];
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
					leave_list.InsertItem(tag, _T("kill"));
					leave_list.SetItemText(tag, 0, Q0);
					leave_list.SetItemText(tag, 1, Q1);
					leave_list.SetItemText(tag, 2, Q2);
					leave_list.SetItemText(tag, 3, Q3);
					leave_list.SetItemText(tag, 4, Q4);
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
	if (result5 != NULL){
		mysql_free_result(result5);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void visit_leave::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = le_d.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, le_d, length, NULL, 0, NULL, NULL);
	char* s_d = new char[nBytes + 1];
	memset(s_d, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, le_d, length, s_d, nBytes, NULL, NULL);
	s_d[nBytes] = 0;

	mysql_init(&myCont5);
	if (mysql_real_connect(&myCont5, host5, username5, pswd5, database5, port5, NULL, 0)){
		mysql_query(&myCont5, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "delete from leave_school where student_num = '");
		sprintf(ch, "%s", s_d);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ";");
		mysql_query(&myCont5, sql);
	}

	int w = mysql_query(&myCont5, "select * from leave_school");
	if (w != 0){
		//cout << "query failed!" << endl;
	}
	else{
		result5 = mysql_store_result(&myCont5);
		int row_num2 = mysql_num_rows(result5);
		if (result5){
			int tag = 0;
			while (row5 = mysql_fetch_row(result5)){
				char * q0 = row5[0];
				char * q1 = row5[1];
				char * q2 = row5[2];
				char * q3 = row5[3];
				char * q4 = row5[4];
				int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
				int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
				int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
				int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
				int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
				//int q5l = MultiByteToWideChar(CP_ACP, 0, q5, -1, NULL, 0);
				LPWSTR Q0 = new WCHAR[q0l];
				LPWSTR Q1 = new WCHAR[q1l];
				LPWSTR Q2 = new WCHAR[q2l];
				LPWSTR Q3 = new WCHAR[q3l];
				LPWSTR Q4 = new WCHAR[q4l];
				//LPWSTR Q5 = new WCHAR[q5l];
				MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
				MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
				MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
				MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
				MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
				//MultiByteToWideChar(CP_ACP, 0, q5, -1, Q5, q5l);
				//if (tag < row_num2){
				leave_list.SetItemText(tag, 0, Q0);
				leave_list.SetItemText(tag, 1, Q1);
				leave_list.SetItemText(tag, 2, Q2);
				leave_list.SetItemText(tag, 3, Q3);
				leave_list.SetItemText(tag, 4, Q4);
				//late_list.SetItemText(tag, 5, Q5);
				//}
				tag++;
				delete[]Q0;
				delete[]Q1;
				delete[]Q2;
				delete[]Q3;
				delete[]Q4;
				//delete[]Q5;
			}
		}
		for (int k = row_num2; k < row_num5; k++){
			leave_list.SetItemText(k, 0, L'');
			leave_list.SetItemText(k, 1, L'');
			leave_list.SetItemText(k, 2, L'');
			leave_list.SetItemText(k, 3, L'');
			leave_list.SetItemText(k, 4, L'');
			//late_list.SetItemText(k, 5, L'');
		}

	}
	if (result5 != NULL){
		mysql_free_result(result5);
	}

	le_d = "";
	UpdateData(FALSE);
}
