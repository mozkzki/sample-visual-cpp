/* Copyright 2017 mozkzki */
#include "SampleApp.h"
#include "MainWindow.h"
#include "SampleDoc.h"
#include "SampleView.h"
#include "SampleWindow.h"

BEGIN_MESSAGE_MAP(SampleApp, CWinApp)
    ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()

// WinMainから呼び出してもらうために
// このクラスのグローバルオブジェクトインスタンスも確保必要(変数名は任意)
SampleApp app;

/*
* WinMainから呼び出される
* WinMainはMFCに実装されている
*/
BOOL SampleApp::InitInstance() {
    // 基本クラスの同メソッドを呼ぶこと
    CWinApp::InitInstance();

    // document template objectを作ってappに登録
    CMultiDocTemplate* doc_template;
    doc_template = new CMultiDocTemplate(
        IDR_SMALLTEXTTYPE,
        RUNTIME_CLASS(SampleDoc),     // doc
        RUNTIME_CLASS(SampleWindow),  // window
        RUNTIME_CLASS(SampleView));   // view
    if (!doc_template) return FALSE;
    CWinApp::AddDocTemplate(doc_template);

    // メインウィンドウを作成
    MainWindow* main_window = new MainWindow();  // インスタンス作成
    // 本来戻り値チェックが必要
    main_window->LoadFrame(IDR_MAINFRAME);       // windowが内部的に作成される
    main_window->ShowWindow(CWinApp::m_nCmdShow);         // 表示
    // message loopを介さずwindowsに対してWM_PAINT送信
    // message loop開始前にwindowのクライアント領域描画
    main_window->UpdateWindow();
    CWinApp::m_pMainWnd = main_window;  // セット絶対必要

    // 「ファイル」メニューの「新規作成」
    // AddDocTemplateで追加された
    // document template objectのOpenDocumentFileが呼ばれる
    // OpenDocumentFile内では、document,window,viewの順で1セットが生成される
    // 各クラスに順番に番号で示す（パワポの図を参照）
    CWinApp::OnFileNew();

    // FALSEを返したらアプリ終了
    return TRUE;
}
