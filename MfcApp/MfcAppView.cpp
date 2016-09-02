
// MfcAppView.cpp : CMfcAppView �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�k���ŁA����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
#ifndef SHARED_HANDLERS
#include "MfcApp.h"
#endif

#include "MfcAppDoc.h"
#include "MfcAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcAppView

IMPLEMENT_DYNCREATE(CMfcAppView, CEditView)

BEGIN_MESSAGE_MAP(CMfcAppView, CEditView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND( IDM_TEST, &CMfcAppView::OnTest )
END_MESSAGE_MAP()

// CMfcAppView �R���X�g���N�V����/�f�X�g���N�V����

CMfcAppView::CMfcAppView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CMfcAppView::~CMfcAppView()
{
}

BOOL CMfcAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���[�h ���b�v���g�p�\�ɂ��܂�

	return bPreCreated;
}


// CMfcAppView ���

BOOL CMfcAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����� CEditView �̈������
	return CEditView::OnPreparePrinting(pInfo);
}

void CMfcAppView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// ����� CEditView �ň�����J�n���܂��B
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMfcAppView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// ����� CEditView �̈����̌㏈��
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CMfcAppView �f�f

#ifdef _DEBUG
void CMfcAppView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMfcAppView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMfcAppDoc* CMfcAppView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcAppDoc)));
	return (CMfcAppDoc*)m_pDocument;
}
#endif //_DEBUG

static void GetTypeNameFromExt( LPCTSTR ext )
{
	CRegKey	keyExt;
	auto result = keyExt.Open( HKEY_CLASSES_ROOT, ext, KEY_READ );
	if( result != ERROR_SUCCESS )
	{
		CString msg;
		msg.Format( _T( "Failed!! keyExt.Open( \"%s\" ):%d" ), ext, result );
		AfxMessageBox( msg );
		return;
	}
	TCHAR	progId[MAX_PATH+1];
	ULONG	length = MAX_PATH;
	result = keyExt.QueryStringValue( nullptr, progId, &length );
	if( result != ERROR_SUCCESS )
	{
		CString msg;
		msg.Format( _T( "Failed!! keyExt(%s).QueryStringValue():%d" ), ext, result );
		AfxMessageBox( msg );
		return;
	}
	CRegKey keyProgId;
	result = keyProgId.Open( HKEY_CLASSES_ROOT, progId, KEY_READ );
	if( result != ERROR_SUCCESS )
	{
		CString msg;
		msg.Format( _T( "Failed!! keyProgId.Open( \"%s\" ):%d" ), progId, result );
		AfxMessageBox( msg );
		return;
	}
	TCHAR	dispName[MAX_PATH+1];
	length = MAX_PATH;
	result = keyProgId.QueryStringValue( nullptr, dispName, &length );
	if( result != ERROR_SUCCESS )
	{
		CString msg;
		msg.Format( _T( "Failed!! keyProgId(%s).QueryStringValue():%d" ), progId, result );
		AfxMessageBox( msg );
		return;
	}
	CString msg;
	msg.Format( _T( "�g���q�u%s�v�̕\�����́u%s�v�ł��B" ), ext, dispName );
	AfxMessageBox( msg );
}

// CMfcAppView ���b�Z�[�W �n���h���[
void CMfcAppView::OnTest()
{
	TRY{
		GetTypeNameFromExt( _T( ".cpp" ) );
	}
	CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
		TRY{
		GetTypeNameFromExt( _T( ".mfcapp" ) );
	}
		CATCH_ALL( e )
	{
		e->ReportError();
	}
	END_CATCH_ALL
}
