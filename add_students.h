#pragma once
#include "afxcmn.h"


// add_students dialog

class add_students : public CDialogEx
{
	DECLARE_DYNAMIC(add_students)

public:
	add_students(CWnd* pParent = NULL);   // standard constructor
	virtual ~add_students();

// Dialog Data
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
	CListCtrl as_list;
	CString student_num;
	CString name;
	CString in_time;
//	CString room_num;
	CString building_num;
	CString room_num;
	afx_msg void OnBnClickedButton1();
	CString as_d;
	afx_msg void OnBnClickedButton2();
};
