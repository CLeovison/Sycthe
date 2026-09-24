#indef STRING_H
#define STRING_H

#include <stddef.h>

typedef struct{
  char *type;
  size_t length;
  size_t capacity;
}String;

#endf 
