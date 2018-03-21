#pragma once
#include "afxcmn.h"


// visit_late dialog

class visit_late : public CDialogEx
{
	DECLARE_DYNAMIC(visit_late)

public:
	visit_late(CWnd* pParent = NULL);   // standard constructor
	virtual ~visit_late();

// Dialog Data
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl late_list;
	virtual BOOL OnInitDialog();
	CString cl_d;
	afx_msg void OnBnClickedButton1();
};
