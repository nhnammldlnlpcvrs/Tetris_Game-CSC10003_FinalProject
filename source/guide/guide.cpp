#include "guide.h"
#include "raylib.h"

void DrawGuide(Font& font)
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
