#include "global.h"

struct entry keywords[] = {
    {"div", DIV},
    {"mod", MOD},
    "BEGIN", BEGIN,
    "END", END,
    "Input", INPUT,
    "Output", OUTPUT,
    "CONST", CONST,
    "VAR", VAR,
    "integer", INTEGER,
    "real", REAL,
    "char", CHAR,
    "IF", IF,
    "THEN", THEN,
    "WHILE", WHILE,
    "REPEAT", REPEAT,
    "UNTIL", UNTIL,
    "DO", DO,
    "WRITELN", WRITELN,
    ">=", GREATEREQUAL,
    "<=", LESSEQUAL,
    "<>", NOTEQUAL,
    "ELSE", ELSE,
    "OR", OR,
    "not", NOT,
    "AND", AND,
    {0, 0}};

void init()
{
    struct entry *p;
    for (p = keywords; p->token; p++)
    {
        insert(p->lexptr, p->token);
    }
}
