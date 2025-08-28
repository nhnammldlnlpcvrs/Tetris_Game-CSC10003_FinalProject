#include "LBlock.h"

/**
 * @brief Constructor của LBlock.
 * 
 * Khởi tạo khối L với:
 * - ID = 2
 * - Trạng thái xoay ban đầu = 0
 * - Vị trí offset hàng/cột = 0
 * - Màu cam (orange)
 * - Các cấu hình tọa độ của 4 trạng thái xoay.
 */
LBlock::LBlock() {
    _id = 2;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {orange};

    _cells = {
        {0, {{0,2}, {1,0}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,1}, {2,1}, {2,2}}},
        {2, {{1,0}, {1,1}, {1,2}, {2,0}}},
        {3, {{0,0}, {0,1}, {1,1}, {2,1}}}
    };
}

/**
 * @brief Tạo bản sao của khối L.
 * 
 * @return std::unique_ptr<Block> con trỏ thông minh tới một bản sao của LBlock.
 */
std::unique_ptr<Block> LBlock::Clone() const {
    return std::make_unique<LBlock>(*this);
}

/**
 * @brief Lấy màu của các ô (cells) trong trạng thái xoay hiện tại.
 * 
 * - Nếu chỉ có một màu trong `_colors`, toàn bộ cell sẽ dùng chung màu đó.  
 * - Nếu có nhiều màu, trả về danh sách màu gốc.
 * 
 * @return std::vector<Color> danh sách màu cho các cell hiện tại.
 */
std::vector<Color> LBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
