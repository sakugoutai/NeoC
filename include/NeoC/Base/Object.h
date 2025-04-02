#pragma once

/* ------------------------------------------------------ */
/* header */
// クラス定義
#define class typedef struct

// インターフェース定義
#define interface typedef struct

// 継承
#define extends(SPRCLS) private SPRCLS _SPRCLS

// 実装
#define implements(ITRFC) private ITRFC _ITRFC

// 函数・値注釈
#define private			// 非公開
#define protected		// 公開・変更非推奨
#define public			// 公開
#define undefined		// 未定義
#define library			// ライブラリ専用
#define inherit			// 継承
#define actualize		// 実装

// 値注釈
#define final			// 変更不能

// インスタンスメソッド第一引数の型
#define self_t void

// 汎用ポインタ用
#define any void

/* source */
// メソッド注釈
#define method

// 生成
#define new(T) (T *)(_Memory.Allocate(sizeof(T)))

// 消去
#define delete(VAR) _Memory.Free(VAR)

// キャスト(基底<>派生クラス)
#define act(T, VAR) ((T *)(VAR))
/* ------------------------------------------------------ */

#include <stdint.h>
#include "NeoC/Base/Memory.h"

class Object_t {
	private uint8_t *_Expr;

	public uint8_t *(* GetExpr)(self_t *);
} Object_t;

class _Object {
	public Object_t *(* Init)(Object_t *);
	public Object_t *(* New)();
	public void (* Delete)(Object_t *);

	public uint8_t *(* GetExpr)(self_t *);
} _Object;

extern _Object Object;
