#include "SBlock.h"

/**
 * @brief Khởi tạo khối S trong trò chơi Tetris.
 *
 * - ID: 4
 * - Màu: xanh lá cây
 * - Có 4 trạng thái xoay.
 */
SBlock::SBlock() {
    _id = 4;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {green};

    _cells = {
        {0, {{0,1}, {0,2}, {1,0}, {1,1}}},
        {1, {{0,0}, {1,0}, {1,1}, {2,1}}},
        {2, {{1,1}, {1,2}, {2,0}, {2,1}}},
        {3, {{0,1}, {1,0}, {1,1}, {2,0}}}
    };
}

/**
 * @brief Tạo một bản sao mới của khối S.
 * 
 * @return std::unique_ptr<Block> Con trỏ thông minh trỏ đến bản sao.
 */
std::unique_ptr<Block> SBlock::Clone() const {
    return std::make_unique<SBlock>(*this);
}

/**
 * @brief Lấy màu sắc của các ô ở trạng thái xoay hiện tại.
 * 
 * @return std::vector<Color> Danh sách màu của các ô.
 */
std::vector<Color> SBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); ///< Lấy ô tương ứng với trạng thái xoay
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
