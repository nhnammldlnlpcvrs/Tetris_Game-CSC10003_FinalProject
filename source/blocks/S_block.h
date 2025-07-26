#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class SBlock
 * @brief Đại diện cho khối S trong trò chơi Tetris.
 */
class SBlock : public Block
{
public:
    /**
     * @brief Constructor khối S.
     */
    SBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng SBlock.
     * 
     * @return std::unique_ptr<SBlock> Con trỏ thông minh tới khối S.
     */
    static std::unique_ptr<SBlock> Create();
};
