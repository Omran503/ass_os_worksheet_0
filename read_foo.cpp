#include <stdio.h>

int main() {
    FILE *file;
    int number, sum = 0;

    // Open the input file in read mode
    file = fopen("foo.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;   // Terminate if the file cannot be accessed
    }

    // Read integers sequentially and accumulate their sum
    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
    }

    // Release the file resource
    fclose(file);

    // Display the computed sum
    printf("The sum of the numbers is: %d\n", sum);

    return 0;  // Normal program termination
}
