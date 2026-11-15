#ifndef LEXER_H
#define LEXER_H

#include "../core/datatype.h"
#include <stdbool.h>
#include "token.h"
typedef struct 
{
    const u8 *start;
    const u8 *position;
    bool endline;
    size_t line;
}Scanner;


typedef struct{
    const u8 *start;
    TokenType type;
    size_t line;
    size_t length;
}Lexer;

#endif
