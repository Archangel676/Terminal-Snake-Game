#include <conio.h> // For _kbhit() and _getch()
#include <iostream>
#include <windows.h> // For Windows-specific functions

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int snakeHeadX, snakeHeadY, fruitX, fruitY, score;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;

void Setup()
{
  gameOver = false;
  dir = STOP;
  snakeHeadX = width / 2;
  snakeHeadY = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw()
{
  system("cls");
  for (int i = 0; i < width + 1; i++)
    cout << "#";

  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0 || j == width - 1)
        cout << "#";
      if (i == snakeHeadY && j == snakeHeadX)
        cout << "O";
      else if (i == fruitY && j == fruitX)
        cout << "F";
      else
        cout << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < width + 1; i++)
    cout << "#";
  cout << endl;
}

void Input()
{
  if (_kbhit()) // check if key board keey is pressed
  {
    switch (_getch()) // returns the ASCII value of the character pressed
    {
    case 'a':
      dir = LEFT;
      break;
    case 'w':
      dir = UP;
      break;
    case 'd':
      dir = RIGHT;
      break;
    case 's':
      dir = DOWN;
      break;
    case 'x':
      gameOver = true;
      break;
    }
  }
}

void Logic()
{
  switch (dir) {
  case LEFT:
    snakeHeadX--;
    break;
  case UP:
    snakeHeadY--;
    break;
  case RIGHT:
    snakeHeadX++;
    break;
  case DOWN:
    snakeHeadY++;
    break;
  default:
    break;
  }

  if (snakeHeadX >= width || snakeHeadX <= 0 || snakeHeadY >= height
      || snakeHeadY <= 0)
    gameOver = true;
}

int main()
{
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    Sleep(100);
  }

  return 0;
}

// Implement a Simple Rendering Engine with a Graphics Library:
//  Include SFML Graphics Library
//  #include <SFML/Graphics.hpp>

// // Your Snake Game Logic here...

// void Render(sf::RenderWindow &window) {
//     // Clear the window with a background color
//     window.clear(sf::Color::Black);

//     // Create and draw your snake and fruit using SFML Sprites or Shapes
//     sf::RectangleShape snakeHead(sf::Vector2f(20, 20));
//     snakeHead.setFillColor(sf::Color::Green);
//     snakeHead.setPosition(snakeHeadX * 20, snakeHeadY * 20);
//     window.draw(snakeHead);

//     // Continue drawing other game elements...

//     // Display everything on the screen
//     window.display();
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(400, 400), "Snake Game");
//     Setup();
//     while (window.isOpen() && !gameOver) {
//         // Handle window events (keyboard, etc.)
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         // Game Logic
//         Input();
//         Logic();

//         // Render
//         Render(window);
//     }

//     return 0;
// }

// class Renderer {
// public:
//   virtual void RenderSnake(int x, int y) = 0;
//   virtual void RenderFruit(int x, int y) = 0;
//   virtual void RenderBoard(int width, int height) = 0;
//   virtual ~Renderer()
//   {
//   }
// };

// class TextRenderer: public Renderer {
// public:
//   void RenderSnake(int x, int y) override
//   {
//     // Fill in the text-based rendering code
//   }
//   void RenderFruit(int x, int y) override
//   {
//     // Fill in the text-based rendering code
//   }
//   void RenderBoard(int width, int height) override
//   {
//     // Fill in the text-based rendering code
//   }
// };

// class ImageRenderer: public Renderer {
// public:
//   void RenderSnake(int x, int y) override
//   {
//     // Fill in the image-based rendering code
//   }
//   void RenderFruit(int x, int y) override
//   {
//     // Fill in the image-based rendering code
//   }
//   void RenderBoard(int width, int height) override
//   {
//     // Fill in the image-based rendering code
//   }
// };
