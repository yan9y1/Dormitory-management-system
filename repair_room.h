#pragma once


// repair_room dialog

class repair_room : public CDialogEx
{
	DECLARE_DYNAMIC(repair_room)

public:
	repair_room(CWnd* pParent = NULL);   // standard constructor
	virtual ~repair_room();

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString rr_student_num;
	CString rr_student_name;
	CString rr_building_num;
	CString rr_room_num;
	CString rr_rn;
	afx_msg void OnBnClickedButton1();
};
