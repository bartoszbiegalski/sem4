////////////////////////////////////////////////////////////////////////////////
// File: symtbl_ads.cpp -- Symtbl interface routines
//
#include "symtbl.h"
// This file contains the create/copy/delete interface routines. Since
// they need to be able to access the C++ storage allocation mechanism,
// they are written in C++.
//
symtbl* symtbl_create(void)
{
 return new symtbl;
}
symtbl* symtbl_copy(symtbl* src)
{
 return new symtbl(*src);
}
void symtbl_destroy(symtbl* src)
{
 delete src;
}
