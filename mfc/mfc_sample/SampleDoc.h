/* Copyright 2017 mozkzki */
#pragma once

// document template objectの管理下クラス
// Doc, View, Windowは1セット
class SampleDoc : public CDocument {
    // document template objectにこのクラスを知らせる
    DECLARE_DYNCREATE(SampleDoc)

 public:
    int data_;

 private:
    SampleDoc();
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
};
