#include "global.h"

int lookahead;
int lastentry = 0; 
void parse(FILE *input, FILE *output)
{ // Modified to take file input and output
    lookahead = lexan(input);
    while (lookahead != DONE)
    {
        expr_list(input, output); // Changed to call expr_list
        match(input, END);        // Match 'end' token
    }
}

void expr_list(FILE *input, FILE *output)
{                              // Added for expr_list production
    match(input, EXPRESSIONS); // Match 'expressions' token
    match(input, ID);          // Match identifier token
    match(input, '(');         // Match '(' token
    match(input, INFIX);       // Match 'infix' token
    match(input, ',');         // Match ',' token
    match(input, POSTFIX);     // Match 'postfix' token
    match(input, ')');         // Match ')' token
    match(input, BEGIN);       // Match 'begin' token
    expr(input, output);       // Call expr to parse expression
}

void expr(FILE *input, FILE *output)
{
    int t;
    term(input, output);
    while (1)
    {
        switch (lookahead)
        {
        case PLUS:
        case MINUS:
            t = lookahead;
            match(input,lookahead);
            term(input,output);
            emit(output,t, NONE);
            continue;
        default:
            return;
        }
    }
}

void term(FILE *input, FILE *output)
{ // Modified to take file input and output
    int t;
    factor(input, output);
    while (1)
    {
        switch (lookahead)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
        case BACKSLASH:
        case UNDERSCORE:

            t = lookahead;
            match(input,lookahead);
            factor(input,output);
            emit(output,t, NONE);
            continue;
        default:
            return;
        }
    }
}

void factor(FILE *input, FILE *output)
{  // Modified to take file input and output
    switch (lookahead)
    {
    case '(':
        match(input,'(');
        expr(input,output);
        match(input,')');
        break;
    case NUM:
        emit(output,NUM, tokenval);
        match(input,NUM);
        break;
    case ID:
        emit(output,ID, tokenval);
        match(input,ID);
        break;
    default:
        error("syntax error");
    }
}

void match(FILE *input, int t)
{
    if (lookahead == t)
    {
        lookahead = lexan(input); // Changed to lexan(input) to read from file
    }
    else
    {
        error("syntax error");
    }
}

void freeSymbolTable() {
    for (int i = 0; i <= lastentry; ++i) {
        free(symtable[i].lexptr);
    }
}