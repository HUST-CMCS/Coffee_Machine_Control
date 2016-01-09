
// MFC-5Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC5Dlg 对话框
class CMFC5Dlg : public CDialogEx
{
// 构造
public:
	CMFC5Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC5_DIALOG };

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
public:
	afx_msg void OnCbnSelchangePicCombo();
	afx_msg void OnStnClickedPic1Static();
	afx_msg void OnStnClickedPic2Static();
	afx_msg void OnStnClickedPic3Static();
	afx_msg void OnStnClickedPic4Static();
	CStatic m_Cup_Picture1;
	CStatic m_Cup_Picture2;
	CComboBox m_Combo_Picture;
	CStatic m_Cup_Picture3;
	CStatic m_Cup_Picture4;
};
