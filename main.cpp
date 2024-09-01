#include <conio.h> // For _kbhit() and _getch()
#include <cstdlib> // for srand and rand
#include <iostream>
#include <windows.h> // For Sleep function

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

  srand(static_cast<unsigned int>(time(0)));

  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw()
{
  system("cls");
  cout << endl;
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
        }

        if (!printed)
          cout << " ";
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

  tailX[0] = headX;
  tailY[0] = headY;

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

  // //Uncomment for Classic Mode: You die if you hit the wall
  //   if (headX >= (width - 1) || headX < 0 || headY >= height || headY < 0)
  //     gameOver = true;

  // //Default is Easy Mode: If you hit the wall you come out the opposite wall
  if (headX >= width - 1)
    headX = 0;

  else if (headX < 0)
    headX = width - 2;

  if (headY >= height)
    headY = 0;

  else if (headY < 0)
    headY = height - 1;

  for (int i = 0; i < nTail; i++) {
    if (tailX[i] == headX && tailY[i] == headY)
      gameOver = true;
  }

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
  cout << endl;

  return 0;
}
