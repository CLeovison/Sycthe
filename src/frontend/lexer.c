#include "lexer.h"

static void lexer_init(Lexer *lexer)
{
    lexer->start = lexer->sourceStart;
    lexer->position = lexer->sourceStart;
    lexer->length = 0;
    lexer->currentRow = 1; 
    lexer->semiColon = NULL;
}


