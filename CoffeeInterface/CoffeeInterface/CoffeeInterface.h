
// CoffeeInterface.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCoffeeInterfaceApp: 
// �йش����ʵ�֣������ CoffeeInterface.cpp
//

class CCoffeeInterfaceApp : public CWinApp
{
public:
	CCoffeeInterfaceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCoffeeInterfaceApp theApp;