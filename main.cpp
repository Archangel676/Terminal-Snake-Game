#include <conio.h> // For _kbhit() and _getch()
#include <iostream>
#include <windows.h> // For Windows-specific functions

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;

void Setup()
{
  gameOver = false;
  dir = STOP;
  headX = width / 2;
  headY = height / 2;
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
      if (i == headY && j == headX)
        cout << "O";
      else if (i == fruitY && j == fruitX)
        cout << "F";
      else {
        bool printed = false;
        for (int k = 0; k < nTail; k++) {
          if (tailX[k] == j && tailY[k] == i) {
            cout << "o";
            printed = true;
          }
          if (!printed)
            cout << " ";
        }
      }
    }
    cout << endl;
  }

  for (int i = 0; i < width + 1; i++)
    cout << "#";
  cout << endl << endl;

  cout << "Your score is: " << score << endl << endl;
}

void Input()
{
  if (_kbhit()) // check if a key board key is pressed
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
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;

  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }

  switch (dir) {
  case LEFT:
    headX--;
    break;
  case UP:
    headY--;
    break;
  case RIGHT:
    headX++;
    break;
  case DOWN:
    headY++;
    break;
  default:
    break;
  }

  if (headX >= (width - 1) || headX < 0 || headY >= height || headY < 0)
    gameOver = true;

  if (headX == fruitX && headY == fruitY) {
    score += 10;
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail++;
  }
}

int main()
{
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    Sleep(100); // Sleep for 100 milliseconds to control the game speed
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
//     snakeHead.setPosition(headX * 20, headY * 20);
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
