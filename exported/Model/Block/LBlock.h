#pragma once
#include "Model/Block/Block.h"

class LBlock : public Block {
public:
    LBlock();
    std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
