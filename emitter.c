#include "global.h"

void emit(FILE *output,int t, int tval)
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
        fprintf(output,"%c\n", t); // Changed to fprintf(output, ...) to write to file
        break;
    // case DIV:
    //     fprintf("DIV\n"); 
    //     break;
    // case MOD:
    //     fprintf("MOD\n");
    //     break;
    case NUM:
        fprintf(output,"%d\n", tval); // Changed to fprintf(output, ...) to write to file
        break;
        break;
    case ID:
        fprintf(output,"%s\n", symtable[tval].lexptr); // Changed to fprintf(output, ...) to write to file
        break;

    default:
        fprintf(output,"token %d, tokenval %d\n", t, tval); // Changed to fprintf(output, ...) to write to file
    }
}
