#include "lexer.h"
#include <stdbool.h>

static void lexer_init(Lexer *lexer)
{
    lexer->start = lexer->sourceStart;
    lexer->position = lexer->sourceStart;
    lexer->length = 0;
    lexer->currentRow = 1;
    lexer->semiColon = NULL;
}

static bool isAtEnd(Lexer *lexer)
{
    return *lexer->position == '\0';
}

static char advance(Lexer *lexer)
{
    lexer->position++;
    return lexer->position[-1];
}