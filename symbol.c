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

    strcpy(symtable[len].lexptr, s);
    symtable[len].token = tok;
    return len;
}
