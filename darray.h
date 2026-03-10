#ifndef MY_LIB_H
#define MY_LIB_H

/**
 * HEADER SECTION
 * This part is visible to everyone who includes the file.
 */

#ifdef __cplusplus
extern "C" {
#endif

// Example function: Adds two integers
int my_lib_add(int a, int b);

// Example function: Returns the square of an integer
int my_lib_square(int x);

#ifdef __cplusplus
}
#endif

#endif // MY_LIB_H

/**
 * IMPLEMENTATION SECTION
 * This part is only compiled in ONE .c file where 
 * #define MY_LIB_IMPLEMENTATION is written before the include.
 */
#ifdef MY_LIB_IMPLEMENTATION

int my_lib_add(int a, int b) {
    return a + b;
}

int my_lib_square(int x) {
    return x * x;
}

#endif // MY_LIB_IMPLEMENTATION
