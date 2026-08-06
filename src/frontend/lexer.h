#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <stdio.h>

typedef struct{
    const char start;
    const char current;
    int line;
} Scanner;


#endif
