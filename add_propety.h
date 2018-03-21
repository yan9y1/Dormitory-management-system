#pragma once
#include "afxcmn.h"


// add_propety dialog

class add_propety : public CDialogEx
{
	DECLARE_DYNAMIC(add_propety)

public:
	add_propety(CWnd* pParent = NULL);   // standard constructor
	virtual ~add_propety();

// Dialog Data
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString ap_building_num;
	CString ap_room_num;
	CString propety_num;
	CListCtrl propety_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
