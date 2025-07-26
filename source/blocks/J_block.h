#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class JBlock
 * @brief Đại diện cho khối J trong trò chơi Tetris.
 *
 * Kế thừa từ lớp Block, JBlock định nghĩa hình dạng và hành vi của khối gạch J.
 */
class JBlock : public Block
{
public:
    /**
     * @brief Constructor khối J.
     */
    JBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng JBlock.
     * 
     * @return std::unique_ptr<JBlock> Con trỏ thông minh tới khối J.
     */
    static std::unique_ptr<JBlock> Create();
};
