#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes

/**
 * @brief Starts the Rock-Paper-Scissors game.
 */
void play_game();

/**
 * @brief Generates and returns the computer's choice.
 * 
 * @return An integer representing the computer's choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
int get_computer_choice();

/**
 * @brief Prompts the user for their choice and returns it.
 * 
 * @return An integer representing the user's choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
int get_user_choice();

/**
 * @brief Determines and prints the winner based on the user's and computer's choices.
 * 
 * @param user_choice An integer representing the user's choice.
 * @param computer_choice An integer representing the computer's choice.
 */
void determine_winner(int user_choice, int computer_choice);

/**
 * @brief Prints the choice corresponding to the given integer.
 * 
 * @param choice An integer representing a choice (1 for Rock, 2 for Paper, 3 for Scissors).
 */
void print_choice(int choice);

#endif // GAME_H
