#pragma once
#include "Model/Block/Block.h"

class ZBlock : public Block {
public:
    ZBlock();

    std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
