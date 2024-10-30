#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame(int boardSize, int winLength)
{
  // This allocates the memory for the game
  Game *game = malloc(sizeof(Game));
  // This checks if incorrect parameters are passed
  if (boardSize != 3 && winLength != 3)
  {
    // for incorrect boardSize or winLength you should return a NULL pointer
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }
  // allocate the Game data structure
  // intialise the Game data structure values
  // board values should be set to '.' (unused location)
  game->boardSize = 3;
  game->maxTurns = 9;
  game->turns = 0;
  game->winLength = 3;
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      game->board[row][col] = '.';
    }
  }
  return game;
}
