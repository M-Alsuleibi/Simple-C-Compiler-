// #ifndef GLOBAL_H
// #define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define PROGRAM 259

#define ID 264
#define DONE 260
#define INFIX 260
#define POSTFIX 261
#define BEGIN 262
#define END 263

extern int tokenval;
extern int lineno;

struct entry {
    char *lexptr;
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

// #endif
