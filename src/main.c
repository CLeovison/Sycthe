#include <stdio.h>
#include "core/string/strings.h"

int main()
{
    String s2 = string_create("Hello");
    printf("%s\n", s2.data);

    String s3 = string_append(s2.data, " World   ");
    printf("[%s]\n", s3.data);

    String s4 = string_trim(s3.data);
    printf("[%s]\n", s4.data);
}