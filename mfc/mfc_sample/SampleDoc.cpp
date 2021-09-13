/* Copyright 2017 mozkzki */
#include "SampleDoc.h"

IMPLEMENT_DYNCREATE(SampleDoc, CDocument)

/**
 * @class ドキュメント
 *
 * @brief 
 */
SampleDoc::SampleDoc() {
    // (1)
}

BOOL SampleDoc::OnNewDocument() {
    // (8)
    // この関数はdocument templateによって呼ばれる

    // ここでは、初期状態のドキュメントを構築する
    // documentの初期設定を行う

    // 親クラスの呼び出し必須
    if (!CDocument::OnNewDocument()) {
        // FALSEを返すと、document初期化失敗とみなされて
        // これまで作られた3 object (doc,view,window)は破棄される
        return FALSE;
    }

    this->data_ = 100;

    return TRUE;
}

void SampleDoc::Serialize(CArchive& ar) {
    if (ar.IsStoring()) {
        ar << this->data_;
    } else {
        ar >> this->data_;
    }
}
