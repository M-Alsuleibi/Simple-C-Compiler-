#include "global.h"

int tokenval = NONE;
int lineno = 1;
struct entry symtable[BSIZE];
char lexbuf[BSIZE];


int lexan(FILE *input)
{
    int t;
    while (1)
    {
        t = getc(input);
        if (t == ' ' || t == '\t')
        {
            ; // strip out white space
        }
        else if (t == '\n')
        {

            lineno = lineno + 1;
        }
        else if (t == '#')
        {
            while (t != '\n' && t != DONE)
            {
                t = getchar();
            }
        }
        else if (isdigit(t))
        {
            // t is a digit
            ungetc(t, stdin);
            fscanf(input, "%d", &tokenval); // Use fscanf instead of scanf
            return NUM;
        }
        else if (isalpha(t))
        {
            // t is a letter
            int p, b = 0;
            while (isalnum(t))
            {
                // t is alphanumeric
                lexbuf[b] = t;
                t = getchar();
                b = b + 1;
                if (b >= BSIZE)
                {
                    error("compiler error");
                }
            }
            lexbuf[b] = EOS;
            if (t != EOF)
            {
                ungetc(t, stdin);
            }
            p = lookup(lexbuf);
            if (p == 0)
            {
                p = insert(lexbuf, ID);
            }
            tokenval = p;
            return symtable[p].token;
        }
        else if (t == EOF)
        {
            return DONE;
        }
        else
        {
            tokenval = NONE;
            return t;
        }
    }
}
