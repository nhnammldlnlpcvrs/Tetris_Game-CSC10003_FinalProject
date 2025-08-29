#pragma once
#include "Model/Block/Block.h"

class SBlock : public Block {
public:
    SBlock();
    
    std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
