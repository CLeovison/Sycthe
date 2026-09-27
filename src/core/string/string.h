#ifndef string_h
#define string_h

#include <stddef.h>
#include <stdbool.h>
typedef struct
{
    char *data;
    size_t length;
} String;


String string_create();
String string_trim();
String string_concat();

bool string_append();
bool string_match();
size_t string_length();

void string_to_upper();
void string_to_lower();
void string_free();
#endif