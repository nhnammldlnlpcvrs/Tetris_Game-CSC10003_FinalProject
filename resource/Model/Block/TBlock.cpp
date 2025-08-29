#include "TBlock.h"

/**
 * @brief Khởi tạo khối T trong trò chơi Tetris.
 *
 * Khối T có 4 trạng thái xoay khác nhau.
 * Trong mặc định, khối được gán màu xanh lá cây.
 */
TBlock::TBlock() {
    _id = 5;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {green};

    _cells = {
        {0, {{0,1}, {1,0}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,1}, {1,2}, {2,1}}},
        {2, {{1,0}, {1,1}, {1,2}, {2,1}}},
        {3, {{0,1}, {1,0}, {1,1}, {2,1}}}
    };
}

/**
 * @brief Tạo một bản sao của khối T.
 * 
 * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới bản sao.
 */
std::unique_ptr<Block> TBlock::Clone() const {
    return std::make_unique<TBlock>(*this);
}

/**
 * @brief Lấy màu của các ô trong khối T ở trạng thái xoay hiện tại.
 * 
 * Nếu chỉ có 1 màu trong `_colors`, tất cả ô sẽ được gán cùng màu đó.
 * 
 * @return std::vector<Color> Danh sách màu cho các ô.
 */
std::vector<Color> TBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
