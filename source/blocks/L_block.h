#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class LBlock
 * @brief Đại diện cho khối L trong trò chơi Tetris.
 */
class LBlock : public Block
{
public:
    /**
     * @brief Constructor khối L.
     */
    LBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng LBlock.
     * 
     * @return std::unique_ptr<LBlock> Con trỏ thông minh tới khối L.
     */
    static std::unique_ptr<LBlock> Create();
};
