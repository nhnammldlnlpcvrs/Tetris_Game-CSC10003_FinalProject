#include <raylib.h>
#include "game/game.h"
#include "data/block.h"
#include "audio/audio_service.h"
#include <iostream>
#include <memory>

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
    InitWindow(720, 1080, "Tetris Game (OOP)");
    SetTargetFPS(60);

    Font font = LoadFontEx("assets/font/PressStart2P-Regular.ttf", 64, 0, 0);

    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->GetAudioService()->PlayMusic();

    while (WindowShouldClose() == false)
    {
        
        UpdateMusicStream(game->GetAudioService()->GetMusic());
        game->HandleInput();
        
        if (EventTriggered(0.2))
        {
            game->MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
        if (game->gameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
        }
        DrawRectangleRounded({ 320.0f, 55.0f, 170.0f, 60.0f }, 0.3f, 6, lightBlue);

        char scoreText[10];
        sprintf_s(scoreText, sizeof(scoreText), "%d", game->score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
        DrawRectangleRounded({ 320.0f, 215.0f, 170.0f, 180.0f }, 0.3f, 6, lightBlue);
        game->Draw();
        EndDrawing();
    }

    CloseWindow();
}