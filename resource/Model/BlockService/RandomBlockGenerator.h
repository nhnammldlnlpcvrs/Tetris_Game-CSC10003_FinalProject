#pragma once
#include <memory>
#include "Model/Block/Block.h"

/**
 * @class RandomBlockGenerator
 * @brief Lớp hỗ trợ sinh ngẫu nhiên các khối Tetris.
 *
 * Lớp này cung cấp phương thức tĩnh để tạo ra một block mới
 * trong số 7 loại block chuẩn của Tetris (I, J, L, O, S, T, Z).
 */
class RandomBlockGenerator {
public:
    /**
     * @brief Sinh ngẫu nhiên một block và đặt nó vào giữa lưới.
     *
     * @param gridColumns Số cột của lưới, dùng để xác định vị trí ban đầu của block.
     * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới block được tạo.
     */
    static std::unique_ptr<Block> Generate(int gridColumns);
};
