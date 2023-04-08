
// MFCwithCSharpDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCwithCSharp.h"
#include "MFCwithCSharpDlg.h"
#include "afxdialogex.h"

#using "CSharpClass.dll"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCwithCSharpDlg dialog



CMFCwithCSharpDlg::CMFCwithCSharpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCWITHCSHARP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCwithCSharpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCwithCSharpDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCwithCSharpDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_ADD_LIST, &CMFCwithCSharpDlg::OnBnClickedBtnAddList)
END_MESSAGE_MAP()


// CMFCwithCSharpDlg message handlers

BOOL CMFCwithCSharpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCwithCSharpDlg::OnPaint()
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
HCURSOR CMFCwithCSharpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCwithCSharpDlg::OnBnClickedBtnAdd()
{
	CSharp::CSharpMath^ mathClass = gcnew CSharp::CSharpMath();
	int result = mathClass->Add(2, 6);

	char buf[200];
	sprintf_s(buf, "Add result: %d", result);
	MessageBoxA(GetSafeHwnd(), buf, "Add", MB_OK);
}


void CMFCwithCSharpDlg::OnBnClickedBtnAddList()
{
	CSharp::CSharpMath^ mathClass = gcnew CSharp::CSharpMath();

	System::Collections::Generic::List<int>^ myList = gcnew System::Collections::Generic::List<int>();

	myList->Add(1);
	myList->Add(2);
	myList->Add(3);

	int result = mathClass->AddList(myList);

	char buf[200];
	sprintf_s(buf, "Add List result: %d", result);
	MessageBoxA(GetSafeHwnd(), buf, "Add List", MB_OK);
}
