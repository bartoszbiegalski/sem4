////////////////////////////////////////////////////////////////////////////////
// File: cppmain.cpp -- Symbol table test driver
//
#include <stdlib.h>
#include <iostream.h>
#include "symtbl.h"
char* input[] =
{
 "the","boy","stood","on","the","burning","deck,",
 "eating","peanuts","by","the","peck.", NULL
};
main()
{
 symtbl mytbl;
 int i = 0;
 for(char** p = input; *p; ) mytbl.add(*p++, i+=1);
 cout << "cppmain -- C++ test driver for C++ symtbl package\n"
 << "The number of items in this table is: "
 << mytbl.howmany << endl;
 for(mytbl.first(); mytbl.print(); mytbl.next()) ;
}
