
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



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
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PAY, &CMFCApplication1Dlg::OnBnClickedPay)
	ON_BN_CLICKED(IDC_CPay, &CMFCApplication1Dlg::OnBnClickedCpay)
//	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//初始化咖啡种类
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("曲奇摩卡");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("拿铁");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("卡布奇诺");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("美式咖啡");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("意式浓缩");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("奶沫");
	((CComboBox*)GetDlgItem(IDC_NAME))->AddString("奶咖");
	((CComboBox*)GetDlgItem(IDC_NAME))->SetCurSel(0);              //设置默认值

	//初始化语言
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->AddString("中文简体");
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->AddString("English");
	((CComboBox*)GetDlgItem(IDC_LANGUAGE))->SetCurSel(0);          //设置默认值


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedPay()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取咖啡名称
	int index;
	index=((CComboBox*)GetDlgItem(IDC_NAME))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_NAME))->GetLBText(index,m_name);

	//显示账单的格式化
	m_cbook.m_str.Format("咖啡种类：%s\n",m_name);
	m_cbook.DoModal();

}


void CMFCApplication1Dlg::OnBnClickedCpay()
{
	// TODO: 在此添加控件通知处理程序代码

	//订单金额确认


		//如果付款成功，开始制作咖啡
	if(m_fpay>=m_spay){

		int index;
	    index=((CComboBox*)GetDlgItem(IDC_NAME))->GetCurSel();
//		CString str;
//		((CComboBox*)GetDlgItem(IDC_NAME))->GetLBText(index,str);
		Coffee coffee(CoffeeKind(index),BottleSize(m_type),m_suger);
		double Ang[2]={0.0,0.0};
		m_robot.Process(coffee);                        //利用Robot对象调用Process()函数
		int n=0;                                        //利用定义的n存储数组数量
		n=m_robot.Getnum(); 
//		str.Format("Number:%d",n);
//		MessageBox(str); 

		UpdateData();                                  //获取对话框数据杯数m_num
		for(int j=0;j<=m_num;j++){                     //利用杯数确定循环次数
		//利用for循环调用Robot实现控制运动
		for(int i=0;i<=n;i++){
			m_robot.GetAngle(i,Ang);

			//此处应该根据上面语句求解的角度调用控制器

			//延时，用于各个动作
				//图片更换与提示语切换
			if(i==0){
				m_show="正在取杯子...";
				UpdateData(FALSE);                      //将m_show上传至对话框
				Sleep(1000);
			}
			if(i==1){
				m_show="正在加水...";
				UpdateData(FALSE);
				Sleep(5000);
			}
			if(i>1&&i<=n){
				m_show="正在加原料...";
				UpdateData(FALSE);
				Sleep(1000);
			}
			
			
		}
		m_show="咖啡制作成功,请取走！";
		UpdateData(FALSE);
		Sleep(8000);
		m_show="";
		UpdateData(FALSE);
	}
}
		//如果未付款，提示“请付款”
//	else if(m_fpay==0) MessageBox("请付款");

	    //如果金额不足，提示“余额不足”
	else if(m_fpay<=m_spay) MessageBox("余额不足");
}


