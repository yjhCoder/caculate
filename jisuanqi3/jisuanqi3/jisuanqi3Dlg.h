
// jisuanqi3Dlg.h : 头文件
//

#pragma once


// Cjisuanqi3Dlg 对话框
class Cjisuanqi3Dlg : public CDialogEx
{
// 构造
public:
	Cjisuanqi3Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JISUANQI3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	double  numfirst;
	double numsecond;
	char op;
	double m_Dis;
//	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedPt();
	bool point_flag;
	double poz;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedMin();
	afx_msg void OnBnClickedEqu();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedCe();
    afx_msg void OnClickedNum9();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnClickedMul();
};
