#pragma once


// leave_school dialog

class leave_school : public CDialogEx
{
	DECLARE_DYNAMIC(leave_school)

public:
	leave_school(CWnd* pParent = NULL);   // standard constructor
	virtual ~leave_school();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString ls_student_num;
	CString ls_student_name;
	CString ls_lt;
	CString ls_ct;
	afx_msg void OnBnClickedButton1();
};
