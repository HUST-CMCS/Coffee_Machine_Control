// CoffeeBook.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CoffeeBook.h"
#include "afxdialogex.h"


// CoffeeBook 对话框

IMPLEMENT_DYNAMIC(CoffeeBook, CDialogEx)

CoffeeBook::CoffeeBook(CWnd* pParent /*=NULL*/)
	: CDialogEx(CoffeeBook::IDD, pParent)
	, m_str(_T(""))
{

}

CoffeeBook::~CoffeeBook()
{
}

void CoffeeBook::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BOOK, m_str);
}


BEGIN_MESSAGE_MAP(CoffeeBook, CDialogEx)
END_MESSAGE_MAP()


// CoffeeBook 消息处理程序





BOOL CoffeeBook::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//设置账单输出文本


	return TRUE;  // return TRUE unless you set the focus to a control

}
