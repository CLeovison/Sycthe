#include "lexer.h"
#include <string.h>

/*
    Initializes the scanner state for tokenizing the source code.
    Sets the start and current pointers to the beginning of the
    source string and resets the line counter to 1.
*/
void initScanner(const char *source)
{
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

/*
    Checks whether a character is a letter (A-Z, a-z) or an underscore (_).
    This is used when scanning identifiers, since identifiers typically
    start with a letter or underscore.
*/
static bool isAlpha(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

/*
    Checks whether a character is a digit (0-9).
    Instead of writing a switch case for every digit,
    we can perform a simple range check here.
*/
static bool isDigit(char c){
    return c >= '0' && c <= '9';
}

/* '\0' represents a Null Terminator
    If the current character is the null byte, then we've reached the end.
*/
static bool isAtEnd()
{
    return *scanner.current == '\0';
}

/*  So this line of code represents reading a next character from the source code,
    then checks if it matches any of the one-character lexems or TokenType, To read
    the new character, we will use a helper that will consume the current character and returns it
*/ 
static char advance()
{
    scanner.current++;
    return scanner.current[-1];
}

/*
    Looks at the current character without moving the scanner forward.
    
    Think of it as "peeking" ahead so we know what's coming. For example, 
    we can check if the next character is whitespace before deciding 
    whether to skip it or let the token scanner handle it.
*/
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

/*
    Creates an error token containing the provided error message.
    Instead of pointing into the source code, the token's start
    pointer references the error message string directly.
*/
static Token errorToken(const char *message)
{
    Token token;
    token.type = TOKEN_ERROR;
    token.start = message;
    token.length = (int)strlen(message);
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
        case '\n':
            scanner.line++;
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
    case ',':
        return makeToken(TOKEN_COMMA);
    case '.':
        return makeToken(TOKEN_DOT);
    case '+':
        return makeToken(TOKEN_PLUS);
    case '-':
        return makeToken(TOKEN_MINUS);
    case '*':
        return makeToken(TOKEN_STAR);
    case '/':
        return makeToken(TOKEN_SLASH);
    case ';':
        return makeToken(TOKEN_SEMICOLON);
    case '&' :
        return match('&') ?makeToken(TOKEN_AND) : makeToken(TOKEN_AMP);
    case '!':
        return makeToken(match('=') ? TOKEN_BANG_EQUAL : TOKEN_BANG);
    case '=':
        return makeToken(match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL);
    case '>':
        return makeToken(match('=') ? TOKEN_GREATER_EQUAL : TOKEN_GREATER);
    case '<':
        return makeToken(match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS);
   
    }

    return errorToken("Unexpected character.");
}

