
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_fpay(0)
	, m_get(0)
	, m_num(1)
	, m_type(0)
	, m_suger(FALSE)
	, m_spay(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FPAY, m_fpay);
	DDX_Text(pDX, IDC_GET, m_get);
	DDX_Text(pDX, IDC_NUM, m_num);
	//  DDX_Text(pDX, IDC_SPAY, m_spy);
	//  DDX_Radio(pDX, IDC_SUGER, m_suger);
	DDX_Radio(pDX, IDC_TYPE, m_type);
	DDX_Radio(pDX, IDC_SUGER, m_suger);
	DDX_Text(pDX, IDC_SPAY, m_spay);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PAY, &CMFCApplication1Dlg::OnBnClickedPay)
	ON_BN_CLICKED(IDC_CPay, &CMFCApplication1Dlg::OnBnClickedCpay)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//��ʼ����������
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("����Ħ��");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("����");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("������ŵ");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ʽ����");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ʽŨ��");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ĭ");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("�̿�");
	((CComboBox*)GetDlgItem(IDC_NAME))->SetCurSel(0);              //����Ĭ��ֵ

	//��ʼ������
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->AddString("���ļ���");
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->AddString("English");
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->SetCurSel(0);          //����Ĭ��ֵ


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedPay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡ��������
	int index;
	index=((CComboBox*)GetDlgItem(IDC_NAME))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_NAME))->GetLBText(index,m_name);

	//��ʾ�˵��ĸ�ʽ��
	m_cbook.m_str.Format("�������ࣺ%s\n",m_name);
	m_cbook.DoModal();

}


void CMFCApplication1Dlg::OnBnClickedCpay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�������ȷ��
		//�������ɹ�����ʼ��������
	if(m_fpay>=m_spay){


	}

		//���δ�����ʾ���븶�
	else if(m_fpay==0) MessageBox("�븶��");

	    //������㣬��ʾ�����㡱
	else if(m_fpay<=m_spay) MessageBox("����");
}
