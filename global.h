#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

// New token types
#define EXPRESSIONS 261
#define INFIX 262
#define POSTFIX 263
#define BEGIN 264
#define END 265
#define TIMES 266
#define PLUS 267
#define MINUS 268
#define BACKSLASH 269
#define UNDERSCORE 270
#define COMMENT 271

// Term Project – Sub-Pascal Compiler - tokens
#define INPUT 266
#define OUTPUT 267
#define CONST 268
#define VAR 269
#define EPSILON 270
#define INTEGER 271
#define REAL 272
#define CHAR 273
#define BOOLEAN 274
#define IF 275
#define THEN 276
#define REPEAT 277
#define WHILE 278
#define DO 279
#define WRITELN 280
#define UNTIL 281
#define NOT 282
#define GREATEREQUAL 283 //>=
#define LESSEQUAL 284    //<=
#define NOTEQUAL 285     //<>
#define OR 286
#define AND 287
#define ELSE 288
// Function prototypes
int lookup(char *s);
int insert(char *s, int tok);
int lexan(FILE *input); // Modified to take file input

extern int tokenval;
extern int lineno;

struct entry
{
    char *lexptr;
    int token;
};

extern struct entry symtable[];

extern char lexbuf[];
extern int lastentry;

// Function prototypes for parsing
void parse(FILE *input, FILE *output);     // Modified to take file input and output
void expr_list(FILE *input, FILE *output); // Added for expr_list production
void expr(FILE *input, FILE *output);      // Modified to take file input and output
void term(FILE *input, FILE *output);      // Modified to take file input and output
void factor(FILE *input, FILE *output);    // Modified to take file input and output
void match(FILE *input, int t);            // Modified to take file input
void emit(FILE *output, int t, int tval);  // Modified to take file output
void error(char *msg);

void freeSymbolTable();


#endif
