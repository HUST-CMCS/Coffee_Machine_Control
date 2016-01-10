#pragma once


// CoffeeBook 对话框

class CoffeeBook : public CDialogEx
{
	DECLARE_DYNAMIC(CoffeeBook)

public:
	CoffeeBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CoffeeBook();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	CString m_str;
	virtual BOOL OnInitDialog();
};
