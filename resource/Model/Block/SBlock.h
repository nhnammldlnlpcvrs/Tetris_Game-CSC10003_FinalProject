#pragma once
#include "Model/Block/Block.h"

/**
 * @class SBlock
 * @brief Đại diện cho khối S trong trò chơi Tetris.
 *
 * Khối S có 4 trạng thái xoay và được gán màu xanh lá cây.
 * Kế thừa từ lớp cơ sở Block.
 */
class SBlock : public Block {
public:
    /**
     * @brief Khởi tạo một khối S mới.
     */
    SBlock();
    
    /**
     * @brief Lấy màu sắc của các ô trong khối S ở trạng thái xoay hiện tại.
     * 
     * @return std::vector<Color> Danh sách màu của các ô.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao của khối S.
     * 
     * @return std::unique_ptr<Block> Con trỏ thông minh trỏ tới bản sao của khối.
     */
    std::unique_ptr<Block> Clone() const override;
};
