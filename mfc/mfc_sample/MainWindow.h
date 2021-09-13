/* Copyright 2017 mozkzki */
#pragma once

class MainWindow : public CMDIFrameWnd {
    // メッセージマップ
    // MFCにおいてメッセージとハンドラの紐付けに必要
    DECLARE_MESSAGE_MAP()

 private:
    static const UINT kIndicators[];

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

    // WM_CREATEのメッセージハンドラ
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

    // ステータスバー
    // メンバ変数化は必須でないが、親と生成/削除タイミングが一致する
    // 管理が楽になる
    CStatusBar status_bar_;
};
