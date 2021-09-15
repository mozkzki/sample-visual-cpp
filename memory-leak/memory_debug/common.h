/* Copyright 2017 mozkzki */
#pragma once

// メモリリークを検出するため
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#define new  ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif	// _DEBUG
