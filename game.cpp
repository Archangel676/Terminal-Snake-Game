#include "game.h"
#include <iostream>

Game::Game(): window(sf::VideoMode(800, 600), "Snake Game")
{
  if (!snakeHeadTexture.loadFromFile("Assets/images/Head UP.png")) {
    std::cerr << "Error loading the snake head image";
  }
  if (!snakeBodyTexture.loadFromFile("Assets/images/Head UP.png")) {
    std::cerr << "Error loading the snake head image";
  }
  if (!snakeHeadTexture.loadFromFile("Assets/images/Head UP.png")) {
    std::cerr << "Error loading the snake head image";
  }
}

// sf::RenderWindow window {}

// sf::Texture snakeHeadTexture {}
// sf::Texture snakeBodyTexture {}
// sf::Texture snakeCornerTexture {}
// sf::Texture snakeTailTexture {}
// sf::Texture fruitTexture {}

// sf::Sprite snakeHeadSprite {}
// sf::Sprite snakeBodySprite {}
// sf::Sprite snakeCornerTexture {}
// sf::Sprite snakeTailTexture {}
// sf::Sprite fruitSprite {}