#pragma once

#include <memory>
#include <stdexcept>
#include "source2/View/BlockView.h"
#include "source2/Model/Service/BlockHistory.h"
#include "source2/Model/Block/Block.h"

/**
 * @brief Controller điều khiển hành vi của Block (di chuyển, xoay, undo, redo).
 * Áp dụng: Command + Memento Pattern.
 */
class BlockController {
public:
    explicit BlockController(std::shared_ptr<Block> block);

    void Move(int delta_row, int delta_col);
    void Rotate();
    std::shared_ptr<Block> GetBlock() const;

    void SaveState();
    void Undo();
    void Redo();

private:
    std::shared_ptr<Block> block_;
    BlockHistory _history;
};
