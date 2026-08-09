#include "lexer.h"

/**/
void init_lexer()
{
}

void advance()
{
}

static char peek()
{
    return *scanner.current;
}
void scan_keyword_identifier()
{
}

Scanner isString()
{
}

void isDigit()
{
}

void isAlpha()
{
}

void skipWhitespace()
{
    char c = peek();

    while (1)
    {
        switch (c)
        {
        case ' ':
        case '\r':
        case '\t':
            break;
        default:
            return;
        }
    }
}