
// MFC-5Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC5Dlg �Ի���
class CMFC5Dlg : public CDialogEx
{
// ����
public:
	CMFC5Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC5_DIALOG };

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
