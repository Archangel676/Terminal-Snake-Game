#include <conio.h> // For _kbhit() and _getch()
#include <iostream>
#include <windows.h> // For Windows-specific functions

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;

class Renderer {
public:
  virtual void RenderSnake(int x, int y) = 0;
  virtual void RenderFruit(int x, int y) = 0;
  virtual void RenderBoard(int width, int height) = 0;
  virtual ~Renderer()
  {
  }
};

class TextRenderer: public Renderer {
public:
  void RenderSnake(int x, int y) override
  {
    // Fill in the text-based rendering code
  }
  void RenderFruit(int x, int y) override
  {
    // Fill in the text-based rendering code
  }
  void RenderBoard(int width, int height) override
  {
    // Fill in the text-based rendering code
  }
};

class ImageRenderer: public Renderer {
public:
  void RenderSnake(int x, int y) override
  {
    // Fill in the image-based rendering code
  }
  void RenderFruit(int x, int y) override
  {
    // Fill in the image-based rendering code
  }
  void RenderBoard(int width, int height) override
  {
    // Fill in the image-based rendering code
  }
};

void Setup()
{
  gameOver = false;
  dir = STOP;
  snakeX = width / 2;
  snakeY = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw()
{
  system("cls");
  for (int i = 0; i < width; i++)
    cout << "#";

  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0 || j == width - 1)
        cout << "#";

      cout << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < width; i++)
    cout << "#";
  cout << endl;
}

void Input()
{
}

void Logic()
{
}

int main()
{
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    // Sleep(10);
  }

  return 0;
}
