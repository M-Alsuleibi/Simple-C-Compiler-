#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BSIZE 128
#define NONE -1
#define Eos '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

extern int tokenval;
extern int lineno;

struct entry {
    char lexptr[BSIZE];
    int token;
};

extern struct entry symtable[];

int lexan();
void error(char *msg);
void emit(int t, int tval);
int lookup(char s[]);
int insert(char s[], int tok);
void init();
void parse();
void expr();
void term();
void factor();
void match(int t);

#endif
