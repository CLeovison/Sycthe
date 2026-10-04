#include "strings.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void string_init(String *s)
{
    if (s == NULL)
    {
        return;
    }
    s->data = NULL;
    s->length;
}

String string_create(const char *src)
{
    String s;
    string_init(&s);

    if (src == NULL)
    {
        return s;
    }

    size_t len = strlen(src);
    char *buffer = malloc(len + 1);

    if (buffer == NULL)
    {
        return s;
    }

    memcpy(buffer, src, len + 1);
    s.data = buffer;
    s.length = len;

    return s;
}

String string_append(const char *s1, const char *s2)
{
    String s;
    string_init(&s);

    if (s1 == NULL || s2 == NULL)
    {
        return s;
    }

    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    size_t total_len = s1_len + s2_len;
    char *buffer = malloc(total_len + 1);

    if (buffer == NULL)
    {
        return s;
    }

    memcpy(buffer, s1, s1_len);
    memcpy(buffer + s1_len, s2, s2_len);
    buffer[total_len] = '\0';

    s.data = buffer;
    s.length = total_len;

    return s;
}

String string_trim(const char *src)
{
    String s;
    string_init(&s);

    if (src == NULL)
    {
        return s;
    }

    size_t len = strlen(src);
    size_t start = 0;
    size_t end = len;

    while (start < end && isspace((unsigned char)src[start]))
    {
        start++;
    }

    // pull end back past trailing whitespace
    while (end > start && isspace((unsigned char)src[end - 1]))
    {
        end--;
    }
    size_t trimmed_len = end - start;
    char *buffer = malloc(trimmed_len + 1);

    if (buffer == NULL)
    {
        return s;
    }

    memcpy(buffer, src + start, trimmed_len);
    buffer[trimmed_len] = '\0';

    s.data = buffer;
    s.length = trimmed_len;

    return s;
}