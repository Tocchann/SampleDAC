
// MfcAppView.h : CMfcAppView �N���X�̃C���^�[�t�F�C�X
//

#pragma once


class CMfcAppView : public CEditView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CMfcAppView();
	DECLARE_DYNCREATE(CMfcAppView)

// ����
public:
	CMfcAppDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CMfcAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDispExt();
	afx_msg void OnListupKnownfolderid();
};

#ifndef _DEBUG  // MfcAppView.cpp �̃f�o�b�O �o�[�W����
inline CMfcAppDoc* CMfcAppView::GetDocument() const
   { return reinterpret_cast<CMfcAppDoc*>(m_pDocument); }
#endif

