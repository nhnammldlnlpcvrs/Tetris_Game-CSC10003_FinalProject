#pragma once
#include "Model/Block/Block.h"

class TBlock : public Block {
public:
    TBlock();
    
    std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
