
// Win32RectCheckerDlg.h : header file
//

#pragma once


// CWin32RectCheckerDlg dialog
class CWin32RectCheckerDlg : public CDialogEx
{
	enum {
		ID_TIMER_MAIN = 1,
	};
// Construction
public:
	CWin32RectCheckerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIN32RECTCHECKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	void UpdateEdit(CString strEdit);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_editMain;
};
