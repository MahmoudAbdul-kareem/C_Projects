#include "game.h"

/**
 * @brief The main function to run the Rock-Paper-Scissors game application.
 * 
 * @return int 0 on successful execution.
 */
int main() {
    char play_again;

    do {
        system("cls");
        play_game();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing!\n");

    return 0;
}
