#include "app.h"
#include <raylib.h>
#include "../game/game.h"
#include "../data/block.h"
#include "../audio/audio_service.h"
#include "../guide/guide.h"
#include <iostream>
#include <memory>

const float panelX = 630.0f;        ///< Toạ độ X của bảng điều khiển bên phải
const float panelWidth = 170.0f;    ///< Chiều rộng của bảng điều khiển

double lastUpdateTime = 0;

/**
 * @brief Kiểm tra xem sự kiện có được kích hoạt theo khoảng thời gian hay không.
 * 
 * @param interval Thời gian (giây) giữa các lần kích hoạt.
 * @return true nếu khoảng thời gian đã trôi qua kể từ lần cuối.
 * @return false nếu chưa đến thời điểm tiếp theo.
 */
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

/**
 * @brief Chạy vòng lặp chính của ứng dụng Tetris.
 * 
 * Khởi tạo cửa sổ, font chữ và game. Điều khiển vòng lặp chính của game,
 * xử lý input, update logic và render toàn bộ nội dung.
 */
void App::Run()
{
    InitWindow(960, 1080, "Tetris Game (OOP)");
    SetTargetFPS(60);

    // Tải font tuỳ chỉnh
    Font font = LoadFontEx("assets/font/PressStart2P-Regular.ttf", 64, 0, 0);

    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->GetAudioService()->PlayMusic();

    while (!WindowShouldClose())
    {
        // Cập nhật nhạc nền
        UpdateMusicStream(game->GetAudioService()->GetMusic());

        // Xử lý input
        game->HandleInput();

        // Di chuyển khối xuống mỗi 0.2 giây
        if (EventTriggered(0.2))
        {
            game->MoveBlockDown();
        }

        // Bắt đầu vẽ
        BeginDrawing();
        ClearBackground(darkBlue);

        // Hiển thị điểm cao nhất
        DrawTextEx(font, "BEST", 
            {panelX + (panelWidth - MeasureTextEx(font, "BEST", 28, 2).x) / 2, 30}, 28, 2, GOLD);
        DrawTextEx(font, "SCORE", 
            {panelX + (panelWidth - MeasureTextEx(font, "SCORE", 28, 2).x) / 2, 60}, 28, 2, GOLD);

        DrawRectangleRounded({panelX, 90, panelWidth, 60}, 0.3f, 6, lightBlue);

        char bestScoreText[10];
        snprintf(bestScoreText, sizeof(bestScoreText), "%d", game->bestScore);
        Vector2 bestScoreSize = MeasureTextEx(font, bestScoreText, 38, 2);
        DrawTextEx(font, bestScoreText, 
            {panelX + (panelWidth - bestScoreSize.x) / 2, 100}, 38, 2, WHITE);

        // Hiển thị điểm hiện tại
        DrawTextEx(font, "SCORE", 
            {panelX + (panelWidth - MeasureTextEx(font, "SCORE", 28, 2).x) / 2, 170}, 28, 2, WHITE);
        DrawRectangleRounded({panelX, 200, panelWidth, 60}, 0.3f, 6, lightBlue);

        char scoreText[10];
        snprintf(scoreText, sizeof(scoreText), "%d", game->score);
        Vector2 scoreSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, 
            {panelX + (panelWidth - scoreSize.x) / 2, 210}, 38, 2, WHITE);

        // Hiển thị khối kế tiếp
        DrawTextEx(font, "NEXT", 
            {panelX + (panelWidth - MeasureTextEx(font, "NEXT", 28, 2).x) / 2, 280}, 28, 2, WHITE);
        DrawRectangleRounded({panelX, 310, panelWidth, 180}, 0.3f, 6, lightBlue);

        // Hiển thị thông báo Game Over
        if (game->gameOver)
        {
            DrawTextEx(font, "GAME OVER", {400, 600}, 38, 2, WHITE);
            game->SaveBestScore();
        }

        // Vẽ lưới và các khối
        game->Draw();

        // Vẽ hướng dẫn chơi
        DrawGuide(font);

        EndDrawing();
    }

    // Đóng cửa sổ khi vòng lặp kết thúc
    CloseWindow();
}
