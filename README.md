# Undertale PingPong Game

## Introduction
Ce projet est un simple jeu de ping-pong en 2D inspiré du jeu populaire Undertale. Il est construit en utilisant la bibliothèque Raylib, qui offre une interface simple pour la gestion des graphiques, de l'audio et des entrées. Le jeu comprend deux palettes contrôlées par les joueurs, une balle qui rebondit entre elles, et un système de score.

Raylib Official Website : www.raylib.com

## Contenu
- [Installation](#installation)
- [Usage](#usage)
- [Code Breakdown](#code-breakdown)

## Installation
Pour exécuter ce jeu:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ZTMY0/PongGameUndertale.git
   cd PongGameUndertale
   explorer .
   ```
   

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
Définit une classe GColors qui contient des codes couleurs RGB dans le jeu

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
# Func ResetPaddles
```
void ResetPaddles() {
        LeftPad = {10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
        RightPad = {screenWidth - paddleWidth - 10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
    }
```
`ResetPaddles` réinitialise les palettes a leur position initial lorsque le jeu commence ou recommence
```
void ResetBall() {
        BALL.x = static_cast<float>(screenWidth / 2 - BALL.width / 2);
        BALL.y = static_cast<float>(screenHeight / 2 - BALL.height / 2);
        BALLSPEED_X = (LeftHit ? 400.0f : -400.0f);
        BALLSPEED_Y = (GetRandomValue(0, 1) == 0 ? 200.0f : -200.0f);
    }
```
- `ResetBall()` réinitialise la position de la balle au centre lorsque le jeu commence ou recommence
- `BALLSPEED_X` si `leftHit = true` signifie que la balle est frappée par le joueur a gauche donc la balle se deplace vers la droite (400.0f)
  si `leftHit = false` signifie que la balle est frappée par le joueur a gauche donc la balle se deplace vers la gauche (-400.0f)
- `BALLSPEED_Y` retourne un nombre aléatoire (0,1) si valeur = 0 la balle se deplace vers le bas (200.0f) si la valeur = 1 la balle se deplace vers le haut (-200.0f) 

# Func GameUpdate
```
 if (IsKeyDown(KEY_W) && LeftPad.y > 0) {
void GameUpdate() {
        if (!GameStarted) {
            if (IsKeyPressed(KEY_SPACE)) {
                GameStarted = true;
                ResetPaddles();
                ResetBall();
            }
        } else {
            if (GameOver) {
                if (IsKeyPressed(KEY_R)) {
                    GameOver = false;
                    LeftPoint = 0;
                    RightPoint = 0;
                    UpdatePoints();
                    ResetPaddles();
                    ResetBall();
                }
            } else {
                if (LeftPoint == 5) {
                    PlayerWin = "Left Player Win!";
                    GameOver = true;
                } else if (RightPoint == 5) {
                    PlayerWin = "Right Player Win!";
                    GameOver = true;
                }

                UpdateMusicStream(BGMusic);
 
                if (IsKeyDown(KEY_W) && LeftPad.y > 0) {
                    LeftPad.y -= 400 * GetFrameTime ();
                }
                if (IsKeyDown(KEY_S) && LeftPad.y < screenHeight - paddleHeight) {
                    LeftPad.y += 400 * GetFrameTime();
                }
                if (IsKeyDown(KEY_Z) && LeftPad.y > 0) {
                    LeftPad.y -= 400 * GetFrameTime();
                }
                if (IsKeyDown(KEY_UP) && RightPad.y > 0) {
                    RightPad.y -= 400 * GetFrameTime();
                }
                if (IsKeyDown(KEY_DOWN) && RightPad.y < screenHeight - paddleHeight) {
                    RightPad.y += 400 * GetFrameTime();
                }
```
# Verification de Collisions
```
 if (CheckCollisionRecs(LeftPad, BALL) && BALLSPEED_X < 0) {
                    PlaySound(HitSound);
                    BALL.x = LeftPad.x + LeftPad.width;
                    BALLSPEED_X = labs(BALLSPEED_X) + speedIncrement;
                    float paddleCenterY = LeftPad.y + LeftPad.height / 2;
                    float ballCenterY = BALL.y + BALL.height / 2;
                    BALLSPEED_Y += (ballCenterY - paddleCenterY) * 0.1f; 
                    // Adjust this multiplier for desired effect
                } else if (CheckCollisionRecs(RightPad, BALL) && BALLSPEED_X > 0) {
                    PlaySound(HitSound);
                    BALL.x = RightPad.x - BALL.width;
                    BALLSPEED_X = -labs(BALLSPEED_X) - speedIncrement;
                }
if (BALL.y < 0) {
                    PlaySound(HitSound);
                    BALL.y = 0;
                    BALLSPEED_Y = labs(BALLSPEED_Y); // Bounce down
                } else if (BALL.y + BALL.height > screenHeight) {
                    PlaySound(HitSound);
                    BALL.y = screenHeight - BALL.height;
                    BALLSPEED_Y = -labs(BALLSPEED_Y); // Bounce up
                }
if (BALL.x + BALL.width < 0) {
                    RightPoint++;
                    UpdatePoints();
                    PlaySound(Point);
                    ResetBall();
                    LeftHit = true;
                } else if (BALL.x > screenWidth) {
                    LeftPoint++;
                    UpdatePoints();
                    PlaySound(Point);
                    ResetBall();
                    LeftHit = false;
                }
            }
        }
```
detecte si la balle touche les palettes ajuste sa trajectoire
- `CheckCollisionRecs(LeftPad, BALL)` , `CheckCollisionRecs(RightPad, BALL)` lorsque la balle touche une palette, sa direction est inversée et sa vitesse est augmentée. La position de la balle est ajustée pour éviter qu'elle ne reste coincée dans la palette.
- ` (BALL.y < 0)` si la balle touche le haut ou le bas de l'écran, elle rebondit.
- `(BALL.x + BALL.width < 0)` si la balle sort à gauche ou à droite, un point est attribué au joueur adverse, et la position balle est réinitialisée.
# Func GameDraw
```
void GameDraw() {
        if (!GameStarted) {
            DrawStartMenu();
        } else {
            DrawTexture(background, 0, 0, WHITE);
            DrawTexture(ballTexture, static_cast<int>(BALL.x), static_cast<int>(BALL.y), WHITE);
            DrawTexture(leftPaddleTexture, static_cast<int>(LeftPad.x), static_cast<int>(LeftPad.y), WHITE);
            DrawTexture(rightPaddleTexture, static_cast<int>(RightPad.x), static_cast<int>(RightPad.y), WHITE);

            if (GameOver) {
                DrawText(PlayerWin.c_str(), 10, 10, 30, gc.Purple5);
                DrawText("Press R to play Again!!", screenWidth / 2 - 200, screenHeight / 2, 60, gc.Purple5);
            } else {
                DrawRectangle(TopBAR.x, TopBAR.y, TopBAR.width, TopBAR.height, gc.Purple3);
                DrawRectangle(BottomBAR.x, BottomBAR.y, BottomBAR.width, BottomBAR.height, gc.Purple3);
                DrawText(Points.c_str(), 240, 10, 30, gc.Purple5);
                DrawFPS(10, 10);
            }
        }
        DrawText("Fangame made by Zaghdane Ihab", screenWidth / 2 - 150, screenHeight - 40, 20 , WHITE);
        DrawText("Original game : Undertale By Toby Fox", screenWidth / 2 - 150, screenHeight - 20, 20, WHITE);
    }
```
`GameDraw` est pour l'affichage des éléments du jeu. Elle vérifie si le jeu a commencé ou s'il est terminé, et dessine les éléments appropriés à l'écran, les palettes, la balle, et le messages de victoire
# UnloadAll
```
void UnloadALL() {
        UnloadSound(HitSound);
        UnloadSound(Point);
        UnloadMusicStream(BGMusic);
        CloseAudioDevice();
        UnloadTexture(background);
        UnloadTexture(ballTexture);
        UnloadTexture(leftPaddleTexture);
        UnloadTexture(rightPaddleTexture);
        UnloadTexture(startMenuBg); 
    }
```
`UnloadAll` est pour liberer la memoire des resources et textures charger pendant le jeu pour ne pas etre stocker lorsque on quitte le jeu
dans un sense `UnloadAll` fonctionne comme `~delete()`
# GameLoop
```
    void GameLoop() {
        InitWindow(screenWidth, screenHeight, GameTitle.c_str());
        ballTexture = LoadTexture("Build\\custom_ball.png");
        leftPaddleTexture = LoadTexture("Build\\sans_paddle.png");
        rightPaddleTexture = LoadTexture("Build\\sans_paddle.png");
        SetTargetFPS(60);

        InitAudioDevice();

        HitSound = LoadSound("Build\\hitSound.wav");
        BGMusic = LoadMusicStream("Build\\music.mp3");
        Point = LoadSound("Build\\point.wav");

        SetSoundVolume(HitSound, 0.2f);
        SetMusicVolume(BGMusic, 0.5f);

        PlayMusicStream(BGMusic);
        background = LoadTexture("Build/undertale.png");
        startMenuBg = LoadTexture("Build\\start.png"); 

        while (!WindowShouldClose()) {
            GameUpdate();
            BeginDrawing();
            ClearBackground(gc.Purple0);
            GameDraw();
            EndDrawing();
        }

        UnloadALL();
        CloseWindow();
    }
};
```
La méthode `GameLoop` constitue le cœur du jeu elle initialise la fenetre, charge les ressources de jeu et actualise l'état du jeu et dessine les éléments à chaque frame en boucle.
