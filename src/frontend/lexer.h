#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <stdio.h>

typedef struct Lexer
{
    TokenType type;
    char *start;
    char position;

} Lexer;

Lexer lexer;

#endif
