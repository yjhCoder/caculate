
// jisuanqi3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cjisuanqi3App:
// �йش����ʵ�֣������ jisuanqi3.cpp
//

class Cjisuanqi3App : public CWinApp
{
public:
	Cjisuanqi3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cjisuanqi3App theApp;