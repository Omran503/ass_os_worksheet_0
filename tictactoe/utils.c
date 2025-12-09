#include <stdio.h>
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>

// Display the game header and the reference index board
void print_title(void) {
    system("clear");   // Clear the terminal display (Linux/Mac)

    printf("\n Tic_Tac_Toe (ass_os_worksheet_0)\n");
    printf("\t====================\n\n");
    printf("Player 1 - [X]          Player 2 - [O]\n\n");

    // Index layout used to indicate board positions
    char list_bsp[] = { '0','1','2','3','4','5','6','7','8' };
    printf("Index layout indicating the array position of each field:\n");
    print_board(list_bsp);
    printf("\n");
}

// Render a 3×3 board using the character array passed in
void print_board(const char arr[]) {
    int array_index = 0;

    for (int i = 0; i < 3; i++) {
        printf("\t\t-------------\n");
        printf("\t\t|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |", arr[array_index]);
            array_index++;
        }
        printf("\n");
    }

    printf("\t\t--.....-....-.......-\n");
}
