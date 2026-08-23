#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <stdio.h>

typedef struct Lexer
{
    TokenType type;
    char *start;
    const char position;
    
} Lexer;

#endif
