#ifndef lexer_h
#define lexer_h

#include "token.h"
#include <stdio.h>

// Macros
#define peek(x) (*(x)->position)
#define peek_next(x) ((x)->position[1])

/*So the Scanner struct handles raw characters and groups them into lexemes,
but it doesn't understand program structure which means it didn't really care how you're Tokens relate to each other
— that's the parser's job*/

typedef struct Scanner
{
    // The start pointer marks the beginning of the current lexeme being scanned
    const char *start;

    // The position points to the current character being looked at.
    const char *position;

    // A line field to track what line the current lexeme is on for error reporting
    int line;
} Scanner;

/*So the Lexer struct stores the token that was scanned from the source code.
It does not parse the full program structure, it only represents one meaningful token at a time.

Example is:
int a = 3;

So this can be represented as:
TOKEN_INT   -> "int"
TOKEN_IDENT -> "a"
TOKEN_EQUAL -> "="
TOKEN_NUM   -> "3"
TOKEN_SEMI  -> ";"
*/

typedef struct Lexer
{
    TokenType type;

    /* Points to the first character of this token's lexeme in the source code*/
    const char *start;

    /* length = number of characters in the lexeme.
       The token points into the source, so there is no '\0' at the end —
       length tells us where the lexeme stops.

       Example:  let user = "String"
                     ^
                     start points at 'u', length = 4  →  lexeme is "user"
    */
    size_t length;

    // So the purpose of using line is to identify whether which line is incorrect during the scanning of the lexer
    size_t line;
} Lexer;

extern Scanner scanner;
extern Lexer lexer;

void init_lexer(const char *src);
char advance(Lexer *lexer);
Lexer scanLexer();

#endif
