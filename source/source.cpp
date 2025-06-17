#include "raylib.h"

int main() {
    InitWindow(500, 620, "Tetris Game");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib is working!", 250, 280, 20, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
