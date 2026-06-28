#ifndef lexer_h
#define lexer_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Token Type of the Language
typedef enum
{
    /// Keyword
    TOKEN_FUNCT,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_RANGE,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_BREAK,
    TOKEN_DEFAULT,
    TOKEN_RETURN,
    TOKEN_STRUCT,
    TOKEN_UNION,
    TOKEN_CONTRACT,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_DEFER,

    /// Literals
    /// Definition : a literal is a textual representation (notation) of a value as it is written in source code.
    TOKEN_IDENTIFIERS,
    TOKEN_STRING,
    TOKEN_NUMBER,

    // Single Character Token
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_OPEN_BRACE,
    TOKEN_CLOSE_BRACE,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_SEMICOLON,

    // One or Two Character Token
    TOKEN_BANG,
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,

    TOKEN_ERROR,
    TOKEN_EOF
} TokenType;

// Scanner: Explanation
typedef struct
{
    const char *start;
    const char *current;
    int line;
} Scanner;

Scanner scanner;

//Token: In Depth Explanation
typedef struct
{
    TokenType type;
    const char* start;
    int length;
    int line;
} Token;

void initScanner(const char *source);

Token scanToken();

#endif