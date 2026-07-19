#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int *items;
    size_t length;
    size_t capacity;
} Array;

int main()
{

    Array array = {0};

    for (int i = 0; i < 10; ++i)
    {

        if (array.length >= array.capacity)
        {
            if (array.capacity == 0)
                array.capacity = 256;
            else
                array.capacity *= 2 ;

            array.capacity = array.capacity * 2;
            array.items = realloc(array.items, array.capacity * sizeof(*array.items));
        }
        array.items[array.length++] = i;
    }

    for (size_t i = 0; i < array.length; ++i)
        printf("%d\n", array.items[i]);
    return 0;
}