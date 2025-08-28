#pragma once

#include <ostream>

/**
 * @struct Position
 * @brief Đại diện cho một vị trí trong lưới trò chơi bằng chỉ số hàng và cột.
 */
struct Position {
    int row;    ///< Chỉ số hàng trong lưới.
    int column; ///< Chỉ số cột trong lưới.

    /**
     * @brief Khởi tạo một vị trí.
     * @param row Chỉ số hàng (mặc định = 0).
     * @param column Chỉ số cột (mặc định = 0).
     */
    Position(int row = 0, int column = 0);

    /**
     * @brief So sánh bằng giữa hai vị trí.
     * @param other Vị trí cần so sánh.
     * @return true nếu cùng hàng và cùng cột.
     */
    bool operator==(const Position& other) const;

    /**
     * @brief So sánh khác nhau giữa hai vị trí.
     * @param other Vị trí cần so sánh.
     * @return true nếu khác hàng hoặc khác cột.
     */
    bool operator!=(const Position& other) const;

    /**
     * @brief Xuất vị trí ra luồng dưới dạng (row, column).
     * @param os Luồng xuất (output stream).
     * @param pos Vị trí cần in.
     * @return Tham chiếu tới luồng đã ghi.
     */
    friend std::ostream& operator<<(std::ostream& os, const Position& pos);
};
