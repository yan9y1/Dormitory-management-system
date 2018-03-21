// visit_drepair.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "visit_drepair.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)
const char username6[] = "root";         //username
const char pswd6[] = "";         //password
const char host6[] = "localhost";    //or"127.0.0.1"
const char database6[] = "domitory_manage";        //database
unsigned int port6 = 3306;           //server port 
MYSQL myCont6;
MYSQL_RES *result6;
MYSQL_ROW row6;
int row_num6;

// visit_drepair dialog

IMPLEMENT_DYNAMIC(visit_drepair, CDialogEx)

visit_drepair::visit_drepair(CWnd* pParent /*=NULL*/)
	: CDialogEx(visit_drepair::IDD, pParent)
{

}

visit_drepair::~visit_drepair()
{
}

void visit_drepair::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, rr_list);
}


BEGIN_MESSAGE_MAP(visit_drepair, CDialogEx)
END_MESSAGE_MAP()


// visit_drepair message handlers


BOOL visit_drepair::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	rr_list.InsertColumn(0, L"—ß∫≈", LVCFMT_CENTER, 80);
	rr_list.InsertColumn(1, L"–’√˚", LVCFMT_CENTER, 80);
	rr_list.InsertColumn(2, L"Àﬁ…·¬•∫≈", LVCFMT_CENTER, 80);
	rr_list.InsertColumn(3, L"Àﬁ…·∫≈", LVCFMT_CENTER, 80);
	rr_list.InsertColumn(4, L"Œ¨–ﬁŒÔ∆∑∫≈", LVCFMT_CENTER, 80);
	int tag;
	mysql_init(&myCont6);
	if (mysql_real_connect(&myCont6, host6, username6, pswd6, database6, port6, NULL, 0)){
		mysql_query(&myCont6, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont6, "select * from repair_room");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result6 = mysql_store_result(&myCont6);
			row_num6 = mysql_num_rows(result6);
			if (result6){
				int tag = 0;
				while (row6 = mysql_fetch_row(result6)){
					char * q0 = row6[0];
					char * q1 = row6[1];
					char * q2 = row6[2];
					char * q3 = row6[3];
					char * q4 = row6[4];
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
					rr_list.InsertItem(tag, _T("kill"));
					rr_list.SetItemText(tag, 0, Q0);
					rr_list.SetItemText(tag, 1, Q1);
					rr_list.SetItemText(tag, 2, Q2);
					rr_list.SetItemText(tag, 3, Q3);
					rr_list.SetItemText(tag, 4, Q4);
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
	if (result6 != NULL){
		mysql_free_result(result6);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
