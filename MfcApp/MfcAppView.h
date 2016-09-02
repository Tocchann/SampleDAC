
// MfcAppView.h : CMfcAppView クラスのインターフェイス
//

#pragma once


class CMfcAppView : public CEditView
{
protected: // シリアル化からのみ作成します。
	CMfcAppView();
	DECLARE_DYNCREATE(CMfcAppView)

// 属性
public:
	CMfcAppDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CMfcAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
};

#ifndef _DEBUG  // MfcAppView.cpp のデバッグ バージョン
inline CMfcAppDoc* CMfcAppView::GetDocument() const
   { return reinterpret_cast<CMfcAppDoc*>(m_pDocument); }
#endif

