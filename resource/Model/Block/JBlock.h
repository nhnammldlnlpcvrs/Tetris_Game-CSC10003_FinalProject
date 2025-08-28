#pragma once
#include "Model/Block/Block.h"

/**
 * @class JBlock
 * @brief Đại diện cho khối J trong trò chơi Tetris.
 * 
 * Khối J có hình dạng đặc trưng:
 *   ##
 *   #
 *   #
 * 
 * Thừa kế từ lớp cơ sở Block và định nghĩa cách xoay,
 * màu sắc của khối J.
 */
class JBlock : public Block {
public:
    /**
     * @brief Khởi tạo khối J với trạng thái mặc định.
     */
    JBlock();

    /**
     * @brief Lấy màu sắc cho từng ô trong khối.
     * @return Vector chứa màu của tất cả ô trong trạng thái xoay hiện tại.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao (clone) của khối J.
     * @return Con trỏ unique_ptr trỏ đến bản sao của JBlock.
     */
    std::unique_ptr<Block> Clone() const override;
};
