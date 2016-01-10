
// MFC-5Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC-5.h"
#include "MFC-5Dlg.h"
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


// CMFC5Dlg �Ի���



CMFC5Dlg::CMFC5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC5Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1_STATIC, m_Cup_Picture1);
	DDX_Control(pDX, IDC_PIC2_STATIC, m_Cup_Picture2);
	DDX_Control(pDX, IDC_PIC_COMBO, m_Combo_Picture);
	DDX_Control(pDX, IDC_PIC3_STATIC, m_Cup_Picture3);
	DDX_Control(pDX, IDC_PIC4_STATIC, m_Cup_Picture4);
}

BEGIN_MESSAGE_MAP(CMFC5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_PIC_COMBO, &CMFC5Dlg::OnCbnSelchangePicCombo)
	ON_STN_CLICKED(IDC_PIC1_STATIC, &CMFC5Dlg::OnStnClickedPic1Static)
	ON_STN_CLICKED(IDC_PIC2_STATIC, &CMFC5Dlg::OnStnClickedPic2Static)
	ON_STN_CLICKED(IDC_PIC3_STATIC, &CMFC5Dlg::OnStnClickedPic3Static)
	ON_STN_CLICKED(IDC_PIC4_STATIC, &CMFC5Dlg::OnStnClickedPic4Static)
END_MESSAGE_MAP()


// CMFC5Dlg ��Ϣ�������

BOOL CMFC5Dlg::OnInitDialog()
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
	 // Ϊ��Ͽ�ؼ����б������б�������ס�   
    m_Combo_Picture.AddString(_T("������ŵ"));   
    // Ϊ��Ͽ�ؼ����б������б���ٶȡ�   
    m_Combo_Picture.AddString(_T("��ʽ����"));   
	m_Combo_Picture.AddString(_T("����"));  
    // ����Ͽ�ؼ����б��������Ϊ1��λ�ò����б�����ˡ�   
    m_Combo_Picture.AddString(_T("����Ħ��"));  
	// Ĭ��ѡ���һ��   
    m_Combo_Picture.SetCurSel(0);  

	CBitmap bitmap1,bitmap2,bitmap3,bitmap4;  // CBitmap�������ڼ���λͼ   ���
    HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��   ���
    bitmap1.LoadBitmap(IDB_BITMAP1);  // ��λͼIDB_BITMAP1���ص�bitmap1
	hBmp = (HBITMAP)bitmap1.GetSafeHandle(); 
	m_Cup_Picture1.SetBitmap(hBmp);  //��ʾλͼ1
    // �༭����Ĭ����ʾ��һ������֡������ס�   
    //SetDlgItemText(IDC_PIC_COMBO, _T("������ŵ"));   

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC5Dlg::OnPaint()
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
HCURSOR CMFC5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC5Dlg::OnCbnSelchangePicCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������   
    int nSel; 
	CBitmap bitmap1,bitmap2,bitmap3,bitmap4;  // CBitmap�������ڼ���λͼ   
    HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��

	bitmap1.LoadBitmap(IDB_BITMAP1);  // ��λͼIDB_BITMAP1���ص�bitmap1
	bitmap2.LoadBitmap(IDB_BITMAP2);  // ��λͼIDB_BITMAP1���ص�bitmap2
	bitmap3.LoadBitmap(IDB_BITMAP3);  // ��λͼIDB_BITMAP1���ص�bitmap3
	bitmap4.LoadBitmap(IDB_BITMAP4);  // ��λͼIDB_BITMAP1���ص�bitmap4
	

  
    // ��ȡ��Ͽ�ؼ����б����ѡ��������� 
    nSel = m_Combo_Picture.GetCurSel(); 
	switch(nSel){
		case 0:hBmp = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Cup_Picture1.SetBitmap(hBmp); break;  // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
		case 1:hBmp = (HBITMAP)bitmap2.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		case 2:hBmp = (HBITMAP)bitmap3.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		case 3:hBmp = (HBITMAP)bitmap4.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		default:break;
		
	}
    // ����ѡ����������ȡ�����ַ���   
   //* m_Combo_Picture.GetLBText(nSel, strWeb);   
    // ����Ͽ���ѡ�е��ַ�����ʾ��IDC_SEL_WEB_EDIT�༭����   
  //*  SetDlgItemText(IDC_PIC_COMBO, strWeb); 
}


void CMFC5Dlg::OnStnClickedPic1Static()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC5Dlg::OnStnClickedPic2Static()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC5Dlg::OnStnClickedPic3Static()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC5Dlg::OnStnClickedPic4Static()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
