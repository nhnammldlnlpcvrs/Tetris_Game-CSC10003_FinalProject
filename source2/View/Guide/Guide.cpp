/**
 * @file guide.cpp
 * @brief Triển khai chức năng vẽ bảng hướng dẫn người chơi (How to Play) trong game.
 * 
 * Tệp này chứa định nghĩa hàm `DrawGuide`, sử dụng thư viện Raylib để hiển thị 
 * hộp thông tin hướng dẫn điều khiển game cho người chơi. Hướng dẫn bao gồm các phím 
 * điều khiển như di chuyển, xoay khối, thả mềm, thả nhanh và cách chơi lại sau khi Game Over.
 * 
 * ## Hướng dẫn hiển thị gồm:
 * - Mũi tên trái/phải: Di chuyển khối
 * - Mũi tên lên: Xoay khối
 * - Mũi tên xuống: Rơi khối nhẹ (Soft Drop)
 * - Phím SPACE: Rơi khối nhanh (Hard Drop)
 * - Bất kỳ phím nào: Bắt đầu lại sau khi thua
 * 
 */

#include "source2/View/Guide/Guide.h"
#include "raylib.h"

void DrawGuide(const Font& font)
{
    Vector2 pos = {50, 700};

    int padding = 20;
    int lineHeight = 30;
    int numLines = 6;
    int boxWidth = 900;
    int boxHeight = padding * 2 + numLines * lineHeight;

    DrawRectangle(pos.x - padding, pos.y - padding, boxWidth, boxHeight, Fade(BLACK, 0.5f));

    DrawRectangleLines(pos.x - padding, pos.y - padding, boxWidth, boxHeight, YELLOW);

    DrawTextEx(font, "How to Play", pos, 24, 2, YELLOW);

    pos.y += 40;
    DrawTextEx(font, "Left / Right Arrow      : Move", pos, 20, 2, WHITE);
    pos.y += lineHeight;
    DrawTextEx(font, "Up Arrow                : Rotate Block", pos, 20, 2, WHITE);
    pos.y += lineHeight;
    DrawTextEx(font, "Down Arrow              : Soft Drop", pos, 20, 2, WHITE);
    pos.y += lineHeight;
    DrawTextEx(font, "SPACE                   : Hard Drop", pos, 20, 2, WHITE);
    pos.y += lineHeight;
    DrawTextEx(font, "Restart after Game Over : Any Key", pos, 20, 2, WHITE);
}
