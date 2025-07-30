#include <raylib.h>
#include "../data/block.h"
#include "../core/position.h"
#include "../data/colors.h"

const int CELL_SIZE = 30;
const int ROWS = 20;
const int COLUMNS = 10;
const int screenWidth = COLUMNS * CELL_SIZE;
const int screenHeight = ROWS * CELL_SIZE;

int main()
{
    InitWindow(screenWidth, screenHeight, "Tetris - Test Move Block ");
    SetTargetFPS(60);

    Block block; 
    std::vector<Color> cellColors = GetCellColors();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_RIGHT))
            block.Move(0, 1);
        else if (IsKeyPressed(KEY_LEFT))
            block.Move(0, -1);
        else if (IsKeyPressed(KEY_DOWN))
            block.Move(1, 0);
        else if (IsKeyPressed(KEY_UP))
            block.Rotate();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i <= ROWS; i++)
            DrawLine(0, i * CELL_SIZE, screenWidth, i * CELL_SIZE, LIGHTGRAY);

        for (int i = 0; i <= COLUMNS; i++)
            DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, screenHeight, LIGHTGRAY);

        Color blockColor = cellColors[block.id % cellColors.size()];

        std::vector<Position> positions = block.GetCellPositions();
        for (const Position& pos : positions)
        {
            int x = pos.column * CELL_SIZE;
            int y = pos.row * CELL_SIZE;

            DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, blockColor);
            DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
