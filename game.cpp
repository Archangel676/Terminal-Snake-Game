#include "game.h"
#include <iostream>

Game::Game(): window(sf::VideoMode(800, 600), "Snake Game")
{
  // Loading all my textures
  if (!snakeHeadTexture.loadFromFile("assets/images/snake_head.png")) {
    std::cerr << "Error loading the snake head image";
  }

  if (!snakeBodyTexture.loadFromFile("assets/images/snake_body.png")) {
    std::cerr << "Error loading the snake body image";
  }

  if (!snakeCornerTexture.loadFromFile(
          "assets/images/snake_corner_up_right.png")) {
    std::cerr << "Error loading the snake corner image";
  }

  if (!snakeTailTexture.loadFromFile("assets/images/fruit_apple.png")) {
    std::cerr << "Error loading the fruit image";
  }

  // Loading all my sprites
  snakeHeadSprite.setTexture(snakeHeadTexture);
  snakeBodySprite;
  snakeCornerSprite;
  snakeTailSprite;
  fruitSprite;
}

// sf::RenderWindow window {}

// sf::Texture snakeHeadTexture {}
// sf::Texture snakeBodyTexture {}
// sf::Texture snakeCornerTexture {}
// sf::Texture snakeTailTexture {}
// sf::Texture fruitTexture {}

// sf::Sprite snakeHeadSprite {}
// sf::Sprite snakeBodySprite {}
// sf::Sprite snakeCornerSprite {}
// sf::Sprite snakeTailSprite {}
// sf::Sprite fruitSprite {}