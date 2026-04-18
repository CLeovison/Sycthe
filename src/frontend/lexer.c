#include "lexer.h"

const char *token_type_to_string(TokenType type)
{
    switch (type)
    {
        // Keywords
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
    case TOKEN_STRUCT:
        return "struct";
    case TOKEN_UNION:
        return "union";
    case TOKEN_CONTRACT:
        return "contract";
    case TOKEN_TRUE:
        return "true";
    case TOKEN_FALSE:
        return "false";

    // Identifiers
    case TOKEN_IDENTIFIERS:
        return "IDENTIFIERS";
    }
}