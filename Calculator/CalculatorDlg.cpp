
// CalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include "ExpParser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, editv(_T(""))
	, resultv(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editc);
	DDX_Text(pDX, IDC_EDIT1, editv);
	DDX_Control(pDX, IDC_EDIT2, resultc);
	DDX_Text(pDX, IDC_EDIT2, resultv);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Font.CreatePointFont(180, _T("仿宋"), NULL);
	editc.SetFont(&m_Font, true);
	resultc.SetFont(&m_Font, true);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 按钮1
void CCalculatorDlg::OnBnClickedButton1()
{
	editv += "1";
	UpdateData(false);
}

// 按钮2
void CCalculatorDlg::OnBnClickedButton2()
{
	editv += "2";
	UpdateData(false);
}

// 按钮3
void CCalculatorDlg::OnBnClickedButton3()
{
	editv += "3";
	UpdateData(false);
}

// 按钮4
void CCalculatorDlg::OnBnClickedButton4()
{
	editv += "4";
	UpdateData(false);
}

// 按钮5
void CCalculatorDlg::OnBnClickedButton5()
{
	editv += "5";
	UpdateData(false);
}

// 按钮6
void CCalculatorDlg::OnBnClickedButton6()
{
	editv += "6";
	UpdateData(false);
}

// 按钮7
void CCalculatorDlg::OnBnClickedButton7()
{
	editv += "7";
	UpdateData(false);
}

// 按钮8
void CCalculatorDlg::OnBnClickedButton8()
{
	editv += "8";
	UpdateData(false);
}

// 按钮9
void CCalculatorDlg::OnBnClickedButton9()
{
	editv += "9";
	UpdateData(false);
}

// 按钮0
void CCalculatorDlg::OnBnClickedButton10()
{
	editv += "0";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton21()
{
	editv += ".";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton15()
{
	editv += "*";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton16()
{
	editv += "/";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton17()
{
	editv += "+";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton18()
{
	editv += "-";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton11()
{
	editv += "(";
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton12()
{
	editv += ")";
	UpdateData(false);
}

// delete
void CCalculatorDlg::OnBnClickedButton13()
{
	editv = editv.Left(editv.GetLength() - 1);
	UpdateData(false);
}

// AC
void CCalculatorDlg::OnBnClickedButton14()
{
	editv = "";
	resultv = "";
	UpdateData(false);
}

// =
void CCalculatorDlg::OnBnClickedButton19()
{
	resultv = editv;
	std::string str = CT2A(editv.GetString());
	char* infix = (char*)str.data();
	Stack num;                    // 计算结果栈
	Stack postfix;                // 逆波兰表达式栈
	int len = GetFix(infix);
	if (!CheckFix(infix, len))
	{
		resultv = "INPUT ERROR";
	}
	else
	{
		InitStack(&num);
		InitStack(&postfix);
		ToPostfix(infix, len, &postfix);
		std::stringstream ss;
		double ans = ToNum(&postfix, &num);
		ss << ans;
		std::string ret = ss.str();
		resultv = CA2T(ret.c_str());
	}
	UpdateData(false);
}

// ^
void CCalculatorDlg::OnBnClickedButton20()
{
	editv += "^";
	UpdateData(false);
}
