#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 
// External functions used for board display, rule checks, and move validation
extern void print_board(const char arr[]);
extern bool is_duplicate_index(const int indices[], int count, int index);
extern void check_row(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2);
extern void check_column(char arr[], int index, char c1, char c2, bool *res_p1, bool *res_p2);
extern bool check_diagonal(char arr[], char c);
extern bool is_game_over(char arr[], int size);
extern int computer_move(char arr[]);
extern bool is_board_full(char arr[], int size);
extern void print_title(void);

char board[9] = {};   // Representation of the Tic-Tac-Toe board

int main() {
    char continue_game = 'y';

    while (continue_game != 'n' && continue_game != 'N') {
        int choice = 0;              // Human player's chosen index
        bool game_won = false;       // Indicates whether the game has ended with a win
        bool result_p1 = false;      // Row/column/diagonal result for Player 1
        bool result_p2 = false;      // Row/column/diagonal result for Player 2 (computer)
        bool game_started = false;   // Tracks whether initial prompt has been handled
        int indices[9] = {-1};       // Tracks previously selected indices
        int player1 = 0;             // Whether the human starts (1) or computer starts (0)
        int computer_choice = 0;
        int turn = 0;                // Turn counter
        int index_count = 0;         // Number of occupied positions

        system("clear");             // Clear the terminal screen (Linux/Mac)

        // Initialize the game board
        for (int i = 0; i < 9; i++) {
            board[i] = ' ';
        }

        srand((unsigned)time(NULL)); // Seed RNG for computer moves

        printf("\n\tTic_Tac_Toe (ass_os_worksheet_0)\n");
        printf("\t=======================\n\n");
        printf("Player 1 - [X]          Player 2 - [O]\n\n");

        // Display the index reference board
        char index_board[] = { '0','1','2','3','4','5','6','7','8' };
        printf("Index layout for board positions:\n");
        print_board(index_board);
        printf("\n\n");

        // Determine who takes the first turn
        if (!game_started) {
            printf("Do you want to play first? 1 = Yes, 0 = No >> ");
            scanf("%d", &player1);
            getchar();               // Consume trailing newline
            game_started = true;
        }

        // If computer goes first, offset the turn counter
        if (player1 != 1)
            turn = 1;

        // Main gameplay loop
        while (true) {

            // Human player's turn
            if (turn % 2 == 0) {
                system("clear");
                printf("\n\tTic_Tac_Toe (OS__Worksheet_0)\n");
                printf("\t====================\n\n");
                printf("Player 1 - [X]          Player 2 - [O]\n\n");
                print_board(index_board);
                printf("\n\n");
                print_board(board);

                // Obtain a valid move
                do {
                    printf("Your choice >> ");
                    scanf("%d", &choice);
                } while (is_duplicate_index(indices, index_count, choice) ||
                         (choice < 0 || choice >= 9));

                indices[index_count++] = choice;
                board[choice] = 'X';
                getchar();
                turn++;

            } else {
                // Computer player's turn
                system("clear");
                printf("\n\tTic_Tac_Toe (OS__Worksheet_0)\n");
                printf("\t=====================\n\n");
                printf("Player 1 - [X]          Player 2 - [O]\n\n");
                print_board(index_board);
                printf("\n\n");
                print_board(board);

                // Select a valid computer move
                do {
                    computer_choice = computer_move(board);
                } while (computer_choice > 8 ||
                         is_duplicate_index(indices, index_count, computer_choice));

                indices[index_count++] = computer_choice;
                if (computer_choice >= 0 && computer_choice < 9)
                    board[computer_choice] = 'O';
                turn++;
            }

            // Check row victories
            for (int index = 0; index < 3; index++) {
                check_row(board, index, 'X', 'O', &result_p1, &result_p2);
                if (result_p1) {
                    print_title();
                    printf("\nPlayer 1 has won.\n");
                    game_won = true;
                    break;
                }
                if (result_p2) {
                    print_title();
                    printf("\nThe computer has won.\n");
                    game_won = true;
                    break;
                }
            }

            if (game_won) break;

            // Check column victories
            for (int index = 0; index < 3; index++) {
                check_column(board, index, 'X', 'O', &result_p1, &result_p2);
                if (result_p1) {
                    print_title();
                    printf("\nPlayer 1 has won.\n");
                    game_won = true;
                    break;
                }
                if (result_p2) {
                    print_title();
                    printf("\nThe computer has won.\n");
                    game_won = true;
                    break;
                }
            }

            if (game_won) break;

            // Check diagonal victories
            result_p1 = check_diagonal(board, 'X');
            if (result_p1) {
                print_title();
                printf("\nPlayer 1 has won.\n");
                game_won = true;
                break;
            }

            result_p2 = check_diagonal(board, 'O');
            if (result_p2) {
                print_title();
                printf("\nThe computer has won.\n");
                game_won = true;
                break;
            }

            // Detect draw (board completely filled)
            if (is_game_over(board, 9)) {
                print_title();
                printf("\nThe game is a draw.\n");
                game_won = true;
                break;
            }
        }

        printf("\n\nDo you want to continue playing? Y = Yes, N = No >> ");
        scanf(" %c", &continue_game);
    }

    printf("\nBye! See you later.\n");
    return 0;
}
