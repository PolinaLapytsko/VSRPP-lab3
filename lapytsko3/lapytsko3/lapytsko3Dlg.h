
// lapytsko3Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Clapytsko3Dlg dialog
class Clapytsko3Dlg : public CDialogEx
{
// Construction
public:
	Clapytsko3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LAPYTSKO3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_random;
	CListBox m_list;
	CListBox m_max;
	CListBox m_min;
	afx_msg void OnBnClickedButton1();
};
