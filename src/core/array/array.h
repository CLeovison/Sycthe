#ifndef array_h
#define array_h
#include <stdlib.h>

typedef struct
{
    void *data;
    size_t item_size;
    size_t capacity;
    size_t length;
} DynamicArray;

void array_init();
DynamicArray array_push(); // Adding a single item
DynamicArray array_pop();  // Removing the Last Element
DynamicArray array_remove();

#endif