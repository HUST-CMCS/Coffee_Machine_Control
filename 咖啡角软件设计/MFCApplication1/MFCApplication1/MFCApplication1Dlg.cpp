
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
	, m_show(_T(""))
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
	DDX_Text(pDX, IDC_SHOW, m_show);
	DDX_Control(pDX, IDC_NAME, m_Combo_Picture);
	DDX_Control(pDX, IDC_Picture1, m_Picture1);
	DDX_Control(pDX, IDC_Picture2, m_Picture2);
	DDX_Control(pDX, IDC_Picture3, m_Picture3);
	DDX_Control(pDX, IDC_Picture4, m_picture4);
	DDX_Control(pDX, IDC_Picture5, m_Picture5);
	DDX_Control(pDX, IDC_Picture6, m_Picture6);
	DDX_Control(pDX, IDC_Picture7, m_Picture7);
	DDX_Control(pDX, IDC_Picture8, m_Picture8);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PAY, &CMFCApplication1Dlg::OnBnClickedPay)
	ON_BN_CLICKED(IDC_CPay, &CMFCApplication1Dlg::OnBnClickedCpay)
//	ON_WM_TIMER()
ON_CBN_SELCHANGE(IDC_NAME, &CMFCApplication1Dlg::OnCbnSelchangeName)
//ON_STN_CLICKED(IDC_Picture8, &CMFCApplication1Dlg::OnStnClickedPicture8)
ON_BN_CLICKED(IDC_EXIT, &CMFCApplication1Dlg::OnBnClickedExit)
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
	/*((CComboBox*)GetDlgItem(IDC_NAME))->AddString("����Ħ��");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("����");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("������ŵ");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ʽ����");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ʽŨ��");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("��ĭ");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("�̿�");
	((CComboBox*)GetDlgItem(IDC_NAME))->SetCurSel(0);   */           //����Ĭ��ֵ

	 
    m_Combo_Picture.AddString(_T("����Ħ��")); // Ϊ��Ͽ�ؼ����б������б������Ħ����    
    m_Combo_Picture.AddString(_T("����"));   
	m_Combo_Picture.AddString(_T("������ŵ"));     
    m_Combo_Picture.AddString(_T("��ʽ����")); 
	m_Combo_Picture.AddString(_T("��ʽŨ��")); 
	m_Combo_Picture.AddString(_T("�̿�")); 
	m_Combo_Picture.AddString(_T("��ĭ")); 
	m_Combo_Picture.SetCurSel(0);

	m_show="��ӭʹ�ã���ѡ�񿧷�����";//��ʼ��ͼƬ�·�����
	UpdateData(FALSE);

	
   

	
	CBitmap bitmap;  // CBitmap�������ڼ���λͼ   ���
    HBITMAP hBmp1;    // ����CBitmap���ص�λͼ�ľ��   ���
    bitmap.LoadBitmap(IDB_BITMAP2);  // ��λͼIDB_BITMAP1���ص�bitmap1
    hBmp1 = (HBITMAP)bitmap.GetSafeHandle(); 
    m_Picture1.SetBitmap(hBmp1);  //��ʾλͼ1     
	
	
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
	UpdateData();                                  //��ȡ�û�����
	int index;
	CString suger,name,type;
	index=((CComboBox*)GetDlgItem(IDC_NAME))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_NAME))->GetLBText(index,name);
	double price=0;
	switch(index){                                 //���ݿ��������жϼ۸�
	case 0:case 3: price=7.5;break;
	case 1:case 2: price=10;break;
	case 4:case 5: price=12;break;
	case 6: price=15;break;
	}
	switch(m_type){                                 //���ݿ��������жϼ۸�
	case 0: price+=0;type="С��";break;
	case 1: price+=3;type="�б�";break;
	case 2: price+=5;type="��";break;
	}
	if(m_suger){               //���ǼӼ�
		price+=1.5;
		suger="��"; 
	}
	else suger="��";

	m_spay=price*m_num;                            //����۸�                        
	UpdateData(false);                             //���۸���ʾ

	//��ʾ�˵��ĸ�ʽ��
	m_cbook.m_str.Format("�������ࣺ%s\n\n�Ƿ���ǣ�%s\n\n���Ӵ�С��%s\n\n������%d\n\nӦ����%0.2f",name,suger,type,m_num,m_spay);
	m_cbook.DoModal();

}


void CMFCApplication1Dlg::OnBnClickedCpay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�������ȷ��
	UpdateData();                                  //��ȡ�û�����
	int index;
	double price=0;
	index=((CComboBox*)GetDlgItem(IDC_NAME))->GetCurSel();
	switch(index){                                 //���ݿ��������жϼ۸�
	case 0:case 3: price=7.5;break;
	case 1:case 2: price=10;break;
	case 4:case 5: price=12;break;
	case 6: price=15;break;
	}
	switch(m_type){                                 //���ݿ��������жϼ۸�
	case 0: price+=0;break;
	case 1: price+=3;break;
	case 2: price+=5;break;
	}
	if(m_suger) price+=1.5;                        //���ǼӼ�                             
	m_spay=price*m_num;                            //����۸�
	m_fpay=50;                                     //����û�и�����򣬴˴�����һ��ʵ����ֵ                         
	UpdateData(false);                             //���۸���ʾ
	m_get=m_fpay-m_spay; 

		//���δ�����ʾ���븶�
	if(m_fpay==0) MessageBox("�븶��");
		//�������ɹ�����ʼ��������
	else if(m_get>=0){
		UpdateData(false);                             //��ʾ����
		
//		CString str;
//		((CComboBox*)GetDlgItem(IDC_NAME))->GetLBText(index,str);
		Coffee coffee(CoffeeKind(index),BottleSize(m_type),m_suger);
		double Ang[2]={0.0,0.0};
		m_robot.Process(coffee);                        //����Robot�������Process()����
		int n=0;                                        //���ö����n�洢��������
		n=m_robot.Getnum(); 
//		str.Format("Number:%d",n);
//		MessageBox(str); 

	CBitmap bitmap8,bitmap9,bitmap10,bitmap11;  // CBitmap�������ڼ���λͼ   
        HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��

	    bitmap8.LoadBitmap(IDB_BITMAP8);  // ��λͼIDB_BITMAP1���ص�bitmap8
	    bitmap9.LoadBitmap(IDB_BITMAP9);  // ��λͼIDB_BITMAP1���ص�bitmap9
	    bitmap10.LoadBitmap(IDB_BITMAP10);  // ��λͼIDB_BITMAP1���ص�bitmap10  
		bitmap11.LoadBitmap(IDB_BITMAP11);  // ��λͼIDB_BITMAP1���ص�bitmap10  
		
	
	  

		
		for(int j=1;j<=m_num;j++){                     //���ñ���ȷ��ѭ������
		//����forѭ������Robotʵ�ֿ����˶�
		for(int i=0;i<=n;i++){
			m_robot.GetAngle(i,Ang);

			//�˴�Ӧ�ø�������������ĽǶȵ��ÿ�����

			//��ʱ�����ڸ�������
				//ͼƬ��������ʾ���л�
			if(i==0){
		/*************************************************************************/
				//��������Ӽ�ˮͼƬָ��
               hBmp = (HBITMAP)bitmap9.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp);  // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP8 

		/*************************************************************************/
				m_show="����ȡ����...";
				UpdateData(FALSE);                      //��m_show�ϴ����Ի���
				Sleep(1000);
			}
			if(i==1)
			{
		/*************************************************************************/
				//���������ȡ����ͼƬָ��
			  hBmp = (HBITMAP)bitmap8.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp);  // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP9 

		/*************************************************************************/
				m_show="���ڼ�ˮ...";
				UpdateData(FALSE);
				Sleep(5000);
			}
			if(i>1&&i<=n)
			{
				if(i==2)
				{
		/*************************************************************************/
				//������������ԭ��ͼƬָ��
			   hBmp = (HBITMAP)bitmap10.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP10 
		/*************************************************************************/
				}
				m_show="���ڼ�ԭ��...";
				UpdateData(FALSE);
				Sleep(1000);
			}
			
			
		}
		hBmp = (HBITMAP)bitmap11.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
        m_Picture1.SetBitmap(hBmp);
		m_show="���������ɹ�,��ȡ�ߣ�";
	
		UpdateData(FALSE);
		Sleep(8000);
		m_show="";                                  //����
		m_spay=m_fpay=m_get=0;
		UpdateData(FALSE);
	}
}
		

	    //������㣬��ʾ�����㡱
	else if(m_get<0) MessageBox("����");
}




void CMFCApplication1Dlg::OnCbnSelchangeName()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel; 
	CBitmap bitmap1,bitmap2,bitmap3,bitmap4,bitmap5,bitmap6,bitmap7;  // CBitmap�������ڼ���λͼ   
    HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��

	bitmap1.LoadBitmap(IDB_BITMAP1);  // ��λͼIDB_BITMAP1���ص�bitmap1
	bitmap2.LoadBitmap(IDB_BITMAP2);  // ��λͼIDB_BITMAP1���ص�bitmap2
	bitmap3.LoadBitmap(IDB_BITMAP3);  // ��λͼIDB_BITMAP1���ص�bitmap3
	bitmap4.LoadBitmap(IDB_BITMAP4);  // ��λͼIDB_BITMAP1���ص�bitmap4
	bitmap5.LoadBitmap(IDB_BITMAP5);  // ��λͼIDB_BITMAP1���ص�bitmap5
	bitmap6.LoadBitmap(IDB_BITMAP6);  // ��λͼIDB_BITMAP1���ص�bitmap6
	bitmap7.LoadBitmap(IDB_BITMAP7);  // ��λͼIDB_BITMAP1���ص�bitmap7
	

  
    // ��ȡ��Ͽ�ؼ����б����ѡ��������� 
    nSel = m_Combo_Picture.GetCurSel(); 
	switch(nSel){
		case 0:hBmp = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;  // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
		case 1:hBmp = (HBITMAP)bitmap2.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
		case 2:hBmp = (HBITMAP)bitmap3.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
		case 3:hBmp = (HBITMAP)bitmap4.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
	    case 4:hBmp = (HBITMAP)bitmap5.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
		case 5:hBmp = (HBITMAP)bitmap6.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
		case 6:hBmp = (HBITMAP)bitmap7.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
               m_Picture1.SetBitmap(hBmp); break;
		default:break;
		
	}
}




void CMFCApplication1Dlg::OnBnClickedExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	if( MessageBox( "ȷ���˳�", "", MB_YESNO | MB_ICONQUESTION ) == IDYES  )
	{
        this->SendMessage( WM_CLOSE );
     }
	
//	CDialog::OnOK();
}
