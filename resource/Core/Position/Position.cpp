#include "Position.h"

/**
 * @brief Khởi tạo một vị trí với hàng và cột.
 * @param row Chỉ số hàng.
 * @param column Chỉ số cột.
 */
Position::Position(int row, int column)
    : row(row), column(column) {}

/**
 * @brief So sánh bằng giữa hai vị trí.
 * @param other Vị trí cần so sánh.
 * @return true nếu cùng hàng và cùng cột.
 */
bool Position::operator==(const Position& other) const {
    return row == other.row && column == other.column;
}

/**
 * @brief So sánh khác nhau giữa hai vị trí.
 * @param other Vị trí cần so sánh.
 * @return true nếu khác hàng hoặc khác cột.
 */
bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

/**
 * @brief Xuất vị trí ra luồng dưới dạng (row, column).
 * @param os Luồng xuất (output stream).
 * @param pos Vị trí cần in.
 * @return Tham chiếu tới luồng đã ghi.
 */
std::ostream& operator<<(std::ostream& os, const Position& pos) {
    return os << "(" << pos.row << ", " << pos.column << ")";
}
