#ifndef strings_h
#define strings_h

#include <stddef.h>
#include <stdbool.h>



/*
 * Immutable string type.
 *
 * Every String owns its own heap buffer, so you can pass them around
 * without worrying about who the memory belongs to. Nothing here ever
 * modifies an input string - you always get a fresh copy back.
 *
 * If something goes wrong (NULL input, malloc fails) you get an empty
 * string back: data == NULL, length == 0. So check data before using it.
 *
 */
typedef struct
{
    char *data;    /* NUL-terminated, malloc'd */
    size_t length; /* not counting the '\0' */
} String;

/* Reset to empty. Doesn't free anything - use string_free for that. */
void string_init(String *s);

/* Make a String from a C string. Copies, doesn't borrow. */
String string_create(const char *src);

/* Copy of src with whitespace stripped from both ends. */
String string_trim(const char *src);

/* s1 + s2 glued together into a new string. */
String string_append(const char *s1, const char *s2);

bool string_match();
size_t string_length(String *s);

void string_to_upper();
void string_to_lower();
void string_free();

#endif