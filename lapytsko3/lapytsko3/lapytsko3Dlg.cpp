
// lapytsko3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "lapytsko3.h"
#include "lapytsko3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clapytsko3Dlg dialog



Clapytsko3Dlg::Clapytsko3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clapytsko3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clapytsko3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_random);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST2, m_max);
	DDX_Control(pDX, IDC_LIST3, m_min);
}

BEGIN_MESSAGE_MAP(Clapytsko3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Clapytsko3Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Clapytsko3Dlg message handlers

BOOL Clapytsko3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clapytsko3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clapytsko3Dlg::OnPaint()
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
HCURSOR Clapytsko3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clapytsko3Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int i, j;
	UINT Number;
	CUIntArray array;
	char str[20];
	srand((unsigned)time(NULL));
	array.SetSize(100, 20);
	array.Add(rand());
	for (i = 1; i < 100; i++)
	{
		Number = rand()%100+1;
		for (j = 0; j<array.GetSize(); j++){
			if (Number>array.GetAt(j)) {
				// Вставить перед элементом, который меньше			
				array.InsertAt(j, Number);
				break;
			}
		}
		// Добавить в конец, если не вставили
		if (j == array.GetSize()) array.Add(Number);
	}
	// Вывести массив в m_listbox
	m_list.ResetContent();
	for (j = 0; j < 99; j++){
		wsprintf(str, "%d", array.GetAt(j));
		if (m_list.AddString(str) == LB_ERR){
			AfxMessageBox("Ошибка при добавлении в список");
		}
	}

	m_list.SetSel(0, array.GetAt(0));
	m_list.SetSel(1, array.GetAt(1));
	m_list.SetSel(2, array.GetAt(2));

	m_list.SetSel(98, array.GetAt(98));
	m_list.SetSel(97, array.GetAt(97));
	m_list.SetSel(96, array.GetAt(96));
	UpdateData(false);

	m_max.ResetContent();
	wsprintf(str, "%d", array.GetAt(0) + array.GetAt(1) + array.GetAt(2));
	m_max.AddString(str);
	UpdateData(false);

	m_min.ResetContent();
	wsprintf(str, "%d", array.GetAt(98) + array.GetAt(97) + array.GetAt(96));
	m_min.AddString(str);
	UpdateData(false);
}
