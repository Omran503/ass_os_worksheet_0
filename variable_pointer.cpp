#include <stdio.h>

int main() {
    int n = 5;                 // Declare and initialize a local variable
    int *ptr_to_n = &n;        // Obtain a pointer referencing n

    *ptr_to_n += 1;            // Increment n indirectly via the pointer

    printf("The value of n after incrementing is: %d\n", n);

    return 0;                  // Program completes successfully
}
