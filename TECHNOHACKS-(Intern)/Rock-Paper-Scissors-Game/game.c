#include "game.h"

#define ROCK     1
#define PAPER    2
#define SCISSORS 3

/**
 * @brief Starts the Rock-Paper-Scissors game.
 */
void play_game() {
    int user_choice, computer_choice;

    user_choice = get_user_choice();
    computer_choice = get_computer_choice();

    printf("You chose:      ");
    print_choice(user_choice);
    printf("Computer chose: ");
    print_choice(computer_choice);

    determine_winner(user_choice, computer_choice);
}

/**
 * @brief Generates and returns the computer's choice.
 * 
 * @return An integer representing the computer's choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
int get_computer_choice() {
    srand(time(0));
    return (rand() % 3) + 1;
}

/**
 * @brief Prompts the user for their choice and returns it.
 * 
 * @return An integer representing the user's choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
int get_user_choice() {
    int choice;
    printf("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3) {
        printf("Invalid choice. Please enter 1 for Rock, 2 for Paper, 3 for Scissors: ");
        scanf("%d", &choice);
    }
    return choice;
}

/**
 * @brief Determines and prints the winner based on the user's and computer's choices.
 * 
 * @param user_choice An integer representing the user's choice.
 * @param computer_choice An integer representing the computer's choice.
 */
void determine_winner(int user_choice, int computer_choice) {
    if (user_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if ((user_choice == ROCK && computer_choice == SCISSORS) ||
               (user_choice == PAPER && computer_choice == ROCK) ||
               (user_choice == SCISSORS && computer_choice == PAPER)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

/**
 * @brief Prints the choice corresponding to the given integer.
 * 
 * @param choice An integer representing a choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
void print_choice(int choice) {
    switch (choice) {
        case ROCK:
            printf("Rock\n");
            break;
        case PAPER:
            printf("Paper\n");
            break;
        case SCISSORS:
            printf("Scissors\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}
