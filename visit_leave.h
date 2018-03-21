#pragma once
#include "afxcmn.h"


// visit_leave dialog

class visit_leave : public CDialogEx
{
	DECLARE_DYNAMIC(visit_leave)

public:
	visit_leave(CWnd* pParent = NULL);   // standard constructor
	virtual ~visit_leave();

// Dialog Data
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl leave_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString le_d;
};
