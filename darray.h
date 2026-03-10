#pragma once

#include <assert.h>
#include "alloc.h"

// Declaration: Defines the struct and prototypes.
#define DARRAY_DECLARE(T, PREFIX) \
typedef struct { \
    T* data; \
    int count; \
    int capacity; \
    allocator* alloc; \
} PREFIX##_darray; \
\
PREFIX##_darray PREFIX##_darray_create(allocator* alloc, int capacity); \
void PREFIX##_darray_reserve(PREFIX##_darray* a, int cap); \
void PREFIX##_darray_free(PREFIX##_darray* a);

// Inline Operations: Fast getters and mutation.
#define DARRAY_INLINE(T, PREFIX) \
static inline void PREFIX##_darray_push(PREFIX##_darray* a, T val) { \
    if (a->count == a->capacity) { \
        int new_cap = a->capacity < 2 ? 2 : a->capacity + (a->capacity >> 1); \
        PREFIX##_darray_reserve(a, new_cap); \
    } \
    a->data[a->count++] = val; \
} \
\
static inline T PREFIX##_darray_pop(PREFIX##_darray* a) { \
    assert(a->count > 0); \
    return a->data[--a->count]; \
} \
\
static inline void PREFIX##_darray_clear(PREFIX##_darray* a) { \
    a->count = 0; \
}


// Source: The heavy lifting (alloc/realloc).
#define DARRAY_SOURCE(T, PREFIX) \
PREFIX##_darray PREFIX##_darray_create(allocator* alloc, int capacity) { \
    PREFIX##_darray a = {0}; \
    a.alloc = alloc; \
    if (capacity > 0) { \
        a.data = (T*)alloc->alloc(alloc->ctx, sizeof(T) * capacity); \
        assert(a.data != NULL); \
        a.capacity = capacity; \
    } \
    return a; \
} \
\
void PREFIX##_darray_reserve(PREFIX##_darray* a, int cap) { \
    if (cap <= a->capacity) return; \
    T* new_data = (T*)a->alloc->realloc(a->alloc->ctx, a->data, sizeof(T) * cap); \
    assert(new_data != NULL); \
    a->data = new_data; \
    a->capacity = cap; \
} \
\
void PREFIX##_darray_free(PREFIX##_darray* a) { \
    if (a->data) { \
        a->alloc->free(a->alloc->ctx, a->data); \
    } \
    a->data = NULL; \
    a->count = 0; \
    a->capacity = 0; \
}
