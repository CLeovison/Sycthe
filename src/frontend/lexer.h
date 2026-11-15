#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "../core/datatype.h"
#include <stdbool.h>
/*
 * The lexer walks through the source as it looks for tokens.
 * `start` marks the token it's reading; `position` points to the next byte
 * to check.
 */
typedef struct
{
    const u8 *start;    /* Beginning of the token being scanned. */
    const u8 *position; /* Next byte the lexer will examine. */
    const u8 *end;      /* One byte past the end of the source. */
    size_t line;        /* Current line number, starting at 1. */
    bool endLine;       /* Set when the lexer reaches a line break. */
} Lexer;

/*
 * A token is one piece of source code, like a name, number, or operator.
 * `start` and `length` point back to the text it came from.
 */
typedef struct
{
    TokenType type; /* What kind of token this is, such as a name or number. */
    const u8 *start; /* Where this token begins in the source. */
    size_t length; /* How many bytes of source text this token covers. */
    size_t line; /* Line where this token starts. */
} Token;

#endif