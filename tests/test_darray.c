// This define triggers the implementation in the header
#define MY_LIB_IMPLEMENTATION
#include "../darray.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_math_logic() {
    printf("Testing my_lib_add...");
    assert(my_lib_add(10, 5) == 15);
    printf(" OK\n");

    printf("Testing my_lib_square...");
    assert(my_lib_square(4) == 16);
    printf(" OK\n");
}

int main() {
    printf("Starting Unit Tests...\n");
    
    test_math_logic();
    
    printf("\nAll tests passed successfully!\n");
    return EXIT_SUCCESS;
}
