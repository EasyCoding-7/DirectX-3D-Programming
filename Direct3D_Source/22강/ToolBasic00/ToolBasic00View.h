
// ToolBasic00View.h : CToolBasic00View Ŭ������ �������̽�
//

#pragma once
#include "ToolBasic00Doc.h"


class CToolBasic00View : public CView
{
protected: // serialization������ ��������ϴ�.
	CToolBasic00View();
	DECLARE_DYNCREATE(CToolBasic00View)

// Ư���Դϴ�.
public:
	CToolBasic00Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CToolBasic00View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ToolBasic00View.cpp�� ����� ����
inline CToolBasic00Doc* CToolBasic00View::GetDocument() const
   { return reinterpret_cast<CToolBasic00Doc*>(m_pDocument); }
#endif

