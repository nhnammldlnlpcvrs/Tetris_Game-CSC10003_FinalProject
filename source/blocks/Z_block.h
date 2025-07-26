#pragma once

#include "../data/block.h"
#include "../core/position.h"
#include <memory>

/**
 * @class ZBlock
 * @brief Đại diện cho khối Z trong trò chơi Tetris.
 */
class ZBlock : public Block
{
public:
    /**
     * @brief Constructor khối Z.
     */
    ZBlock();

    /**
     * @brief Tạo một unique_ptr tới đối tượng ZBlock.
     * 
     * @return std::unique_ptr<ZBlock> Con trỏ thông minh tới khối Z.
     */
    static std::unique_ptr<ZBlock> Create();
};
