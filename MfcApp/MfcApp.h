
// MfcApp.h : MfcApp �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CMfcAppApp:
// ���̃N���X�̎����ɂ��ẮAMfcApp.cpp ���Q�Ƃ��Ă��������B
//

class CMfcAppApp : public CWinApp
{
public:
	CMfcAppApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	CString value;

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMfcAppApp theApp;
