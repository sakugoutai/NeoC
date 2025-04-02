#pragma once

/* ------------------------------------------------------ */
#define in(...)

#define Comparator(X, Y, EqEvaFm)			\
	({										\
		bool _cmptr(any *X, any *Y) {		\
			return EqEvaFm;					\
		};									\
		_cmptr;								\
	})
/* ------------------------------------------------------ */

#include <stdint.h>
#include <stdbool.h>
#include <threads.h>
#include "NeoC/Base/Object.h"

class Collection_t {
	private int32_t _Size;
	private int32_t _Length;
	private mtx_t _Mtx;

	public int32_t (* GetLength)(self_t *);
	public bool (* IsEmpty)(self_t *);

	public void (* Lock)(self_t *);
	public void (* Unlock)(self_t *);
} Collection_t;

class _Collection {
	public void (* _Setup)();

	public Collection_t *(* Init)(Collection_t *);
	public void (* Delete)(Collection_t *);

	public int32_t (* GetLength)(self_t *);
	public bool (* IsEmpty)(self_t *);

	public void (* Lock)(self_t *);
	public void (* Unlock)(self_t *);
} _Collection;

extern _Collection Collection;
