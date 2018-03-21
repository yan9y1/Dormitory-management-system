#pragma once
#include "afxcmn.h"
#include"add_students.h"
#include"add_domitory.h"
#include"add_propety.h"
#include"visit_late.h"
#include"visit_leave.h"
#include"visit_brepair.h"
#include"visit_drepair.h"

// managers_in dialog

class managers_in : public CDialogEx
{
	DECLARE_DYNAMIC(managers_in)

public:
	managers_in(CWnd* pParent = NULL);   // standard constructor
	virtual ~managers_in();
	add_students as_page;
	add_propety ap_page;
	add_domitory ad_page;
	visit_late vl_page;
	visit_leave vle_page;
	visit_drepair vd_page;
	visit_brepair vb_page;

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl managers_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeManagers(NMHDR *pNMHDR, LRESULT *pResult);
};
