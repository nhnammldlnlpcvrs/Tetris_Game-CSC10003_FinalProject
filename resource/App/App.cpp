#include "App.h"
#include "raylib.h"
#include "Controller/Game/GameController.h"
#include "View/Guide/Guide.h"  

const int screenWidth = 1080;
const int screenHeight = 1080;
const int targetFPS = 60;

const float panelX = 630.0f;
const float panelWidth = 300.0f;

void App::Run() {
    InitWindow(screenWidth, screenHeight, "Tetris Game (OOP + Clean Architecture)");
    SetTargetFPS(targetFPS);

    Font font = LoadFontEx("assets/font/PressStart2P-Regular.ttf", 64, 0, 0);

    GameController game(20, 10, 30);  // rows, columns, cellSize
    game.Init();

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        game.Update(deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        DrawRectangle(panelX, 50, panelWidth, 900, DARKGRAY);

        DrawTextEx(font, "NEXT", {panelX + 20, 60}, 20, 2, WHITE); // Giữ nguyên
        game.DrawNextBlock();  // Vẽ khối tiếp theo

        DrawTextEx(font, "SCORE", {panelX + 20, 180}, 20, 2, WHITE); // Giữ nguyên
        DrawTextEx(font, TextFormat("%d", game.GetScore()), {panelX + 20, 210}, 24, 2, YELLOW);

        DrawTextEx(font, "BEST", {panelX + 20, 270}, 20, 2, WHITE); // Giữ nguyên
        DrawTextEx(font, TextFormat("%d", game.GetBestScore()), {panelX + 20, 300}, 24, 2, GREEN);

        DrawGuide(font, panelX + 12, 360, panelWidth - 24);

        if (game.IsGameOver()) {
            DrawTextEx(font, "GAME OVER", {screenWidth / 2.0f - 130, screenHeight / 2.0f - 50}, 30, 4, RED);
            DrawTextEx(font, "Press R to Restart", {screenWidth / 2.0f - 140, screenHeight / 2.0f}, 20, 2, WHITE);
            if (IsKeyPressed(KEY_R)) {
                game.Reset();
            }  
        }

        EndDrawing();
    }

    UnloadFont(font);
    CloseWindow();
}