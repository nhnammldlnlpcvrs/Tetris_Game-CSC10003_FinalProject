#include "IBlock.h"

/**
 * @brief Constructor của IBlock (khối dạng chữ I trong Tetris).
 * 
 * - Gán ID = 0, trạng thái xoay = 0, offset hàng/cột = 0.  
 * - Màu mặc định: cyan (cho toàn bộ cell).  
 * - Định nghĩa 4 trạng thái xoay của khối I:
 *   - 0: Nằm ngang hàng 1 (4 cell liền nhau).  
 *   - 1: Nằm dọc ở cột 2.  
 *   - 2: Nằm ngang ở hàng 2.  
 *   - 3: Nằm dọc ở cột 1.  
 */
IBlock::IBlock() {
    _id = 0;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = { cyan };  ///< Mặc định 1 màu cho tất cả các cell.

    // Định nghĩa các vị trí cell cho 4 trạng thái xoay
    _cells = {
        {0, { {1,0}, {1,1}, {1,2}, {1,3} }},
        {1, { {0,2}, {1,2}, {2,2}, {3,2} }},
        {2, { {2,0}, {2,1}, {2,2}, {2,3} }},
        {3, { {0,1}, {1,1}, {2,1}, {3,1} }}
    };
}

/**
 * @brief Tạo bản sao (clone) của IBlock.
 * @return std::unique_ptr<Block> Bản sao của khối I.
 */
std::unique_ptr<Block> IBlock::Clone() const {
    return std::make_unique<IBlock>(*this);
}

/**
 * @brief Lấy màu sắc cho từng cell của khối I.
 * 
 * - Nếu `_colors` chỉ có 1 màu (cyan), thì trả về vector màu cùng kích thước
 *   với số cell hiện tại (tất cả cell cùng màu).  
 * - Nếu có nhiều màu, trả về vector màu gốc.
 * 
 * @return std::vector<Color> Danh sách màu của các cell.
 */
std::vector<Color> IBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() an toàn cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
