#pragma once

#include <stdbool.h>
#include "NeoC/Base/Object.h"
#include "NeoC/Type/PrimitiveWrapper.h"

class Bool_t {
	implements (PrimitiveWrapper_i);

	private bool _bool;

	public bool (* Unpack)(self_t *);
	public actualize uint8_t *(* GetExpr)(self_t *);

	public self_t *(* Not)(self_t *);
	public self_t *(* And)(self_t *, self_t *);
	public self_t *(* Or)(self_t *, self_t *);
	public self_t *(* Xor)(self_t *, self_t *);
	public self_t *(* Nand)(self_t *, self_t *);
	public self_t *(* Nor)(self_t *, self_t *);
} Bool_t;

class _Bool_ {
	public Bool_t *(* Init)(Bool_t *, bool bl);
	public Bool_t *(* New)(bool bl);
	public void (* Delete)(Bool_t *);

	public bool (* Unpack)(self_t *);
	public actualize uint8_t *(* GetExpr)(self_t *);

	public self_t *(* Not)(self_t *);
	public self_t *(* And)(self_t *, self_t *);
	public self_t *(* Or)(self_t *, self_t *);
	public self_t *(* Xor)(self_t *, self_t *);
	public self_t *(* Nand)(self_t *, self_t *);
	public self_t *(* Nor)(self_t *, self_t *);
} _Bool_;

extern _Bool_ Bool;
