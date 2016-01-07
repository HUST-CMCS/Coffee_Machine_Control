
// MultiLanguagesDlg.h : ͷ�ļ�
//

#pragma once


// CMultiLanguagesDlg �Ի���
class CMultiLanguagesDlg : public CDialogEx
{
// ����
public:
	CMultiLanguagesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MULTILANGUAGES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	BOOL m_bRestartFlag;  // �����Ի���ı�ʶ

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLanguageSwitch();
	afx_msg void OnClose();
};
