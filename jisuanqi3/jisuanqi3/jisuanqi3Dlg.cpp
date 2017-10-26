
// jisuanqi3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jisuanqi3.h"
#include "jisuanqi3Dlg.h"
#include "afxdialogex.h"
#include <math.h>

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


// Cjisuanqi3Dlg ��Ϣ�������

BOOL Cjisuanqi3Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cjisuanqi3Dlg::OnPaint()
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
	numfirst=m_Dis;                                 //���мӷ������m-Dis�����������ڶ�����
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
	switch(op)             //���ݷ�������������
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
	m_Dis=(int) m_Dis/10;            //����10�ڽ���ǿ��ת��
	UpdateData(false);
}


void Cjisuanqi3Dlg::OnBnClickedClear()
{
	op=NULL; //��շ��� 
	numfirst=0;//��յ�һ������
	numsecond=0;//��յڶ������� 
	point_flag=FALSE;//��ΪĬ������λ
	poz=1;//С�����λ
	m_Dis=0; 
	UpdateData(FALSE); //��Ļ��ʾ��0
}


void Cjisuanqi3Dlg::OnBnClickedCe()
{
	if(numfirst!=0 && numsecond==0)//CEֻ���޸ĵڶ�������
	{
		m_Dis=0;  //����Ļ��ֵ��ֵΪ0
		UpdateData(FALSE);//����ʾ����
	}
}

void Cjisuanqi3Dlg::OnClickedNum9()
{
	if(point_flag==TRUE)            //�����С��
	{
		m_Dis=m_Dis+pow(0.1,poz)*9;      //�Ͱ���С�������λ�����Ӧ����С
		poz++;                                      //���ҽ�С����λ���
		UpdateData(false);
	}
	else                                  //���������
	{
		m_Dis=m_Dis*10+9;         //ÿһ�����붼��λ
		UpdateData(false);
	}
}

void Cjisuanqi3Dlg::OnBnClickedNum8()
{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*8;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+8;         //ÿһ�����붼��λ
			UpdateData(false);
    	}
}


void Cjisuanqi3Dlg::OnBnClickedNum7()
{
	if(point_flag==TRUE)            //�����С��
	{
		m_Dis=m_Dis+pow(0.1,poz)*7;      //�Ͱ���С�������λ�����Ӧ����С
		poz++;                                      //���ҽ�С����λ���
		UpdateData(false);
	}
	else                                  //���������
	{
		m_Dis=m_Dis*10+7;         //ÿһ�����붼��λ
		UpdateData(false);
	}
}


void Cjisuanqi3Dlg::OnBnClickedNum6()
{
	if(point_flag==TRUE)            //�����С��
	{
		m_Dis=m_Dis+pow(0.1,poz)*6;      //�Ͱ���С�������λ�����Ӧ����С
		poz++;                                      //���ҽ�С����λ���
		UpdateData(false);
	}
	else                                  //���������
	{
		m_Dis=m_Dis*10+6;         //ÿһ�����붼��λ
		UpdateData(false);
	}
}

	void Cjisuanqi3Dlg::OnBnClickedNum5()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*5;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+5;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}


	void Cjisuanqi3Dlg::OnBnClickedNum4()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*4;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+4;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}


	void Cjisuanqi3Dlg::OnBnClickedNum3()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*3;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+3;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum2()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*2;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+2;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum1()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*1;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+1;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnBnClickedNum0()
	{
		if(point_flag==TRUE)            //�����С��
		{
			m_Dis=m_Dis+pow(0.1,poz)*0;      //�Ͱ���С�������λ�����Ӧ����С
			poz++;                                      //���ҽ�С����λ���
			UpdateData(false);
		}
		else                                  //���������
		{
			m_Dis=m_Dis*10+0;         //ÿһ�����붼��λ
			UpdateData(false);
		}
	}

	void Cjisuanqi3Dlg::OnClickedMul()
	{
		op='*';
		numfirst=m_Dis;
		m_Dis=0;
	}
