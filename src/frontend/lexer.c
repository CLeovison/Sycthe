#include "lexer.h"
#include <stdbool.h>
#include <string.h>


void init_scanner(const char *src)
{
    scanner.start = src;
    scanner.position = src;
    scanner.line = 1;
}
Lexer scanLexer()
{
    scanner.start = scanner.position;
    if (isAtEnd())
    {
        return makeToken(TOKEN_EOF);
    }

    return errorToken("Unexpected Character");
}

static Lexer makeToken(TokenType type)
{
    Lexer lexer;

    lexer.type = type;
    lexer.start = scanner.start;
    lexer.line = scanner.line;
    lexer.length = (size_t)(scanner.position - scanner.start);

    return lexer;
}

static Lexer errorToken(const char *message)
{
    Lexer lexer;
    lexer.type = TOKEN_ERROR;
    lexer.start = message;
    lexer.length = (size_t)strlen(message);
    lexer.line = scanner.line;

    return lexer;
}