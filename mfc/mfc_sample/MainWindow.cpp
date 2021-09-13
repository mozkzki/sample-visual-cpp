/* Copyright 2017 mozkzki */
#include "MainWindow.h"

// メッセージマップ
// MFCにおいてメッセージとハンドラの紐付けに必要
BEGIN_MESSAGE_MAP(MainWindow, CMDIFrameWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

const UINT MainWindow::kIndicators[] = {
    ID_SEPARATOR,
    ID_INDICATOR_CAPS,
};

// windowが作成される前に呼び出される
// window生成前にwindowのスタイルなどを設定する関数
BOOL MainWindow::PreCreateWindow(CREATESTRUCT& cs) {
    // 基本クラスの同名関数を呼ぶ
    if (!CMDIFrameWnd::PreCreateWindow(cs)) {
        return FALSE;
    }

    // 最大化ボタンをoff
    cs.style &= ~(WS_MAXIMIZEBOX);
    // 常に全面（拡張スタイル）
    cs.dwExStyle |= WS_EX_TOPMOST;

    return TRUE;
}


// WM_CREATEメッセージハンドラ
// OSが発行したWM_CREATEメッセージを受けて動作する
// window handleは確定済み、まだ表示されていない状態
// このwindowに属する子window等の子要素を作るのに適切なタイミング
int MainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) {
    // 基本クラスの同名関数を呼ぶ
    if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }

    // ステータスバーの作成
    // 親windowを渡して生成
    // 親に子供windowが張り付く
    if (!status_bar_.Create(this)) {
        // 作成できない場合
        // LoadFrameの戻り値がFALSEになる
        return -1;
    }

    status_bar_.SetIndicators(
        kIndicators, sizeof(kIndicators) / sizeof(UINT));

    // 作成できた場合
    return 0;
}
