#ifndef lexer_h
#define lexer_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "token.h"
// Token Type of the Language

// Scanner: Explanation
typedef struct
{
    const char *start;
    const char *current;
    int line;
} Scanner;

Scanner scanner;

// Token: In Depth Explanation
typedef struct
{
    TokenType type;
    const char *start;
    size_t length;
    int line;
} Token;

void initScanner(const char *source);

Token scanToken();

#endif
