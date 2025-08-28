#include "GridRender.h"

/**
 * @brief Khởi tạo đối tượng GridRenderer với kích thước ô (cell size).
 * 
 * @param cellSize Kích thước của mỗi ô trong lưới (pixel).
 */
GridRenderer::GridRenderer(int cellSize)
    : _cellSize(cellSize) {}

/**
 * @brief Vẽ lưới và các ô màu của grid lên màn hình.
 * 
 * Hàm này hiển thị:
 * - Các đường viền lưới bằng màu xám nhạt (có alpha để hiển thị mờ).
 * - Các ô đã có block (cell có màu, alpha khác 0).
 * 
 * @param grid Lưới game hiện tại.
 * @param offset_x Vị trí dịch theo trục X (pixel).
 * @param offset_y Vị trí dịch theo trục Y (pixel).
 */
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
