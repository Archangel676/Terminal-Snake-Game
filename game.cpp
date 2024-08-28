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

  if (!snakeTailTexture.loadFromFile("assets/images/snake_tail.png")) {
    std::cerr << "Error loading the snake tail image";
  }

  if (!fruitTexture.loadFromFile("assets/images/fruit_apple.png")) {
    std::cerr << "Error loading the fruit image";
  }

  // Loading all my sprites
  snakeHeadSprite.setTexture(snakeHeadTexture);
  snakeBodySprite.setTexture(snakeBodyTexture);
  snakeCornerSprite.setTexture(snakeCornerTexture);
  snakeTailSprite.setTexture(snakeTailTexture);
  fruitSprite.setTexture(fruitTexture);
}

void Game::run()
{
  std::cout << "Before the game logic while loop..."
            << std::endl; // Debugging output
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    std::cout << "Running game loop..." << std::endl; // Debugging output
    window.clear();

    // Draw out my Sprites
    std::cout << "Drawing sprites..." << std::endl; // Debugging output
    window.draw(snakeHeadSprite);
    window.draw(snakeBodySprite);
    window.draw(snakeCornerSprite);
    window.draw(snakeTailSprite);
    window.draw(fruitSprite);

    window.display();
  }
}