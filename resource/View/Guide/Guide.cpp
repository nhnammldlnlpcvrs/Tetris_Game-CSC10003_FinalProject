#include "Guide.h"
#include "raylib.h"

/**
 * @brief Vẽ khung hướng dẫn chơi game lên màn hình.
 *
 * Hàm này vẽ một hộp bán trong suốt chứa các dòng hướng dẫn điều khiển.
 *
 * @param font   Font chữ để hiển thị văn bản.
 * @param x      Tọa độ X của khung hướng dẫn.
 * @param y      Tọa độ Y của khung hướng dẫn.
 * @param width  Chiều rộng của khung hướng dẫn.
 *
 * @note
 *  - Các phím điều khiển được hiển thị gồm: 
 *    - Left/Right: Di chuyển
 *    - Up: Xoay
 *    - Down: Rơi mềm
 *    - SPACE: Rơi cứng
 *    - R: Chơi lại
 *    - Q: Thoát game
 */
void DrawGuide(const Font& font, float x, float y, float width) {
    const int padding = 16;
    const int lineH = 22; // Giảm xuống 22 để tối ưu không gian
    const int numLines = 6;
    const int boxH = padding * 2 + numLines * lineH + 50; // Tăng lên 50 để đủ không gian

    DrawRectangle(x, y, width, boxH, Fade(BLACK, 0.5f));
    DrawRectangleLines(x, y, width, boxH, YELLOW);

    Vector2 p{ x + padding, y + padding };
    DrawTextEx(font, "HOW TO PLAY", p, 16, 2, YELLOW); // Giảm từ 20 xuống 16

    p.y += 24; // Giữ khoảng cách 24 sau tiêu đề
    DrawTextEx(font, "Left/Right : Move", p, 12, 2, WHITE); 
    p.y += lineH;
    DrawTextEx(font, "Up      : Rotate", p, 12, 2, WHITE);
    p.y += lineH;
    DrawTextEx(font, "Down    : Soft Drop", p, 12, 2, WHITE);
    p.y += lineH;
    DrawTextEx(font, "SPACE   : Hard Drop", p, 12, 2, WHITE);
    p.y += lineH;
    DrawTextEx(font, "R       : Restart", p, 12, 2, WHITE);
    p.y += lineH;
    DrawTextEx(font, "Q       : Quit Game", p, 12, 2, WHITE);
}
