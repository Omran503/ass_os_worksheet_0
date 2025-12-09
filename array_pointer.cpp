#include <stdio.h>

int main() {
    int arr[3] = {10, 30, 2000};     // Declare and initialize an integer array
    int *ptr = arr;                  // Pointer initialized to the base address of the array

    // Iterate through the array using pointer arithmetic
    for (int i = 0; i < 3; i++) {
        printf("Element %d: Value = %d, Address = %p\n", 
               i, *(ptr + i), (ptr + i));
    }

    return 0; // Exit the program
}
