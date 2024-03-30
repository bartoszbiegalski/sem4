////////////////////////////////////////////////////////////////////////////////
// File: symtbl.h -- Interface for symbol table class
//
class symtbl; ////////// Symbol table class
class ste; ////////// Symbol table entry
class symtbl // Symbol Table
{
public: // Everything is public for this example
 int howmany; // Number of elements in the list
 ste* elements; // List head pointer
 ste* current; // The "current" table element
 symtbl(); // Default constructor
 symtbl(const symtbl&); // Copy constructor
 ~symtbl(); // Destructor
 ste* add(char* name, int value); // Add an element to a table
 ste* first(void); // Find the first element of a table
 ste* next(void); // Find the successor element
 ste* print(void); // Print the current element of a table
};
class ste // Symbol Table Entry
{
public: // Everything is public for this example
 ste* link; // Elements are linked in a list
 char* namestring; // Pointer to the name string
 int value; // Associated value
 ste(); // Default constructor
 ste(const ste&); // Copy constructor
 ste(char* name, int value); // Normal constructor
 ~ste(); // Destructor
};
