#pragma once
#include "Model/Block/Block.h"

class OBlock : public Block {
public:
    OBlock();
        std::vector<Color> GetCellColor() const override;

    std::unique_ptr<Block> Clone() const override;
};
