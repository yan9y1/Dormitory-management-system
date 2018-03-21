#pragma once
#include "afxwin.h"


// come_late dialog

class come_late : public CDialogEx
{
	DECLARE_DYNAMIC(come_late)

public:
	come_late(CWnd* pParent = NULL);   // standard constructor
	virtual ~come_late();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CEdit lr_student_num;
	CString lr_student_name;
	CString lr_building_num;
	CString lr_room_num;
	CString lr_time;
	CString lr_reason;
	afx_msg void OnBnClickedButton1();
	CString lre_student_num;
};
