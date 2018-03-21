// add_propety.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "add_propety.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char username2[] = "root";         //username
const char pswd2[] = "*******";         //password
const char host2[] = "localhost";    //or"127.0.0.1"
const char database2[] = "domitory_manage";        //database
unsigned int port2 = 3306;           //server port 
MYSQL myCont2;
MYSQL_RES *result2;
MYSQL_ROW row2;
int row_num2;

// add_propety dialog

IMPLEMENT_DYNAMIC(add_propety, CDialogEx)

add_propety::add_propety(CWnd* pParent /*=NULL*/)
	: CDialogEx(add_propety::IDD, pParent)
	, ap_building_num(_T(""))
	, ap_room_num(_T(""))
	, propety_num(_T(""))
{

}

add_propety::~add_propety()
{
}

void add_propety::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ap_building_num);
	DDX_Text(pDX, IDC_EDIT2, ap_room_num);
	DDX_Text(pDX, IDC_EDIT3, propety_num);
	DDX_Control(pDX, IDC_LIST1, propety_list);
}


BEGIN_MESSAGE_MAP(add_propety, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &add_propety::OnBnClickedButton1)
END_MESSAGE_MAP()


// add_propety message handlers


BOOL add_propety::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	propety_list.InsertColumn(0, L"楼号", LVCFMT_CENTER, 150);
	propety_list.InsertColumn(1, L"宿舍号", LVCFMT_CENTER, 150);
	propety_list.InsertColumn(2, L"财产号", LVCFMT_CENTER, 150);
	//domitory_list.InsertColumn(3, L"可住人数", LVCFMT_CENTER, 80);
	int tag;
	mysql_init(&myCont2);
	if (mysql_real_connect(&myCont2, host2, username2, pswd2, database2, port2, NULL, 0)){
		mysql_query(&myCont2, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont2, "select * from domitory_propety");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result2 = mysql_store_result(&myCont2);
			row_num2 = mysql_num_rows(result2);
			if (result2){
				int tag = 0;
				while (row2 = mysql_fetch_row(result2)){
					char * q0 = row2[0];
					char * q1 = row2[1];
					char * q2 = row2[2];
					//char * q3 = row1[3];
					//char * q4 = row[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					//int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					//int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					//LPWSTR Q3 = new WCHAR[q3l];
					//LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					//MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					//MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					propety_list.InsertItem(tag, _T("kill"));
					propety_list.SetItemText(tag, 0, Q0);
					propety_list.SetItemText(tag, 1, Q1);
					propety_list.SetItemText(tag, 2, Q2);
					//domitory_list.SetItemText(tag, 3, Q3);
					//domitory_list.SetItemText(tag, 4, Q4);
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					//delete[]Q3;
					//delete[]Q4;
				}
			}
		}
	}
	else{
		//cout << "connect failed!" << endl;
	}
	if (result2 != NULL){
		mysql_free_result(result2);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void add_propety::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int length = ap_building_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, ap_building_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ap_building_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = ap_room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, ap_room_num, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ap_room_num, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = propety_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, propety_num, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, propety_num, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;
	/*
	length = people_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, people_num, length, NULL, 0, NULL, NULL);
	char* b_n = new char[nBytes + 1];
	memset(b_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, people_num, length, b_n, nBytes, NULL, NULL);
	b_n[nBytes] = 0;
	length = room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, room_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, room_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;*/
	mysql_init(&myCont2);
	if (mysql_real_connect(&myCont2, host2, username2, pswd2, database2, port2, NULL, 0)){
		mysql_query(&myCont2, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into domitory_propety values('");
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
		/*
		sprintf(ch, "%s", in_t);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ",");
		strcat(sql, "'");
		*/
		sprintf(ch, "%s", in_t);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ")");
		strcat(sql, ";");


		mysql_query(&myCont2, sql);

		int w = mysql_query(&myCont2, "select * from domitory_propety");
		if (w != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result2 = mysql_store_result(&myCont2);
			if (result2){
				int tag = 0;
				while (row2 = mysql_fetch_row(result2)){
					char * q0 = row2[0];
					char * q1 = row2[1];
					char * q2 = row2[2];
					//char * q3 = row2[3];
					//char * q4 = row1[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					//int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					//int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					//LPWSTR Q3 = new WCHAR[q3l];
					//LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					//MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					//MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					//Please.InsertItem(tag, _T("kill"));
					//Please.SetItemText(tag, 0, Q0);
					//if (tag == 2){
					//test = "fads";
					//}
					//ttest = row_num;
					UpdateData(FALSE);
					if (tag < row_num2){
						propety_list.SetItemText(tag, 0, Q0);
						propety_list.SetItemText(tag, 1, Q1);
						propety_list.SetItemText(tag, 2, Q2);
						//domitory_list.SetItemText(tag, 3, Q3);
						//domitory_list.SetItemText(tag, 4, Q4);
					}
					else{
						propety_list.InsertItem(tag, _T("kill"));
						propety_list.SetItemText(tag, 0, Q0);
						propety_list.SetItemText(tag, 1, Q1);
						propety_list.SetItemText(tag, 2, Q2);
						//domitory_list.SetItemText(tag, 3, Q3);
						//as_list.SetItemText(tag, 4, Q4);
						++row_num2;
					}
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					//delete[]Q3;
					//delete[]Q4;
				}
			}
		}
	}
	if (result2 != NULL){
		mysql_free_result(result2);
	}
	ap_building_num = "";
	ap_room_num = "";
	propety_num = "";
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
