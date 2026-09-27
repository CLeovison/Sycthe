#include "string.h"
#include <stdlib.h>

String string_create()
{
    String string;
    string.data = malloc(sizeof *string.data);
    string.length = 0;

    if (string.data != NULL)
    {
        string.data[0] = '\0';
    }
    return string;
}