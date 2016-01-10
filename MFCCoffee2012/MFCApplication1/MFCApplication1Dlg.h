
// MFCApplication1Dlg.h : 头文件
//

#pragma once

#include "CoffeeBook.h"
#include "Robot.h"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	double m_fpay;
	double m_get;
	int m_num;
	double m_spay;
	BOOL m_suger;
	int m_type;
	CoffeeBook m_cbook;
	CString m_name;
	Robot m_robot;
	afx_msg void OnBnClickedPay();
public:
	
	afx_msg void OnBnClickedCpay();

//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_show;
};
