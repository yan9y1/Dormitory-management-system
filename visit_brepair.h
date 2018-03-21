#pragma once
#include "afxcmn.h"


// visit_brepair dialog

class visit_brepair : public CDialogEx
{
	DECLARE_DYNAMIC(visit_brepair)

public:
	visit_brepair(CWnd* pParent = NULL);   // standard constructor
	virtual ~visit_brepair();

// Dialog Data
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl br_list;
	virtual BOOL OnInitDialog();
};
