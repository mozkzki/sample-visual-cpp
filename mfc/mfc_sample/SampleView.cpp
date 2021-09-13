/* Copyright 2017 mozkzki */
#include "SampleDoc.h"
#include "SampleView.h"

// document template objectにこのクラスを知らせる
IMPLEMENT_DYNCREATE(SampleView, CView)

BEGIN_MESSAGE_MAP(SampleView, CView)
    ON_WM_CREATE()
    ON_EN_CHANGE(IDC_EDIT1, &SampleView::OnChangeEditControl)
END_MESSAGE_MAP()

SampleView::SampleView() {
    // (5)
}

// このviewに対応するdocumentを返す
SampleDoc* SampleView::GetDocument() {
    // m_pDocumentはMFCによって設定済み
    return (SampleDoc*)CView::m_pDocument;
}

BOOL SampleView::PreCreateWindow(CREATESTRUCT& cs) {
    // (6)

    if (CView::PreCreateWindow(cs) == FALSE) {
        return FALSE;
    }

    return TRUE;
}

int SampleView::OnCreate(LPCREATESTRUCT lpCreateStruct) {
    // (7)

    if (CView::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }

    edit_control_.Create(
        ES_NUMBER | ES_RIGHT | WS_CHILD | WS_VISIBLE | WS_BORDER,
        CRect(10, 10, 110, 36), this, IDC_EDIT1);

    return 0;
}
void SampleView::OnInitialUpdate() {
    // (9)

    // この時点でdocumentの初期化は終わっている
    // viewのコンテンツ描画コードが実行される直前の初期化処理を書く

    // docの内容に基づいてviewの部品を初期化する処理もここ

    SampleDoc* document = GetDocument();
    CString data;
    data.Format(_T("%d"), document->data_);
    edit_control_.SetWindowTextW(data);

    // <1>
    // このOnInitialUpdate関数の中から、
    // viewの更新を行うOnUpdateが呼び出される
    // 最終的にOnDraw関数が呼び出され、viewのクライアント領域に対する
    // 描画コードが実行される
    CView::OnInitialUpdate();  // このコードの順番は処理による
}

void SampleView::OnDraw(CDC* pDC) {
    // pDCは、viewのクライアント領域に対するデバイスコンテキスト

    // その時のdocumentの値に基づいたview描画を行う
    SampleDoc* document = GetDocument();
    int value = document->data_;
    CBrush brush(RGB(0, 0, 255));
    pDC->FillRect(CRect(10, 50, 10 + value, 80), &brush);
}

void SampleView::OnChangeEditControl() {
    // viewに配置されたコントロールから値取得
    CString data_text;
    edit_control_.GetWindowTextW(data_text);
    int data = ::_wtoi(data_text);

    // documentに設定
    SampleDoc* document = GetDocument();
    document->data_ = data;

    // <1>
    // 明示的にdocument更新を通知
    // そのdocument関連付いた全てのviewに対して
    // OnUpdate関数が呼び出され、viewを更新できる
    document->UpdateAllViews(NULL);
}
