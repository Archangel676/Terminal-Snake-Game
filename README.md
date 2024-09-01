# Terminal Snake Game (Using C++)
A classic snake game made in C++ which is playable in a PowerShell or terminal window, displayed using ASCII characters.

This repository contains a simple Snake game created for educational purposes. 

## How to Play

Use the awds keys to move the snake around the screen, eating apples.

### Controls:
- a: The snake will move left
- w: The snake will move up
- d: The snake will move right
- s: The snake will move down
- x: End and exit the game

Each apple that you eat will increase your score by ten and the snake's size by one length.
- The apple will reapear somewhere new after being eaten
- Your current score is displayed at the bottom of the screen

### Goal:
The goal of the game is to grow your snake as long as possible by eating apples without running into the walls or the snake's tail. 

### Options: 
- The game's default is Easy Mode: If you hit the wall you come out the opposite wall
- Otherwise uncomment the Classic Mode for harder gameplay: You die if you hit the wall

In both modes, hitting your tail or doubling back on yourself will end the game.

## About

This project was developed to practice game development techniques and to learn more about programming and game design. The code is based on various tutorials and resources available online.

## Attribution

The code used in this project is not original and is based on publicly available resources listed below. 

The purpose of this project is to practice and understand game development concepts.

The boilerplate starter code (Makefile, .vscode, .clang-format, and .gitignore) is from the VSCodeTemplates repository Basic Project template.

- BoostMyTool - SFML Setup in Visual Studio Code | Create C/C++ Applications using SFML + VSCode + MinGW-w64
- NVitanovic - C++ Tutorial - Simple Snake Game (Parts 1, 2, amd 3)
- The assets including all pixel art are my own original work

## License

This project is provided for educational purposes only and is not intended for commercial use. Feel free to use or modify it for your personal learning.
