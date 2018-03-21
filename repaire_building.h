#pragma once


// repaire_building dialog

class repaire_building : public CDialogEx
{
	DECLARE_DYNAMIC(repaire_building)

public:
	repaire_building(CWnd* pParent = NULL);   // standard constructor
	virtual ~repaire_building();

// Dialog Data
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString rb_student_num;
	CString rb_student_name;
	CString rb_building_num;
	CString rb_floor_num;
	CString rb_situation;
	afx_msg void OnEnChangeEdit4();
};
