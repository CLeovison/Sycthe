#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frontend/lexer.h"

static char *readFile(const char *path)
{
    FILE *file = fopen(path, "rb");

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
}


int main(int argc, const char *argv[])
{
    return 0;
}