
// MFC-5Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-5.h"
#include "MFC-5Dlg.h"
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


// CMFC5Dlg 对话框



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


// CMFC5Dlg 消息处理程序

BOOL CMFC5Dlg::OnInitDialog()
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
	 // 为组合框控件的列表框添加列表项“鸡啄米”   
    m_Combo_Picture.AddString(_T("卡布奇诺"));   
    // 为组合框控件的列表框添加列表项“百度”   
    m_Combo_Picture.AddString(_T("美式咖啡"));   
	m_Combo_Picture.AddString(_T("拿铁"));  
    // 在组合框控件的列表框中索引为1的位置插入列表项“新浪”   
    m_Combo_Picture.AddString(_T("曲奇摩卡"));  
	// 默认选择第一项   
    m_Combo_Picture.SetCurSel(0);  

	CBitmap bitmap1,bitmap2,bitmap3,bitmap4;  // CBitmap对象，用于加载位图   添加
    HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄   添加
    bitmap1.LoadBitmap(IDB_BITMAP1);  // 将位图IDB_BITMAP1加载到bitmap1
	hBmp = (HBITMAP)bitmap1.GetSafeHandle(); 
	m_Cup_Picture1.SetBitmap(hBmp);  //显示位图1
    // 编辑框中默认显示第一项的文字“鸡啄米”   
    //SetDlgItemText(IDC_PIC_COMBO, _T("卡布奇诺"));   

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC5Dlg::OnPaint()
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
HCURSOR CMFC5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC5Dlg::OnCbnSelchangePicCombo()
{
	// TODO: 在此添加控件通知处理程序代码   
    int nSel; 
	CBitmap bitmap1,bitmap2,bitmap3,bitmap4;  // CBitmap对象，用于加载位图   
    HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄

	bitmap1.LoadBitmap(IDB_BITMAP1);  // 将位图IDB_BITMAP1加载到bitmap1
	bitmap2.LoadBitmap(IDB_BITMAP2);  // 将位图IDB_BITMAP1加载到bitmap2
	bitmap3.LoadBitmap(IDB_BITMAP3);  // 将位图IDB_BITMAP1加载到bitmap3
	bitmap4.LoadBitmap(IDB_BITMAP4);  // 将位图IDB_BITMAP1加载到bitmap4
	

  
    // 获取组合框控件的列表框中选中项的索引 
    nSel = m_Combo_Picture.GetCurSel(); 
	switch(nSel){
		case 0:hBmp = (HBITMAP)bitmap1.GetSafeHandle();  // 获取bitmap加载位图的句柄   
               m_Cup_Picture1.SetBitmap(hBmp); break;  // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
		case 1:hBmp = (HBITMAP)bitmap2.GetSafeHandle();  // 获取bitmap加载位图的句柄   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		case 2:hBmp = (HBITMAP)bitmap3.GetSafeHandle();  // 获取bitmap加载位图的句柄   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		case 3:hBmp = (HBITMAP)bitmap4.GetSafeHandle();  // 获取bitmap加载位图的句柄   
               m_Cup_Picture1.SetBitmap(hBmp); break;
		default:break;
		
	}
    // 根据选中项索引获取该项字符串   
   //* m_Combo_Picture.GetLBText(nSel, strWeb);   
    // 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
  //*  SetDlgItemText(IDC_PIC_COMBO, strWeb); 
}


void CMFC5Dlg::OnStnClickedPic1Static()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC5Dlg::OnStnClickedPic2Static()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC5Dlg::OnStnClickedPic3Static()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC5Dlg::OnStnClickedPic4Static()
{
	// TODO: 在此添加控件通知处理程序代码
}
