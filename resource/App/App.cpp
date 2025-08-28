#include "App.h"
#include "raylib.h"
#include "Controller/Game/GameController.h"
#include "View/Guide/Guide.h"  

/// Screen width in pixels
const int screenWidth = 1080;

/// Screen height in pixels
const int screenHeight = 1080;

/// Target frames per second
const int targetFPS = 60;

/// X position of the right-side panel
const float panelX = 630.0f;

/// Width of the right-side panel
const float panelWidth = 300.0f;

/**
 * @brief Main application loop for the Tetris game.
 *
 * Initializes the window, sets the target FPS, loads resources,
 * and runs the main game loop until the window is closed.
 * Inside the loop, it handles:
 * - Updating the game state
 * - Drawing game board, next block preview, score, and guide
 * - Handling game over state and restart
 */
void App::Run() {
    InitWindow(screenWidth, screenHeight, "Tetris Game (OOP + Clean Architecture)");
    SetTargetFPS(targetFPS);

    /// Load game font from assets
    Font font = LoadFontEx("assets/font/PressStart2P-Regular.ttf", 64, 0, 0);

    /// Game controller: manages board and gameplay
    GameController game(20, 10, 30);  ///< rows = 20, columns = 10, cellSize = 30
    game.Init();

    // Main game loop
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        game.Update(deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw main game board
        game.Draw();

        // Draw right-side info panel
        DrawRectangle(panelX, 50, panelWidth, 900, DARKGRAY);

        // Next block preview
        DrawTextEx(font, "NEXT", {panelX + 20, 60}, 20, 2, WHITE);
        game.DrawNextBlock();

        // Score
        DrawTextEx(font, "SCORE", {panelX + 20, 180}, 20, 2, WHITE);
        DrawTextEx(font, TextFormat("%d", game.GetScore()), {panelX + 20, 210}, 24, 2, YELLOW);

        // Best score
        DrawTextEx(font, "BEST", {panelX + 20, 270}, 20, 2, WHITE);
        DrawTextEx(font, TextFormat("%d", game.GetBestScore()), {panelX + 20, 300}, 24, 2, GREEN);

        // Control guide
        DrawGuide(font, panelX + 12, 360, panelWidth - 24);

        // Game over screen
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
