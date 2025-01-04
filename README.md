# Undertale PingPong Game

## Description
This project is a simple 2D ping pong game inspired by the popular game Undertale. It is built using the Raylib library, which provides a straightforward interface for graphics, audio, and input handling. The game features two paddles controlled by players, a ball that bounces between them, and a scoring system.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Code Breakdown](#code-breakdown)
- [Game Features](#game-features)
- [Credits](#credits)

## Installation
To run this game, Follow these steps to set up the project:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ZTMY0/PongGameUndertale.git
   cd PongGameUndertale
2. **Install Raylib**:
https://github.com/raysan5/raylib#installation
3.**Compile with MINGW OR CLANG**

## Usage
Controls:
 - Left Paddle: Use W to move up(QWERTY) / use Z to move up(AZERTY) and S to move down.
 - Right Paddle: Use the UP arrow key to move up and the DOWN arrow key to move down.
 - Start Game: Press SPACE to start the game.
 - Restart Game: If the game is over, press R to restart.

## Code Breakdown
# Colors Class
```
class GColors {
public:
    Color Purple0 = (Color){  31,  0,  71, 255 };
    Color Purple1 = (Color){  34,  2,  77, 255 };
    Color Purple2 = (Color){  49,  3, 110, 255 };
    Color Purple3 = (Color){  67,  5, 150, 255 };
    Color Purple4 = (Color){  86,  6, 194, 255 };
    Color Purple5 = (Color){ 110, 10, 245, 255 };
};
```
Defines a class GColors that contains custom color definitions used throughout the game
# SimpleGame Class
```


