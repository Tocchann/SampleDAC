
// MfcAppView.cpp : CMfcAppView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
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
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND( IDM_TEST, &CMfcAppView::OnTest )
END_MESSAGE_MAP()

// CMfcAppView コンストラクション/デストラクション

CMfcAppView::CMfcAppView()
{
	// TODO: 構築コードをここに追加します。

}

CMfcAppView::~CMfcAppView()
{
}

BOOL CMfcAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ワード ラップを使用可能にします

	return bPreCreated;
}


// CMfcAppView 印刷

BOOL CMfcAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の CEditView の印刷準備
	return CEditView::OnPreparePrinting(pInfo);
}

void CMfcAppView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 既定の CEditView で印刷を開始します。
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMfcAppView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 既定の CEditView の印刷後の後処理
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CMfcAppView 診断

#ifdef _DEBUG
void CMfcAppView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMfcAppView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMfcAppDoc* CMfcAppView::GetDocument() const // デバッグ以外のバージョンはインラインです。
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
	msg.Format( _T( "拡張子「%s」の表示名は「%s」です。" ), ext, dispName );
	AfxMessageBox( msg );
}

// CMfcAppView メッセージ ハンドラー
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
