// game_logic.h
#include <stdbool.h>

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

bool is_duplicate_index(const int indices[], int count, int index);
void check_row(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2);
void check_column(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2);
bool check_diagonal(char arr[], char c);
bool is_board_empty(char arr[], int size);
bool is_game_over(char arr[], int size);
int computer_move(char arr[]);
#endif

