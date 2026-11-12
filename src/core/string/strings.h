#ifndef strings_h
#define strings_h

#include <stdbool.h>
#include "datatype.h"


typedef struct
{
    u8 *data;
    u64 length;
} String;



String string_init();
String string_create(const u8 src, u64 length);
String string_append(String s1, const u8 *data,  u64 length);
u64 string_length();
bool string_match(String s1, String s2);
String string_trim(String s1);



#endif