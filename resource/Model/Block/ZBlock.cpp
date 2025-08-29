#include "ZBlock.h"

/**
 * @brief Khởi tạo khối Z với trạng thái mặc định.
 *
 * Khối Z có 4 trạng thái xoay khác nhau. Mỗi trạng thái được mô tả
 * bởi tập hợp các tọa độ ô trong ma trận. Mặc định khối có màu đỏ.
 */
ZBlock::ZBlock() {
    _id = 6;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {red};

    _cells = {
        {0, {{0,0}, {0,1}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,0}, {1,1}, {2,0}}},
        {2, {{1,0}, {1,1}, {2,1}, {2,2}}},
        {3, {{0,2}, {1,1}, {1,2}, {2,1}}}
    };
}

/**
 * @brief Tạo một bản sao (clone) của khối Z.
 * @return std::unique_ptr<Block> Con trỏ thông minh tới bản sao của khối.
 */
std::unique_ptr<Block> ZBlock::Clone() const {
    return std::make_unique<ZBlock>(*this);
}

/**
 * @brief Lấy màu của các ô trong khối Z ở trạng thái xoay hiện tại.
 *
 * Nếu khối chỉ có một màu, tất cả các ô sẽ được gán cùng màu.
 * Ngược lại, trả về danh sách màu đã định nghĩa sẵn cho từng ô.
 *
 * @return std::vector<Color> Danh sách màu ứng với các ô hiện tại.
 */
std::vector<Color> ZBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); ///< Lấy các ô ở trạng thái xoay hiện tại.
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
