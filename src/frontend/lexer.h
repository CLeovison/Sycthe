#ifndef lexer_h
#define lexer_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Token Type of the Language
typedef enum
{
    //Modules

    TOKEN_ACCESS,
    TOKEN_SCOPE,
    /// Keyword
    TOKEN_PROC,
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
    TOKEN_LATER,
    TOKEN_WHEN,
    TOKEN_ENUM,


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
    TOKEN_AMP,
    TOKEN_BIT_OR,
    TOKEN_BANG,
    TOKEN_EQUAL,
    TOKEN_GREATER,
    TOKEN_LESS,

    // Two Character Token
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS_EQUAL,
    
    //Logical Operator
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NOT,

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

// Token: In Depth Explanation
typedef struct
{
    TokenType type;
    const char *start;
    int length;
    int line;
} Token;

void initScanner(const char *source);

Token scanToken();

#endif
