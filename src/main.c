#include <stdio.h>
#include "frontend/lexer.c"

int main(void)
{
    const char source[] = "abc";
    Lexer lexer = {0};
    lexer.sourceStart = source;

    lexer_init(&lexer);

    printf("Input: %s\n", source);
    printf("Starting position: %s\n", lexer.position);
    printf("At end initially: %s\n", isAtEnd(&lexer) ? "yes" : "no");

    while (!isAtEnd(&lexer)) {
        char ch = advance(&lexer);
        printf("Read character: %c\n", ch);
    }

    printf("At end now: %s\n", isAtEnd(&lexer) ? "yes" : "no");
    return 0;
}