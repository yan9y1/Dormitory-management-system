// visit_brepair.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "visit_brepair.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)
const char username7[] = "root";         //username
const char pswd7[] = "*****";         //password
const char host7[] = "localhost";    //or"127.0.0.1"
const char database7[] = "domitory_manage";        //database
unsigned int port7 = 3306;           //server port 
MYSQL myCont7;
MYSQL_RES *result7;
MYSQL_ROW row7;
int row_num7;

// visit_brepair dialog

IMPLEMENT_DYNAMIC(visit_brepair, CDialogEx)

visit_brepair::visit_brepair(CWnd* pParent /*=NULL*/)
	: CDialogEx(visit_brepair::IDD, pParent)
{

}

visit_brepair::~visit_brepair()
{
}

void visit_brepair::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, br_list);
}


BEGIN_MESSAGE_MAP(visit_brepair, CDialogEx)
END_MESSAGE_MAP()


// visit_brepair message handlers


BOOL visit_brepair::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	br_list.InsertColumn(0, L"Ñ§ºÅ", LVCFMT_CENTER, 80);
	br_list.InsertColumn(1, L"ÐÕÃû", LVCFMT_CENTER, 80);
	br_list.InsertColumn(2, L"ËÞÉáÂ¥ºÅ", LVCFMT_CENTER, 80);
	br_list.InsertColumn(3, L"ËÞÉáÂ¥²ãºÅ", LVCFMT_CENTER, 80);
	br_list.InsertColumn(4, L"Ëð»µÇé¿ö", LVCFMT_CENTER, 80);
	int tag;
	mysql_init(&myCont7);
	if (mysql_real_connect(&myCont7, host7, username7, pswd7, database7, port7, NULL, 0)){
		mysql_query(&myCont7, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont7, "select * from repair_building");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result7 = mysql_store_result(&myCont7);
			row_num7 = mysql_num_rows(result7);
			if (result7){
				int tag = 0;
				while (row7 = mysql_fetch_row(result7)){
					char * q0 = row7[0];
					char * q1 = row7[1];
					char * q2 = row7[2];
					char * q3 = row7[3];
					char * q4 = row7[4];
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
					br_list.InsertItem(tag, _T("kill"));
					br_list.SetItemText(tag, 0, Q0);
					br_list.SetItemText(tag, 1, Q1);
					br_list.SetItemText(tag, 2, Q2);
					br_list.SetItemText(tag, 3, Q3);
					br_list.SetItemText(tag, 4, Q4);
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
	if (result7 != NULL){
		mysql_free_result(result7);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
