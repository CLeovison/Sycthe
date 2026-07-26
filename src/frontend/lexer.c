#include "lexer.h"
#include "token.h"
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
static bool isAlpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

/*
    Checks whether a character is a digit (0-9).
    Instead of writing a switch case for every digit,
    we can perform a simple range check here.
*/
static bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

/* ' \0 ' represents a Null Terminator
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

/*
    If the current character is the desired one, we advance and return true. Otherwise, we return false to indicate it wasn’t matched.
*/
static bool match(char expected)
{
    if (isAtEnd())
        return false;
    if (*scanner.current != expected)
        return false;
    scanner.current++;
    return true;
}

/*
 This line of code represents the creation of token. The scanner's start and current pointers capture the token's lexeme.
*/
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

/*
    This is like peek() but for one character past the current one. If the current character and the next one are both /,
    we consume them and then any other characters until the next newline or the end of the source code.

    We use peek() to check for the newline but not consume it. That way, the newline will be the current character on the
    next turn of the outer loop in skipWhitespace() and we’ll recognize it and increment scanner.line.
*/
static char peekNext()
{
    if (isAtEnd())
    {
        return 0;
    }
    return scanner.current[1];
}

/*
    Consumes `steps` characters at once. A wrapper around advance()
    so stepping over a known delimiter (like a comment opener) reads
    as one clear action instead of repeated advance() calls.

    Goes through advance() rather than bumping the pointer directly,
    so any future bookkeeping (line/column tracking) still happens.

    Only call this after peeking — the next `steps` characters must
    exist, or we'd walk past the '\0' terminator.
*/

static void skip(int steps)
{
    for (int i = 0; i < steps; i++)
    {
        advance();
    }
}

/* Line comment: consume up to (not including) the newline,
   so skipWhiteSpace can count the line. */
static void skipLineComment()
{
    while (peek() != '\n' && !isAtEnd())
    {
        advance();
    }
}

/*
    Skips a block comment, from the opening "/ *" to its matching
    "* /" (spaced so this comment doesn't end itself).

    A counter tracks nesting: "/ *" increments, "* /" decrements,
    done when it hits zero. Newlines still bump scanner.line.
    If the comment is unterminated, we stop at EOF.
*/
static void skipBlockComment()
{
    skip(2);
    int nesting = 1;

    while (nesting > 0)
    {
        if (isAtEnd())
        {
            return;
        }

        if (peek() == '/' && peekNext() == '*')
        {
            skip(2);
            nesting++;
        }
        else if (peek() == '*' && peekNext() == '/')
        {
            skip(2);
            nesting--;
        }
        else
        {
            if (peek() == '\n')
            {
                scanner.line++;
            }
            advance();
        }
    }
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
        case '/':
            if (peekNext() == '/')
            {
                skipLineComment();
            }
            else if (peekNext == '*')
            {
                skipBlockComment();
            }
            else
            {
                return;
            }
            break;
        default:
            return;
        }
    }
}

Token scanToken()
{
    skipWhiteSpace();
    // Scanner.start represents a point to the current character where the lexeme scan starts
    scanner.start = scanner.current;

    // Check if the end of the source code has been reached, if it was reach EOF Token will be returned and stop
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
    case '&':
        return match('&') ? makeToken(TOKEN_AND) : makeToken(TOKEN_AMP);
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
