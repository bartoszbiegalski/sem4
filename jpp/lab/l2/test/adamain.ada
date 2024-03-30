WITH text_io;
WITH symtbl; USE symtbl;
with interfaces.c; use interfaces.c;
PROCEDURE symtbl_main IS
 PROCEDURE cpp_Initialization;
 PRAGMA IMPORT(C, cpp_Initialization, "_main");
 pt_my_table : symtbl_ptr; -- Ptr to a table
 tmp : ste_ptr; -- Ptr to a table entry
BEGIN
 cpp_Initialization;
 text_io.put_line("adamain -- Ada test driver for C++ symtbl package");
 -- Create a table
 --
 pt_my_table := symtbl_create;
 -- Add a bunch of entries
 --
 tmp := symtbl_add(pt_my_table, TO_C("the"), 1);
 tmp := symtbl_add(pt_my_table, TO_C("boy"), 2);
 tmp := symtbl_add(pt_my_table, TO_C("stood"), 3);
 tmp := symtbl_add(pt_my_table, TO_C("on"), 4);
 tmp := symtbl_add(pt_my_table, TO_C("the"), 5);
 tmp := symtbl_add(pt_my_table, TO_C("burning"), 6);
 tmp := symtbl_add(pt_my_table, TO_C("deck,"), 7);
 tmp := symtbl_add(pt_my_table, TO_C("eating"), 8);
 tmp := symtbl_add(pt_my_table, TO_C("peanuts"), 9);
 tmp := symtbl_add(pt_my_table, TO_C("by"), 10);
 tmp := symtbl_add(pt_my_table, TO_C("the"), 11);
 tmp := symtbl_add(pt_my_table, TO_C("peck."), 12);
 -- Print out the table.
 --
 text_io.put("The number of items in this table is:");
-- text_io.put(INTEGER’IMAGE(pt_my_table.howmany));
 text_io.new_line;
 tmp := symtbl_first(pt_my_table);
 WHILE(tmp /= NULL) LOOP
 tmp := symtbl_print(pt_my_table);
 tmp := symtbl_next (pt_my_table);
 END LOOP;
 -- Clean up.
 --
 symtbl_destroy(pt_my_table); -- Destroy my table
END symtbl_main;
