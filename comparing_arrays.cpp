#include <stdio.h>
#include <stdbool.h>  // Enables use of Boolean types (true/false)

// Function to compare two integer arrays using pointer traversal
bool compare_arrays(int *arr1, int *arr2, int length) {
    // Validate that both pointers reference valid memory
    if (arr1 == NULL || arr2 == NULL) {
        return false;  // Comparison is invalid if either pointer is NULL
    }

    // Sequentially compare corresponding elements
    for (int i = 0; i < length; i++) {
        if (*(arr1 + i) != *(arr2 + i)) {  // Pointer-based element access
            return false;  // Arrays differ at this position
        }
    }

    return true;  // All elements match
}

int main() {
    // Example arrays for testing
    int array1[] = {10, 20, 30};
    int array2[] = {10, 20, 30};
    int array3[] = {10, 21, 30};

    int length = 3;  // Common array length

    // Test case 1: Arrays with identical content
    if (compare_arrays(array1, array2, length)) {
        printf("array1 and array2 are the same.\n");
    } else {
        printf("array1 and array2 are different.\n");
    }

    // Test case 2: Arrays with differing content
    if (compare_arrays(array1, array3, length)) {
        printf("array1 and array3 are the same.\n");
    } else {
        printf("array1 and array3 are different.\n");
    }

    return 0; // End of program
}
