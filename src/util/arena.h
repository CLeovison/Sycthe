#ifndef arena_h
#define arena_h

#include <stdio.h>

typedef struct RegionAllocator
{
    unsigned char *buffer;
    size_t buffer_length;
    size_t prev_offset;
    size_t curr_offset;
} Arena;

void *arena_alloc_allign(Arena *a, size_t size, size_t align);
void *arena_alloc(Arena *a, size_t size);
void arena_init(Arena *a, void *backing_buffer, size_t backing_buffer_len);
void arena_free(Arena *a, void *ptr);
void *arena_resize_alloc(Arena *a, void *old_memory, size_t new_size, size_t align);
void arena_free_all(Arena *a);

#endif