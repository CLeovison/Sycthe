#include "lexer.h"
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


void init_scanner(const char *src)
{
    scanner.start = src;
    scanner.position = src;
    scanner.line = 1;
}
static bool isAtEnd()
{
    return *scanner.position == '\0';
}

/*advance consumes one character by moving the cursor forward, then returns the consumed character using scanner.position[-1].
scanner.position always points to the next unread character, so [-1] means one character back, which is the one just consumed.

Example with int c = 5;:

advance reads i, n, t → lexer groups them as "int" → emits TOKEN_INT
reads c → emits TOKEN_IDENTIFIER
reads = → emits TOKEN_EQUAL
reads 5 → emits TOKEN_NUMBER
reads ; → emits TOKEN_SEMICOLON
*/
static char advance()
{
    scanner.position++;
    return scanner.position[-1];
}

// static gives makeToken internal linkage, so it is visible only inside this source file and cannot be called from other .c files.
// makeToken builds a Lexer token from the current scanner state by setting its type, start position, line, and length.
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

Lexer scanLexer()
{
    scanner.start = scanner.position;
    if (isAtEnd())
    {
        return makeToken(TOKEN_EOF);
    }

    char c = advance();

    switch (c)
    {
    case '(':
        return makeToken(TOKEN_LEFT_PAREN);
    case ')':
        return makeToken(TOKEN_RIGHT_PAREN);
    case '{':
        return makeToken(TOKEN_RBRACKET);
    case '}':
        return makeToken(TOKEN_LBRACKET);
    }
    return errorToken("Unexpected Character");
}
 
static int64_t scanUTF8(){
    
    
}