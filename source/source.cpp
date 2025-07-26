#include <raylib.h>
#include "game/game.h"
#include "data/block.h"
#include "audio/audio_service.h"
#include "guide/guide.h"
#include <iostream>
#include <memory>

const float panelX = 630.0f;       // Tọa độ X gốc của các khối bên phải
const float panelWidth = 170.0f;   // Chiều rộng khối

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(960, 1080, "Tetris Game (OOP)");
    SetTargetFPS(60);

    Font font = LoadFontEx("assets/font/PressStart2P-Regular.ttf", 64, 0, 0);

    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->GetAudioService()->PlayMusic();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game->GetAudioService()->GetMusic());
        game->HandleInput();

        if (EventTriggered(0.2))
        {
            game->MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        // BEST SCORE
        DrawTextEx(font, "BEST", 
            {panelX + (panelWidth - MeasureTextEx(font, "BEST", 28, 2).x) / 2, 30}, 28, 2, 
            GOLD);
        DrawTextEx(font, "SCORE", 
            {panelX + (panelWidth - MeasureTextEx(font, "SCORE", 28, 2).x) / 2, 60}, 28, 2, 
            GOLD);

        DrawRectangleRounded({panelX, 90, panelWidth, 60}, 0.3f, 6, lightBlue);

        char bestScoreText[10];
        sprintf_s(bestScoreText, sizeof(bestScoreText), "%d", game->bestScore);
        Vector2 bestScoreSize = MeasureTextEx(font, bestScoreText, 38, 2);
        DrawTextEx(font, bestScoreText, {panelX + (panelWidth - bestScoreSize.x) / 2, 100}, 38, 2, WHITE);

        // CURRENT SCORE
        DrawTextEx(font, "SCORE", 
            {panelX + (panelWidth - MeasureTextEx(font, "SCORE", 28, 2).x) / 2, 170}, 28, 2, 
            WHITE);
        DrawRectangleRounded({panelX, 200, panelWidth, 60}, 0.3f, 6, lightBlue);

        char scoreText[10];
        sprintf_s(scoreText, sizeof(scoreText), "%d", game->score);
        Vector2 scoreSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, 
            {panelX + (panelWidth - scoreSize.x) / 2, 210}, 38, 2, WHITE);

        // NEXT BLOCK
        DrawTextEx(font, "NEXT", 
            {panelX + (panelWidth - MeasureTextEx(font, "NEXT", 28, 2).x) / 2, 280}, 28, 2, 
            WHITE);
        DrawRectangleRounded({panelX, 310, panelWidth, 180}, 0.3f, 6, lightBlue);

        // GAME OVER
        if (game->gameOver)
        {
            DrawTextEx(font, "GAME OVER", {400, 600}, 38, 2, WHITE);
            game->SaveBestScore();
        }

        game->Draw();
        DrawGuide(font);
        EndDrawing();
    }

    CloseWindow();
}
