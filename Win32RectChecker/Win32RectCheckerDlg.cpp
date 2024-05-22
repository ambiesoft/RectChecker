
// Win32RectCheckerDlg.cpp : implementation file
//

#include "pch.h"

#include "framework.h"
#include "Win32RectChecker.h"
#include "Win32RectCheckerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace Ambiesoft;
using namespace Ambiesoft::stdosd;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWin32RectCheckerDlg dialog



CWin32RectCheckerDlg::CWin32RectCheckerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WIN32RECTCHECKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWin32RectCheckerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MAIN, m_editMain);
}

BEGIN_MESSAGE_MAP(CWin32RectCheckerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CWin32RectCheckerDlg message handlers

BOOL CWin32RectCheckerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	DVERIFY(ID_TIMER_MAIN == SetTimer(ID_TIMER_MAIN, 1000, nullptr));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWin32RectCheckerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWin32RectCheckerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWin32RectCheckerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWin32RectCheckerDlg::UpdateEdit(CString strEdit)
{
	strEdit.Replace(L"\r\n", L"\n");
	strEdit.Replace(L"\r", L"\n");
	strEdit.Replace(L"\n", L"\r\n");

	static CString lastUpdate;
	if (strEdit == lastUpdate)
		return;
	lastUpdate = strEdit;

	m_editMain.SetWindowText(strEdit);
}
void CWin32RectCheckerDlg::OnTimer(UINT_PTR nIDEvent)
{
	RECT rect;
	DVERIFY(::GetWindowRect(m_hWnd, &rect));

	WINDOWPLACEMENT wp = { 0 };
	wp.length = sizeof(wp);
	DVERIFY(::GetWindowPlacement(m_hWnd, &wp));

	constexpr wchar_t* format = STDOSD_WCHARLITERAL(
R"(GetWindowRect:
left=%d
top=%d
right=%d
bottomt=%d
Width(calculated)=%d
Height(calculated)=%d

GetWindowPlacement:
wp.flags=%s
wp.showCmd=%d
wp.ptMinPosition.x=%d
wp.ptMinPosition.y=%d
wp.ptMaxPosition.x=%d
wp.ptMaxPosition.y=%d
wp.rcNormalPosition.left=%d
wp.rcNormalPosition.top=%d
wp.rcNormalPosition.right=%d
wp.rcNormalPosition.bottom=%d

)");

	vector<wstring> wpFlagsString;
	if (wp.flags & WPF_ASYNCWINDOWPLACEMENT)
		wpFlagsString.push_back(L"WPF_ASYNCWINDOWPLACEMENT");
	if (wp.flags & WPF_RESTORETOMAXIMIZED)
		wpFlagsString.push_back(L"WPF_RESTORETOMAXIMIZED");
	if (wp.flags & WPF_SETMINPOSITION)
		wpFlagsString.push_back(L"WPF_SETMINPOSITION");
	if (wp.flags == 0)
		wpFlagsString.push_back(L"0");

	CString strEditMain;
	strEditMain.Format(format,
		rect.left,
		rect.top,
		rect.right,
		rect.bottom,
		rect.right - rect.left,
		rect.bottom - rect.top,
		
		stdJoinStrings(wpFlagsString, L" ", L"",L"").c_str(),
		wp.showCmd,
		wp.ptMinPosition.x,
		wp.ptMinPosition.y,
		wp.ptMaxPosition.x,
		wp.ptMaxPosition.y,
		wp.rcNormalPosition.left,
		wp.rcNormalPosition.top,
		wp.rcNormalPosition.right,
		wp.rcNormalPosition.bottom
	);

	UpdateEdit(strEditMain);

	CDialogEx::OnTimer(nIDEvent);
}
