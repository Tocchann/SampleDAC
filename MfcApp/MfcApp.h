
// MfcApp.h : MfcApp アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CMfcAppApp:
// このクラスの実装については、MfcApp.cpp を参照してください。
//

class CMfcAppApp : public CWinApp
{
public:
	CMfcAppApp();


// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	CString value;

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMfcAppApp theApp;
