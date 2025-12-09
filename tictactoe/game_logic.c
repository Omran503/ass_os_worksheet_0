#include "game_logic.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_duplicate_index(const int indices[], int count, int index) {
    for (int i = 0; i < count; i++) {
        if (indices[i] == index) {
            return true;
        }
    }
    return false;
}

void check_row(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2) {
    int check = 0;

    if (c1 == 'X') {
        for (int j = index * 3; j < (index * 3) + 3; j++) {
            if (arr[j] == c1)
                check++;
        }
        *res_p1 = (check == 3);
    }
    if (c2 == 'O') {
        check = 0;
        for (int j = index * 3; j < (index * 3) + 3; j++) {
            if (arr[j] == c2)
                check++;
        }
        *res_p2 = (check == 3);
    }
}

void check_column(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2) {
    int check = 0;

    if (c1 == 'X') {
        for (int j = index; j <= index + 6; j += 3) {
            if (arr[j] == c1)
                check++;
        }
        *res_p1 = (check == 3);
    }

    if (c2 == 'O') {
        check = 0;
        for (int j = index; j <= index + 6; j += 3) {
            if (arr[j] == c2)
                check++;
        }
        *res_p2 = (check == 3);
    }
}


bool check_diagonal(char arr[], char c) {
    int check = 0;

    // Diagonal 1
    for (int i = 0; i < 9; i += 4) {
        if (arr[i] == c)
            check++;
    }
    if (check == 3)
        return true;

    check = 0;

    // Diagonal 2
    for (int i = 2; i < 7; i += 2) {
        if (arr[i] == c)
            check++;
    }
    return check == 3;
}

bool is_board_empty(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == 'O' || arr[i] == 'X')
            return false;
    }
    return true;
}



bool is_game_over(char arr[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 'O' || arr[i] == 'X') {
            check++;
        }
    }

    if (check == 9) {
        return true;
    } else {
        return false;
    }
}


int computer_move(char arr[]) {
    char players[2] = { 'O', 'X' };
    int positions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // The Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // The Columns
        {0, 4, 8}, {2, 4, 6}             // The Diagonals
    };
    if (is_board_empty(arr, 9)) return 4;
 //Let us check for winning or blocking moves for each of the players
    for (int p = 0; p < 2; p++) {
        char player = players[p];
        for (int pos = 0; pos < 8; pos++) {
            int *position = positions[pos];
            for (int i = 0; i < 3; i++) {
                if (arr[position[i]] == player && arr[position[(i + 1) % 3]] == player && arr[position[(i + 2) % 3]] == ' ') {
                    return position[(i + 2) % 3];
                }
            }
        }
    }
    if (is_game_over(arr, 9)) return -1;
    return rand() % 9;
}


