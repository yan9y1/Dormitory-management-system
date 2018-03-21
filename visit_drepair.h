#pragma once
#include "afxcmn.h"


// visit_drepair dialog

class visit_drepair : public CDialogEx
{
	DECLARE_DYNAMIC(visit_drepair)

public:
	visit_drepair(CWnd* pParent = NULL);   // standard constructor
	virtual ~visit_drepair();

// Dialog Data
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl rr_list;
	virtual BOOL OnInitDialog();
};
