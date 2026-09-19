#include "lexer.h"
#include <stdbool.h>
void init_lexer()
{
    lexer.start = 1;
    lexer.position = 1;
}

// Returns the current character without consuming it
char peek()
{
}

/*
 Returns the character after the current one without advancing the lexer
*/
char peek_next()
{
}

void advance()
{
}

static bool match(char expected)
{
}

void skipWhitespace()
{
}

static void isKeywordIdentifier()
{
}

/*This check if it combines alphabet and number*/
static void isAlphaNum()
{
}

/*
This check if the token is digit / number
*/
static void isDigit()
{
}

/*
This check if the token is alphabet
*/
static void isAlpha()
{
}
