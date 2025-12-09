#include <stdio.h>

void print_array(int *arr, int width, int height) {
    // Traverse the array row by row
    for (int i = 0; i < height; i++) {
        // Traverse the current row column by column
        for (int j = 0; j < width; j++) {
            printf("%d ", *((arr + i * width) + j));  // Element access via pointer arithmetic
        }
        printf("\n");  // Advance to the next row
    }
}

int main() {
    // Declaration and initialization of a 3×3 integer matrix
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Invoke the print function using the base address of the matrix
    print_array((int *)arr, 3, 3);

    return 0; // Program termination
}
