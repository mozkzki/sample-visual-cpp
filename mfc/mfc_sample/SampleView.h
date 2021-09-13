/* Copyright 2017 mozkzki */
#pragma once

#include "resource.h"

// document template objectの管理下クラス
// Doc, View, Windowは1セット
class SampleView : public CView {
    // document template objectにこのクラスを知らせる
    DECLARE_DYNCREATE(SampleView)
    DECLARE_MESSAGE_MAP()

 private:
    SampleView();

    SampleDoc* GetDocument();
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void OnInitialUpdate();
    virtual void OnDraw(CDC* pDC);

    // WM_CREATEメッセージハンドラ
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    // EN_CHANGEメッセージハンドラ
    afx_msg void OnChangeEditControl();

    // Editコントロール
    CEdit edit_control_;
};
