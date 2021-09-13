/* Copyright 2017 mozkzki */
#include "SampleWindow.h"

// document template objectにこのクラスを知らせる
IMPLEMENT_DYNCREATE(SampleWindow, CMDIChildWnd)

SampleWindow::SampleWindow() {
    // (2)
}

BOOL SampleWindow::PreCreateWindow(CREATESTRUCT& cs) {
    // (3)
    // window styleの設定など

    // 基本クラスの同名関数を呼ぶ
    if (CMDIChildWnd::PreCreateWindow(cs) == FALSE) {
        return FALSE;
    }

    return TRUE;
}

// WM_CREATEのメッセージハンドラ
int SampleWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) {
    // (4)
    // 子要素の作成など
    // 標準実装ではビューを作成する

    // viewは、子フレームウィンドウ（このクラス）の
    // クライアント領域に埋め込まれた子ウィンドウである
    // なので、ここで(下記OnCreate内で)Viewが生成までされる

    // 基本クラスの同名関数を呼ぶ
    if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }

    return 0;
}
