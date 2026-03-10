#pragma once
#include <stdlib.h>

typedef struct allocator {
    void* (*alloc)(void* ctx, size_t size);
    void* (*realloc)(void* ctx, void* ptr, size_t size);
    void  (*free)(void* ctx, void* ptr);
    void* ctx;
} allocator;


static void* libc_alloc(void* ctx, size_t size)
{
    (void)ctx;
    return malloc(size);
}

static void* libc_realloc(void* ctx, void* ptr, size_t size)
{
    (void)ctx;
    return realloc(ptr, size);
}

static void libc_free(void* ctx, void* ptr)
{
    (void)ctx;
    free(ptr);
}

static allocator libc_allocator = {
    libc_alloc,
    libc_realloc,
    libc_free,
    NULL
};
