#include <stdio.h>

//Find utput of following code.

int main() {
    int *ptr;
    int  x;

    ptr = &x; *ptr = 0;

    printf("x = %d\n", x);
    printf("ptr = %p\n", (void*)ptr);
    printf("*ptr = %d\n\n", *ptr);

    *ptr = 5;
    printf("x = %d\n", x);
    printf("ptr = %p\n", (void*)ptr);
    printf("*ptr = %d\n\n", *ptr);

    (*ptr)++;
    printf("x = %d\n", x);
    printf("ptr = %p\n", (void*)ptr);
    printf("*ptr = %d\n\n", *ptr);

    return 0;
}