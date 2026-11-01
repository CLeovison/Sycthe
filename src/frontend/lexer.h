#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stddef.h>
typedef struct Lexer
{
    const char *start;    // Start of the token being scanned
    const char *position; // Next character to examine

    TokenType type;          // Kind of token currently being scanned
    const char *sourceStart; // Start of the source code being scanned
    size_t length;           // Length of the current token; defines its boundary along with 'start'
    size_t line;             // Line where the current token starts
    const char *semiColon;   // Source position for an inserted semicolon (if needed)
} Lexer;

Lexer error_token();
#endif
