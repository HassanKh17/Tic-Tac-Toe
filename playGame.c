#include <stdio.h>
#include "game.h"
#include "playGame.h"
#include "endGame.h"
/*
 * Controls the game logic from start to end
 */
int row, col;
void playGame(Game *game)
{
  char symbols[2] = {'X', 'O'};
  // player 'X' plays first
  int player = 0;
  // starting board
  printf("New game starting\n");
  showGame(game);
  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  // Request a move from the next player and check it is valid (an unused square within the board)
  while (game->turns < game->maxTurns && winGame(game, symbols[player]) == 0)
  {
    printf("Player %c: Enter your move as row column values:\n", symbols[player]); // use this to request the player move
    scanf("%d %d", &row, &col);
    // If the move is valid update the board
    // After each completed move display the board
    // After each valid move you can test for win or draw using functions you implement in endGame.c
    makeMove(game, symbols[player]);
    // This checks if an invalid move is made
    if (makeMove(game, symbols[player]) == 0)
    {
      // If the move is invalid you should repeat the request for the current player
      printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
    }
    else
    {
      // This updates the . on the grid with player's symbol if the move made is valid
      game->board[row][col] = symbols[player];
      showGame(game);
      // This increments the number of turns
      game->turns += 1;
      // This checks if the current player has won the game
      if (winGame(game, symbols[player]) == 1)
      {
        printf("Player %c has won\n", symbols[player]); // use to announce a winner - game is over
        return;
      }
      // This switches the turn after a valid move has not resulted in a win
      if (player == 0)
      {
        player = 1;
      }
      else
      {
        player = 0;
      }
    }
  }
  // This checks if the game is a draw
  if (drawGame(game) == 1)
  {
    printf("Match is drawn\n"); // use to announce a draw - game is over
    return;
  }
}
/*
 * Display the game board - do not adjust the formatting
 */
void showGame(Game *game)
{
  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n", game->board[0][0], game->board[0][1], game->board[0][2]);
  printf(" 1    %c  %c  %c\n", game->board[1][0], game->board[1][1], game->board[1][2]);
  printf(" 2    %c  %c  %c\n", game->board[2][0], game->board[2][1], game->board[2][2]);
  printf("\n");
  return;
}
/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */
int makeMove(Game *game, char symbol)
{
  // read the players move from the keyboard, expected as two integers coordinates as shown on the board
  // test that the chosen location is a valid empty space
  // if we do not accept the move return 0
  // if we accept then update the board and return 1
  if (game->board[row][col] == '.')
  {
    return 1; // move accepted
  }
  else
  {
    return 0; // move rejected
  }
}