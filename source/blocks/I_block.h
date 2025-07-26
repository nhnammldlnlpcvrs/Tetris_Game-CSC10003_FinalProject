#pragma once 

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class IBlock
 * @brief Đại diện cho khối I trong trò chơi xếp gạch (Tetris).
 * 
 * Kế thừa từ lớp Block, IBlock định nghĩa cấu trúc và hành vi của khối gạch dạng I.
 */
class IBlock : public Block
{
public:
    /**
     * @brief Constructor của khối I.
     * 
     * Thiết lập vị trí ban đầu và trạng thái xoay của khối.
     */
    IBlock();

    /**
     * @brief Tạo một unique_ptr đến đối tượng IBlock.
     * 
     * @return std::unique_ptr<IBlock> Con trỏ thông minh tới khối I vừa được tạo.
     */
    static std::unique_ptr<IBlock> Create();
};
