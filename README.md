# Undertale PingPong Game

## Description
Ce projet est un simple jeu de ping-pong en 2D inspiré du jeu populaire Undertale. Il est construit en utilisant la bibliothèque Raylib, qui offre une interface simple pour la gestion des graphiques, de l'audio et des entrées. Le jeu comprend deux palettes contrôlées par les joueurs, une balle qui rebondit entre elles, et un système de score.

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
   cd PongGameUndertale
   explorer .

## Usage
Controls:
 - palette gauche : Utilisez W pour monter (QWERTY) / utilisez Z pour monter (AZERTY) et S pour descendre.
 - palette droite : Utilisez la touche flèche HAUT pour monter et la touche flèche BAS pour descendre.
 - Démarrer le jeu : Appuyez sur ESPACE pour commencer le jeu.
 - Redémarrer le jeu : Si le jeu est terminé, appuyez sur R pour redémarrer.

## Code Breakdown
# Class Colors
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
Définit une classe GColors qui contient des définitions de couleurs personnalisées utilisées dans tout le jeu

# Class SimpleGame
```
class SimpleGame {
public:
    const int screenWidth = 1000;
    const int screenHeight = 600;
    string GameTitle = "Undertale PingPong";
    Texture2D background;
    Texture2D ballTexture;
    Texture2D leftPaddleTexture;
    Texture2D rightPaddleTexture;
    Texture2D startMenuBg;
    const float paddleWidth = 60.0f;
    const float paddleHeight = 120.0f;
    GColors gc;
    Rectangle LeftPad = {10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
    Rectangle RightPad = {screenWidth - paddleWidth - 10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
    Rectangle TopBAR = {0, 0, static_cast<float>(screenWidth), 5};
    Rectangle BottomBAR = {0, static_cast<float>(screenHeight - 5), static_cast<float>(screenWidth), 5};

    Rectangle BALL = {static_cast<float>(screenWidth / 2 - 15), static_cast<float>(screenHeight / 2 - 15), 30, 30};
    float BALLSPEED_X = 400.0f;
    float BALLSPEED_Y = 200.0f;
    float speedIncrement = 20.0f;


    int LeftPoint = 0;
    int RightPoint = 0;
    string Points = " | Left Player: 0 | Right Player: 0";

    Sound HitSound;
    Music BGMusic;
    Sound Point;

    string PlayerWin;
    bool GameOver = false;
    bool GameStarted = false;
```
- `screenWidth` et `screenHeight` définissent la taille de la fenêtre du jeu.
`GameTitle` est le titre du jeu.
- `Texture2D` sont utilisées pour stocker les textures images qui seront affichées dans le jeu, comme l'arrière-plan, la balle et les palettes
- `Rectangle LeftPad` et `Rectangle RightPad` sont des rectangles représentant les palettes gauche et droite, positionnées au centre vertical de l'écran.
- `Rectangle TopBAR` et `Rectangle BottomBAR` sont des rectangles représentant les barres en haut et en bas de l'écran.
- `Rectangle BALL` est un rectangle représentant la balle, positionnée au centre de l'écran.
- `BALLSPEED_X` et `BALLSPEED_Y` définissent la vitesse de la balle sur les axes X et Y.
- `speedIncrement` est pour augmenter la vitesse de la balle lorsque elle est frappe par la palette


