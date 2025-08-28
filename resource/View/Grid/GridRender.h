#pragma once
#include "Core/Grid/Grid.h"
#include "Core/Graphics/Color.h"
#include "raylib.h"

/**
 * @class GridRenderer
 * @brief Lớp chịu trách nhiệm hiển thị lưới (grid) và các ô chứa block.
 * 
 * Lớp này đảm nhiệm vai trò "View" trong mô hình MVC, chỉ phụ trách phần hiển thị,
 * không xử lý logic của game. Nó sẽ vẽ:
 * - Đường viền lưới với màu xám nhạt.
 * - Các ô block đã được tô màu trong grid.
 */
class GridRenderer {
public:
    /**
     * @brief Khởi tạo GridRenderer với kích thước của mỗi ô.
     * 
     * @param cellSize Kích thước (pixel) của mỗi ô trong lưới.
     */
    GridRenderer(int cellSize);

    /**
     * @brief Vẽ lưới và các block từ grid lên màn hình.
     * 
     * @param grid Lưới hiện tại của game (bao gồm thông tin các ô).
     * @param offset_x Tọa độ dịch chuyển theo trục X (pixel).
     * @param offset_y Tọa độ dịch chuyển theo trục Y (pixel).
     */
    void Draw(const Grid& grid, int offset_x, int offset_y) const;

private:
    int _cellSize; ///< Kích thước (pixel) của mỗi ô trong lưới.
};
