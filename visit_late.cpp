// visit_late.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "visit_late.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)
const char username4[] = "root";         //username
const char pswd4[] = "";         //password
const char host4[] = "localhost";    //or"127.0.0.1"
const char database4[] = "domitory_manage";        //database
unsigned int port4 = 3306;           //server port 
MYSQL myCont4;
MYSQL_RES *result4;
MYSQL_ROW row4;
int row_num4;

// visit_late dialog

IMPLEMENT_DYNAMIC(visit_late, CDialogEx)

visit_late::visit_late(CWnd* pParent /*=NULL*/)
	: CDialogEx(visit_late::IDD, pParent)
	, cl_d(_T(""))
{

}

visit_late::~visit_late()
{
}

void visit_late::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, late_list);
	DDX_Text(pDX, IDC_EDIT1, cl_d);
}


BEGIN_MESSAGE_MAP(visit_late, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &visit_late::OnBnClickedButton1)
END_MESSAGE_MAP()


// visit_late message handlers


BOOL visit_late::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	late_list.InsertColumn(0, L"—ß∫≈", LVCFMT_CENTER, 80);
	late_list.InsertColumn(1, L"–’√˚", LVCFMT_CENTER, 80);
	late_list.InsertColumn(2, L"Àﬁ…·¬•∫≈", LVCFMT_CENTER, 80);
	late_list.InsertColumn(3, L"Àﬁ…·∫≈", LVCFMT_CENTER, 80);
	late_list.InsertColumn(4, L"ÕÌπÈ ±º‰(h)", LVCFMT_CENTER, 80);
	late_list.InsertColumn(5, L"ÕÌπÈ‘≠“Ú", LVCFMT_CENTER, 80);
	int tag;
	mysql_init(&myCont4);
	if (mysql_real_connect(&myCont4, host4, username4, pswd4, database4, port4, NULL, 0)){
		mysql_query(&myCont4, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont4, "select * from come_late");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result4 = mysql_store_result(&myCont4);
			row_num4 = mysql_num_rows(result4);
			if (result4){
				int tag = 0;
				while (row4 = mysql_fetch_row(result4)){
					char * q0 = row4[0];
					char * q1 = row4[1];
					char * q2 = row4[2];
					char * q3 = row4[3];
					char * q4 = row4[4];
					char * q5 = row4[5];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					int q5l = MultiByteToWideChar(CP_ACP, 0, q5, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					LPWSTR Q3 = new WCHAR[q3l];
					LPWSTR Q4 = new WCHAR[q4l];
					LPWSTR Q5 = new WCHAR[q5l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					MultiByteToWideChar(CP_ACP, 0, q5, -1, Q5, q5l);
					late_list.InsertItem(tag, _T("kill"));
					late_list.SetItemText(tag, 0, Q0);
					late_list.SetItemText(tag, 1, Q1);
					late_list.SetItemText(tag, 2, Q2);
					late_list.SetItemText(tag, 3, Q3);
					late_list.SetItemText(tag, 4, Q4);
					late_list.SetItemText(tag, 5, Q5);
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					delete[]Q3;
					delete[]Q4;
					delete[]Q5;
				}
			}
		}
	}
	else{
		//cout << "connect failed!" << endl;
	}
	if (result4 != NULL){
		mysql_free_result(result4);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void visit_late::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = cl_d.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, cl_d, length, NULL, 0, NULL, NULL);
	char* s_d = new char[nBytes + 1];
	memset(s_d, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, cl_d, length, s_d, nBytes, NULL, NULL);
	s_d[nBytes] = 0;

	mysql_init(&myCont4);
	if (mysql_real_connect(&myCont4, host4, username4, pswd4, database4, port4, NULL, 0)){
		mysql_query(&myCont4, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "delete from come_late where student_num = '");
		sprintf(ch, "%s", s_d);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ";");
		mysql_query(&myCont4, sql);
	}

	int w = mysql_query(&myCont4, "select * from come_late");
	if (w != 0){
		//cout << "query failed!" << endl;
	}
	else{
		result4 = mysql_store_result(&myCont4);
		int row_num2 = mysql_num_rows(result4);
		if (result4){
			int tag = 0;
			while (row4 = mysql_fetch_row(result4)){
				char * q0 = row4[0];
				char * q1 = row4[1];
				char * q2 = row4[2];
				char * q3 = row4[3];
				char * q4 = row4[4];
				char * q5 = row4[5];
				int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
				int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
				int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
				int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
				int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
				int q5l = MultiByteToWideChar(CP_ACP, 0, q5, -1, NULL, 0);
				LPWSTR Q0 = new WCHAR[q0l];
				LPWSTR Q1 = new WCHAR[q1l];
				LPWSTR Q2 = new WCHAR[q2l];
				LPWSTR Q3 = new WCHAR[q3l];
				LPWSTR Q4 = new WCHAR[q4l];
				LPWSTR Q5 = new WCHAR[q5l];
				MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
				MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
				MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
				MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
				MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
				MultiByteToWideChar(CP_ACP, 0, q5, -1, Q5, q5l);
				//if (tag < row_num2){
				late_list.SetItemText(tag, 0, Q0);
				late_list.SetItemText(tag, 1, Q1);
				late_list.SetItemText(tag, 2, Q2);
				late_list.SetItemText(tag, 3, Q3);
				late_list.SetItemText(tag, 4, Q4);
				late_list.SetItemText(tag, 5, Q5);
				//}
				tag++;
				delete[]Q0;
				delete[]Q1;
				delete[]Q2;
				delete[]Q3;
				delete[]Q4;
				delete[]Q5;
			}
		}
		for (int k = row_num2; k < row_num4; k++){
			late_list.SetItemText(k, 0, L'');
			late_list.SetItemText(k, 1, L'');
			late_list.SetItemText(k, 2, L'');
			late_list.SetItemText(k, 3, L'');
			late_list.SetItemText(k, 4, L'');
			late_list.SetItemText(k, 5, L'');
		}

	}
	if (result4 != NULL){
		mysql_free_result(result4);
	}

	s_d = "";
	UpdateData(FALSE);

}
