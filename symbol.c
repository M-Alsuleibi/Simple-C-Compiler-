#include "global.h"

int lookup(char *s)
{
    int p;

    for (p = BSIZE - 1; p >= 0; p--)
    {
        if (strcmp(symtable[p].lexptr, s) == 0)
            return p;
    }
    return 0;
}

int insert(char *s, int tok)
{
    int len = strlen(s);
    if (len + 1 >= BSIZE)
        error("lexemes array full");

    symtable[lastentry].lexptr = malloc(len + 1); // Allocate memory for lexptr
    if (symtable[lastentry].lexptr == NULL) {
        error("memory allocation failed"); // Handle allocation failure
    }
    
    strcpy(symtable[lastentry].lexptr, s); // Copy the string into lexptr
    symtable[lastentry].token = tok;
    return lastentry;
}
