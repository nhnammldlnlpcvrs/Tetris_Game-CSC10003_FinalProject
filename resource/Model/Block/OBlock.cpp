#include "OBlock.h"

/**
 * @brief Constructor khối O.
 * 
 * Khởi tạo khối vuông (OBlock) với:
 * - ID = 3
 * - Trạng thái xoay mặc định = 0
 * - Màu sắc = vàng
 * - Hình dạng gồm 4 ô vuông sắp thành khối 2x2 (cố định ở mọi trạng thái xoay).
 */
OBlock::OBlock() {
    _id = 3;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {yellow};
    _cells = {
        {0, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {1, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {2, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {3, {{0,0}, {0,1}, {1,0}, {1,1}}}
    };
}

/**
 * @brief Tạo bản sao của khối O.
 * 
 * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới bản sao mới của OBlock.
 */
std::unique_ptr<Block> OBlock::Clone() const {
    return std::make_unique<OBlock>(*this);
}

/**
 * @brief Lấy danh sách màu sắc cho các ô trong trạng thái xoay hiện tại.
 * 
 * - Nếu khối chỉ có 1 màu, nhân bản ra cho toàn bộ các ô.
 * - Nếu có nhiều màu, trả về danh sách màu đã được định nghĩa sẵn.
 * 
 * @return std::vector<Color> Danh sách màu sắc của các ô.
 */
std::vector<Color> OBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); ///< Lấy các ô của trạng thái xoay hiện tại
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
