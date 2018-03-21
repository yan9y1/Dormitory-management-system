#pragma once
#include "afxcmn.h"
#include"come_late.h"
#include"leave_school.h"
#include"come_school.h"
#include"repair_room.h"
#include"repaire_building.h"
// students_in dialog

class students_in : public CDialogEx
{
	DECLARE_DYNAMIC(students_in)

public:
	students_in(CWnd* pParent = NULL);   // standard constructor
	virtual ~students_in();
	come_late cl_page;
	leave_school ls_page;
	come_school cs_page;
	repair_room rr_page;
	repaire_building rb_page;

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl students_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeStudents(NMHDR *pNMHDR, LRESULT *pResult);
};
