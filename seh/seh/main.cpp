/* Copyright 2017 mozkzki */
#include <Windows.h>
#include <tchar.h>

// 参考:http://www.ne.jp/asahi/hishidama/home/tech/vcpp/seh.html

LONG dump_exception(_EXCEPTION_POINTERS *ep) {
    PEXCEPTION_RECORD rec = ep->ExceptionRecord;

    TCHAR buf[1024];
    wsprintf(buf, _T("code:%x flag:%x addr:%p params:%d\n"),
        rec->ExceptionCode,
        rec->ExceptionFlags,
        rec->ExceptionAddress,
        rec->NumberParameters);
    ::OutputDebugString(buf);

    for (DWORD i = 0; i < rec->NumberParameters; i++) {
        wsprintf(buf, _T("param[%d]:%x\n"),
            i,
            rec->ExceptionInformation[i]);
        ::OutputDebugString(buf);
    }

    // EXCEPTION_EXECUTE_HANDLER: 1 発生した例外を自分で処理する
    // EXCEPTION_CONTINUE_SEARCH: 0 自分より外側の__tryブロックに処理を任せる
    // EXCEPTION_CONTINUE_EXECUTION: -1 例外が発生した箇所から再実行させる
    return EXCEPTION_EXECUTE_HANDLER;
}

int _tmain(int argc, _TCHAR* argv[]) {
    __try {
        __try {
            int *p = reinterpret_cast<int*>(0x123);
            *p = 456;  // 例外発生
        }
        // デフォルト動作(ダイアログを出す)
        // __except(UnhandledExceptionFilter(GetExceptionInformation())) {
        __except(dump_exception(GetExceptionInformation())) {
            DWORD code = GetExceptionCode();
            TCHAR buf[1024];
            wsprintf(buf, _T("code:%x\n"), code);
            ::OutputDebugString(buf);
            return code;
        }
    }
    __finally {
        ::OutputDebugString(_T("finally\n"));
    }

    return 0;
}
