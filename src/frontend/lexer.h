#ifndef lexer.h
#define lexer .h

typedef enum
{
    token_identifiers,
    token_operators,
    token_constants,
    token_keywords,
    token_literals,
    token_seperators,
    token_special_characters
} TokenType;

struct Lexeme
{
    TokenType token;
    char *lexeme;
    int line;
};
#endif