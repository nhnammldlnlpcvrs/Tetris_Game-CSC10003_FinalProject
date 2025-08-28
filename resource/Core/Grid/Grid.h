#pragma once

#include <vector>
#include "Core/Graphics/Color.h"   ///< @note Dùng Color tự định nghĩa, không phải raylib::Color
#include "Core/Position/Position.h" ///< @note Dùng Position tự định nghĩa, không phải raylib::Vector2
#include <algorithm>

/**
 * @class Grid
 * @brief Đại diện cho lưới (bảng trò chơi) chứa các cell màu sắc.
 * 
 * - Mỗi cell có thể rỗng hoặc chứa màu (tương ứng với khối).
 * - Quản lý việc kiểm tra hợp lệ, xóa dòng đầy, và trạng thái lưới.
 */
class Grid {
public:
    /**
     * @brief Khởi tạo lưới với số hàng và cột.
     * @param rows Số hàng.
     * @param columns Số cột.
     */
    Grid(int rows, int columns);

    /**
     * @brief Kiểm tra xem ô tại (row, column) có bị chiếm không.
     * @param row Chỉ số hàng.
     * @param column Chỉ số cột.
     * @return true nếu bị chiếm hoặc ngoài lưới.
     */
    bool IsCellOccupied(int row, int column) const;

    /**
     * @brief Đặt màu cho một ô trong lưới.
     * @param row Chỉ số hàng.
     * @param column Chỉ số cột.
     * @param color Màu cần đặt.
     */
    void SetCell(int row, int column, const Color& color);

    /**
     * @brief Xóa (làm trống) một ô trong lưới.
     * @param row Chỉ số hàng.
     * @param column Chỉ số cột.
     */
    void ClearCell(int row, int column);

    /**
     * @brief Xóa toàn bộ các dòng đầy trong lưới.
     * @return Số dòng đã bị xóa.
     */
    int ClearFullLines();

    /// @brief Lấy số hàng của lưới.
    int GetRows() const;

    /// @brief Lấy số cột của lưới.
    int GetColumns() const;

    /// @brief Lấy toàn bộ dữ liệu các ô của lưới.
    const std::vector<std::vector<Color>>& GetCells() const;

    /**
     * @brief Kiểm tra xem một tập hợp vị trí có hợp lệ trong lưới hay không.
     * @param positions Danh sách vị trí.
     * @return true nếu tất cả đều nằm trong lưới và không bị chiếm.
     */
    bool IsValidPosition(const std::vector<Position>& positions) const;

    /**
     * @brief Kiểm tra xem có block nào chạm đỉnh lưới không.
     * @return true nếu có block ở hàng trên cùng.
     */
    bool HasBlockAtTop() const;

private:
    int _rows;    ///< Số hàng.
    int _columns; ///< Số cột.
    std::vector<std::vector<Color>> _cells; ///< Ma trận cell (mỗi cell là một màu).
};
