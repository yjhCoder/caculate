
// jisuanqi3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "jisuanqi3.h"
#include "jisuanqi3Dlg.h"
#include "afxdialogex.h"
#include <math.h>

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


Cjisuanqi3Dlg::Cjisuanqi3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cjisuanqi3Dlg::IDD, pParent)
	, numfirst(0)
	, numsecond(0)
	, op(0)
	, m_Dis(0)
	, point_flag(false)
	, poz(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cjisuanqi3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIS, m_Dis);
}

BEGIN_MESSAGE_MAP(Cjisuanqi3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PT, &Cjisuanqi3Dlg::OnBnClickedPt)
	ON_BN_CLICKED(IDC_ADD, &Cjisuanqi3Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MIN, &Cjisuanqi3Dlg::OnBnClickedMin)
	ON_BN_CLICKED(IDC_EQU, &Cjisuanqi3Dlg::OnBnClickedEqu)
	ON_BN_CLICKED(IDC_BACK, &Cjisuanqi3Dlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_CLEAR, &Cjisuanqi3Dlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_CE, &Cjisuanqi3Dlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_NUM9, &Cjisuanqi3Dlg::OnClickedNum9)
	ON_BN_CLICKED(IDC_NUM8, &Cjisuanqi3Dlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM7, &Cjisuanqi3Dlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM6, &Cjisuanqi3Dlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM5, &Cjisuanqi3Dlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM4, &Cjisuanqi3Dlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM3, &Cjisuanqi3Dlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM2, &Cjisuanqi3Dlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM1, &Cjisuanqi3Dlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM0, &Cjisuanqi3Dlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_DIV, &Cjisuanqi3Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_MUL, &Cjisuanqi3Dlg::OnClickedMul)
	END_MESSAGE_MAP()


// Cjisuanqi3Dlg 消息处理程序

BOOL Cjisuanqi3Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cjisuanqi3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cjisuanqi3Dlg::OnPaint()
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
HCURSOR Cjisuanqi3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void Cjisuanqi3Dlg::OnBnClickedPt()
{
	point_flag=TRUE;
}


void Cjisuanqi3Dlg::OnBnClickedAdd()
{
	op='+';
	numfirst=m_Dis;                                 //进行加法运算后，m-Dis归零进行输入第二个数
	m_Dis=0;
}


void Cjisuanqi3Dlg::OnBnClickedMin()
{
	op='-';
	numfirst=m_Dis;
	m_Dis=0;
}

void Cjisuanqi3Dlg::OnBnClickedDiv()
{
	op='/';
	numfirst=m_Dis;
	m_Dis=0;
}


void Cjisuanqi3Dlg::OnBnClickedEqu()
{   numsecond=m_Dis;
	switch(op)             //根据符号来进行运算
		{case '+' :  m_Dis=numfirst+numsecond;break;
		 case '-'  :  m_Dis=numfirst-numsecond;break;
		 case '*' :  m_Dis=numfirst*numsecond;break;
		 case '/' :  m_Dis=numfirst/numsecond;break;
		 default:break;
	    }
	UpdateData(false);
}


void Cjisuanqi3Dlg::OnBnClickedBack()
{
	m_Dis=(int) m_Dis/10;            //除以10在进行强制转换
	UpdateData(false);
}


void Cjisuanqi3Dlg::OnBnClickedClear()
{
	op=NULL; //清空符号 
	numfirst=0;//清空第一个数字
	numsecond=0;//清空第二个数字 
	point_flag=FALSE;//改为默认整数位
	poz=1;//小数点归位
	m_Dis=0; 
	UpdateData(FALSE); //屏幕显示归0
}


void Cjisuanqi3Dlg::OnBnClickedCe()
{
	if(numfirst!=0 && numsecond==0)//CE只能修改第二个数字
	{
		m_Dis=0;  //把屏幕的值赋值为0
		UpdateData(FALSE);//并显示出来
	}
}

void Cjisuanqi3Dlg::OnClickedNum9()
{
	if(point_flag==TRUE)            //如果是小数
	{
		m_Dis=m_Dis+pow(0.1,poz)*9;      //就按照小数点的数位来相对应的缩小
		poz++;                                      //并且将小数点位相加
		UpdateData(false);
	}
	else                                  //如果是整数
	{
		m_Dis=m_Dis*10+9;         //每一次输入都进位
		UpdateData(false);
	}
}

void Cjisuanqi3Dlg::OnBnClickedNum8()
{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*8;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+8;         //每一次输入都进位
			UpdateData(false);
    	}
}


void Cjisuanqi3Dlg::OnBnClickedNum7()
{
	if(point_flag==TRUE)            //如果是小数
	{
		m_Dis=m_Dis+pow(0.1,poz)*7;      //就按照小数点的数位来相对应的缩小
		poz++;                                      //并且将小数点位相加
		UpdateData(false);
	}
	else                                  //如果是整数
	{
		m_Dis=m_Dis*10+7;         //每一次输入都进位
		UpdateData(false);
	}
}


void Cjisuanqi3Dlg::OnBnClickedNum6()
{
	if(point_flag==TRUE)            //如果是小数
	{
		m_Dis=m_Dis+pow(0.1,poz)*6;      //就按照小数点的数位来相对应的缩小
		poz++;                                      //并且将小数点位相加
		UpdateData(false);
	}
	else                                  //如果是整数
	{
		m_Dis=m_Dis*10+6;         //每一次输入都进位
		UpdateData(false);
	}
}

	void Cjisuanqi3Dlg::OnBnClickedNum5()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*5;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+5;         //每一次输入都进位
			UpdateData(false);
		}
	}


	void Cjisuanqi3Dlg::OnBnClickedNum4()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*4;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+4;         //每一次输入都进位
			UpdateData(false);
		}
	}


	void Cjisuanqi3Dlg::OnBnClickedNum3()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*3;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+3;         //每一次输入都进位
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum2()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*2;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+2;         //每一次输入都进位
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum1()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*1;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+1;         //每一次输入都进位
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum0()
	{
		if(point_flag==TRUE)            //如果是小数
		{
			m_Dis=m_Dis+pow(0.1,poz)*0;      //就按照小数点的数位来相对应的缩小
			poz++;                                      //并且将小数点位相加
			UpdateData(false);
		}
		else                                  //如果是整数
		{
			m_Dis=m_Dis*10+0;         //每一次输入都进位
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnClickedMul()
	{
		op='*';
		numfirst=m_Dis;
		m_Dis=0;
	}
