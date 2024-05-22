# Rock-Paper-Scissors Game

This is a simple Rock-Paper-Scissors game implemented in C. The user can play against the computer, and the computer's choice is randomly generated each time the game is played.

## Files

The project is divided into three files:

1. `app.c` - Contains the main function to run the application.
2. `game.c` - Contains the implementation of the game's functionality.
3. `game.h` - Contains the function prototypes and necessary includes.

## Features

- **User Input**: The game prompts the user to enter their choice (Rock, Paper, or Scissors).
- **Random Computer Choice**: The computer's choice is randomly generated each time the game is played, ensuring unpredictability.
- **Result Determination**: The game determines and displays the result (win, lose, or tie) based on the user's and computer's choices.
- **Replay Option**: After each round, the user is prompted if they want to play again.
- **Input Validation**: The game ensures that the user inputs a valid choice before proceeding.
- **Clear Output**: The game clearly prints the user's and computer's choices, as well as the result of each round.

## How to Compile and Run

To compile and run the program, use the following commands in your terminal:

```sh
gcc -o rock_paper_scissors app.c game.c
./rock_paper_scissors
```

This will compile the app.c and game.c files into an executable named rock_paper_scissors, which you can then run.

## Sample run

