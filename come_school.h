#pragma once


// come_school dialog

class come_school : public CDialogEx
{
	DECLARE_DYNAMIC(come_school)

public:
	come_school(CWnd* pParent = NULL);   // standard constructor
	virtual ~come_school();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString c_student_num;
	CString c_student_name;
	afx_msg void OnBnClickedButton1();
};
