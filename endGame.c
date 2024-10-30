#include <stdio.h>
#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame(Game *game, char symbol)
{
  // return 1(true) if game is won, 0(false) otherwise
  //
  // You may wish to define further functions to test different win conditions
  // Games can be won with horizontal, vertical or diagonal lines
  if (checkRow(game, symbol) == 1 || checkCol(game, symbol) == 1 || checkDiagLeft(game, symbol) == 1 || checkDiagRight(game, symbol) == 1)
  {
    return 1;
  }
  else
  {
    return 0; // continue
  }
}
// This function checks for a horizontal win
int checkRow(Game *game, char symbol)
{
  // This loop goes through each row
  for (int i = 0; i < 3; i++)
  {
    if (game->board[i][0] == symbol)
    {
      if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2])
      {
        return 1;
      }
    }
  }
  return 0;
}
// This function checks for a vertical win
int checkCol(Game *game, char symbol)
{
  // This loop goes through each column
  for (int j = 0; j < 3; j++)
  {
    if (game->board[0][j] == symbol)
    {
      if (game->board[0][j] == game->board[1][j] && game->board[1][j] == game->board[2][j])
      {
        return 1;
      }
    }
  }
  return 0;
}
// This checks for a diagonal right win
int checkDiagRight(Game *game, char symbol)
{
  if (game->board[0][0] == symbol)
  {
    // This checks for a diagonal down win
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2])
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}
// This check for a diagonal left win
int checkDiagLeft(Game *game, char symbol)
{
  if (game->board[2][0] == symbol)
  {
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0])
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}

// test for a draw
int drawGame(Game *game)
{
  // return 1(true) if game is drawn, 0(false) otherwise
  // This checks if the number of turns equal the maximum number of moves possible
  if (game->turns == game->maxTurns)
  {
    return 1;
  }
  return 0;
}
