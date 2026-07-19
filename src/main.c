#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frontend/lexer.h"

int main(void)
{
    const char *source = "proc add(a, b) { return a + b; }";

    initScanner(source);

    for (;;)
    {
        Token token = scanToken();
        // %.*s prints 'length' chars starting at 'start' (lexemes aren't null-terminated!)
        printf("line %d  type %2d  '%.*s'\n",
               token.line, token.type, token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }

    return 0;
}