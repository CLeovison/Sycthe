#ifndef token_h
#define token_h

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
    TOKEN_ENUM,
    //Boolean
    TOKEN_TRUE,
    TOKEN_FALSE,

    //Refers to Defer in Some Language
    TOKEN_LATER,
    TOKEN_WHEN,
    
    //String Interpolation
    TOKEN_INTERP_START,
    TOKEN_INTERP_END

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

#endif