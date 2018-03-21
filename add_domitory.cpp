// add_domitory.cpp : implementation file
//

#include "stdafx.h"
#include "D_M_S.h"
#include "add_domitory.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "mysql.h"
#include "Windows.h"
#include "CString"
#include "string"
#include "cstdio"
#include"iostream"
#pragma warning(disable:4996)

const char username1[] = "root";         //username
const char pswd1[] = "*********";         //password
const char host1[] = "localhost";    //or"127.0.0.1"
const char database1[] = "domitory_manage";        //database
unsigned int port1 = 3306;           //server port 
MYSQL myCont1;
MYSQL_RES *result1;
MYSQL_ROW row1;
int row_num1;
// add_domitory dialog

IMPLEMENT_DYNAMIC(add_domitory, CDialogEx)

add_domitory::add_domitory(CWnd* pParent /*=NULL*/)
	: CDialogEx(add_domitory::IDD, pParent)
	, md_building_num(_T(""))
	, md_room_num(_T(""))
	, phone_num(_T(""))
	, people_num(_T(""))
	, ad_d(_T(""))
{

}

add_domitory::~add_domitory()
{
}

void add_domitory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, md_building_num);
	DDX_Text(pDX, IDC_EDIT2, md_room_num);
	DDX_Text(pDX, IDC_EDIT3, phone_num);
	DDX_Text(pDX, IDC_EDIT4, people_num);
	DDX_Control(pDX, IDC_LIST2, domitory_list);
	DDX_Text(pDX, IDC_EDIT5, ad_d);
}


BEGIN_MESSAGE_MAP(add_domitory, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &add_domitory::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &add_domitory::OnBnClickedButton2)
END_MESSAGE_MAP()


// add_domitory message handlers


BOOL add_domitory::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//CDialogEx::OnInitDialog();
	domitory_list.InsertColumn(0, L"楼号", LVCFMT_CENTER, 100);
	domitory_list.InsertColumn(1, L"宿舍号", LVCFMT_CENTER, 100);
	domitory_list.InsertColumn(2, L"电话号", LVCFMT_CENTER, 100);
	domitory_list.InsertColumn(3, L"可住人数", LVCFMT_CENTER, 100);
	int tag;
	mysql_init(&myCont1);
	if (mysql_real_connect(&myCont1, host1, username1, pswd1, database1, port1, NULL, 0)){
		mysql_query(&myCont1, "SET NAMES GBK");
		int q;
		q = mysql_query(&myCont1, "select * from domitory");
		if (q != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result1 = mysql_store_result(&myCont1);
			row_num1 = mysql_num_rows(result1);
			if (result1){
				int tag = 0;
				while (row1 = mysql_fetch_row(result1)){
					char * q0 = row1[0];
					char * q1 = row1[1];
					char * q2 = row1[2];
					char * q3 = row1[3];
					//char * q4 = row[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					//int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					LPWSTR Q3 = new WCHAR[q3l];
					//LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					//MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					domitory_list.InsertItem(tag, _T("kill"));
					domitory_list.SetItemText(tag, 0, Q0);
					domitory_list.SetItemText(tag, 1, Q1);
					domitory_list.SetItemText(tag, 2, Q2);
					domitory_list.SetItemText(tag, 3, Q3);
					//domitory_list.SetItemText(tag, 4, Q4);
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					delete[]Q3;
					//delete[]Q4;
				}
			}
		}
	}
	else{
		//cout << "connect failed!" << endl;
	}
	if (result1 != NULL){
		mysql_free_result(result1);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void add_domitory::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int length = md_building_num.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, md_building_num, length, NULL, 0, NULL, NULL);
	char* s_n = new char[nBytes + 1];
	memset(s_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, md_building_num, length, s_n, nBytes, NULL, NULL);
	s_n[nBytes] = 0;

	length = md_room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, md_room_num, length, NULL, 0, NULL, NULL);
	char* nam = new char[nBytes + 1];
	memset(nam, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, md_room_num, length, nam, nBytes, NULL, NULL);
	nam[nBytes] = 0;

	length = phone_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, phone_num, length, NULL, 0, NULL, NULL);
	char* in_t = new char[nBytes + 1];
	memset(in_t, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, phone_num, length, in_t, nBytes, NULL, NULL);
	in_t[nBytes] = 0;

	length = people_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, people_num, length, NULL, 0, NULL, NULL);
	char* b_n = new char[nBytes + 1];
	memset(b_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, people_num, length, b_n, nBytes, NULL, NULL);
	b_n[nBytes] = 0;
	/*
	length = room_num.GetLength();
	nBytes = WideCharToMultiByte(CP_ACP, 0, room_num, length, NULL, 0, NULL, NULL);
	char* r_n = new char[nBytes + 1];
	memset(r_n, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, room_num, length, r_n, nBytes, NULL, NULL);
	r_n[nBytes] = 0;*/
	mysql_init(&myCont1);
	if (mysql_real_connect(&myCont1, host1, username1, pswd1, database1, port1, NULL, 0)){
		mysql_query(&myCont1, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "insert into domitory values('");
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
		strcat(sql, ")");
		strcat(sql, ";");
		

		mysql_query(&myCont1, sql);

		int w = mysql_query(&myCont1, "select * from domitory");
		if (w != 0){
			//cout << "query failed!" << endl;
		}
		else{
			result1 = mysql_store_result(&myCont1);
			if (result1){
				int tag = 0;
				while (row1 = mysql_fetch_row(result1)){
					char * q0 = row1[0];
					char * q1 = row1[1];
					char * q2 = row1[2];
					char * q3 = row1[3];
					//char * q4 = row1[4];
					int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
					int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
					int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
					int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
					//int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
					LPWSTR Q0 = new WCHAR[q0l];
					LPWSTR Q1 = new WCHAR[q1l];
					LPWSTR Q2 = new WCHAR[q2l];
					LPWSTR Q3 = new WCHAR[q3l];
					//LPWSTR Q4 = new WCHAR[q4l];
					MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
					MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
					MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
					MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
					//MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
					//Please.InsertItem(tag, _T("kill"));
					//Please.SetItemText(tag, 0, Q0);
					//if (tag == 2){
					//test = "fads";
					//}
					//ttest = row_num;
					UpdateData(FALSE);
					if (tag < row_num1){
						domitory_list.SetItemText(tag, 0, Q0);
						domitory_list.SetItemText(tag, 1, Q1);
						domitory_list.SetItemText(tag, 2, Q2);
						domitory_list.SetItemText(tag, 3, Q3);
						//domitory_list.SetItemText(tag, 4, Q4);
					}
					else{
						domitory_list.InsertItem(tag, _T("kill"));
						domitory_list.SetItemText(tag, 0, Q0);
						domitory_list.SetItemText(tag, 1, Q1);
						domitory_list.SetItemText(tag, 2, Q2);
						domitory_list.SetItemText(tag, 3, Q3);
						//as_list.SetItemText(tag, 4, Q4);
						++row_num1;
					}
					tag++;
					delete[]Q0;
					delete[]Q1;
					delete[]Q2;
					delete[]Q3;
					//delete[]Q4;
				}
			}
		}
	}
	if (result1 != NULL){
		mysql_free_result(result1);
	}
	md_building_num = "";
	md_room_num = "";
	phone_num = "";
	people_num = "";
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void add_domitory::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int length = ad_d.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, ad_d, length, NULL, 0, NULL, NULL);
	char* s_d = new char[nBytes + 1];
	memset(s_d, 0, length + 1);
	WideCharToMultiByte(CP_OEMCP, 0, ad_d, length, s_d, nBytes, NULL, NULL);
	s_d[nBytes] = 0;

	mysql_init(&myCont1);
	if (mysql_real_connect(&myCont1, host1, username1, pswd1, database1, port1, NULL, 0)){
		mysql_query(&myCont1, "SET NAMES GBK");
		char sql[300] = { 0 };
		char ch[100];
		strcpy(sql, "delete from domitory where phone_num = '");
		sprintf(ch, "%s", s_d);
		strcat(sql, ch);
		strcat(sql, "'");
		strcat(sql, ";");
		mysql_query(&myCont1, sql);
	}

	int w = mysql_query(&myCont1, "select * from domitory");
	if (w != 0){
		//cout << "query failed!" << endl;
	}
	else{
		result1 = mysql_store_result(&myCont1);
		int row_num2 = mysql_num_rows(result1);
		if (result1){
			int tag = 0;
			while (row1 = mysql_fetch_row(result1)){
				char * q0 = row1[0];
				char * q1 = row1[1];
				char * q2 = row1[2];
				char * q3 = row1[3];
				//char * q4 = row[4];
				int q0l = MultiByteToWideChar(CP_ACP, 0, q0, -1, NULL, 0);
				int q1l = MultiByteToWideChar(CP_ACP, 0, q1, -1, NULL, 0);
				int q2l = MultiByteToWideChar(CP_ACP, 0, q2, -1, NULL, 0);
				int q3l = MultiByteToWideChar(CP_ACP, 0, q3, -1, NULL, 0);
				//int q4l = MultiByteToWideChar(CP_ACP, 0, q4, -1, NULL, 0);
				LPWSTR Q0 = new WCHAR[q0l];
				LPWSTR Q1 = new WCHAR[q1l];
				LPWSTR Q2 = new WCHAR[q2l];
				LPWSTR Q3 = new WCHAR[q3l];
				//LPWSTR Q4 = new WCHAR[q4l];
				MultiByteToWideChar(CP_ACP, 0, q0, -1, Q0, q0l);
				MultiByteToWideChar(CP_ACP, 0, q1, -1, Q1, q1l);
				MultiByteToWideChar(CP_ACP, 0, q2, -1, Q2, q2l);
				MultiByteToWideChar(CP_ACP, 0, q3, -1, Q3, q3l);
				//MultiByteToWideChar(CP_ACP, 0, q4, -1, Q4, q4l);
				//if (tag < row_num2){
				domitory_list.SetItemText(tag, 0, Q0);
				domitory_list.SetItemText(tag, 1, Q1);
				domitory_list.SetItemText(tag, 2, Q2);
				domitory_list.SetItemText(tag, 3, Q3);
				//as_list.SetItemText(tag, 4, Q4);
				//}
				tag++;
				delete[]Q0;
				delete[]Q1;
				delete[]Q2;
				delete[]Q3;
				//delete[]Q4;
			}
		}
		for (int k = row_num2; k < row_num1; k++){
			domitory_list.SetItemText(k, 0, L'');
			domitory_list.SetItemText(k, 1, L'');
			domitory_list.SetItemText(k, 2, L'');
			domitory_list.SetItemText(k, 3, L'');
			//as_list.SetItemText(k, 4, L'');
		}

	}
	if (result1 != NULL){
		mysql_free_result(result1);
	}

	ad_d = "";
	UpdateData(FALSE);
}
