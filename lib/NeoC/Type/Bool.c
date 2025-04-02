#include "NeoC/Type/Bool.h"

method static bool Unpack(self_t *b) {
	return act(Bool_t, b)->_bool;
}

method static uint8_t *GetExpr(self_t *b) {
	return (Bool.Unpack(b))? u8"true" : u8"false";
}

method static self_t *Not(self_t *b) {
	return Bool.New(!Bool.Unpack(b));
}

method static self_t *And(self_t *b1, self_t *b2) {
	return Bool.New(Bool.Unpack(b1) && Bool.Unpack(b2));
}

method static self_t *Or(self_t *b1, self_t *b2) {
	return Bool.New(Bool.Unpack(b1) || Bool.Unpack(b2));
}

method static self_t *Xor(self_t *b1, self_t *b2) {
	if (Bool.Unpack(b1) == 1 && Bool.Unpack(b1) == Bool.Unpack(b2))
		return Bool.New(false);
	else return Bool.Or(b1, b2);
}

method static self_t *Nand(self_t *b1, self_t *b2) {
	return Bool.New(!(Bool.Unpack(b1) && Bool.Unpack(b2)));
}

method static self_t *Nor(self_t *b1, self_t *b2) {
	return Bool.New(!(Bool.Unpack(b1) || Bool.Unpack(b2)));
}

method static Bool_t *Init(Bool_t *b , bool bl) {
	act(PrimitiveWrapper_i, b)->GetExpr		= GetExpr;

	b->_bool								= bl;

	b->Unpack								= Unpack;
	b->GetExpr								= GetExpr;
	b->Not									= Not;
	b->And									= And;
	b->Or									= Or;
	b->Xor									= Xor;
	b->Nand									= Nand;
	b->Nor									= Nor;

	return b;
}

method static Bool_t *New(bool bl) {
	return Bool.Init(new (Bool_t), bl);
}

method static void Delete(Bool_t *b) {
	if (b == NULL) return;

	delete (b);
}

_Bool_ Bool = {
	.Init		= Init,
	.New		= New,
	.Delete		= Delete,

	.Unpack		= Unpack,
	.GetExpr	= GetExpr,

	.Not		= Not,
	.And		= And,
	.Or			= Or,
	.Xor		= Xor,
	.Nand		= Nand,
	.Nor		= Nor,
};
