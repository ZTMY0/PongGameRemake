#include <raylib.h>
#include <string>
using namespace std;

class GColors {
public:
    Color Purple0 = (Color){  31,  0,  71, 255 };
    Color Purple1 = (Color){  34,  2,  77, 255 };
    Color Purple2 = (Color){  49,  3, 110, 255 };
    Color Purple3 = (Color){  67,  5, 150, 255 };
    Color Purple4 = (Color){  86,  6, 194, 255 };
    Color Purple5 = (Color){ 110, 10, 245, 255 };
};

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

    bool LeftHit = true;

    int LeftPoint = 0;
    int RightPoint = 0;
    string Points = " | Left Player: 0 | Right Player: 0";

    Sound HitSound;
    Music BGMusic;
    Sound Point;

    string PlayerWin;
    bool GameOver = false;
    bool GameStarted = false;
    void ResetPaddles() {
        LeftPad = {10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
        RightPad = {screenWidth - paddleWidth - 10, static_cast<float>(screenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight};
    }

    void ResetBall() {
        BALL.x = static_cast<float>(screenWidth / 2 - BALL.width / 2);
        BALL.y = static_cast<float>(screenHeight / 2 - BALL.height / 2);
        BALLSPEED_X = (LeftHit ? 400.0f : -400.0f); 
        BALLSPEED_Y = (GetRandomValue(0, 1) == 0 ? 200.0f : -200.0f);
    }

    void UpdatePoints() {
        Points = " | Left Player: " + to_string(LeftPoint) + " | Right Player: " + to_string(RightPoint);
    }

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

                
                BALL.x += BALLSPEED_X * GetFrameTime();
                BALL.y += BALLSPEED_Y * GetFrameTime();

                
                if (CheckCollisionRecs(LeftPad, BALL) && BALLSPEED_X < 0) {
                    PlaySound(HitSound);
                    BALL.x = LeftPad.x + LeftPad.width; 
                    BALLSPEED_X = labs(BALLSPEED_X) + speedIncrement; 
                    float paddleCenterY = LeftPad.y + LeftPad.height / 2;
                    float ballCenterY = BALL.y + BALL.height / 2;
                    BALLSPEED_Y += (ballCenterY - paddleCenterY) * 0.1f; 
                } else if (CheckCollisionRecs(RightPad, BALL) && BALLSPEED_X > 0) {
                    PlaySound(HitSound);
                    BALL.x = RightPad.x - BALL.width;
                    BALLSPEED_X = -labs(BALLSPEED_X) - speedIncrement;
                }

                
                if (BALL.y < 0) {
                    PlaySound(HitSound);
                    BALL.y = 0;
                    BALLSPEED_Y = labs(BALLSPEED_Y); 
                } else if (BALL.y + BALL.height > screenHeight) {
                    PlaySound(HitSound);
                    BALL.y = screenHeight - BALL.height;
                    BALLSPEED_Y = -labs(BALLSPEED_Y);
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
    }

    void DrawStartMenu() {
        DrawTexture(startMenuBg, 0, 0, WHITE);
        DrawText("Undertale PingPong!", screenWidth / 2 - 200, screenHeight / 2 - 50, 40, WHITE);
        DrawText("Press SPACE to Start", screenWidth / 2 - 150, screenHeight / 2 + 10, 20, WHITE);
    }

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

int main(void) {
    SimpleGame GC;
    GC.GameLoop();
    return 0;
}
