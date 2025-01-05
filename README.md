# Undertale PingPong Game

## Description
Ce projet est un simple jeu de ping-pong en 2D inspiré du jeu populaire Undertale. Il est construit en utilisant la bibliothèque Raylib, qui offre une interface simple pour la gestion des graphiques, de l'audio et des entrées. Le jeu comprend deux raquettes contrôlées par les joueurs, une balle qui rebondit entre elles, et un système de score.

## Contenu
- [Installation](#installation)
- [Usage](#usage)
- [Code Breakdown](#code-breakdown)
- [Game Features](#game-features)
- [Credits](#credits)

## Installation
Pour exécuter ce jeu:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ZTMY0/PongGameUndertale.git

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


