/* Copyright 2017 mozkzki */
#pragma once

// document template objectの管理下クラス
// Doc, View, Windowは1セット
class SampleWindow : public CMDIChildWnd {
    // document template objectにこのクラスを知らせる
    DECLARE_DYNCREATE(SampleWindow)

 private:
    SampleWindow();

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);  // NOLINT (MFC method)

    // WM_CREATEのメッセージハンドラ
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
