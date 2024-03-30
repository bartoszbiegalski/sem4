////////////////////////////////////////////////////////////////////////////////
// File: symtbl.cpp -- Body for symbol table class
//
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include "symtbl.h"
// class ste member functions.
//
ste::ste() // Default constructor
{
 link = NULL; // Init the link
 namestring = new char[10]; // Allocate memory
 if(namestring) // Default string
 strcpy(namestring, "$DEFAULT$");
 value = 0; // Default value
}
ste::ste(const ste& src) // Copy constructor
{
 link = NULL; // Init the link
 namestring = // Allocate memory
 new char[strlen(src.namestring)+1];
 if(namestring) // Copy the string
 strcpy(namestring, src.namestring);
 value = src.value; // Default value
}
ste::ste(char* nam, int val) // Normal constructor
{
 link = NULL; // Init the link
 namestring = new char[strlen(nam)+1]; // Allocate memory
 if(namestring) strcpy(namestring, nam); // Copy the string
 value = val; // Save the value
}
ste::~ste() // Destructor
{
 delete namestring; // Delete the string’s memory
}
// class symtbl member functions
//
symtbl::symtbl() // Default constructor
{
 howmany = 0; // No elements in the table
 elements = NULL; // Element list is empty
 current = NULL; // No current element
}
symtbl::symtbl(const symtbl& src) // Copy Constructor
{
 ste* p = src.elements; // Get listhead from src
 while(p) // While something to do...
 {
 add(p->namestring, p->value); // Add this new element
 p = p->link; // Point at the next one
 }
}
symtbl::~symtbl() // Destroy the table
{
 while(elements) // Something is in the list...
 {
 ste* p = elements->link; // Get a pointer to next one
 delete elements; // Delete this element
 elements = p;
 }
}
ste* symtbl::add(char *nam, int val)
{
 ste* p = elements; // Get a pointer to the list
 ste* q = NULL; // Get a place to save the end
 while(p) // Go look for it
 {
 if(strcmp(p->namestring, nam) == 0) // Already here
 return NULL;
 q = p; // Remember this pointer
 p = p->link; // Link to the next one
 }
 p = new ste(nam, val); // Make a new one
 if(q) // Something already on list
 q->link = p; // Put this new one on too
 else // Nothing is on the list
 elements = p; // Make this new one first
 howmany += 1; // Show one more in the list
 return current = p; // Make this new one current
}
ste* symtbl::first(void)
{
 return current = elements; // Make list head current
}
ste* symtbl::next(void)
{
 if(current) current = current->link; // Return next element pointer
 return current;
}
ste* symtbl::print(void)
{
 if(current) // Only if current exists
 {
 cout << ’<’ << current->value << "> ";
 cout << current->namestring;
 cout << endl;
 }
 return current;
}
