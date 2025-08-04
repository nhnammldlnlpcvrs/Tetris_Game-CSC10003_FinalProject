#include "App.h"
#include "raylib.h"

#include "../source2/Controller/Game/GameController.h"

const int screenWidth = 960;
const int screenHeight = 1080;
const int targetFPS = 60;

const float panelX = 630.0f;
const float panelWidth = 260.0f;

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

        // Vẽ game
        game.Draw();

        // Giao diện bên phải
        DrawRectangle(panelX, 50, panelWidth, 900, DARKGRAY);

        DrawTextEx(font, "NEXT", {panelX + 20, 60}, 18, 2, WHITE);
        // Có thể thêm game.DrawNextBlock() nếu có hỗ trợ vẽ trước

        DrawTextEx(font, "SCORE", {panelX + 20, 200}, 18, 2, WHITE);
        DrawTextEx(font, TextFormat("%d", game.GetScore()), {panelX + 20, 230}, 24, 2, YELLOW);

        DrawTextEx(font, "BEST", {panelX + 20, 280}, 18, 2, WHITE);
        DrawTextEx(font, TextFormat("%d", game.GetBestScore()), {panelX + 20, 310}, 24, 2, GREEN);

        DrawTextEx(font, "ARROWS:", {panelX + 20, 400}, 18, 2, WHITE);
        DrawTextEx(font, "←→: Move", {panelX + 20, 430}, 14, 2, LIGHTGRAY);
        DrawTextEx(font, "↑: Rotate", {panelX + 20, 460}, 14, 2, LIGHTGRAY);
        DrawTextEx(font, "↓: Drop", {panelX + 20, 490}, 14, 2, LIGHTGRAY);

        if (game.IsGameOver()) {
            DrawTextEx(font, "GAME OVER", {screenWidth / 2.0f - 130, screenHeight / 2.0f - 50}, 30, 4, RED);
            DrawTextEx(font, "Press R to Restart", {screenWidth / 2.0f - 140, screenHeight / 2.0f}, 16, 2, WHITE);
            if (IsKeyPressed(KEY_R)) {
                game.Reset();
            }
        }

        EndDrawing();
    }

    UnloadFont(font);
    CloseWindow();
}
