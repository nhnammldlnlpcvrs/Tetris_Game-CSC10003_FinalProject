#include "JBlock.h"

/**
 * @brief Constructor cho khối J trong Tetris.
 * 
 * Khối J có hình dạng đặc trưng:
 *   ##
 *   #
 *   #
 */
JBlock::JBlock() {
    _id = 1;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = { blue };

    // Định nghĩa vị trí các ô (cells) cho 4 trạng thái xoay
    _cells = {
        {0, {{0,0}, {1,0}, {1,1}, {1,2}}},
        {1, {{0,1}, {0,2}, {1,1}, {2,1}}},
        {2, {{1,0}, {1,1}, {1,2}, {2,2}}},
        {3, {{0,1}, {1,1}, {2,0}, {2,1}}}
    };
}

/**
 * @brief Tạo một bản sao của JBlock.
 * @return std::unique_ptr<Block> con trỏ tới bản sao của JBlock
 */
std::unique_ptr<Block> JBlock::Clone() const {
    return std::make_unique<JBlock>(*this);
}

/**
 * @brief Trả về màu của từng ô trong khối.
 * 
 * Nếu chỉ có 1 màu, trả về vector màu cùng size với số ô hiện tại.
 */
std::vector<Color> JBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // an toàn với at()
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
