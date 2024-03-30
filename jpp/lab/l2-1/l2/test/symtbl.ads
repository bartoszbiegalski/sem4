--------------------------------------------------------------------------------
-- File: symtbl.ads -- Ada interface spec. for C++ symtbl package.
--
WITH Interfaces.C;
PACKAGE symtbl IS
 -- Declare some useful types.
 --
 TYPE ste IS RECORD NULL; END RECORD; -- Dummy entry record
 TYPE ste_ptr IS ACCESS ste; -- Entry record pointer
 TYPE symtbl IS -- Table record
 RECORD
 howmany : INTEGER; -- How many in this table
 elements : ste_ptr; -- List head
 current : ste_ptr; -- Current element
 END RECORD;
 TYPE symtbl_ptr IS ACCESS symtbl; -- Table record pointer
 TYPE char_ptr IS NEW Interfaces.C.char_array; -- Pointer to C string
 -- Declare the create, copy and destroy interface functions. Note
 -- that in the following three PRAGMA IMPORTs, the second and third
 -- arguments are the same. This is just a convention and not a
 -- requirement.
 --
 FUNCTION symtbl_create RETURN symtbl_ptr;
 FUNCTION symtbl_copy(src : IN symtbl_ptr) RETURN symtbl_ptr;
 PROCEDURE symtbl_destroy(src : IN symtbl_ptr);
 PRAGMA IMPORT(CPP, symtbl_create, "symtbl_create");
 PRAGMA IMPORT(CPP, symtbl_copy, "symtbl_copy");
 PRAGMA IMPORT(CPP, symtbl_destroy, "symtbl_destroy");
 -- Declare the C++ member functions. These functions are accessed directly;
 -- i.e., there is no intermediate interface routine.
 --
 FUNCTION symtbl_add (this : IN symtbl_ptr;
 name : IN char_ptr;
 value : IN Interfaces.C.int) RETURN ste_ptr;
 FUNCTION symtbl_first(this : IN symtbl_ptr) RETURN ste_ptr;
 FUNCTION symtbl_next (this : IN symtbl_ptr) RETURN ste_ptr;
 FUNCTION symtbl_print(this : IN symtbl_ptr) RETURN ste_ptr;
 PRAGMA IMPORT(CPP, symtbl_add, "symtbl::add");
 PRAGMA IMPORT(CPP, symtbl_first, "symtbl::first");
 PRAGMA IMPORT(CPP, symtbl_next, "symtbl::next");
 PRAGMA IMPORT(CPP, symtbl_print, "symtbl::print");
END symtbl;
