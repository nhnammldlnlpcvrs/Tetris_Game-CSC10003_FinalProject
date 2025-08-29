#pragma once
#include "Model/Block/Block.h"

class JBlock : public Block {
public:
    JBlock();
    std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
