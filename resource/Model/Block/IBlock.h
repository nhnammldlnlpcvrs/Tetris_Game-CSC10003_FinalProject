#pragma once
#include "Model/Block/Block.h"

/**
 * @brief Lớp đại diện cho khối I trong Tetris.
 * 
 * Khối I là một khối gồm 4 ô liên tiếp, có 4 trạng thái xoay:
 * - Nằm ngang ở hàng 1 hoặc hàng 2.  
 * - Nằm dọc ở cột 1 hoặc cột 2.  
 * 
 * Mặc định có màu cyan cho toàn bộ cell.
 */
class IBlock : public Block {
public:
    /**
     * @brief Constructor khởi tạo khối I với trạng thái mặc định.
     */
    IBlock();

    /**
     * @brief Lấy màu của từng cell trong khối I.
     * 
     * - Nếu chỉ định 1 màu duy nhất, tất cả cell sẽ cùng màu.  
     * - Nếu có nhiều màu, trả về vector màu gốc.  
     * 
     * @return std::vector<Color> Danh sách màu của các cell.
     */
    std::vector<Color> GetCellColor() const override;
    
    /**
     * @brief Tạo bản sao (clone) của khối I.
     * @return std::unique_ptr<Block> Bản sao của IBlock.
     */
    std::unique_ptr<Block> Clone() const override;
};
