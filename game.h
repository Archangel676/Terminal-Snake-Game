#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
  /**
   * @brief EXAMPLE: Constructs a new Tic Tac Toe object.
   *        Sets default starting player to X and
   *        initializes board with dash '-' characters
   */
  Game();

  /**
   * @brief EXAMPLE: Loops through the two dimensional array
   *        of the current board and turns it into a string
   *        that if printed to the console, will be formatted
   *        like a regular Tic Tac Toe game
   */
  void run();

private:
  // char currentPlayer;
  // char board[3][3];
};

#endif // GAME_H