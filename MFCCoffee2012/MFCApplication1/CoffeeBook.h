#pragma once


// CoffeeBook �Ի���

class CoffeeBook : public CDialogEx
{
	DECLARE_DYNAMIC(CoffeeBook)

public:
	CoffeeBook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CoffeeBook();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	CString m_str;
	virtual BOOL OnInitDialog();
};
