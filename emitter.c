#include "global.h"

void emit(FILE *output, int t, int tval)
{
    switch (t)
    {
    case PLUS:
    case MINUS:
    case '*':
    case '/':
    case DIV:
    case MOD:
    case BACKSLASH:
    case UNDERSCORE:
        if (fprintf(output, "%c\n", t) < 0)
        {
            perror("Error writing to output file");
            exit(EXIT_FAILURE);
        }
        break;
    case NUM:
        if (fprintf(output, "%d\n", tval) < 0)
        {
            perror("Error writing to output file");
            exit(EXIT_FAILURE);
        }
        break;
    case ID:
        if (fprintf(output, "%s\n", symtable[tval].lexptr) < 0)
        {
            perror("Error writing to output file");
            exit(EXIT_FAILURE);
        }
        break;
    default:
        if (fprintf(output, "token %d, tokenval %d\n", t, tval) < 0)
        {
            perror("Error writing to output file");
            exit(EXIT_FAILURE);
        }
    }
}