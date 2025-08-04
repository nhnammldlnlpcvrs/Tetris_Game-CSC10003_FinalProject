#include "GridRender.h"

GridRenderer::GridRenderer(int cellSize)
    : _cellSize(cellSize) {}

void GridRenderer::Draw(const Grid& grid, int offset_x, int offset_y) const {
    for (int row = 0; row < grid.GetRows(); ++row) {
        for (int col = 0; col < grid.GetColumns(); ++col) {
            Color cellColor = grid.GetCells()[row][col];
            if (cellColor.a != 0) {
                DrawRectangle(
                    offset_x + col * _cellSize,
                    offset_y + row * _cellSize,
                    _cellSize - 1,
                    _cellSize - 1,
                    cellColor
                );
            }
        }
    }
}
