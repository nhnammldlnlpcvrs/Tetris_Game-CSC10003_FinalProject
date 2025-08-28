#pragma once
#include "Model/Block/Block.h"

/**
 * @class OBlock
 * @brief Đại diện cho khối O trong trò chơi Tetris.
 *
 * Khối O có dạng hình vuông 2x2 và không thay đổi khi xoay.
 * - ID mặc định: 3
 * - Màu mặc định: vàng
 * - Các trạng thái xoay đều giữ nguyên hình dạng.
 */
class OBlock : public Block {
public:
    /**
     * @brief Khởi tạo khối O với hình dạng và màu sắc mặc định.
     */
    OBlock();

    /**
     * @brief Lấy màu của các ô trong trạng thái hiện tại của khối.
     * 
     * @return std::vector<Color> Danh sách màu sắc cho các ô.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao của khối O.
     * 
     * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới bản sao mới.
     */
    std::unique_ptr<Block> Clone() const override;
};
