#include "GridRender.h"

GridRenderer::GridRenderer(int cellSize)
    : _cellSize(cellSize) {}

void GridRenderer::Draw(const Grid& grid, int offset_x, int offset_y) const {
    // Màu xám nhạt có alpha để hiển thị mờ
    Color faintGray = {100, 100, 100, 50};  // R, G, B, A

    for (int row = 0; row < grid.GetRows(); ++row) {
        for (int col = 0; col < grid.GetColumns(); ++col) {
            Color cellColor = grid.GetCells()[row][col];

            // Vẽ lưới cho mọi ô
            DrawRectangleLines(
                offset_x + col * _cellSize,
                offset_y + row * _cellSize,
                _cellSize,
                _cellSize,
                faintGray
            );

            // Nếu ô có màu (có block), thì vẽ ô đó
            if (cellColor.a != 0) {
                DrawRectangle(
                    offset_x + col * _cellSize + 1,
                    offset_y + row * _cellSize + 1,
                    _cellSize - 2,
                    _cellSize - 2,
                    cellColor
                );
            }
        }
    }
}
