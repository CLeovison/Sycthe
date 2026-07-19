#include "lexer.h"
#include <string.h>
void initScanner(const char *source)
{
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}


// '\0' represents a Null Terminator
// If the current character is the null byte, then we've reached the end.
static bool isAtEnd()
{
    return *scanner.current == '\0';
}

static char advance()
{
    scanner.current++;
    return scanner.current[-1];
}

static char peek()
{
    return *scanner.current;
}

static bool match(char expected)
{
    if (isAtEnd())
        return false;
    if (*scanner.current != expected)
        return false;
    scanner.current++;
    return true;
}


//This line of code represents the creation of token. The scanner's start and current pointers capture the token's lexeme. 
static Token makeToken(TokenType type)
{
    Token token;
    token.type = type;
    token.start = scanner.start;
    token.length = (int)(scanner.current - scanner.start);
    token.line = scanner.line;
    return token;
}

// This line of code represents an returning error tokens.
// This helper function is pointing the error message string instead of pointing to the user's source code.
static Token errorToken(const char *message)
{
    Token token;
    token.type = TOKEN_ERROR;
    token.start = message;
    token.line = (int)strlen(message);
    token.line = scanner.line;
    return token;
}

static void skipWhiteSpace()
{
    for (;;)
    {
        char c = peek();
        switch (c)
        {
        case ' ':
        case '\r':
        case '\t':
            advance();
            break;
        default:
            return;
        }
    }
}

Token scanToken()
{
    skipWhiteSpace();
    //Scanner.start represents a point to the current character where the lexeme scan starts
    scanner.start = scanner.current;

    //Check if the end of the source code has been reached, if it was reach EOF Token will be returned and stop
    if (isAtEnd())
        return makeToken(TOKEN_EOF);

    char c = advance();

    switch (c)
    {
    case '(':
        return makeToken(TOKEN_LEFT_PAREN);
    case ')':
        return makeToken(TOKEN_RIGHT_PAREN);
    case '{':
        return makeToken(TOKEN_OPEN_BRACE);
    case '}':
        return makeToken(TOKEN_CLOSE_BRACE);
    case ';':
        return makeToken(TOKEN_SEMICOLON);
    case ',':
        return makeToken(TOKEN_COMMA);
    case '.':
        return makeToken(TOKEN_DOT);
    case '-':
        return makeToken(TOKEN_MINUS);
    case '+':
        return makeToken(TOKEN_PLUS);
    case '/':
        return makeToken(TOKEN_SLASH);
    case '*':
        return makeToken(TOKEN_STAR);
    case '!':
        return makeToken(
            match('=') ? TOKEN_BANG_EQUAL : TOKEN_BANG);
    case '=':
        return makeToken(
            match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL);
    case '<':
        return makeToken(
            match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS);
    case '>':
        return makeToken(
            match('=') ? TOKEN_GREATER_EQUAL : TOKEN_GREATER);
    }

    return errorToken("Unexpected character.");
}

