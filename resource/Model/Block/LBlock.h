#pragma once
#include "Model/Block/Block.h"

/**
 * @class LBlock
 * @brief Lớp đại diện cho khối L trong trò chơi Tetris.
 * 
 * Kế thừa từ lớp Block và cài đặt các phương thức đặc thù của khối L:
 * - Xác định hình dạng (các trạng thái xoay).
 * - Xác định màu sắc cho các ô (cells).
 * - Cho phép nhân bản đối tượng (Clone).
 */
class LBlock : public Block {
public:
    /**
     * @brief Constructor mặc định, khởi tạo khối L với:
     * - ID cố định
     * - Trạng thái xoay ban đầu
     * - Màu sắc
     * - Cấu hình hình dạng các cell
     */
    LBlock();

    /**
     * @brief Lấy màu sắc của các ô trong trạng thái xoay hiện tại.
     * 
     * @return std::vector<Color> Danh sách màu của các cell theo trạng thái hiện tại.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao của khối L.
     * 
     * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới bản sao mới của LBlock.
     */
    std::unique_ptr<Block> Clone() const override;
};
