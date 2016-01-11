
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once

#include "CoffeeBook.h"
#include "Robot.h"
#include "afxwin.h"

// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��


// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	afx_msg void OnCbnSelchangeName();
	CComboBox m_Combo_Picture;
	CStatic m_Picture1;
	CStatic m_Picture2;
	CStatic m_Picture3;
	CStatic m_picture4;
	CStatic m_Picture5;
	CStatic m_Picture6;
	CStatic m_Picture7;
	CStatic m_Picture8;
	//afx_msg void OnStnClickedPicture8();
	afx_msg void OnBnClickedExit();
};
