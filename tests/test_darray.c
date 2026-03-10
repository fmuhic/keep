#include "../darray.h"
#include <stdio.h>
#include <assert.h>

DARRAY_DECLARE(int, int)
DARRAY_INLINE(int, int)
DARRAY_SOURCE(int, int)


void test_int_darray_lifecycle()
{
    printf("[TEST] Starting int_darray lifecycle test...\n");

    int_darray a = int_darray_create(&libc_allocator, 2);

    assert(a.data != NULL);
    assert(a.count == 0);
    assert(a.capacity == 2);

    printf(" - Creation OK\n");


    int_darray_push(&a, 10);
    int_darray_push(&a, 20);

    assert(a.count == 2);
    assert(a.data[0] == 10);
    assert(a.data[1] == 20);

    printf(" - Initial Pushes OK\n");


    int_darray_push(&a, 30);

    assert(a.count == 3);
    assert(a.capacity == 3);
    assert(a.data[2] == 30);

    printf(" - Resize OK (New capacity: %d)\n", a.capacity);


    int val = int_darray_pop(&a);

    assert(val == 30);
    assert(a.count == 2);

    printf(" - Pop OK\n");


    int_darray_clear(&a);

    assert(a.count == 0);
    assert(a.capacity == 3);

    printf(" - Clear OK\n");


    int_darray_free(&a);

    assert(a.data == NULL);
    assert(a.count == 0);
    assert(a.capacity == 0);

    printf(" - Free OK\n");
}


int main()
{
    test_int_darray_lifecycle();
    printf("\n--- All tests passed ---\n");
    return 0;
}
