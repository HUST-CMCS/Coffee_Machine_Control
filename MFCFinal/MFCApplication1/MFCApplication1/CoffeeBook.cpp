// CoffeeBook.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CoffeeBook.h"
#include "afxdialogex.h"


// CoffeeBook �Ի���

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


// CoffeeBook ��Ϣ�������





BOOL CoffeeBook::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//�����˵�����ı�


	return TRUE;  // return TRUE unless you set the focus to a control

}
