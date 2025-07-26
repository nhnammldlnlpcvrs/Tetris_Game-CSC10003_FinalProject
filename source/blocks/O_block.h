#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class OBlock
 * @brief Đại diện cho khối O trong trò chơi Tetris.
 *
 * OBlock có hình vuông và không bị xoay.
 */
class OBlock : public Block
{
public:
    /**
     * @brief Constructor khối O.
     */
    OBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng OBlock.
     * 
     * @return std::unique_ptr<OBlock> Con trỏ thông minh tới khối O.
     */
    static std::unique_ptr<OBlock> Create();
};
