
// D_M_SDlg.h : header file
//

#pragma once
#include"managers_in.h"
#include"students_in.h"

// CD_M_SDlg dialog
class CD_M_SDlg : public CDialogEx
{
// Construction
public:
	CD_M_SDlg(CWnd* pParent = NULL);	// standard constructor
	managers_in* managers_p;
	students_in* students_p;
// Dialog Data
	enum { IDD = IDD_D_M_S_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
