#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <stdio.h>

typedef struct Lexer
{
    TokenType type;
    char *start;
    char position;
    size_t length;
} Lexer;

Lexer lexer;

#endif
