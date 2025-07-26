#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class TBlock
 * @brief Đại diện cho khối T trong trò chơi Tetris.
 */
class TBlock : public Block
{
public:
    /**
     * @brief Constructor khối T.
     */
    TBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng TBlock.
     * 
     * @return std::unique_ptr<TBlock> Con trỏ thông minh tới khối T.
     */
    static std::unique_ptr<TBlock> Create();
};
