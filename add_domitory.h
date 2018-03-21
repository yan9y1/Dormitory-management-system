#pragma once
#include "afxcmn.h"


// add_domitory dialog

class add_domitory : public CDialogEx
{
	DECLARE_DYNAMIC(add_domitory)

public:
	add_domitory(CWnd* pParent = NULL);   // standard constructor
	virtual ~add_domitory();

// Dialog Data
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString md_building_num;
	CString md_room_num;
	CString phone_num;
	CString people_num;
	CListCtrl domitory_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString ad_d;
	afx_msg void OnBnClickedButton2();
};
