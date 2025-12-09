#include <stdio.h>
#include <stdlib.h>   // Provides malloc and free
#include <string.h>   // Provides memcpy

// Generic swap function that exchanges the contents of two memory locations
void swap(void* x, void* y, size_t size) {
    void* temp = malloc(size);   // Allocate temporary storage
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;                  // Abort swap if allocation fails
    }

    // Perform the swap using memory copying
    memcpy(temp, x, size);       // Store the contents of x
    memcpy(x, y, size);          // Copy y into x
    memcpy(y, temp, size);       // Copy the saved value into y

    free(temp);                  // Release the temporary buffer
}

int main() {
    int a = 5, b = 10;
    float p = 3.14f, q = 6.28f;

    // Demonstration with integers
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swapping:  a = %d, b = %d\n", a, b);

    // Demonstration with floats
    printf("Before swapping: p = %.2f, q = %.2f\n", p, q);
    swap(&p, &q, sizeof(float));
    printf("After swapping:  p = %.2f, q = %.2f\n", p, q);

    return 0;  // Normal program termination
}
