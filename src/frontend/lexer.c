#include "lexer.h"

const char *token_type_to_string(TokenType type)
{
    switch (type)
    {
    case TOKEN_FUNCT:
        return "funct";
    case TOKEN_IF:
        return "if";
    case TOKEN_ELSE:
        return "else";
    case TOKEN_FOR:
        return "for";
    case TOKEN_WHILE:
        return "while";
    case TOKEN_DO:
        return "do";
    case TOKEN_SWITCH:
        return "switch";
    case TOKEN_CASE:
        return "case";
    case TOKEN_BREAK:
        return "break";
    case TOKEN_DEFAULT:
        return "default";
    case TOKEN_RETURN:
        return "return";
    }
}