#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "initGame.h"
#include "playGame.h"
#include "endGame.h"

/*
 * main function: program entry point
 */

int main(void)
{
  // allocate memory and assign starting values to the structure
  Game *game = initGame(3, 3); // pointer for the game structure
  // play a full game
  playGame(game);
  free(game); // free heap memory that was used
  return 0;
}
